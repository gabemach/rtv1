/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:20:29 by gmachado          #+#    #+#             */
/*   Updated: 2020/03/11 12:12:39 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

void	draw(t_rt *rt)
{
	rt->screen = ft_memalloc(sizeof(t_screen));
	rt->screen->view = SDL_CreateTexture(rt->rend,
		SDL_GetWindowPixelFormat(rt->win),
		SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);
	SDL_LockTexture(rt->screen->view, NULL, &rt->screen->data, &rt->screen->pitch);
	rt->screen->pixel = (Uint32 *)rt->screen->data;
	create_rays(rt);
	SDL_UnlockTexture(rt->screen->view);
	SDL_RenderCopy(rt->rend, rt->screen->view, NULL, NULL);
	SDL_RenderPresent(rt->rend);
}

int	main(int ac, char **av)
{
	t_rt	*rt;
	
	if (!(rt = (t_rt*)ft_memalloc(sizeof(t_rt))))
		exit(0);
	SDL_Init(SDL_INIT_EVERYTHING);
	init(rt, "RTv1");
	init_viewport(rt);
	draw(rt);
	while (rt->quit == 0)
	{
		rt->state = SDL_GetKeyboardState(NULL);
		while (SDL_PollEvent(&rt->event))
			if (rt->event.type == SDL_QUIT || rt->state[SDL_SCANCODE_ESCAPE])
				rt->quit = 1;
		SDL_Delay(90);
	}
	free(rt);
	return (0);
}