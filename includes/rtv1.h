/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 08:40:19 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/17 16:04:44 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//TODO
//Remove unused camera values


#ifndef RTV1_H
# define RTV1_H

////////////// REMOVE HEADERS ///////////////
# include "mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

# include <math.h>

# define WIN_W 640
# define WIN_H 480

/* Mac keybinds */
# define KB_ESC 53
# define KB_UP 126
# define KB_DOWN 125
# define KB_LEFT 123
# define KB_RIGHT 124

/* Linux keybinds */
# define KB_ESC_X11 65307
# define KB_UP_X11 65362
# define KB_DOWN_X11 65364
# define KB_LEFT_X11 65361
# define KB_RIGHT_X11 65363

# define min(a,b) (((a) < (b)) ? (a) : (b))

typedef struct				s_vector
{
	float					x;
	float					y;
	float					z;
}							t_vector;

typedef struct				s_colour
{
	float					r;
	float					g;
	float					b;
}							t_colour;

typedef struct				s_material
{
	int					num;
	t_colour				diffuse;
	float					reflection;
}							t_material;

typedef struct				s_light
{
	t_vector				origin;
	t_colour				intensity;
}							t_light;

typedef struct				s_sphere
{
	t_vector				origin;
	float					radius;
	int						material;
}							t_sphere;
/*
typedef struct				s_cam
{
//	float					fov;
	t_vector				origin;
	t_vector				dir;
}							t_cam;
*/
typedef	struct				s_ray
{
	t_vector				start;
	t_vector				dir;
}							t_ray;

typedef struct				s_env
{
	void					*mlx;
	void					*win;
	void					*img;
	char					*cursor;
	char					*data;
	int						fd;
	int						bpp;
	int						size_line;
	int						endian;
}							t_env;

typedef struct				s_obj_list
{
	char					*obj_name;
//	int						item_number;
	t_sphere				sphere;
	t_light					light;
	t_material				material;
	struct s_obj_list		*next;
}							t_obj_list;

typedef struct				s_glob
{
	t_env					env;
	t_obj_list				*head;
	t_obj_list				*node;
	t_obj_list				*current;
	t_ray					cam;
	int						cam_read;
	t_vector				vec;
	t_ray					ray;
	t_ray					light_ray;
	t_light					current_light;
	t_material				current_mat;
	t_vector				scaled;
	t_vector				new_start;
	t_vector				normal;
	t_vector				dist;
	int						level;
	int						type;
	int						in_shadow;
	float						coef;
	float						nearest;
	float						lambert;
	float						reflect;
	float						red;
	float						green;
	float						blue;
	float						temp;
// 		PARSER FUNCTIONS
	int						data_field;
	char					*data;
}							t_glob;

int							calc_sphere(t_ray ray, t_sphere sphere, float near);
//int							calc_shadow(t_glob *g);
void						calc_light(t_glob *g);
void						get_data(t_glob *g);
void						get_material(t_glob *g, int num);
float						dot_prod(t_vector a, t_vector b);
float						magnitude(t_vector a);
t_vector					normalize(t_vector c);
t_vector					negative(t_vector c);
t_vector					cross_prod(t_vector a, t_vector b);
t_vector					add_vec(t_vector a, t_vector b);
t_vector					multiply_vec(t_vector a, t_vector b);

t_vector					scale_vec(float x, t_vector a);
t_vector					subtract_vec(t_vector a, t_vector b);


void						render(t_glob *g);
void						get_scene(t_glob *g, char *file);
void						error(int err);
int							ft_esc(int keycode);
//////////////////////////////// FIX PROTOTYPE //////////
/////////////////////////////// CHECK FOR LEAKS /////////
int							quitwin(t_glob *g);
int							key_press(int keycode, t_glob *g);
int							key_release(int keycode, t_glob *g);
#endif
