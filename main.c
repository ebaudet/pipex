/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:48:12 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/30 20:30:52 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_exec(t_data *data, char *cmd)
{
	char	*tmp;
	char	**path;
	int		i;
	int		t;

	path = ft_get_path(data->env);
	i = 0;
	while (path[i] != 0)
	{
		tmp = ft_strjoin(path[i], cmd);
		t = access(tmp, X_OK);

		execve(tmp, data->av, data->env);
		free(tmp);
		i++;
	}
	if (t == -1 && ft_strcmp(cmd, "exit") != 0)
		p_err("command not found: ", cmd, 0);
	return (0);
}

void	init_data(int ac, char const *av[], char **env, t_data *data)
{
	data->env = env;
	data->ac = ac;
	data->av = (char **)av;
	data->file1 = ft_strdup((char *)av[1]);
	data->file2 = ft_strdup((char *)av[4]);
	data->cmd1 = ft_strsplit((char *)av[2], ' ');
	data->cmd2 = ft_strsplit((char *)av[3], ' ');
}

int		main(int ac, char const *av[])
{
	t_data			data;
	extern char		**environ;

	if (ac == 5)
	{
		init_data(ac, av, environ, &data);
		data.pfd[0] = 3;
		data.pfd[1] = 4;
		if ((data.pid = fork()) < 0)
			exit(0);
		if (data.pid == 0) /* son */
		{
			close(data.pfd[1]);
			dup2(data.pfd[0], 0);
			ft_exec(&data, data.cmd2[0]);
			close(data.pfd[0]);
			exit(0);
		}
		else if (data.pid > 0) /* father */
		{
			wait(0);
			close(data.pfd[0]);
			dup2(data.pfd[1], 1);
			ft_exec(&data, data.cmd1[0]);
			close(data.pfd[1]);
			exit(0);
		}
	}
	return (0);
}
