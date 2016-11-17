/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyork <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:04:20 by kyork             #+#    #+#             */
/*   Updated: 2016/11/16 16:19:33 by kyork            ###   ########.fr       */
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

void		shell_loop(void)
{
	char	*line;
	int		status;
	t_cmd	*cmd;

	while (1)
	{
		status = get_next_line(0, &line);
		if (status <= 0)
			break ;
		cmd = parse_line(line);
		free(line);
	}
	if (status == 0)
		ft_printf("logout\n");
	free(line);
}
