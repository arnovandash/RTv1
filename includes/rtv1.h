/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnovan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/05 08:40:19 by arnovan-          #+#    #+#             */
/*   Updated: 2016/07/14 11:24:59 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

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

/*
# define RED1		0xFF0000
# define RED2		0x550000
# define GREEN1		0x00FF00
# define GREEN2		0x005500
# define BLUE1		0x0000FF
# define BLUE2		0x000055
# define YELLOW1	0xFFFF00
# define YELLOW2	0x555500
# define PURPLE1	0xBF3EFF
# define PURPLE2	0x551A8B
 */

/*
// forward declarations
// struct List;
// struct Node;
//
// typedef struct List *ListP;
// typedef struct Node *NodeP;
//
//HAVE SPHERE NODE
// struct Node{
//    char name[20];
//       NodeP next;
//       };
//
//CREATE A SEPERATE STRUCT FOR THE HEAD NODE
//       struct List{
//          NodeP head;
//             int size;
//             };
 *
 */

typedef struct				s_cam
{
//	int						key;i
	int						cam_read;
	float					fov;
	int					orig_x;
	int					orig_y;
	int					orig_z;
	int					dir_x;
	int					dir_y;
	int					dir_z;

	struct s_cam_list	*next;
}							t_cam;


typedef struct				s_vector
{
	int						x;
	int						y;
	int						z;
}							t_vector;

typedef	struct				s_ray
{
	t_vector				start;
	t_vector				dir;
}							t_ray;

typedef struct	s_env
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

/*Object List*/

typedef struct				s_sphere_list
{
//	int						key;
	int					radius;
	int					orig_x;
	int					orig_y;
	int					orig_z;
	struct s_sphere_list	*next;
}							t_sphere_list;

/*Scene*/ 

typedef struct				s_lights_list
{
//	int						key;
	float					fov;
	int					orig_x;
	int					orig_y;
	int					orig_z;
	int					dir_x;
	int					dir_y;
	int					dir_z;

	struct s_lights_list	*next;
}							t_lights_list;





typedef struct				s_glob
{

	//REMOVE OBSOLETE VALUES
	t_sphere_list			*head_s;
	t_sphere_list			*current_s;
	t_sphere_list			*node_s;
//	int						spheres;
	
	t_cam					*cam;
	
	
	
	
	t_vector				coord;
	t_ray					ray;
	t_env					env;
	t_sphere_list			sphere;
// 		PARSER FUNCTIONS
	int						data_field;
	char					*data;
}							t_glob;


void						obj_list(t_glob *g, char *data, int col, int type);
void						env_list(t_glob *g, char *data, int col, int type);
void						get_sphere(t_glob *g);
void						get_cam(t_glob *g);
void						read_scene(t_glob *g, char *file);
void						error(int err);
int							ft_esc(int keycode);
//////////////////////////////// FIX PROTOTYPE //////////
/////////////////////////////// CHECK FOR LEAKS /////////
int							quitwin();//t_glob *g);
int							key_press(int keycode, t_glob *g);
int							key_release(int keycode, t_glob *g);
#endif
