/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:13:33 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 17:49:25 by kyork            ###   ########.fr       */
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
	char				**envp;
	t_builtin_f			builtin;
	struct s_cmd		*next;
}						t_cmd;
/*
** t_cmd.argv: allocated[allocated]
*/

typedef struct			s_builtin_def {
	const char			*name;
	t_builtin_f			func;
}						t_builtin_def;
typedef struct			s_signal_def {
	int					sig;
	const char			*name;
}						t_signal_def;

void					ft_perror(char *ctx);

void					shell_loop(t_shell *sh);

t_cmd					*parse_line(char *line);

t_builtin_f				get_builtin(char **argv);
int						exec_command(t_shell *sh, t_cmd *cmd);
void					handle_result(t_shell *sh, t_cmd *cmd, int status);

#endif
