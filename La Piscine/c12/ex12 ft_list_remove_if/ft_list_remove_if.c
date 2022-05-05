/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 19:46:11 by jayang            #+#    #+#             */
/*   Updated: 2022/02/23 21:48:02 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref \
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*next_level;

	next_level = *begin_list;
	while (next_level && next_level->next)
	{
		if ((*cmp)(next_level->data, data_ref) == 0)
		{
			(*free_fct)(next_level->data);
			tmp = next_list;
			next_level = next_level->next;
			free(temp);
		}
		next_level = next_level->next;
	}
}
