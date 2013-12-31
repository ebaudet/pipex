/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xenv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apieropa <apieropa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/29 01:31:48 by apieropa          #+#    #+#             */
/*   Updated: 2013/12/31 13:11:48 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path(char **env)
{
	char	**path;
	char	**tmp;
	int		i;
	int		j;

	if ((tmp = ft_strsplit(ft_getenv(env, "PATH"), ':')) == NULL)
		return (NULL);
	i = ft_count_c(ft_getenv(env, "PATH"), ':') + 1;
	if ((path = (char **)malloc(i * sizeof(*path))) == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		if ((path[j] = ft_strjoin(tmp[j], "/")) == NULL)
			return (NULL);
		free(tmp[j]);
		j++;
	}
	path[i] = NULL;
	free(tmp);
	return (path);
}

char	*ft_getenv(char **env, char *name)
{
	int		i;
	char	loop;

	i = 0;
	loop = 'y';
	while (*(env + i) != NULL && loop == 'y')
	{
		if (ft_strncmp(*(env + i), name, ft_strlen(name)) == 0)
			loop = 'n';
		else
			i++;
	}
	if (i == env_size(env))
		return (NULL);
	return (*(env + i) + ft_strlen(name) + 1);
}

int		env_size(char **env)
{
	int		i;

	i = 0;
	while (*(env + i) != NULL)
		i++;
	return (i);
}
