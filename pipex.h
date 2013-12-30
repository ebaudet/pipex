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
# include <unistd.h>

# ifndef NO_ERR
#  define NO_ERR 42
# endif

typedef struct	s_data
{
	char		**av;
	int			ac;
	char		*file1;
	char		*file2;
	char		**cmd1;
	char		**cmd2;
	int			pfd[2];
	int			pid;
	char		**env;
}				t_data;

/*
** xenv.c
*/
char	**ft_get_path(char **env);
char	*ft_getenv(char **env, char *name);
int		env_size(char **env);

/*
** function.c
*/
int		ft_strlen(char *str);
char	*ft_strdup(char *src);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_count_c(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);

/*
** function2.c
*/
void	p_err(char *s1, char *s2, int error);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char const *s);

/*
** ft_strsplit.c
*/
char		**ft_strsplit(char const *s, char c);

/*
** main.c
*/
int		ft_exec(t_data *data, char *cmd);
void	init_data(int ac, char const *av[], char **env, t_data *data);

#endif
