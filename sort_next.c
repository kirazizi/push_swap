/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:42:42 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/21 13:52:01 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_prev(t_data **kira_a, t_data **kira_b)
{
	while ((*kira_b)->number != ft_prev_max(*kira_b)
		&& ft_pos_prev(*kira_b) <= ft_lstsize(*kira_b) / 2)
		ra_swap(kira_b, 2);
	while ((*kira_b)->number != ft_prev_max(*kira_b)
		&& ft_pos_prev(*kira_b) > ft_lstsize(*kira_b) / 2)
		rra_swap(kira_b, 2);
	if ((*kira_b)->number == ft_prev_max(*kira_b))
	{
		push_a(kira_a, kira_b, 1);
		while ((*kira_b)->number != ft_max(*kira_b)
			&& ft_pos_max(*kira_b) <= ft_lstsize(*kira_b) / 2)
			ra_swap(kira_b, 2);
		while ((*kira_b)->number != ft_max(*kira_b)
			&& ft_pos_max(*kira_b) > ft_lstsize(*kira_b) / 2)
			rra_swap(kira_b, 2);
		if ((*kira_b)->number == ft_max(*kira_b))
			push_a(kira_a, kira_b, 1);
		sa_swap(kira_a, 1);
	}
}

void	push_max(t_data **kira_a, t_data **kira_b)
{
	while ((*kira_b)->number != ft_max(*kira_b)
		&& ft_pos_max(*kira_b) <= ft_lstsize(*kira_b) / 2)
		ra_swap(kira_b, 2);
	while ((*kira_b)->number != ft_max(*kira_b)
		&& ft_pos_max(*kira_b) > ft_lstsize(*kira_b) / 2)
		rra_swap(kira_b, 2);
	if ((*kira_b)->number == ft_max(*kira_b))
		push_a(kira_a, kira_b, 1);
}

void	sort_next(t_data **kira_a, t_data **kira_b)
{
	while ((*kira_b))
	{
		if (size_push(*kira_b, ft_pos_prev(*kira_b))
			< size_push(*kira_b, ft_pos_max(*kira_b)))
		{
			push_prev(kira_a, kira_b);
		}
		else
		{
			push_max(kira_a, kira_b);
		}
		if (ft_lstsize(*kira_b) == 1)
			push_a(kira_a, kira_b, 1);
	}
}
