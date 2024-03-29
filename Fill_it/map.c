/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lminta <lminta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 19:56:01 by lminta            #+#    #+#             */
/*   Updated: 2019/10/17 22:12:44 by lminta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			fill_map_clean(int **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (0);
}

static int	**map_start(int size)
{
	int		**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (int **)malloc(sizeof(int *) * size)))
		return (0);
	while (i < size)
	{
		if (!(map[i] = (int *)malloc(sizeof(int) * size)))
		{
			fill_map_clean(map, i);
			return (0);
		}
		j = 0;
		while (j < size)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

int			re_map(int ***map, int size)
{
	int		**buff;
	int		i;
	int		j;

	buff = *map;
	if (!(*map = map_start(size + 1)))
		return (fill_map_clean(buff, size));
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			(*map)[i][j] = buff[i][j];
			j++;
		}
		i++;
	}
	fill_map_clean(buff, size);
	return (size + 1);
}

t_map_fill	*map_create(int size)
{
	t_map_fill	*map;

	if (!(map = (t_map_fill *)malloc(sizeof(t_map_fill))))
		return (0);
	if (!(map->map = map_start(size)))
	{
		free(map);
		return (0);
	}
	map->size = size;
	return (map);
}

int			print_map(t_map_fill *map)
{
	int i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->map[i][j] == 0)
				ft_putchar('.');
			else
				ft_putchar((char)(map->map[i][j]));
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (1);
}
