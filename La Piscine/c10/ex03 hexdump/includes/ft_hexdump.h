/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:36:55 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 20:57:00 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# include <unistd.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>

void			ft_putchar(char c);
void			ft_putstr(char *str);
unsigned char	*ft_strncpy(unsigned char *dest, \
					unsigned char *src, unsigned int n);
unsigned int	ft_strncmp(unsigned char *s1, \
					unsigned char *s2, unsigned int n);
void			ft_print_hex(char *str, unsigned int size);
void			ft_print_hex_option(char *str, unsigned int size);
void			ft_print_errno(char *param_str, int err);
void			bad_type_err(char *str);

char				*g_path;
char				g_file[16];
unsigned char		g_pre[16];
unsigned long long	g_addr;
int					g_flag;
int					g_err;
int					g_idx;
#endif