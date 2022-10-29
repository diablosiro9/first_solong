/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dojannin <dojannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:45:28 by dojannin          #+#    #+#             */
/*   Updated: 2022/10/29 18:19:30 by dojannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

char	**stocking_map(char **map, int fd)
{
	char	save[2];
	int		size;
	char	*line;

	size = read(fd, save, 1);
	save[1] = '\0';
	line = ft_strdup(save);
	size = read(fd, save, 1);
	save[1] = '\0';
	while (size > 0)
	{
		line = ft_strjoin(line, save);
		size = read(fd, save, 1);
		save[1] = '\0';
	}
	map = ft_split(line,'\n');
	return (map);
}

void	do_all(char **map)
{
	if (checking_map_is_playable(map) == 0)
		return ;
	else
	{
		printf("We got a solid map.\n");
		// USAGE MINILIB affichage de la map;
		
	}
}

void	puterror(int i)
{
	if (i == 500)
	{
		printf("No map found.\n");
		exit (1);
	}
}

int	main(int ac, char **av)
{
	int	fd;
	char	**map;
	int		hauteur_map;

	fd = 0;
	map = NULL;
	hauteur_map = 0;
	if (ac != 2)
	{
		puterror(500);
		return 0;
	}
	else
	{
		if (is_map(av[1]) == 1)
		{
			// printf("On a une map\n");
			fd = open(av[1], O_RDONLY);
			if (fd < 0)
				ft_error("File doesn't exist\n");
			if (open(av[1], O_DIRECTORY) > 0)	
				ft_error("This is a directory\n");

			// printf("le open se passe bien, fd == %d\n", fd);
			map = stocking_map(map, fd);
			print_map(map);
				// return (0);
			// else
			// {
			// 	printf("weird\n");
			// 	printf("Test = %s\n", map[0]);
			// 	printf("tu vas jusaue lq ma caille\n");
			do_all(map);
			// }
		}
	}
	return (0);
}