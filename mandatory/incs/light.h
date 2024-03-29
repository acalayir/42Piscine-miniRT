
#ifndef LIGHT_H
# define LIGHT_H

# include "ray.h"
# include "object.h"
# include "three_value.h"

typedef struct s_ambient
{
	double	ratio;
	t_rgb	color;
}	t_ambient;

typedef struct s_diffuse
{
	double	kd;
}	t_diffuse;

typedef struct s_specular
{
	double	ks;
	double	spec;
	int		n;
}	t_specular;

typedef struct s_light
{
	t_point			point;
	t_rgb			rgb;
	t_ambient		ambient;
	t_diffuse		diffuse;
	t_specular		specular;
	struct s_light	*next;
}	t_light;

void	cal_diffuse(t_hit hit, t_light *light);
void	cal_pixel_color(t_hit hit,
			t_hit hit_shadow, t_light *light, t_rgb *color);
int		get_argb(t_hit hit, t_light *light, t_object *obj);

#endif