/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:21:04 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/29 16:51:51 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "../includes/so_long.h"

char	**filling(char **tab, char c, t_point size, int colonne, int ligne)
{
	if (colonne < 0 || ligne < 0 || colonne >= size.y || ligne >= size.x)
		return (tab);
	if (tab[colonne][ligne] == 'F' || tab[colonne][ligne] == '1' || tab[colonne][ligne] == 'P')
		return (tab);
	tab[colonne][ligne] = 'F';
	tab = filling(tab, c, size, colonne - 1, ligne);
	tab = filling(tab, c, size, colonne + 1, ligne);
	tab = filling(tab, c, size, colonne, ligne - 1);
	tab = filling(tab, c, size, colonne, ligne + 1);
	return (tab);
}

char	**flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;

	c = tab[begin.x][begin.y];
	// printf("c == %c\n", c);
	// printf("tab[0] == %s\n", tab[0]);
	tab = filling(tab, c, size, begin.x, begin.y);
	// while(tab[i])
	// {
	// 	printf("tab[i]= %s\n", tab[i]);
	// 	i++;
	// }	
	return (tab);
}

int	checking_after_fill(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			j++;
		}	
		i++;
	}
	return (1);
}

int	map_is_not_split(char **map)
{
	int		i;
	t_point	pos;
	t_point save;
	char	**copy;
	
	i = 0;
	copy = map;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[i] = NULL;
	(void)pos;
	(void)save;
	printf("max len copy - %d\n", max_len_map(copy));
	i = 0;
	pos = return_pos(map, 'P');
	save = pos;
	copy[pos.x][pos.y] = '0';
	// pos = return_pos(map, 'E');
	// map[pos.x][pos.y] = 'F';
	printf("bah alors\n");
	copy = flood_fill(copy, (t_point){ft_strlen(map[1]), max_len_map(map)}, (t_point){ 1 , 1 });
	if (checking_after_fill(copy) == 0)
	{
		free(copy);
		return (0);
	}	
	if (copy[save.x][save.y] == '0')
	{
		printf("Error: Player is locked at starting. Be careful\n");
		free(copy);
		return (0);
	}
	free(copy);
	return (1); 
}
