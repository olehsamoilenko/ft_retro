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
// 	// g_ofs << e.getBullets();
// 	// g_ofs << e.getPlanes();

// 	for (int i = 0; i < 10; i++)
// 	{
// 		// e.getActor()->moveDown();
// 		// e.shoot();
// 		e.nextStep();

// 		// g_ofs << e.getBullets();
// 		g_ofs << e.getPlanes();
// 	}
	
// 	// e.shoot();

	
// 	// g_ofs << e.getBullets();
// 	// e.nextStep();
// 	// e.nextStep();
// 	// g_ofs << e.getBullets();

// 	system ("leaks ft_retro > leaks.txt");

// 	return (0);
// }


#include "Engine.hpp"
#include "Plane.hpp"
#include "Asteroid.hpp"
#include "Renderer.hpp"
#include <cmath>

Actor * Engine::getActor(void) const
{
	return (_actor);
}

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

	/* move planes */
	for (int i = 0; i < _planes.getArrayLen(); i++)
	{
		if (_planes.getItem(i))
		{
			_planes.getItem(i)->moveLeft();
			if (_planes.getItem(i)->getY() < 0)
			{
				g_ofs << "* ";
				_planes.getItem(i)->showInfo(g_ofs);
				g_ofs << " out of map *" << std::endl;

				_planes.kill(i);
			}
		}
	}

	/* create new planes */
	int planes = rand() % 2;
	for (int i = 0; i < planes; i++)
	{
		_planes.push(new Plane(
			rand() % (Renderer::GAME_SCENE_HEIGHT - 2) + 1,
			Renderer::GAME_SCENE_WIDTH - 2));
	}

	/* move asteroids */
	for (int i = 0; i < _asteriods.getArrayLen(); i++)
	{
		_asteriods.getItem(i)->moveLeft();
	}

	// /* move bullets */
	for (int i = 0; i < _bullets.getArrayLen(); i++)
	{
		if (_bullets.getItem(i))
		{
			_bullets.getItem(i)->moveRight();
			if (_bullets.getItem(i)->getX() < 0)
			{
				g_ofs << "* ";
				_bullets.getItem(i)->showInfo(g_ofs);
				g_ofs << " out of map *" << std::endl;

				_bullets.kill(i);
			}
		}
	}

	/* check bullet-plane colision */
	for (int i = 0; i < _planes.getArrayLen(); i++)
	{
		if (_planes.getItem(i))
		{
			for (int j = 0; j < _bullets.getArrayLen(); j++)
			{
				if (_bullets.getItem(j) &&
					_bullets.getItem(j)->getX() == _planes.getItem(i)->getX() &&
					_bullets.getItem(j)->getY() >= _planes.getItem(i)->getY())
					{
						g_ofs << "* colision: ";
						_bullets.getItem(j)->showInfo(g_ofs);
						g_ofs << " and ";
						_planes.getItem(i)->showInfo(g_ofs);
						g_ofs << " *" << std::endl;

						_bullets.kill(j);
						_planes.kill(i);
						break ;
					}
			}
		}
	}
}

Engine::Engine(void)
{
	srand(clock());
	for (int i = 0; i < 30; i++)
	{
		_asteriods.push(new Asteroid(
			rand() % (Renderer::GAME_SCENE_HEIGHT - 2) + 1,
			rand() % (Renderer::GAME_SCENE_WIDTH - 1)
			));
	}
	_actor = new Actor(Renderer::GAME_SCENE_HEIGHT / 2, 1);
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
