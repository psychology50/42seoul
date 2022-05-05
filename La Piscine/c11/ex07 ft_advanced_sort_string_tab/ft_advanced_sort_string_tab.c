/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:34:17 by jayang            #+#    #+#             */
/*   Updated: 2022/02/17 20:58:28 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len(char **ptr)
{
	int	index;

	index = 0;
	while (ptr[index] != 0)
		index++;
	return (index);
}

void	my_swap(char **ptr1, char **ptr2)
{
	char	*temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	tab_size;

	tab_size = ft_len(tab);
	i = 0;
	while (i < tab_size)
	{
		j = 0;
		while (j < tab_size - 1 - i)
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				my_swap(tab + j, tab + j + 1);
			j++;
		}
		i++;
	}
}