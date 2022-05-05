/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:36:36 by jayang            #+#    #+#             */
/*   Updated: 2022/02/23 18:20:02 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*list;
	t_list	*update;

	if (size < 0)
		return (0);
	i = 1;
	list = ft_create_elem(strs[0]);
	while (i < size)
	{
		update = ft_create_elem(strs[i]);
		update->next = list;
		list = update;
		i++;
	}
	return (list);
}
