/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:09:22 by ealves            #+#    #+#             */
/*   Updated: 2023/08/09 18:31:31 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// entree standard (lecture)-> stdin == 0
// sortie standard (ecriture)-> stdout == 1
// infile, envoi l'info
// 0 = stdin
// 1 = stdout

void	child(t_data *data, char **argv, char **env, int *p_tube)
{
	recup_in(data, argv, data->fd);
	redirect_out(data, argv, p_tube);
	execute_cmd(data, argv, env);
}

void	parents(t_data *data, int *p_tube)
{
	if (data->nmb_cmd != data->first_cmd)
	{
		close(data->fd[0]);
		close(data->fd[1]);
	}
	if (data->nmb_cmd != 1)
	{
		data->fd[0] = p_tube[0];
		data->fd[1] = p_tube[1];
	}
}
