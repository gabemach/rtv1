/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmachado <gmachado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 17:59:56 by gmachado          #+#    #+#             */
/*   Updated: 2020/03/11 13:14:47 by gmachado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/rtv1.h"

bool RaySphereIntersection(t_ray *ray, t_sphere sphere)
{
	t_vec3 origintosphere = {sphere.position.x - ray->origin.x,
		sphere.position.y - ray->origin.y, sphere.position.z - ray->origin.z};
	float proj = origintosphere.x * ray->direction.x +
		origintosphere.y * ray->direction.y +
		origintosphere.z * ray->direction.z;
	t_vec3 distvec = {origintosphere.x - ray->direction.x * proj,
		origintosphere.y - ray->direction.y * proj,
		origintosphere.z - ray->direction.z * proj};
	float distancesq = distvec.x * distvec.x +
		distvec.y * distvec.y + distvec.z * distvec.z;
	float radiussq = sphere.radius*sphere.radius;
	if (distancesq > radiussq)
		return false;
	float newlength = proj - sqrtf(radiussq - distancesq);
	if (newlength < ray->length && newlength >0.0f)
	{
		ray->length = newlength;
		return (true);
	}
	return(false);
}

t_vec3 normalize(t_vec3 raydir)
{
	int l;
	int total;
	total = raydir.x * raydir.x + raydir.y * raydir.y + raydir.z * raydir.z;
	l = sqrt(total);
	t_vec3 normalize = {raydir.x / l, raydir.y / l, raydir.z /l};
	return (normalize);
}

void	create_rays(t_rt *rt)
{
	t_vec3 screenCenter = {rt->campos.x + rt->viewdir.x * rt->screendist,
		rt->campos.y + rt->viewdir.y * rt->screendist, rt->campos.z + rt->viewdir.z * rt->screendist};
	t_vec3 p0 = {screenCenter.x - 1.0f, screenCenter.y + 1.0f, screenCenter.z};
	t_vec3 p1 = {screenCenter.x + 1.0f, screenCenter.y + 1.0f, screenCenter.z};
	t_vec3 p2 = {screenCenter.x - 1.0f, screenCenter.y - 1.0f, screenCenter.z};
	t_vec3 temp = {0, 0, 10};
	t_sphere sphere = {temp, 2.0f};
	int x = 0;
	int y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			float u = (float)x / WIDTH;
			float v = (float)y / HEIGHT;
			t_vec3 point = {p0.x + (p1.x - p0.x)*u + (p2.x - p0.x)*v, p0.y + (p1.y - p0.y)*u + (p2.y - p0.y)*v,p0.z + (p1.z - p0.z)*u + (p2.z - p0.z)*v};
			t_vec3 raydir = {point.x - rt->campos.x, point.y - rt->campos.y, point.z - rt->campos.z};
			t_vec3 raydirnormalized = normalize(raydir);
			t_ray ray = {rt->campos, raydirnormalized, 10000000.0f};
			if (RaySphereIntersection(&ray, sphere) == true)
				rt->screen->pixel[x + (WIDTH * y)] = 0xff;
			else
				rt->screen->pixel[x + (WIDTH * y)] = 0x000000;
			x++;
		}
		y++;
	}
}