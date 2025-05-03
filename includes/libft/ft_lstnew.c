/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealves <ealves@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:51:25 by ealves            #+#    #+#             */
/*   Updated: 2022/11/29 17:55:33 by ealves           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newstruct;

	newstruct = malloc(sizeof(t_list));
	if (!newstruct)
		return (0);
	newstruct->content = content;
	newstruct->next = NULL;
	return (newstruct);
}
