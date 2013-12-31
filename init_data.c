/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 12:10:45 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/31 20:07:20 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		init_data(int ac, char const *av[], char **env, t_data *data)
{
	data->ac = ac;
	data->av = (char **)av;
	if ((data->file1 = ft_strdup((char *)av[1])) == NULL)
		return (-1);
	if ((data->file2 = ft_strdup((char *)av[4])) == NULL)
		return (-1);
	if ((data->cmd1 = ft_strsplit((char *)av[2], ' ')) == NULL)
		return (-1);
	if ((data->cmd2 = ft_strsplit((char *)av[3], ' ')) == NULL)
		return (-1);
	data->env = env;
	return (0);
}

void	usage_fct(char *pgm_name)
{
	ft_putstr_err("usage: ");
	ft_putstr_err(pgm_name);
	ft_putstr_err(" file1 cmd1 cmd2 file2\n");
}
