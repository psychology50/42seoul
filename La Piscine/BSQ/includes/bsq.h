/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:24:16 by sryou             #+#    #+#             */
/*   Updated: 2022/02/21 14:35:22 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define STDINPUT "stdinput_file"

# include "stack.h"
# include "string.h"

void	stdinput_handler(void);
void	file_handler(int argc, char **argv);

void	solve(void);
void	make_mapint(void);
void	make_map_answer(int y, int x, int line);
void	print_map(void);
void	make_map(int fd);

typedef struct s_mapinfo
{
	int		y;
	int		x;
	char	empty;
	char	obstacle;
	char	full;
}	t_mapinfo;

char		**g_map;
int			**g_mapint;
t_mapinfo	g_mapinfo;

#endif