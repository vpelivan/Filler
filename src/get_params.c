/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:23:54 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/12 15:23:57 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void	get_maps(void)
{
	int i;
	int y;

	i = 0;
	y = g_lst.msize_y;
	while (i < y)
	{
		get_next_line(0, &g_lst.str);
		if (ft_isdigit(g_lst.str[0]) && ft_isdigit(g_lst.str[1])
			&& ft_isdigit(g_lst.str[2]) && !(ft_isdigit(g_lst.str[3])))
		{
			if (i == 0)
			{
				g_lst.map = (char **)malloc(sizeof(char *) * (y + 1));
				g_lst.map[y] = NULL;
			}
			g_lst.map[i] = ft_strdup(&g_lst.str[4]);
			i++;
		}
		free(g_lst.str);
	}
}

void	get_piece(void)
{
	int i;
	int y;

	i = 0;
	y = g_lst.tetrsize_y;
	while (i < y)
	{
		get_next_line(0, &g_lst.str);
		if (ft_strchr(".*", g_lst.str[0]) != NULL)
		{
			if (i == 0)
			{
				g_lst.piece = (char **)malloc(sizeof(char *) * (y + 1));
				g_lst.piece[y] = NULL;
			}
			g_lst.piece[i] = ft_strdup(g_lst.str);
			i++;
		}
		free(g_lst.str);
	}
}

void	get_piece_coords(void)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	g_lst.coords = (int *)malloc(sizeof(int) * 2048);
	while (i < 2048)
		g_lst.coords[i++] = -1;
	i = 0;
	while (g_lst.piece[y])
	{
		x = 0;
		while (g_lst.piece[y][x])
		{
			if (g_lst.piece[y][x] == '*')
			{
				g_lst.coords[i] = x;
				g_lst.coords[i + 1] = y;
				i += 2;
			}
			x++;
		}
		y++;
	}
}

void	get_size(char *str, int *y, int *x)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]) == 0)
		i++;
	*y = ft_atoi(&str[i]);
	while (str[i] && ft_isdigit(str[i]) == 1)
		i++;
	*x = ft_atoi(&str[i]);
}

void	get_player(void)
{
	if (ft_strstr(g_lst.str, "p1") && ft_strstr(g_lst.str, "vpelivan"))
	{
		g_lst.p_char = "oO";
		g_lst.e_char = "xX";
	}
	else if (ft_strstr(g_lst.str, "p2") && ft_strstr(g_lst.str, "vpelivan"))
	{
		g_lst.p_char = "xX";
		g_lst.e_char = "oO";
	}
	else
	{
		free(g_lst.str);
		exit(1);
	}
}
