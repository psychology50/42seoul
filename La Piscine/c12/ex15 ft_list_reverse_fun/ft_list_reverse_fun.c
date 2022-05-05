/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:09:03 by jayang            #+#    #+#             */
/*   Updated: 2022/02/24 10:19:11 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_swap(void **elem1, void **elem2)
{
	void	*tmp;

	tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		size;
	int		i;
	int		j;
	t_list	*list;

	size = 0;
	list = begin_list;
	while (list)
	{
		list = list->next;
		size++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i;
		list = begin_list;
		while (list && list->next && j < size - 1)
		{
			ft_swap(&list->data, &list->next->data);
			list = list->next;
			j++;
		}
		i++;
	}
}