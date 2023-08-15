/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:43:08 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/21 21:50:58 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup( char *s)
{
	int		i;
	char	*src;
	char	*dst;

	src = (char *)s;
	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

long long	ft_atoi(const char *str)
{
	long long	i;
	long long	res;
	long long	signe;

	i = 0;
	res = 0;
	signe = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	return (res * signe);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*src;

	if (!s1)
		s1 = ft_strdup("");
	if (s2)
	{
		src = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!src)
			return (NULL);
		i = -1;
		while (s1[++i])
			src[i] = s1[i];
		i = -1;
		while (s2[++i])
			src[ft_strlen(s1) + i] = s2[i];
		src[ft_strlen(s1) + i] = '\0';
		if (src[0] == '\0')
			return (free (src), free(s1), NULL);
		free(s1);
		return (src);
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{	
		i++;
	}
	return (s1[i] - s2[i]);
}
