/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbzizal <sbzizal@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:29:43 by sbzizal           #+#    #+#             */
/*   Updated: 2023/05/23 13:19:36 by sbzizal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

long long	ft_atoi(const char *str);
char		*get_next_line(int fd);
char		*ft_read(int fd, char *keep);
int			ft_strlen(char *str);
int			ft_strchr( char *str, char c);
char		*ft_strdup( char *s);
char		*ft_strjoin(char *s1, char *s2);

typedef struct s_data{
	long long		number;
	int				index;
	struct s_data	*next;
}	t_data;

typedef struct s_tools{
	int	index;
	int	chank;
	int	size_ch;
}	t_tools;

t_data		*ft_lstnew(long long number);
t_data		*ft_lstlast(t_data *lst);

void		sort_next(t_data **kira_a, t_data **kira_b);
void		ft_lstadd_back(t_data **lst, t_data *new);
void		ft_lstadd_front(t_data **lst, t_data *new);
void		ra_swap(t_data **kira_a, int num);
void		sa_swap(t_data **kira_a, int num);
void		rra_swap(t_data **kira_a, int num);
void		push_a(t_data **kira_a, t_data **kira_b, int num);
void		push_b(t_data **kira_a, t_data **kira_b, int num);
void		ft_index(t_data	**kira_a);
void		ft_sort_big(t_data **kira_a, t_data **kira_b, t_tools var, int nb);
void		rr_swap(t_data **kira_a, t_data **kira_b, int num);
void		ss_swap(t_data **kira_a, t_data **kira_b, int num);
void		rrr_swap(t_data **kira_a, t_data **kira_b, int num);
void		clear_list(t_data	*head);
void		ft_sort_all(t_data *kira_a, t_data *kira_b);
void		free_it(char **tab);
void		ft_putstr_fd(char *s, int fd);
int			check_min(t_data *kira_a);
int			ft_lstsize(t_data *lst);
int			min_number(t_data *kira_a);
int			max_number(t_data *kira_a);
int			ft_prev_max(t_data *kira_a);
int			ft_pos_prev(t_data *kira_a);
int			ft_pos_max(t_data *kira_a);
int			ft_max(t_data *kira_a);
int			size_push(t_data *kira_b, int pos);
int			ft_check_sort(t_data *stack_a);
int			ft_strcmp(char *s1, char *s2);
char		**parsing_swap(int ac, char **av);
char		*ft_strjoin(char *s1, char *s2);
char		**ft_split(char const	*s, char c);
char		*ft_check_num(char **str);
char		*ft_check_int(char **str);
char		*ft_check_dub(char **str);

#endif