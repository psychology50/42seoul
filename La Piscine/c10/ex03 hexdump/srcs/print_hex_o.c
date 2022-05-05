/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:06:50 by jayang            #+#    #+#             */
/*   Updated: 2022/02/20 21:52:28 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void    print_hex_element2(unsigned char c)
{
        char    *c_hex;

        c_hex = "0123456789abcdef";
        ft_putchar(c_hex[c / 16]);
        ft_putchar(c_hex[c % 16]);
}

void    print_hex_addr2(void)
{
        unsigned long long      c_addr;
        unsigned char           sub[8];
        int                                     i;

        c_addr = g_addr;
        i = 0;
        while (c_addr > 0)
        {
                sub[7 - i] = "0123456789abcdef"[c_addr % 16];
                c_addr /= 16;
                i++;
        }
        while (i < 8)
        {
                sub[7 - i] = '0';
                i++;
        }
        write(1, sub, 8);
}

void    print_original_line(unsigned char *str, unsigned int size)
{
        unsigned int    idx;

        idx = 0;
        ft_putchar('|');
        while (idx < size)
        {
                if (' ' <= str[idx] && str[idx] <= '~')
                        write(1, str + idx, 1);
                else
                        ft_putchar('.');
                idx++;
        }
        ft_putchar('|');
}

void    print_line2(unsigned char *str, unsigned int size)
{
        unsigned int    idx;

        idx = 0;
        while (idx < size)
        {
                print_hex_element2(str[idx]);
                if (idx == 7 || idx == 15)
                        ft_putstr("  ");
                else
                        ft_putchar(' ');
                idx++;
        }
        while (idx < 16)
        {
                ft_putstr("  ");
                if (idx == 7 || idx == 15)
                        ft_putstr("  ");
                else
                        ft_putchar(' ');
                idx++;
        }
        print_original_line(str, size);
}

void    ft_print_hex_option(char *str, unsigned int size)
{
        unsigned char   *sub;

        sub = (unsigned char *)str;
        if (ft_strncmp(sub, g_pre, 16) != 0)
        {
                flag = 0;
                ft_strncpy(g_pre, sub, 16);
                print_hex_addr2();
                ft_putstr("  ");
                print_line2(sub, size);
                ft_putchar('\n');
        }
        else if (flag == 0)
        {
                flag = 1;
                ft_putstr("*\n");
        }
}