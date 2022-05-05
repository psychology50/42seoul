/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 13:42:52 by jayang            #+#    #+#             */
/*   Updated: 2022/02/17 21:05:22 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "oper.h"

void	ft_putchar(char c);
void	ft_add(int a, int b);
void	ft_sub(int a, int b);
void	ft_mul(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
int		ft_atoi(char *str);

int	ft_exception_handling(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (argv[1] == 0 && argv[3] == 0)
		return (0);
	if (!(*argv[2] == '+' || *argv[2] == '-' || *argv[2] == '*' || \
		*argv[2] == '/' || *argv[2] == '%'))
	{
		ft_putchar('0');
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

void	ft_calculrator(int nb1, int nb2, char oper)
{
	t_calc_ptr	calc;

	if (oper == '+')
		calc = ft_add;
	else if (oper == '-')
		calc = ft_sub;
	else if (oper == '*')
		calc = ft_mul;
	else if (oper == '/')
		calc = ft_div;
	else
		calc = ft_mod;
	calc(nb1, nb2);
}

int	main(int args, char *argv[])
{
	int		nb1;
	int		nb2;

	if (ft_exception_handling(args, argv))
	{
		nb1 = ft_atoi(argv[1]);
		nb2 = ft_atoi(argv[3]);
		ft_calculrator(nb1, nb2, *(argv[2]));
		ft_putchar('\n');
	}
	return (0);
}