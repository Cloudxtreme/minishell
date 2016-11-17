/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:51:19 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 17:31:40 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define NORETURN void __attribute__((noreturn))

/*
** this function will have the dup2() etc calls
*/
static NORETURN	do_exec(t_shell *sh, t_cmd *cmd)
{
	(void)sh;
	execve(cmd->argv[0], cmd->argv, cmd->envp);
	ft_perror(cmd->argv[0]);
	exit(127);
}

pid_t			g_foreground;

static int		do_wait(pid_t pid)
{
	int		status;
	pid_t	ret;

	g_foreground = pid;
	while (1)
	{
		ret = waitpid(pid, &status, 0);
		if (ret == -1 && errno == EINTR)
			continue ;
		if (ret == -1 && errno == ECHILD)
		{
			g_foreground = 0;
			return (0);
		}
		if (ret == -1)
		{
			ft_perror("wait");
		}
		g_foreground = 0;
		return (status);
	}
}

int				exec_command(t_shell *sh, t_cmd *cmd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		do_exec(sh, cmd);
	else if (pid == -1)
	{
		ft_perror("fork");
		return (127);
	}
	else
	{
		return (do_wait(pid));
	}
}
