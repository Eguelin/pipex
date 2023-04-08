/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/08 14:07:04 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/mylib/include/mylib.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_data
{
	int		cmd;
	int		pipefd[2];
	char	**path_list;
}	t_data;

void	ft_path_list(char **env, t_data *data);
char	*ft_relative_path(char **argv, char **cmd, t_data *data);
char	*ft_absolute_path(char **argv, char **cmd, t_data *data);

void	ft_exit(t_data *data, int i);

#endif
