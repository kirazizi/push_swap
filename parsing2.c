/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:03:13 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/21 12:08:23 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '+' || str[i] == '-')
			i++;
		else
			return (0);
	}
	return (1);
}

char	*ft_check_num(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strcmp(str[i], "") == 0 || ft_strlen(str[i]) >= 12)
			return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
		if (ft_is_number(str[i]) == 0)
			return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
		i++;
	}
	return (0);
}

char	*ft_check_int(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
		i++;
	}
	return (str[0]);
}

char	*ft_check_dub(char **str)
{
	char	*num;
	int		i;
	int		k;

	i = 1;
	k = 0;
	num = str[k];
	while (str[i])
	{
		if (ft_atoi(num) == ft_atoi(str[i]))
			return (ft_putstr_fd("\033[0;31mError\n", 2), exit(1), NULL);
		i++;
		if (str[i] == NULL)
		{
			k++;
			i = k + 1;
			num = str[k];
		}
	}
	return (0);
}
