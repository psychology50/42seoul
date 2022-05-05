/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 20:38:03 by jayang            #+#    #+#             */
/*   Updated: 2022/02/19 20:41:02 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_process_str(char *str, int *minus)
{
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	*minus = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			*minus *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	minus;
	int	result;

	str = ft_process_str(str, &minus);
	result = 0;
	while ('0' <= *str && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (minus * result);
}