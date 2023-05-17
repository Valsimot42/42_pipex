/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbolkova <tbolkova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:42:06 by tbolkova          #+#    #+#             */
/*   Updated: 2023/04/24 13:07:25 by tbolkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_find_correct_path(char *cmd, char **paths)
{
	char	*tmp;
	char	*tmp_1;
	int		i;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		tmp_1 = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(tmp_1, F_OK | X_OK) == 0)
			return (tmp_1);
		free(tmp_1);
		i++;
	}
	return (NULL);
}

char	*ft_find_path(char *cmd, char **envp)
{
	char	i;
	char	*tmp;
	char	**paths;
	char	*valid_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			tmp = ft_strdup(envp[i] + 5);
			if (!envp)
				write (2, "Error with path", 15);
			break ;
		}
		i++;
	}
	paths = ft_split(tmp, ':');
	if (!paths)
		write (2, "Error with path_2", 17);
	valid_path = ft_find_correct_path(cmd, paths);
	return (valid_path);
}
