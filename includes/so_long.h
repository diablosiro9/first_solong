/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:44:42 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/29 18:20:25 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef	struct s_point
{
	int	x;
	int	y;
}t_point;

typedef	struct s_data
{
	int		x;
	int		y;
	char	c;
	/* data */
}t_data;

// POUR GNL
int		int_strlen(char *s);
int	max_len_map(char **map);
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*make_save(int fd, char *save, char *buffer);
char	**ft_split(char const *s, char c);
// static char	*ligne(char *save);
// static char	*newline(char *save);

int	checking_str(char *str, int	hauteur_map);
t_point	return_pos(char	**tab, char c);
int	doublon(char **map, char c, t_point pos);
int	map_is_not_split(char **map);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	checking_map_is_playable(char **map);
void	ft_putstr(char *str);
void	print_map(char **map);
int	is_map(char *str);
void	ft_error(char *msg);

#endif