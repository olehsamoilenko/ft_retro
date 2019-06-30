/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 11:21:53 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/30 11:21:54 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



// #include "Plane.hpp"
// #include "Container.hpp"
// #include "Engine.hpp"
// #include "Renderer.hpp"

// int		main(void)
// {
// 	Renderer *gameRender = new Renderer();
// 	Engine e;
// 	g_ofs << e.getPlanes();
// 	e.shoot();

	
// 	g_ofs << e.getBullets();
// 	e.nextStep();
// 	e.nextStep();
// 	g_ofs << e.getBullets();

// 	return (0);
// }

#include "Engine.hpp"
#include "Plane.hpp"
#include "Asteroid.hpp"
#include "Renderer.hpp"
#include <cmath>

Container const & Engine::getBullets(void) const
{
	return (_bullets);
}

Container const & Engine::getPlanes(void) const
{
	return (_planes);
}

Container const & Engine::getAsteroids(void) const
{
	return (_asteriods);
}

void Engine::shoot(void)
{
	_bullets.push(_actor->shoot());
}

void Engine::nextStep(void)
{
	int i = -1;
	while (++i < _planes.getArrayLen())
	{
		if (_planes.getItem(i))
		{
			_planes.getItem(i)->moveLeft();
			if (_planes.getItem(i)->getY() < 0)
				_planes.kill(i);
		}
	}
	i = -1;
	while (++i < _asteriods.getArrayLen())
		_asteriods.getItem(i)->moveLeft();

	i = -1;
	while (++i < _bullets.getArrayLen())
	{
		if (_bullets.getItem(i))
		{
			_bullets.getItem(i)->moveRight();
			if (_bullets.getItem(i)->getX() < 0)
				_bullets.kill(i);
		}
	}
}

Engine::Engine(void)
{
	for (int i = 0; i < 10; i++)
	{
		_planes.push(new Plane(
			rand() % (Renderer::GAME_SCENE_HEIGHT - 1) + 1,
			Renderer::GAME_SCENE_WIDTH - 1));
	}
	for (int i = 0; i < 30; i++)
	{
		_asteriods.push(new Asteroid(
			rand() % (Renderer::GAME_SCENE_HEIGHT - 1) + 1,
			rand() % Renderer::GAME_SCENE_WIDTH - 1
			));
	}
	_actor = new Actor(Renderer::GAME_INFO_HEIGHT / 2, 0);
}

Engine::~Engine(void)
{

}

Engine & Engine::operator=(Engine const & src)
{
	if (this != &src)
	{
		// ?
	}
	return (*this);
}

Engine::Engine(Engine const & src)
{
	*this = src;
}
