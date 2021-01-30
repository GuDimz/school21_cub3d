/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 22:47:43 by agigi             #+#    #+#             */
/*   Updated: 2021/01/29 19:43:59 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>/*DELETE BEFORE PUSH!!!!!!*/
# define MAX_RES_X 1920
# define MAX_RES_Y 1080
# define MIN_RES_X 120
# define MIN_RES_Y 68
typedef struct	s_color
{
	unsigned char		flag;
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}				t_color;

typedef struct	s_conf
{
	int	res_x;
	int	res_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	t_color	floor;
	t_color	ceiling;
	int flag;
	int count;
}				t_conf;

typedef struct	s_map
{
	size_t		width;
	size_t		height;
	t_list		*begin;
	char	*array;
}				t_map;

typedef struct  s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_all
{
	t_data img;
	t_map map;
	t_conf conf;
}				t_all;


int ft_print_error(char *str, int len);
int ft_param_parser (char *line, t_all *all);
char ft_map_char(t_all *all, size_t xx, size_t yy);
void ft_init_struct(t_all *all);
int ft_check_struct(t_all *all);
int ft_check_duplicate(char *path);
void ft_map_parser(char *line, t_all *all);
void ft_map_create(t_all *all);
int ft_check_rgb_range(char *rgb);
void	ft_mlx_init(t_all *all);


#endif
