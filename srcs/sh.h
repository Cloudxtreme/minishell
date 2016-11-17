/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:13:33 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 16:25:25 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <stdbool.h>
# include <libft.h>

typedef struct			s_envvar {
	char				*value;
	bool				is_export;
}						t_envvar;
/*
** t_var.value: allocated
*/

typedef struct			s_shell {
	t_array				env;
}						t_shell;
/*
** t_shell.env: t_array<t_envvar>
*/

typedef int				(*t_builtin_f)(t_shell* sh, char **argv);

typedef struct			s_cmd {
	char				**argv;
	t_builtin_f			builtin;
	struct s_cmd		*next;
}					t_cmd;
/*
** t_cmd.argv: allocated[allocated]
*/

typedef struct			s_builtin_def {
	const char			*name;
	t_builtin_f			func;
}						t_builtin_def;

t_builtin_f				get_builtin(char **argv);
t_cmd					*parse_line(char *line);
void					shell_loop(t_shell *sh);

#endif
