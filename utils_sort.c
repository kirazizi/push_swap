/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:42:51 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/21 11:58:11 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_push(t_data *kira_b, int pos)
{
	int	instra;
	int	size;

	size = ft_lstsize(kira_b);
	if (pos > size / 2)
		instra = (size - pos);
	else
		instra = pos;
	return (instra);
}

int	ft_max(t_data *kira_a)
{
	int	max;

	max = kira_a->number;
	while (kira_a)
	{
		if (kira_a->number > max)
			max = kira_a->number;
		kira_a = kira_a->next;
	}
	return (max);
}

int	ft_prev_max(t_data *kira_a)
{
	int	prev;
	int	max;

	prev = kira_a->number;
	max = ft_max(kira_a);
	if (prev == max)
		prev = kira_a->next->number;
	while (kira_a)
	{
		if (kira_a->number > prev && kira_a->number < max)
			prev = kira_a->number;
		kira_a = kira_a->next;
	}
	return (prev);
}

int	ft_pos_prev(t_data *kira_a)
{
	int	prev;
	int	i;

	i = 0;
	prev = ft_prev_max(kira_a);
	while (kira_a)
	{
		if (kira_a->number == prev)
			return (i);
		i++;
		kira_a = kira_a->next;
	}
	return (i);
}

int	ft_pos_max(t_data *kira_a)
{
	int	max;
	int	i;

	i = 0;
	max = ft_max(kira_a);
	while (kira_a)
	{
		if (kira_a->number == max)
			return (i);
		i++;
		kira_a = kira_a->next;
	}
	return (i);
}
