/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/01 19:47:13 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/mylib/include/mylib.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_arg
{
	char	*infile;
	char	*outfile;
	char	**path_list;
	t_list	*cmd;
}	t_arg;

void	parsing_pipex(t_arg *data, int argc, char **argv, char **env);

#endif
