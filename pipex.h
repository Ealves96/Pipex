/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:05:44 by ealves            #+#    #+#             */
/*   Updated: 2023/08/13 20:45:27 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "includes/ft_printf/ft_printf.h"
# include "includes/libft/libft.h"
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_data
{
	pid_t	pid;
	int		nmb_cmd;
	int		first_cmd;
	int		idx_cmd;
	int		outfile;
	int		infile;
	char	**cut_path;
	int		argc;
	int		fd[2];
	int		ret;

}	t_data;

//////////main.c///////////
int		work(t_data *data, char **argv, char **env, int (*tube)[2]);

//////////utils.c///////////
void	ft_free_split(char **str);
void	found_path(t_data *data, char **env);
char	*found_cmd(t_data *data, char **cmd_arg);

//////////error.c///////////
void	ft_error_infile(t_data *data, char *cuth_path);
void	ft_error_outfile(t_data *data, char *cuth_path);
void	ft_error_cmd(t_data *data, char **cuth_path);
void	ft_error_cmd_path(t_data *data, char **cuth_path);

//////////fork.c///////////
void	parents(t_data *data, int *p_tube);
void	child(t_data *data, char **argv, char **env, int *p_tube);

//////////child.c///////////
void	recup_in(t_data *data, char **argv, int *p_tube);
void	redirect_out(t_data *data, char **argv, int *p_tube);
void	execute_cmd(t_data *data, char **argv, char **env);

#endif
