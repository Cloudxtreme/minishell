/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:24:16 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 16:51:15 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"
#include "builtins.h"

#include <stdlib.h>

t_builtin_def	g_builtins[] = {
	{":", &builtin_colon},
	{"bye", &builtin_exit},
	{"logout", &builtin_exit},
	{"exit", &builtin_exit},
	{"cd", &builtin_cd},
	{"chdir", &builtin_cd},
	{"pwd", &builtin_pwd},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"env", &builtin_env},
	{"export", &builtin_export},
};

t_builtin_f		get_builtin(char **argv)
{
	int		idx;

	idx = -1;
	while (++idx < ARRAYLEN(g_builtins))
	{
		if (0 == ft_strcmp(argv[0], g_builtins[idx].name))
			return (g_builtins[idx].func);
	}
	return (NULL);
}

int				builtin_colon(t_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}

int				builtin_true(t_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (0);
}

int				builtin_false(t_shell *sh, char **argv)
{
	(void)sh;
	(void)argv;
	return (1);
}

int				builtin_exit(t_shell *sh, char **argv)
{
	int	code;

	(void)sh;
	if (argv[1])
		code = ft_atoi(argv[1]);
	else
		code = 0;
	exit(code);
	return (0);
}
