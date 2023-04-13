/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:43:10 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/12 16:25:19 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "../lib/mylib/include/mylib.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# define TRUE 1

typedef struct s_data
{
	int		cmd;
	int		here_doc;
	int		pipefd[2];
	pid_t	pid;
	char	**path_list;
}	t_data;

////////// [ ft_file.c ] //////////

int		ft_open_infile(char **argv);
int		ft_open_outfile(char **argv, t_data *data);
void	ft_here_doc(char **argv, t_data *data);

////////// [ ft_path.c ] //////////

void	ft_path_list(char **env, t_data *data);
char	*ft_check_relative_path(char **argv, char **cmd, t_data *data);
char	*ft_check_absolute_path(char **argv, char **cmd, t_data *data);

////////// [ ft_tools.c ] //////////

void	ft_exit(t_data *data, int i);
void	ft_close(int *fd);
void	ft_dup(int fd, int fd2, t_data *data);
void	ft_set_data(char **argv, t_data *data);

#endif
