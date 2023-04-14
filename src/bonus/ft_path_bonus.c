/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 14:04:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 15:18:19 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_path_list(char **env, t_data *data)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			data->path_list = ft_split(env[i] + 5, ':');
			if (!data->path_list)
				exit(EXIT_FAILURE);
			return ;
		}
		i++;
	}
}

char	*ft_check_absolute_path(char **argv, char **cmd, t_data *data)
{
	if (ft_strchr(cmd[0], '/'))
	{
		if (!access(cmd[0], X_OK))
			return (cmd[0]);
		else if (!access(cmd[0], F_OK))
		{
			ft_printf("%s: %s: Permission denied\n", argv[0], cmd[0]);
			ft_free_split(cmd);
			ft_exit(data, 126);
		}
		else
		{
			ft_printf("%s: %s: not found\n", argv[0], cmd[0]);
			ft_free_split(cmd);
			ft_exit(data, 127);
		}
	}
	return (NULL);
}

char	*ft_check_relative_path(char **argv, char **cmd, t_data *data)
{
	char	*path;
	int		i;

	i = 0;
	while (data->path_list && data->path_list[i])
	{
		path = ft_strjoin_three(data->path_list[i], "/", cmd[0]);
		if (!path)
			ft_exit(data, EXIT_FAILURE);
		if (!access(path, X_OK))
			return (path);
		free(path);
		i++;
	}
	ft_printf("%s: %s: not found\n", argv[0], cmd[0]);
	ft_free_split(cmd);
	ft_exit(data, 127);
	return (NULL);
}
