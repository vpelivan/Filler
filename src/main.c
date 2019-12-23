/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:22:10 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/13 14:26:32 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

int		check_to_paste_piece(int x, int y)
{
	int i;
	int j;
	int tx;
	int ty;
	int pf;

	i = 0;
	j = i + 1;
	pf = 0;
	while (g_lst.coords[i] != -1)
	{
		ty = y + g_lst.coords[j];
		tx = x + g_lst.coords[i];
		if ((ty >= 0 && ty < g_lst.msize_y) && (tx >= 0 && tx < g_lst.msize_x)
		&& ft_strchr(g_lst.e_char, g_lst.map[ty][tx]) == NULL)
		{
			(ft_strchr(g_lst.p_char, g_lst.map[ty][tx]) != NULL) ? pf++ : 0;
			i += 2;
			j += 2;
		}
		else
			break ;
	}
	return ((g_lst.coords[i] == -1 && pf == 1) ? 1 : 0);
}

int		get_min_dist(int x, int y)
{
	g_d.i = -1;
	g_d.len = g_lst.min_d_ofs;
	while (++g_d.i < g_lst.msize_y)
	{
		g_d.j = -1;
		while (g_lst.map[g_d.i][++g_d.j])
			if (ft_strchr(g_lst.e_char, g_lst.map[g_d.i][g_d.j]))
			{
				g_d.k = 0;
				while (g_lst.coords[g_d.k] != -1)
				{
					g_d.crd_y = g_lst.coords[g_d.k + 1];
					g_d.crd_x = g_lst.coords[g_d.k];
					((y + g_d.crd_y - g_d.i) < 0) ? (g_d.tmp_y = g_d.i
					- y + g_d.crd_y) : (g_d.tmp_y = y + g_d.crd_y - g_d.i);
					((x + g_d.crd_x - g_d.j) < 0) ? (g_d.tmp_x = g_d.j
					- x + g_d.crd_x) : (g_d.tmp_x = x + g_d.crd_x - g_d.j);
					if (g_d.tmp_y + g_d.tmp_x < g_d.len
					&& g_d.tmp_y + g_d.tmp_x > 0)
						g_d.len = g_d.tmp_y + g_d.tmp_x;
					g_d.k += 2;
				}
			}
	}
	return (g_d.len);
}

void	find_optimal_decision(int min_d_x, int min_d_y)
{
	int x;
	int y;
	int min_d;

	y = -1;
	min_d = g_lst.min_d_ofs;
	while (g_lst.map[++y])
	{
		x = -1;
		while (g_lst.map[y][++x])
		{
			if (check_to_paste_piece(x, y) == 1 && get_min_dist(x, y) < min_d)
			{
				min_d = get_min_dist(x, y);
				min_d_x = x;
				min_d_y = y;
				(min_d_x == 0 && min_d_y == 0) ? (min_d = g_lst.min_d_ofs) : 0;
				if (min_d_x == 0 && min_d_y == 0)
					continue ;
			}
		}
	}
	(min_d_y == 0 && min_d_x == 0) ? ft_printf("%i %i\n", min_d_y, min_d_x) : 0;
	(min_d_y == 0 && min_d_x == 0) ? exit(1) : 0;
	ft_printf("%i %i\n", min_d_y, min_d_x);
}

void	get_params(void)
{
	while (get_next_line(0, &g_lst.str) > 0)
	{
		if (ft_strstr(g_lst.str, "$$$"))
		{
			get_player();
			free(g_lst.str);
		}
		else if (ft_strstr(g_lst.str, " 0123"))
			free(g_lst.str);
		else if (ft_strstr(g_lst.str, "Plateau"))
		{
			get_size(&g_lst.str[7], &g_lst.msize_y, &g_lst.msize_x);
			free(g_lst.str);
			get_maps();
		}
		else if (ft_strstr(g_lst.str, "Piece"))
		{
			get_size(&g_lst.str[5], &g_lst.tetrsize_y, &g_lst.tetrsize_x);
			free(g_lst.str);
			get_piece();
			get_piece_coords();
			find_optimal_decision(0, 0);
			free_lst();
		}
	}
}

int		main(void)
{
	make_init_lst();
	get_params();
	return (0);
}
