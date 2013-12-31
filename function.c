/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:37:30 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/31 01:48:38 by apieropa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(src));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		ret;

	ret = 0;
	while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2)
		&& *s2 && n--)
	{
		++s1;
		++s2;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1 ;
	return (ret);
}
*/
int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int		ft_count_c(char *str, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*tmp;

	len = (ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	tmp = (char *)malloc(sizeof(*tmp) * (len));
	i = 0;
	if (tmp)
	{
		while (*s1)
			tmp[i++] = *s1++;
		while (*s2)
			tmp[i++] = *s2++;
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
