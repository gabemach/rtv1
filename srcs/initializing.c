/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:35:35 by gmachado          #+#    #+#             */
/*   Updated: 2020/03/11 13:03:28 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

void	init_viewport(t_rt *rt)
{
	rt->campos.x = 0.0;
	rt->campos.y = 0.0;
	rt->campos.z = 0.0;
	rt->viewdir.x = 0.0;
	rt->viewdir.y = 0.0;
	rt->viewdir.z = 1.0;
	rt->screendist = 1.0f;
}

void	init(t_rt *rt, char *name)
{
	rt->win = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	rt->rend = SDL_CreateRenderer(rt->win, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_TARGETTEXTURE);
	SDL_SetRenderDrawColor(rt->rend, 169, 169, 169, 255);
	SDL_RenderClear(rt->rend);
	SDL_RenderPresent(rt->rend);
	rt->quit = 0;
}