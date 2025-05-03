/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:30:21 by ealves            #+#    #+#             */
/*   Updated: 2023/08/13 20:45:20 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_infile(t_data *data, char *cuth_path)
{
	write (2, "bash: no such file or directory: ", 34);
	ft_putstr_fd(cuth_path, 2);
	write (2, "\n", 1);
	data->ret = 2;
	ft_free_split(data->cut_path);
	exit (data->ret);
}

void	ft_error_outfile(t_data *data, char *cuth_path)
{
	write (2, "bash: ", 6);
	ft_putstr_fd(cuth_path, 2);
	write (2, ": permission denied", 19);
	write (2, "\n", 1);
	data->ret = 1;
	ft_free_split(data->cut_path);
	exit (data->ret);
}

void	ft_error_cmd(t_data *data, char **cuth_path)
{
	write (2, "bash: command not found: ", 26);
	ft_putstr_fd(*cuth_path, 2);
	write (2, "\n", 1);
	data->ret = 127;
	ft_free_split(cuth_path);
	ft_free_split(data->cut_path);
	exit (data->ret);
}

void	ft_error_cmd_path(t_data *data, char **cuth_path)
{
	write (2, "bash: command not found: ", 26);
	write (2, "\n", 1);
	ft_putstr_fd(*data->cut_path, 2);
	write (2, "\n", 1);
	data->ret = 127;
	ft_free_split(cuth_path);
	ft_free_split(data->cut_path);
	exit (data->ret);
}
