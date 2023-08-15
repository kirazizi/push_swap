/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 14:27:59 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/23 13:28:20 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("\033[0;31mError\n", 2);
	exit(1);
}

void	ft_instra(t_data **stack_a, t_data **stack_b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa_swap(stack_a, 3);
	else if (ft_strcmp(line, "sb\n") == 0)
		sa_swap(stack_b, 3);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra_swap(stack_a, 3);
	else if (ft_strcmp(line, "rb\n") == 0)
		ra_swap(stack_b, 3);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra_swap(stack_a, 3);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rra_swap(stack_b, 3);
	else if (ft_strcmp(line, "pa\n") == 0)
		push_a(stack_a, stack_b, 2);
	else if (ft_strcmp(line, "pb\n") == 0)
		push_b(stack_a, stack_b, 2);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr_swap(stack_a, stack_b, 4);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss_swap(stack_a, stack_b, 4);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr_swap(stack_a, stack_b, 4);
	else
		ft_error();
}

void	*ft_input(t_data *stack_a, t_data *stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			if (ft_check_sort(stack_a) && !stack_b)
			{
				ft_putstr_fd("\033[0;32mOK\n", 2);
				break ;
			}
			else
			{
				ft_putstr_fd("\033[0;31mKO\n", 2);
				break ;
			}
		}
		ft_instra(&stack_a, &stack_b, line);
		free(line);
	}
	clear_list(stack_a);
	clear_list(stack_b);
	return (0);
}

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

int	main(int ac, char **av)
{
	t_data	*stack_a;
	t_data	*stack_b;
	char	**str;
	int		i;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	stack_a = NULL;
	str = parsing_swap(ac, av);
	stack_a = ft_lstnew(ft_atoi(str[0]));
	stack_b = NULL;
	i = 1;
	while (str[i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(str[i++])));
	ft_index(&stack_a);
	ft_input(stack_a, stack_b);
	exit(0);
}
