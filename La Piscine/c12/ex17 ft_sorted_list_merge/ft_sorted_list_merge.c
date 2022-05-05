/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 09:37:31 by jayang            #+#    #+#             */
/*   Updated: 2022/02/24 10:22:26 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge2(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	if (*begin_list1 == 0)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	list = *begin_list1;
	while (list->next)
		list = list->next;
	list->next = begin_list2;
}

void	ft_list_sort3(t_list **begin_list, int (*cmp)())
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

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
							int (*cmp)())
{
	ft_list_merge2(begin_list1, begin_list2);
	ft_list_sort3(begin_list1, cmp);
}