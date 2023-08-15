/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 10:47:12 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/23 13:16:18 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_swap(t_data **kira_a, int num)
{
	t_data	*temp;
	t_data	*temp2;

	if (!(*kira_a) || !(*kira_a)->next)
		return ;
	temp = (*kira_a);
	temp2 = (*kira_a)->next;
	ft_lstadd_back(&temp2, temp);
	temp->next = NULL;
	(*kira_a) = temp2;
	if (num == 1)
		write(1, "ra\n", 3);
	else if (num == 2)
		write(1, "rb\n", 3);
}

void	sa_swap(t_data **kira_a, int num)
{
	t_data	*temp;

	if (!(*kira_a) || !(*kira_a)->next)
		return ;
	temp = (*kira_a)->next;
	(*kira_a)->next = (*kira_a)->next->next;
	ft_lstadd_front(kira_a, temp);
	if (num == 1)
		write(1, "sa\n", 3);
	else if (num == 2)
		write(1, "sb\n", 3);
}

void	rrr_swap(t_data **kira_a, t_data **kira_b, int num)
{
	rra_swap(kira_a, 3);
	rra_swap(kira_b, 3);
	if (num == 3)
		write(1, "ss\n", 3);
}
