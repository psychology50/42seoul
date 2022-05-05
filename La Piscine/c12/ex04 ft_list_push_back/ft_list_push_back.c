/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:59:19 by jayang            #+#    #+#             */
/*   Updated: 2022/02/23 11:22:03 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*update;
	t_list	*current;

	update = ft_create_elem(data);
	if (*begin_list == 0)
	{
		*begin_list = update;
		return ;
	}
	current = *begin_list
	while (current->next != 0)
		current = current->next;
	current->next = update;
}
