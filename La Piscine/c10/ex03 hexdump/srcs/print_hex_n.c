/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:08:30 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 16:19:41 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	print_hex_element(unsigned char c)
{
	char	*c_hex;

	c_hex = "0123456789abcdef";
	ft_putchar(c_hex[c / 16]);
	ft_putchar(c_hex[c % 16]);
}

void	print_hex_addr(void)
{
	unsigned long long	c_addr;
	unsigned char		sub[7];
	int					i;

	c_addr = g_addr;
	i = 0;
	while (c_addr > 0)
	{
		sub[6 - i] = "0123456789abcdef"[c_addr % 16];
		c_addr /= 16;
		i++;
	}
	while (i < 7)
	{
		sub[6 - i] = '0';
		i++;
	}
	write(1, sub, 7);
}

void	print_line(unsigned char *str, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size)
	{
		print_hex_element(str[idx]);
		if (idx != 15)
			ft_putchar(' ');
		idx++;
	}
	while (idx < 16)
	{
		ft_putstr("  ");
		if (idx != 15)
			ft_putchar(' ');
		idx++;
	}
}

void	ft_print_hex(char *str, unsigned int size)
{
	unsigned char	*sub;

	sub = (unsigned char *)str;
	if (ft_strncmp(sub, g_pre, 16) && g_file[0] != 0)
	{
		g_flag = 0;
		ft_strncpy(g_pre, sub, 16);
		print_hex_addr();
		ft_putchar(' ');
		print_line(sub, size);
		ft_putchar('\n');
	}
	else if (g_flag == 0 && g_file[0] != 0)
	{
		ft_putstr("*\n");
		g_flag = 1;
	}
}