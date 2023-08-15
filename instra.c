/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:04:39 by sbzizal           #+#    #+#             */
/*   Updated: 2023/03/14 10:47:19 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss_swap(t_data **kira_a, t_data **kira_b, int num)
{
	sa_swap(kira_a, 3);
	sa_swap(kira_b, 3);
	if (num == 3)
		write(1, "ss\n", 3);
}

void	rr_swap(t_data **kira_a, t_data **kira_b, int num)
{
	ra_swap(kira_a, 3);
	ra_swap(kira_b, 3);
	if (num == 3)
		write(1, "rr\n", 3);
}

void	push_a(t_data **kira_a, t_data **kira_b, int num)
{
	t_data	*temp_b;

	if (!(*kira_b))
		return ;
	temp_b = (*kira_b);
	(*kira_b) = (*kira_b)->next;
	temp_b->next = NULL;
	ft_lstadd_front(&(*kira_a), temp_b);
	if (num == 1)
		write(1, "pa\n", 3);
}

void	push_b(t_data **kira_a, t_data **kira_b, int num)
{
	t_data	*temp_a;

	if (!(*kira_a))
		return ;
	temp_a = (*kira_a);
	(*kira_a) = (*kira_a)->next;
	temp_a->next = NULL;
	ft_lstadd_front(&(*kira_b), temp_a);
	if (num == 1)
		write(1, "pb\n", 3);
}

void	rra_swap(t_data **kira_a, int num)
{
	t_data	*last;
	t_data	*temp;
	t_data	*last_1;

	if (!(*kira_a) || !(*kira_a)->next)
		return ;
	temp = (*kira_a);
	while ((*kira_a)->next)
	{
		last_1 = (*kira_a);
		(*kira_a) = (*kira_a)->next;
	}
	last = ft_lstlast(*kira_a);
	ft_lstadd_front(& temp, last);
	last_1->next = NULL;
	(*kira_a) = last;
	if (num == 1)
		write(1, "rra\n", 4);
	else if (num == 2)
		write(1, "rrb\n", 4);
}
