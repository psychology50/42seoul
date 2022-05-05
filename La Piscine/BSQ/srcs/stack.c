/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 09:00:02 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 10:12:52 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	stack_free_all(t_stack *stack)
{
	if (stack == 0)
		return ;
	stack_free_all(stack->next);
	stack_free_one(stack);
}

void	stack_free_one(t_stack *stack)
{
	stack->next = 0;
	free(stack);
}

t_stack	*stack_create_stack(int index, int height)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		exit (1);
	stack->index = index;
	stack->height = height;
	stack->next = 0;
	return (stack);
}

void	stack_push(t_stack **stack, int index, int height)
{
	t_stack	*push;

	push = stack_create_stack(index, height);
	if (push == 0)
	{
		stack_free_all(*stack);
		*stack = 0;
		exit(1);
	}
	push->next = *stack;
	*stack = push;
}

void	stack_pop(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == 0)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	stack_free_one(temp);
}