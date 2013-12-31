/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:48:12 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/31 01:48:35 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_exec(t_data *data, char **cmd)
{
	char	*tmp;
	char	**path;
	int		i;
	int		t;

	path = ft_get_path(data->env);
	i = 0;
	while (path[i] != 0)
	{
		tmp = ft_strjoin(path[i], cmd[0]);
		t = access(tmp, X_OK);
		printf("tmp: %s\n", tmp);
		execve(tmp, cmd, data->env);
		free(tmp);
		i++;
	}
	if (t == -1 && ft_strcmp(cmd[0], "exit") != 0)
		p_err("command not found: ", cmd[0], 0);
	return (0);
}

void	init_data(int ac, char const *av[], char **env, t_data *data)
{
	data->ac = ac;
	data->av = (char **)av;
	data->file1 = ft_strdup((char *)av[1]);
	data->file2 = ft_strdup((char *)av[4]);
	data->cmd1 = ft_strsplit((char *)av[2], ' ');
	add_file1_to_cmd1(data);
	data->cmd2 = ft_strsplit((char *)av[3], ' ');
	data->env = env;
}

void	add_file1_to_cmd1(t_data *data)
{
	int		i;
	char	**n_cmd1;
	int		len;

	len = 0;
	while (data->cmd1[len] != '\0')
		len++;
	if ((n_cmd1 = (char **)malloc(sizeof(char *) * (len + 2))) == NULL)
		exit(0);
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
}

int		main(int ac, char const *av[])
{
	t_data			data;
	extern char		**environ;
	int				file2_fd;

	if (ac == 5)
	{
		init_data(ac, av, environ, &data);
		file2_fd = open(data.file2, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (pipe(data.pfd) == -1)
		{
			printf("pipe failed\n");
			return (0);
		}
		if ((data.pid = fork()) < 0)
			exit(0);
		if (data.pid == 0) /* child */
		{
			close(data.pfd[0]);
			dup2(data.pfd[1], 1);
			close(data.pfd[1]);
			ft_exec(&data, data.cmd1);
		}
		else /* father */
		{
			wait(0);
			close(data.pfd[1]);
			dup2(data.pfd[0], 0);
			close(data.pfd[0]);
			dup2(file2_fd, 1);
			close(file2_fd);
			ft_exec(&data, data.cmd2);
		}
	}
	return (0);
}
