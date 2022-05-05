/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 18:17:28 by sryou             #+#    #+#             */
/*   Updated: 2022/02/21 12:33:38 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_stack
{
	int				index;
	int				height;
	struct s_stack	*next;
}	t_stack;

void	stack_free_all(t_stack *stack);
void	stack_free_one(t_stack *stack);
t_stack	*stack_create_stack(int index, int height);
void	stack_push(t_stack **stack, int index, int height);
void	stack_pop(t_stack **stack);

#endif