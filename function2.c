/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 19:15:05 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/31 18:03:39 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		ret;

	ret = 0;
	while (!(ret = *(unsigned char *) s1 - *(unsigned char *) s2) && *s2)
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

void	p_err(char *s1, char *s2)
{
	ft_putstr_err(s1);
	ft_putstr_err(s2);
	ft_putstr_err("\n");
}

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen((char *)s));
}

void	ft_putstr_err(char const *s)
{
	write(2, s, ft_strlen((char *)s));
}
