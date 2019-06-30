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

#include "Engine.hpp"

#include "Plane.hpp"
#include "Asteroid.hpp"

#include <cmath>

// int		main(void)
// {
// 	Renderer *gameRender = new Renderer();
// 	Engine e(gameRender->GAME_SCENE_HEIGHT, gameRender->GAME_SCENE_WIDTH, 5);
// 	g_ofs << e.getPlanes();
// 	e.shoot();

	
// 	g_ofs << e.getBullets();
// 	e.nextStep();
// 	e.nextStep();
// 	g_ofs << e.getBullets();

// 	return (0);
// }

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
			_planes.getItem(i)->moveLeft(_winHeight, _winWidth);
			if (_planes.getItem(i)->getY() < 0)
				_planes.kill(i);
		}
	}
	i = -1;
	while (++i < _asteriods.getArrayLen())
		_asteriods.getItem(i)->moveLeft(_winHeight, _winWidth);

	i = -1;
	while (++i < _bullets.getArrayLen())
	{
		if (_bullets.getItem(i))
		{
			_bullets.getItem(i)->moveRight(_winHeight, _winWidth);
			if (_bullets.getItem(i)->getX() < 0)
				_bullets.kill(i);
		}
	}
}

Engine::Engine(int height, int width, int planes)
{
	_winHeight = height;
	_winWidth = width;
	int i = -1;
	while (++i < 10)
		_planes.push(new Plane(rand() % _winHeight, _winWidth));
	i = -1;
	while (++i < 30)
		_asteriods.push(new Asteroid(rand() % _winHeight, rand() % _winWidth));
	_actor = new Actor(_winHeight / 2, 0);
	g_ofs << _planes;
	_planes.kill(5);
	nextStep();
	g_ofs << _planes;
}

Engine::~Engine(void)
{
	// g_ofs << "* marine dead *" << std::endl;
}

Engine & Engine::operator=(Engine const & src)
{
	if (this != &src)
	{

	}
	return (*this);
}

Engine::Engine(Engine const & src)
{
	*this = src;
}
