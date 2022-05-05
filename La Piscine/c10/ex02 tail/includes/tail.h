/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:49:02 by jayang            #+#    #+#             */
/*   Updated: 2022/02/21 21:29:22 by jayang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <fcntl.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_print_errno(char *param_str, int err);
int		ft_atoi(char *str);

char	*g_path;
char	*g_cont;
int		g_errflag;

#endif