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
	char	**str;

	data->env = env;
	data->ac = ac;
	data->av = (char **)av;
	data->file1 = ft_strdup((char *)av[1]);
	data->file2 = ft_strdup((char *)av[4]);
	str = ft_strsplit((char *)av[2], ' ');
	data->cmd1 = str;
	free(str);
	str = ft_strsplit((char *)av[3], ' ');
	data->cmd2 = str;
	free(str);
}

int		main(int ac, char const *av[])
{
	t_data			data;
	extern char		**environ;

	if (ac == 5)
	{
		init_data(ac, av, environ, &data);
		if (pipe(data.pfd) == -1)
			exit(1);
		if ((data.pid = fork()) < 0)
			exit(2);
		if (data.pid == 0)
		{
			close(data.pfd[1]);
			dup2(data.pfd[0], 0);
			close(data.pfd[0]);

			ft_exec(&data, data.cmd2[0]);

			/*
			execve("/bin/cmd2", data.cmd2, data->env);
			execlp(data.cmd2, data.cmd2, data.cmd2_opt, (char *)0);
			*/
			exit(3);
		}
		else
		{
			close(data.pfd[0]);
			dup2(data.pfd[1], 1);
			close(data.pfd[1]);
			ft_exec(&data, data.cmd1[0]);
			/*execlp(data.cmd1, data.cmd1, data.cmd1_opt, (char *)0);*/
			exit(4);
		}
	}
	return (0);
}
