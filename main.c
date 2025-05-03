/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:05:29 by ealves            #+#    #+#             */
/*   Updated: 2023/08/10 22:29:32 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// O_TRUNC: Tronque le fichier s'il existe, en supprimant son contenu actuel.
// O_CREAT: Crée le fichier s'il n'existe pas déjà.
// O_RDWR: Ouvre le fichier en lecture et en écriture.
// 0644 : definit les permissions du fichier
// argc : 1 nombre d arguments
// argv : 0

int	work(t_data *data, char **argv, char **env, int (*tube)[2])
{
	while (data->nmb_cmd != 0)
	{
		if (pipe(*tube) == -1)
			return (perror ("pipe"), 1);
		data->pid = fork();
		if (data->pid == -1)
			return (perror ("fork"), 1);
		if (data->pid == 0)
			child(data, argv, env, *tube);
		else
			parents(data, *tube);
		data->nmb_cmd--;
		data->idx_cmd++;
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		garbage;
	int		tube[2];

	data.ret = 0;
	if (argc < 5 || argc > 5)
		return (write (2, "bash: wrong number of arguments\n", 33), 0);
	data.nmb_cmd = argc - 3;
	data.first_cmd = 2;
	data.idx_cmd = 2;
	found_path(&data, env);
	if (work(&data, argv, env, &tube))
		return (EXIT_FAILURE);
	ft_free_split(data.cut_path);
	close (tube[0]);
	close (tube[1]);
	waitpid(data.pid, &data.ret, 0);
	while (waitpid(-1, &garbage, 0) > 0)
		;
	if (WIFEXITED(data.ret))
		data.ret = WEXITSTATUS(data.ret);
	return (data.ret);
}
