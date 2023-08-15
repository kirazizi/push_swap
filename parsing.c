/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:31:41 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/22 11:51:26 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_empt(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_check_sin(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '+' || str[i][j] == '-')
			{
				if (str[i][j +1] == '+' || str[i][j +1] == '-'
				|| str[i][j +1] == '\0')
					return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
			}
			if (str[i][j] != '+' || str[i][j] != '-')
			{
				if (str[i][j +1] == '+' || str[i][j +1] == '-')
					return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	free_it(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**parsing_swap(int ac, char **av)
{
	char	*src;
	char	**str;
	int		i;
	int		j;

	i = 1;
	src = NULL;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
		if (ft_check_empt(av[i]) == 0)
			return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
		src = ft_strjoin(src, av[i]);
		src = ft_strjoin(src, " ");
		i++;
	}
	str = ft_split(src, ' ');
	free(src);
	ft_check_num(str);
	ft_check_sin(str);
	ft_check_dub(str);
	ft_check_int(str);
	return (str);
}
