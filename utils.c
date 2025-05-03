/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:42:07 by ealves            #+#    #+#             */
/*   Updated: 2023/08/13 20:45:43 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	*found_cmd(t_data *data, char **cmd_arg)
{
	int		idx;
	char	*path_cmd;
	char	*tmp;

	idx = 0;
	if (cmd_arg[0][0] == '/' && access(cmd_arg[0], X_OK) == 0)
		return (ft_strdup(cmd_arg[0]));
	if (data->cut_path == NULL)
		ft_error_cmd_path(data, NULL);
	while (data->cut_path[idx] != NULL)
	{
		tmp = ft_strjoin(data->cut_path[idx], "/");
		path_cmd = ft_strjoin(tmp, cmd_arg[0]);
		if (access(path_cmd, X_OK) == 0)
			break ;
		idx++;
		(free(path_cmd), free(tmp));
	}
	if (data->cut_path[idx] != NULL)
		return (free(tmp), path_cmd);
	return (NULL);
}

void	found_path(t_data *data, char **env)
{
	int		idx;
	char	**tmp;

	idx = 0;
	tmp = env;
	while (*tmp && ft_strncmp("PATH", env[idx], 4) != 0)
	{
		idx++;
		tmp++;
	}
	if (*tmp == NULL)
	{
		data->cut_path = NULL;
		return ;
	}
	data->cut_path = ft_split(env[idx] + 5, ':');
	if (!data->cut_path)
		ft_error_cmd(data, NULL);
}
