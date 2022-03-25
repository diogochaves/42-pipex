/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 20:40:22 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/25 11:40:42 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	error(int error_code)
{
	if (error_code == ERROR_MALLOC)
		ft_putstr_fd("\033[31;1m\n   MALLOC ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_OPEN)
		ft_putstr_fd("\033[33;1m\n   ERROR OPENING FILE\033[0m\n\n", 1);
	if (error_code == ERROR_ARGC)
		ft_putstr_fd("\033[33;1m\n   WRONG NUMBER OF ARGUMENTS\033[0m\n\n", 1);
	if (error_code == ERROR_FORK)
		ft_putstr_fd("\033[31;1m\n   FORK ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_PIPE)
		ft_putstr_fd("\033[31;1m\n   PIPE ERROR\033[0m\n\n", 1);
	if (error_code == ERROR_EXEC)
		ft_putstr_fd("\033[31;1m\n   EXEC ERROR\033[0m\n\n", 1);
	exit(error_code);
}

void	free_pipex(t_pipex *px)
{
	int	i;
	int	j;

	i = -1;
	while (++i < px->cmd_count)
	{
		j = 0;
		while (px->cmd[i]->args[j])
			free(px->cmd[i]->args[j++]);
		free(px->cmd[i]->args);
		free(px->cmd[i]);
	}
	free(px->cmd);
}
