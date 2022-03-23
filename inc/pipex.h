/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 00:36:04 by dchaves-          #+#    #+#             */
/*   Updated: 2022/03/23 20:46:26 by dchaves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h> // malloc free exit
# include <unistd.h> // read write close access dup execve fork pipe unlink
# include <fcntl.h> // open
# include <stdio.h> // perror
# include <string.h> // strerror
# include <sys/wait.h> // wait waitpid
# include "../lib/libft/inc/libft.h" // libft gnl
# include "./macros.h"
# include "./structs.h"

void	init(int argc, char **argv, t_pipex *px);
void	error(int error_code);
void	free_pipex(t_pipex *px);

#endif
