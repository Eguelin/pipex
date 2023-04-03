/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/03 18:49:09 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_arg	data;

	if (argc < 5)
		return (EXIT_FAILURE);
	parsing_pipex(&data, argc, argv, env);
	ft_process(&data, env);
	ft_free_data(&data);
	return (EXIT_SUCCESS);
}

void	ft_free_data(t_arg *data)
{
	ft_lstclear(&(data->cmd), ft_free_split);
	ft_free_split(data->path_list);
}

void	ft_exit(t_arg *data)
{
	ft_free_data(data);
	exit(1);
}
