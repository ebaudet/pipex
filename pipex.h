/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebaudet <ebaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/30 16:13:18 by ebaudet           #+#    #+#             */
/*   Updated: 2013/12/30 16:13:18 by ebaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUPEX_H
# define PUPEX_H

# include <stdlib.h>

typedef struct	s_data
{
	char		**av;
	int			ac;
	char		*file1;
	char		*file2;
	char		*cmd1;
	char		*cmd2;
}				t_data;

/*
** function.c
*/
int		ft_strlen(char *str);
char	*ft_strdup(char *src);

/*
** main.c
*/
void	init_data(int ac, char const *av[], t_data *data);

#endif
