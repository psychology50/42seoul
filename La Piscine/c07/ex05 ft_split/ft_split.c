/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:40:15 by jayang            #+#    #+#             */
/*   Updated: 2022/02/13 21:23:33 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	cmp_words(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (str[idx])
	{
		if (cmp_words(str[idx], charset) == 0 \
			&& (cmp_words(str[idx + 1], charset) == 1 || str[idx + 1] == '\0'))
			cnt++;
		idx++;
	}
	return (cnt);
}

void	save_words(char **answer, char *str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		(*answer)[idx] = str[idx];
		idx++;
	}
	(*answer)[size] = '\0';
}

void	separate_words(char *str, char *charset, char **answer)
{
	int	idx;
	int	size;
	int	tab;

	idx = 0;
	tab = 0;
	while (str[idx])
	{
		if (cmp_words(str[idx], charset) == 1)
			idx++;
		else
		{
			size = 0;
			while (cmp_words(str[idx + size], charset) == 0 && \
				   	str[idx + size] != '\0')
				size++;
			answer[tab] = (char *)malloc(sizeof (char) * (size + 1));
			save_words(answer + tab, str + idx, size);
			tab++;
			idx += size;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	int		nb_words;
	char	**answer;

	nb_words = count_words(str, charset);
	answer = (char **)malloc(sizeof (char *) * (nb_words + 1));
	answer[nb_words] = 0;
	separate_words(str, charset, answer);
	return (answer);
}