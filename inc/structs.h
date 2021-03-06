/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:32:20 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/26 21:03:19 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		file[2];
	int		pipe[2];
	char	**path;
	t_cmd	**cmd;
	int		cmd_count;
	int		exit_code;
}	t_pipex;

#endif
