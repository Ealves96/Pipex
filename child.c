/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:00:07 by ealves            #+#    #+#             */
/*   Updated: 2023/08/10 22:10:12 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// redirection depuis entree
// deux tubes, oldfd et newfd
void	recup_in(t_data *data, char **argv, int *p_tube)
{
	if (data->nmb_cmd == data->first_cmd)
	{
		data->infile = open(argv[1], O_RDONLY);
		if (data->infile < 0)
			ft_error_infile(data, argv[1]);
		dup2(data->infile, 0);
		close(data->infile);
	}
	else
	{
		dup2(p_tube[0], 0);
		close(p_tube[0]);
		close(p_tube[1]);
	}
}

// redirection vers la sortie
//new fd
void	redirect_out(t_data *data, char **argv, int *p_tube)
{
	if (data->nmb_cmd == 1)
	{
		data->outfile = open(argv[data->idx_cmd + 1],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (data->outfile < 0)
			ft_error_outfile(data, argv[data->idx_cmd + 1]);
		dup2(data->outfile, 1);
		close(data->outfile);
		close(p_tube[0]);
		close(p_tube[1]);
	}
	else
	{
		close(p_tube[0]);
		dup2(p_tube[1], 1);
		close(p_tube[1]);
	}
}

// execution pour 2 commandes
void	execute_cmd(t_data *data, char **argv, char **env)
{
	char	*path_cmd;
	char	**cmd_arg;

	path_cmd = NULL;
	cmd_arg = ft_split(argv[data->idx_cmd], ' ');
	if (cmd_arg && cmd_arg[0])
		path_cmd = found_cmd(data, cmd_arg);
	if (path_cmd && cmd_arg)
		execve(path_cmd, cmd_arg, env);
	ft_error_cmd(data, cmd_arg);
	(free(path_cmd), ft_free_split(cmd_arg));
	exit(EXIT_FAILURE);
}
