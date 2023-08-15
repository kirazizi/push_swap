/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:04:16 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/21 11:58:56 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_data *lst)
{
	t_data	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp -> next;
		i++;
	}
	return (i);
}

t_data	*ft_lstnew(long long number)
{
	t_data	*head;

	head = NULL;
	head = malloc(sizeof(t_data));
	if (!head)
		return (NULL);
	head -> number = number;
	head->index = -1;
	head -> next = NULL;
	return (head);
}

t_data	*ft_lstlast(t_data *lst)
{
	t_data	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp -> next != NULL)
	{
		tmp = tmp -> next;
	}
	return (tmp);
}

void	clear_list(t_data	*head)
{
	t_data	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	head = NULL;
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
