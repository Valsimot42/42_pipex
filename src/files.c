/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:46:11 by tbolkova          #+#    #+#             */
/*   Updated: 2023/04/19 17:21:31 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	open_files(t_data *data, char **argv)
{
	int	i;

	i = 0;
	data->in_file = open(argv[1], O_RDONLY, 0666);
	if (data->in_file < 0)
	{
		exit_error("Couldn't open in_file.\n");
	}
	data->out_file = open(argv[data->my_argc - 1], \
	O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (data->out_file < 0)
	{
		exit_error("Couldn't open out_file.\n");
	}
}
