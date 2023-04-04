/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:19:24 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/04 15:48:08 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char		**ft_path_list(char **env);
static t_list	*ft_cmd(int argc, char **argv);

void	parsing_pipex(t_arg *data, int argc, char **argv, char **env)
{
	data->infile = argv[1];
	data->outfile = argv[argc - 1];
	data->path_list = ft_path_list(env);
	data->cmd = ft_cmd(argc, argv);
	if (!data->cmd)
	{
		ft_free_split(data->path_list);
		exit(EXIT_FAILURE);
	}
}

static char	**ft_path_list(char **env)
{
	char	**path_list;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strlen(env[i]) >= 5 && !ft_strncmp(env[i], "PATH=", 5))
		{
			path_list = ft_split(env[i] + 5, ':');
			if (!path_list)
				exit(EXIT_FAILURE);
			return (path_list);
		}
		i++;
	}
	return (NULL);
}

static t_list	*ft_cmd(int argc, char **argv)
{
	int		i;
	char	**cmd;
	t_list	*lst;
	t_list	*lstnew;

	i = 2;
	lst = NULL;
	while (i < argc - 1)
	{
		cmd = ft_split(argv[i], ' ');
		if (!cmd)
		{
			ft_lstclear(&lst, ft_free_split);
			return (NULL);
		}
		lstnew = ft_lstnew(cmd);
		ft_lstadd_back(&lst, lstnew);
		i++;
	}
	return (lst);
}
