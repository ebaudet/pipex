/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 12:10:45 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/31 12:19:34 by apieropa         ###   ########.fr       */
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
	if ((add_file1_to_cmd1(data)) == -1)
		return (-1);
	if ((data->cmd2 = ft_strsplit((char *)av[3], ' ')) == NULL)
		return (-1);
	data->env = env;
	return (0);
}

int		add_file1_to_cmd1(t_data *data)
{
	int		i;
	char	**n_cmd1;
	int		len;

	len = 0;
	while (data->cmd1[len] != '\0')
		len++;
	if ((n_cmd1 = (char **)malloc(sizeof(char *) * (len + 2))) == NULL)
		return (-1);
	i = 0;
	while (i < len)
	{
		n_cmd1[i] = data->cmd1[i];
		i++;
	}
	n_cmd1[i] = data->file1;
	n_cmd1[i + 1] = '\0';
	free(data->cmd1);
	data->cmd1 = n_cmd1;
	return (0);
}
