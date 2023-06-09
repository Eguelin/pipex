/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 14:46:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		exit_ft;

	ft_set_data(&data);
	if (argc <= 4)
	{
		ft_printf("%s: not enough arguments\n", argv[0]);
		return (2);
	}
	if (argc > 5)
	{
		ft_printf("%s: too many arguments\n", argv[0]);
		return (2);
	}
	ft_dup(ft_open_infile(argv), STDIN_FILENO, &data);
	exit_ft = ft_pipex(argv, env, &data);
	return (exit_ft);
}
