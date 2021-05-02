/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 13:23:37 by mvuente           #+#    #+#             */
/*   Updated: 2020/10/22 13:23:41 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "minilibx_mms_20200219/mlx.h"
# include "libft/libft.h"
# include <float.h>
# include <limits.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct			s_crd
{
	int					x;
	int					y;
}						t_crd;

typedef struct			s_coord
{
	double				x;
	double				y;
	double				z;
}						t_coord;

typedef struct			s_colour
{
	unsigned char		red;
	unsigned char		green;
	unsigned char		blue;
}						t_colour;

typedef	struct			s_bord
{
	double				xmin;
	double				xmax;
}						t_bord;

typedef struct			s_peak
{
	t_coord				a;
	t_coord				b;
	t_coord				c;
	t_coord				d;
}						t_peak;

typedef struct			s_img
{
	void				*img;
	char				*addr;
}						t_img;

typedef	struct			s_camera
{
	t_coord				*point;
	t_coord				*vector;
	int					fov;
	t_img				*ca_img;
}						t_camera;

typedef	struct			s_light
{
	double				ratio;
	t_colour			*rgb;
}						t_light;

typedef struct			s_figure
{
	char				*id;
	t_coord				point;
	t_coord				vector;
	t_coord				pt2;
	t_coord				pt3;
	t_peak				peaks;
	double				size;
	double				height;
	t_colour			rgb;
}						t_figure;

typedef	struct			s_list
{
	t_figure			fig;
	struct s_list		*next;
}						t_list;

typedef	struct			s_listcirc
{
	t_camera			*cam;
	struct s_listcirc	*nextf;
	struct s_listcirc	*nextb;
}						t_listcirc;

typedef struct			s_scene
{
	t_coord				vpoint;
	t_crd				res_sys;
	t_crd				*res;
	t_camera			*current_ca;
	t_listcirc			*cams;
	t_light				*amb;
	t_list				*spo;
	t_list				*spo_base;
	t_list				*obj;
	t_list				*obj_base;
	int					back;
}						t_scene;

typedef struct			s_equat
{
	double				k1;
	double				k2;
	double				k3;
}						t_equat;

typedef	struct			s_data
{
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct			s_matrix
{
	t_coord				*row1;
	t_coord				*row2;
	t_coord				*row3;
}						t_matrix;

typedef struct			s_vars
{
	void				*mlx;
	void				*win;
	t_scene				*scene;
	t_data				*imgdet;
}						t_vars;

void					rt_error(void);
void					malloc_error(void);
void					com_error(void);
void					mlx_error(void);
void					oc_error(void);
void					save_error(void);
void					vectorvalidator(t_coord vector);
void					scenevalidator(t_scene *scene);
void					cleaner(t_scene *scene);
double					rd_parser(char **start);
double					atof_rt(char **start);
double					ft_dot(t_coord a, t_coord b);
double					vector_mod(t_coord a);
double					ray_pars(t_figure fig, t_coord point, t_coord vpoint,
						t_bord bord);
t_colour				colour_parser(char **start);
t_scene					*l_pars(t_figure fig, t_scene *scene, t_coord vpoint,
						double t);
double					pnt_ln_dst_sq(t_coord cross, t_coord a, t_coord b,
						t_coord d);
double					c_eq_sp_cyl(t_figure fig, t_coord point,
						t_coord vpoint, t_bord bord);
double					c_eq_pl(t_figure fig, t_coord point, t_coord vpoint,
						t_bord bord);
double					cross_pls(t_figure fig, t_coord point, t_coord vpoint,
						double t);
double					cross_tri(t_figure fig, t_coord point, t_coord vpoint,
						double t);
double					cross_cyl(t_figure fig, t_coord point, t_coord vpoint,
						double t);
t_scene					*pcomp_sp(t_figure fig, t_figure *spot, t_scene *scene,
						t_coord
						pcross);
t_scene					*pcomp_pl(t_figure fig, t_figure *spot, t_scene *scene,
						t_coord
						pcross);
double					ft_gerone(t_coord a, t_coord b, t_coord c);
double					channelcalculator(t_scene *scene, int i);
double					ft_min_more_than_min(double min, double max, double y,
						double z);
t_equat					*equation_cyl(t_figure fig, t_coord point,
						t_coord vpoint);
t_equat					*equation_sp_cyl(t_figure fig, t_coord point,
						t_coord vpoint);
t_coord					coord_parser(char **ptr);
t_coord					ft_vctr(t_coord a, t_coord b);
t_coord					minusvector(t_coord b);
t_coord					vector_sum(t_coord a, t_coord b);
t_coord					normalizer(t_coord a);
t_coord					linear(t_coord o, t_coord v, double t);
t_coord					viewpoint(t_crd *spt, t_scene *scene);
t_coord					normalcrtr(t_coord vector);
t_coord					vectormult(t_coord a, t_coord b);
t_coord					axemaker(t_coord *vector);
t_coord					rotation(t_matrix *rotor, t_coord a);
t_list					*ft_create_item(t_figure fig);
t_list					*ft_add_item(t_list *current, t_figure fig);
t_list					*sqchecker(t_list *obj);
void					ft_add_item_front(t_list **current, t_list *new);
t_listcirc				*ft_create_item_circ(t_listcirc *fig, t_listcirc *tmp,
						t_camera *data);
t_listcirc				*ft_add_item_circ(t_listcirc *fig, t_camera *data);
t_listcirc				*move_listcirc(t_listcirc *fig, int flag);
int						filler_img_by_pixels(t_vars var, t_img *new_img);
void					my_mlx_pixel_put(t_data *data, char *addr, t_crd *spt,
						int color);
int						scene_newcam_prep(t_scene *scene, int flag);
void					right_arrow(t_vars *var);
void					listmove(t_list *dst, t_list *src);
int						counter(int a);
float					atoi_f_divider(char **ptr);
int						atoi_clr(char **start);
float					atoi_rt(char **ptr);
int						clrtransf(t_colour *rgb, t_scene *scene);
int						clrmaker(t_scene *scene, t_coord vpoint);
int						scsaver(t_img *img, t_data *data, t_crd *size);
int						gnl(int fd, char **line);
t_figure				figrotor(t_matrix *rotor, t_figure fig,
						t_coord *point);
t_peak					point_to_peak(t_figure *fig);
int						shadow_check(t_coord pcross, t_coord lvector,
						t_scene *scene);
t_scene					*initial(t_vars var);
t_scene					*scenenormalizer(t_scene *scene);
t_scene					*base_state_prep(t_scene *scene);
t_scene					*scenemake(t_vars var, char *rt);
t_scene					*resol_parser(char *start, t_scene *scene);
t_scene					*light_parser(char *start, t_scene *scene);
t_scene					*spot_parser(char *start, t_scene *scene);
t_scene					*plain_parser(char *start, t_scene *scene);
t_scene					*triangle_parser(char *start, t_scene *scene);
t_scene					*cylinder_parser(char *start, t_scene *scene);
t_scene					*camera_parser(char *start, t_scene *scene);
t_scene					*sphere_parser(char *start, t_scene *scene);
t_scene					*square_parser(char *start, t_scene *scene);
t_scene					*parser(char *line, t_scene *scene);
t_scene					*scenerotor(t_scene *scene);
t_matrix				*rotmatrixmaker();
t_matrix				*rotmatrix(t_coord *vector);
t_camera				*camera_installer(t_scene *scene, int flag);
t_vars					new_img_crtr(int flag, t_vars var);
t_vars					general_scene_prep(t_vars var, char *rt);

#endif
