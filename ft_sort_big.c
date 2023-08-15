/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:21:39 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/23 13:59:51 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_data **kira_a, t_data **kira_b, t_tools var, int nb)
{
	var.index = 0;
	var.chank = ft_lstsize(*kira_a) / nb;
	var.size_ch = ft_lstsize(*kira_a) / nb;
	while (ft_lstsize(*kira_a))
	{
		while ((*kira_a) && var.index < var.chank)
		{
			if ((*kira_a)->index < var.chank)
			{
				if ((*kira_a)->index > var.chank - (var.size_ch / 2))
				{
					push_b(kira_a, kira_b, 1);
					ra_swap(kira_b, 2);
				}
				else
					push_b(kira_a, kira_b, 1);
				var.index++;
			}
			else
				ra_swap(kira_a, 1);
		}
		var.chank += var.size_ch;
	}
	sort_next(kira_a, kira_b);
}
