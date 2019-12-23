/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:23:42 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/12 15:23:47 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_filler.h"

void	make_init_lst(void)
{
	g_lst.p_char = NULL;
	g_lst.e_char = NULL;
	g_lst.min_d_ofs = 999999999;
	g_lst.msize_x = 0;
	g_lst.msize_y = 0;
	g_lst.tetrsize_x = 0;
	g_lst.tetrsize_y = 0;
	g_lst.coords = NULL;
	g_lst.map = NULL;
	g_lst.piece = NULL;
}

void	free_lst(void)
{
	ft_free_tab(g_lst.map);
	ft_free_tab(g_lst.piece);
	free(g_lst.coords);
}

int		ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}
