/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maperrea <maperrea@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:35:43 by maperrea          #+#    #+#             */
/*   Updated: 2021/07/28 20:16:26 by maperrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "global.h"

t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		error();
	new->key = nb;
	new->next = NULL;
	return (new);
}

t_stack	*stack_add_front(t_stack *stack, t_stack *elem)
{
	if (elem)
		elem->next = stack;
	return (elem);
}

t_stack	*stack_add_back(t_stack *stack, t_stack *elem)
{
	t_stack *start;

	if (!stack)
		return (elem);
	start = stack;
	while (stack->next)
		stack = stack->next;
	stack->next = elem;
	return (start);
}

t_stack	*stack_insert(t_stack *stack, t_stack *elem)
{
	if (!stack)
		return (elem);
	if (!elem)
		return (stack);
	elem->next = stack->next;
	stack->next = elem;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	while (stack && stack->next)
		stack = stack->next;
	return (stack);
}

t_stack *stack_find(t_stack *stack, int key)
{
	while (stack)
	{
		if (stack->key == key)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack *stack_previous(t_stack *stack, t_stack *elem)
{
	while (stack)
	{
		if (stack->next == elem)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	del_elem(t_stack *elem)
{
	free(elem);
}

void	del_stack(t_stack *stack)
{
	t_stack *next;

	while (stack)
	{
		next = stack->next;
		del_elem(stack);
		stack = next;
	}
}
