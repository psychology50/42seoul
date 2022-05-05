/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:56:20 by jayang            #+#    #+#             */
/*   Updated: 2022/02/23 20:09:09 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*index;
	t_list	*next_level;

	temp = 0;
	index = *begin_list;
	while (index)
	{
		next_level = index->next;
		index->next = temp;
		temp = index;
		index = next_level;
	}
	*begin_list = temp;
}
