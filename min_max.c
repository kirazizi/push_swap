/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:55:56 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/19 22:57:24 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_min(t_data *kira_a)
{
	long long	min;

	min = kira_a->number;
	while (kira_a)
	{
		if (kira_a->number < min && kira_a->index == -1)
			min = kira_a->number;
		kira_a = kira_a->next;
	}
	return (min);
}

int	max_number(t_data *kira_a)
{
	int	max_indx;

	max_indx = kira_a->index;
	while (kira_a->next)
	{
		if (max_indx < kira_a->next->index)
			max_indx = kira_a->next->index;
		kira_a = kira_a->next;
	}
	return (max_indx);
}

int	min_number(t_data *kira_a)
{
	int	min;

	min = kira_a->number;
	while (kira_a)
	{
		if (kira_a-> number < min)
			min = kira_a->number;
		kira_a = kira_a->next;
	}
	return (min);
}

void	ft_index(t_data	**kira_a)
{
	t_data		*tmp;
	long long	min;
	int			i;

	tmp = *kira_a;
	i = 0;
	while (tmp)
	{
		min = check_min(tmp);
		if (tmp->number == min && tmp->index == -1)
		{
			tmp->index = i;
			i++;
			tmp = *kira_a;
		}
		else
			tmp = tmp->next;
	}
}
