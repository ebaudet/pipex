/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:48:12 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/30 13:48:12 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_data(int ac, char const *av[], t_data *data)
{
	data->ac = ac;
	data->av = (char **)av;
	data->file1 = ft_strdup((char *)av[1]);
	data->file2 = ft_strdup((char *)av[4]);
	data->cmd1 = ft_strdup((char *)av[2]);
	data->cmd2 = ft_strdup((char *)av[3]);
}

int		main(int ac, char const *av[])
{
	t_data	data;

	if (ac == 5)
	{
		init_data(ac, av, &data);
	}
	return (0);
}
