/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:26:27 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 17:28:58 by kyork            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "sh.h"

int			builtin_colon(t_shell *sh, char **argv);
int			builtin_exit(t_shell *sh, char **argv);

int			builtin_setenv(t_shell *sh, char **argv);
int			builtin_unsetenv(t_shell *sh, char **argv);
int			builtin_env(t_shell *sh, char **argv);
int			builtin_export(t_shell *sh, char **argv);

int			builtin_cd(t_shell *sh, char **argv);
int			builtin_pwd(t_shell *sh, char **argv);

int			builtin_true(t_shell *sh, char **argv);
int			builtin_false(t_shell *sh, char **argv);

#endif
