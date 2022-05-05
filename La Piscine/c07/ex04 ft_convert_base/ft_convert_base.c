/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conver_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:32:09 by jayang            #+#    #+#             */
/*   Updated: 2022/02/15 16:37:14 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************* */

#include <stdlib.h>

int	base_rdx(char *base);
int	_len(char *base, long long num);
int	check_base(char *base);
int	nb_base(char c, char *base);
int	check_minus(int minus);

long long	ft_atoi_base(char *str, char *base_from, int *minus)
{
	long long	fbase_rdx;
	long long	result;

	fbase_rdx = base_rdx(base_from);
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	*minus = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*minus *= -1;
		str++;
	}
	result = 0;
	while (nb_base(*str, base_from) != -1)
	{
		result = (result * fbase_rdx) + (long long)nb_base(*str, base_from);
		str++;
	}
	return (result);
}

void	ft_putnbr_base(int idx, long long result, char *ch_base, char *base_to)
{
	long long	tbase_rdx;

	tbase_rdx = (long long)base_rdx(base_to);
	ch_base[idx] = 0;
	while (idx > 0)
	{
		ch_base[idx - 1] = base_to[result % tbase_rdx];
		result /= tbase_rdx;
		idx--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			minus;
	long long	result;
	int			idx;
	char		*ch_base;

	if (check_base(base_from) && check_base(base_to))
	{
		result = ft_atoi_base(nbr, base_from, &minus);
		if (result == 0)
			idx = 1;
		else
			idx = _len(base_to, result) + check_minus(minus);
		ch_base = (char *)malloc(sizeof (char) * (idx + 1));
		ft_putnbr_base(idx, result, ch_base, base_to);
		if (check_minus(minus) && result != 0)
			ch_base[0] = '-';
		return (ch_base);
	}
	return (0);
}