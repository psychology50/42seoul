/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:20:00 by jayang            #+#    #+#             */
/*   Updated: 2022/02/15 16:12:17 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_rdx(char *base)
{
	int	len;

	len = 0;
	while (base[len])
		len++;
	return (len);
}

int	_len(char *base, long long num)
{
	int			num_len;
	long long	rdx;

	num_len = 0;
	rdx = base_rdx(base);
	while (num > 0)
	{
		num_len++;
		num /= rdx;
	}
	return (num_len);
}

int	check_base(char *base)
{
	int	idx;
	int	target;

	idx = 0;
	while (base[idx])
	{
		target = 0;
		if (base[idx] == '+' || base[idx] == '-')
			return (0);
		else if (base[idx] == ' ' || (9 <= base[idx] && base[idx] <= 13))
			return (0);
		while (target < idx)
		{
			if (base[target] == base[idx])
				return (0);
			target++;
		}
		idx++;
	}
	if (idx <= 1)
		return (0);
	return (1);
}

int	nb_base(char c, char *base)
{
	int	nb;

	nb = 0;
	while (base[nb])
	{
		if (c == base[nb])
			return (nb);
		nb++;
	}
	return (-1);
}

int	check_minus(int minus)
{
	if (minus < 0)
		return (1);
	return (0);
}