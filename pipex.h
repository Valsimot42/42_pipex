/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 12:05:44 by tbolkova          #+#    #+#             */
/*   Updated: 2023/04/20 10:58:48 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# define MAX_FD 1024

//	Std Libraries
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>

//	Custom Libraries
# include "Library/Ft_printf/Libft/libft.h"
# include "Library/Ft_printf/ft_printf.h"

//	Structs
typedef struct s_data
{
	int	my_argc;
	int	pipes[MAX_FD][2];
	int	in_file;
	int	out_file;
	int	amount_pipes;
	int	i;
	int	j;
}	t_data;

typedef struct s_path
{
	int		i;
	char	*envp_path;
	char	**paths;
	char	*tmp;
	char	*cmd_path;
}	t_path;

//	errors.c
void	exit_error(const char *message);
void	arg_error(void);

//	extra.c
void	ft_print_arr(char **arr);
void	close_fds(t_data *data);
void	execute_cmd(char **argv, char **envp, int i);

//	files.c
void	open_files(t_data *data, char **argv);

//	path.c
char	*ft_find_correct_path(char *cmd, char **arr);
char	*ft_find_path(char *cmd, char **envp);

//	pipex.c
void	pipex(t_data *data, char **argv, char **envp);
void	open_pipes(t_data *data);
void	redirection(t_data *data, int i);

#endif
