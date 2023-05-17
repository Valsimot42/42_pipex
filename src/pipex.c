/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:48:33 by tbolkova          #+#    #+#             */
/*   Updated: 2023/04/19 17:26:56 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"
#include <stdio.h>
#include <stdlib.h>

void	pipex(t_data *data, char **argv, char **envp)
{
	int	i;

	i = 0;
	open_pipes(data);
	open_files(data, argv);
	while (i <= data->amount_pipes)
	{
		if (fork() == 0)
		{
			redirection(data, i);
			close_fds(data);
			execute_cmd(argv, envp, i);
			exit(69);
		}
		i++;
	}
	i = 0;
	while (i < data->amount_pipes)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

void	open_pipes(t_data *data)
{
	int	i;

	i = 0;
	data->amount_pipes = data->my_argc - 4;
	while (i < data->amount_pipes)
	{
		if (pipe(data->pipes[i]) < 0)
		{
			write(1, "errorr pipe\n", 12);
			exit_error("Error with pipes.\n");
		}
		i++;
	}
}

void	redirection(t_data *data, int i)
{
	if (i == 0)
	{
		dup2(data->in_file, STDIN_FILENO);
		dup2(data->pipes[0][1], STDOUT_FILENO);
	}
	else if (i == data->amount_pipes)
	{
		dup2(data->out_file, STDOUT_FILENO);
		dup2(data->pipes[i - 1][0], STDIN_FILENO);
	}
	else
	{
		dup2(data->pipes[i - 1][0], STDIN_FILENO);
		dup2(data->pipes[i][1], STDOUT_FILENO);
	}
}
