/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:04:20 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 17:32:51 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include <libft.h>
#include <ft_printf.h>

#include <stdlib.h>
#include <unistd.h>

static void	prompt(void)
{
	char	*str;

	str = getcwd(NULL, -1);
	ft_printf("[%s]$> ", str);
	free(str);
}

void		shell_loop(t_shell *sh)
{
	char	*line;
	int		status;
	t_cmd	*cmd;

	while (1)
	{
		prompt();
		status = get_next_line(0, &line);
		if (status <= 0)
			break ;
		cmd = parse_line(line);
		free(line);
		if (cmd->builtin)
			status = cmd->builtin(sh, cmd->argv);
		else
			status = exec_command(sh, cmd);
		handle_result(sh, cmd, status);
	}
	if (status == 0)
		ft_printf("logout\n");
	free(line);
}
