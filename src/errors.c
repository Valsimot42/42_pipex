/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:14:07 by tbolkova          #+#    #+#             */
/*   Updated: 2023/04/19 17:18:10 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	exit_error(const char *message)
{
	perror(message);
	exit(1);
}

void	arg_error(void)
{
	write(2, "Invalid number of arguments\n", 29);
	exit(2);
}
