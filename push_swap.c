/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:19:17 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/23 12:35:55 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_data	*kira_a;
	t_data	*kira_b;
	char	**str;
	int		size;
	int		i;

	if (ac < 2)
		return (0);
	kira_a = NULL;
	kira_b = NULL;
	str = parsing_swap(ac, av);
	kira_a = ft_lstnew(ft_atoi(str[0]));
	i = 1;
	while (str[i])
		ft_lstadd_back(&kira_a, ft_lstnew(ft_atoi(str[i++])));
	free_it(str);
	ft_index(&kira_a);
	ft_sort_all(kira_a, kira_b);
	clear_list(kira_a);
	exit(0);
}
