/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelivan <vpelivan@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 15:25:20 by vpelivan          #+#    #+#             */
/*   Updated: 2019/03/12 17:11:27 by vpelivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "../libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct	s_fill
{
	char		*p_char;
	char		*e_char;
	int			min_d_ofs;
	int			msize_x;
	int			msize_y;
	int			tetrsize_x;
	int			tetrsize_y;
	int			*coords;
	char		**map;
	char		**piece;
	char		*str;
}				t_fill;

typedef struct	s_dst
{
	int			k;
	int			j;
	int			i;
	int			tmp_y;
	int			tmp_x;
	int			crd_y;
	int			crd_x;
	int			len;
}				t_dst;

t_fill			g_lst;
t_dst			g_d;

void			make_init_lst(void);
void			get_player(void);
void			get_params(void);
void			get_maps(void);
void			get_piece(void);
void			get_piece_coords(void);
void			get_size(char *str, int *y, int *x);
void			free_lst(void);
void			find_optimal_decision(int min_d_x, int min_d_y);
int				check_to_paste_piece(int x, int y);
int				get_min_dist(int x, int y);
int				ft_abs(int value);

#endif
