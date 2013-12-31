/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 13:48:12 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/31 13:44:12 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		main(int ac, char const *av[])
{
	t_data			data;
	extern char		**environ;

	if (ac == 5)
	{
		if ((init_data(ac, av, environ, &data)) == -1)
			return (-1);
		if ((open_fds(&data)) == -1)
			return (-1);
		if ((data.pid = fork()) < 0)
			return (-1);
		if (data.pid == 0)
		{
			if (exec_child(&data) == -1)
				return (-1);
		}
		else
		{
			if (exec_parent(&data) == -1)
				return (-1);
		}
	}
	return (0);
}

int		open_fds(t_data *data)
{
	data->file2_fd = open(data->file2, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (data->file2_fd == -1)
		return (-1);
	if (pipe(data->pfd) == -1)
	{
		ft_putstr("pipe failed\n");
		return (-1);
	}
	return (0);
}

int		exec_child(t_data *data)
{
	close(data->pfd[0]);
	if ((dup2(data->pfd[1], 1)) == -1)
		return (-1);
	close(data->pfd[1]);
	if ((ft_exec(data, data->cmd1)) == -1)
		return (-1);
	return (0);
}

int		exec_parent(t_data *data)
{
	wait(0);
	close(data->pfd[1]);
	if ((dup2(data->pfd[0], 0)) == -1)
		return (-1);
	close(data->pfd[0]);
	if ((dup2(data->file2_fd, 1)) == -1)
		return (-1);
	close(data->file2_fd);
	if ((ft_exec(data, data->cmd2)) == -1)
		return (-1);
	return (0);
}

int		ft_exec(t_data *data, char **cmd)
{
	char	*tmp;
	char	**path;
	int		i;
	int		t;

	if ((path = ft_get_path(data->env)) == NULL)
		return (-1);
	i = 0;
	while (path[i] != 0)
	{
		if ((tmp = ft_strjoin(path[i], cmd[0])) == NULL)
			return (-1);
		t = access(tmp, X_OK);
		execve(tmp, cmd, data->env);
		free(tmp);
		i++;
	}
	if (t == -1)
		p_err("command not found: ", cmd[0]);
	return (0);
}
