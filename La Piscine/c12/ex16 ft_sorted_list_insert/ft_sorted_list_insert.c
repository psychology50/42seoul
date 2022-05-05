/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:26:55 by jayang            #+#    #+#             */
/*   Updated: 2022/02/24 10:20:04 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back2(t_list **begin_list, void *data)
{
	t_list	*tmp;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	tmp = *begin_list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = ft_create_elem(data);
}

void	ft_list_sort2(t_list **begin_list, int (*cmp)())
{
	t_list	*i;
	t_list	*tmp;
	void	*swap;

	if (*begin_list == 0)
		return ;
	i = *begin_list;
	while (i)
	{
		tmp = *begin_list;
		while (tmp->next)
		{
			if ((*cmp)(tmp->data, tmp->next->data) > 0)
			{
				swap = tmp->data;
				tmp->data = tmp->next->data;
				tmp->next->data = swap;
			}
			tmp = tmp->next;
		}
		i = i->next;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_back2(begin_list, data);
	ft_list_sort2(begin_list, cmp);
}