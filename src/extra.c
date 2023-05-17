/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 11:09:17 by tbolkova          #+#    #+#             */
/*   Updated: 2023/04/24 13:09:52 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_print_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		printf("arr[%i]: %s\n", i, arr[i]);
		i++;
	}
}

void	close_fds(t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->amount_pipes)
	{
		close(data->pipes[i][0]);
		close(data->pipes[i][1]);
		i++;
	}
	if (data->in_file)
		close(data->in_file);
	if (data->out_file)
		close(data->out_file);
}

void	execute_cmd(char **argv, char **envp, int i)
{
	char	*path;
	char	**cmd_table;
	int		p;

	p = 0;
	cmd_table = ft_split(argv[i + 2], ' ');
	if (!cmd_table)
		write(2, "Error with cmd_table", 20);
	path = ft_find_path(cmd_table[0], envp);
	execve(path, cmd_table, envp);
	while (cmd_table[p])
	{
		free(cmd_table[p]);
		p++;
	}
	if (!path)
		write (2, "I fucked up, sorry\n", 19);
	free(path);
}
