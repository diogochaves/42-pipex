/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:32:20 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/23 21:33:58 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pipex {
	int		file[2];
	int		pipe[2];
	int		cmds;
	//char	**cmd;
	char	***cmd_args;
}	t_pipex;

#endif
