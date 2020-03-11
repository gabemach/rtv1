/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:15:22 by gmachado          #+#    #+#             */
/*   Updated: 2020/03/11 12:41:27 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_timer.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
#include <stdbool.h>

typedef struct		s_vec3
{
					float x; 
					float y; 
					float z;
} 					t_vec3;

typedef struct		s_sphere
{
	t_vec3			position;
	float 			radius;
}					t_sphere;

typedef struct		s_ray
{
	t_vec3 			origin;
	t_vec3			direction;
	float 			length;
}					t_ray;

typedef struct		s_screen
{
	SDL_Texture		*view;
	void			*data;
	int				pitch;
	Uint32			*pixel;
}					t_screen;

typedef struct		s_rt
{
	SDL_Window		*win;
	SDL_Renderer	*rend;
	SDL_Surface		*surf;
	SDL_Event		event;
	const Uint8		*state;
	int				quit;
	t_screen		*screen;
	t_vec3			campos;
	t_vec3			viewdir;
	float			screendist;
}					t_rt;

void	init(t_rt *rt, char *name);
void	create_rays(t_rt *rt);
void	init_viewport(t_rt *rt);

# define HEIGHT 600
# define WIDTH	600
# define INF	INFINITY

#endif