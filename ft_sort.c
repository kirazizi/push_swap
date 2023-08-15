/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:06:14 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/21 15:20:35 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_data *stack_a)
{
	if (!stack_a)
		return (0);
	while (stack_a->next)
	{
		if (stack_a->number < stack_a->next->number)
			stack_a = stack_a->next;
		else
			return (0);
	}
	return (1);
}

int	ft_pos(t_data *kira_a)
{
	int	min;
	int	i;

	i = 0;
	min = min_number(kira_a);
	while (kira_a)
	{
		if (kira_a->number == min)
			return (i);
		i++;
		kira_a = kira_a->next;
	}
	return (i);
}

void	ft_sort_3(t_data **kira_a)
{
	int	max;

	max = max_number(*kira_a);
	if ((*kira_a)->index == max)
		ra_swap(kira_a, 1);
	else if ((*kira_a)->next->index == max)
		rra_swap(kira_a, 1);
	if ((*kira_a)->index > (*kira_a)->next->index)
		sa_swap(kira_a, 1);
}

void	ft_sort_5(t_data **kira_a, t_data **kira_b)
{
	t_data	*temp;
	t_data	*min_nd;
	int		min;
	int		size;
	int		pos_min;

	size = ft_lstsize(*kira_a);
	while (size > 3)
	{
		min = min_number(*kira_a);
		pos_min = ft_pos(*kira_a);
		while ((*kira_a)->number != min)
		{
			if (pos_min > size / 2)
				rra_swap(kira_a, 1);
			else
				ra_swap(kira_a, 1);
		}
		if ((*kira_a)->number == min)
			push_b(kira_a, kira_b, 1);
		size--;
	}
	ft_sort_3(kira_a);
	while (*kira_b)
		push_a(kira_a, kira_b, 1);
}

void	ft_sort_all(t_data *kira_a, t_data *kira_b)
{
	t_tools	var;

	if (ft_lstsize(kira_a) == 1)
		exit (0);
	else if (ft_check_sort(kira_a) == 1)
		exit (0);
	else if (ft_lstsize(kira_a) <= 5)
	{
		ft_sort_5(&kira_a, &kira_b);
		exit (0);
	}
	else if (ft_lstsize(kira_a) <= 100)
	{
		ft_sort_big(&kira_a, &kira_b, var, 5);
		exit (0);
	}
	else
	{
		ft_sort_big(&kira_a, &kira_b, var, 9);
		exit (0);
	}
}
