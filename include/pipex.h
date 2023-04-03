/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/03 18:49:22 by eguelin          ###   ########lyon.fr   */
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
void	ft_free_data(t_arg *data);
void	ft_exit(t_arg *data);

int		ft_process(t_arg *data, char **env);

#endif
