/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:08 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Asteroid.hpp"
#include "AItem.hpp"
#include "Renderer.hpp"

Asteroid * Asteroid::clone(void) const
{
	return (new Asteroid(*this));
}

char Asteroid::getCharacter(void) const
{
	return ('A');
}

void Asteroid::moveLeft(int limitX, int limitY)
{
	AItem::moveLeft();
	if (_y < 0)
		_y = Renderer::GAME_SCENE_WIDTH - 1;
}

void Asteroid::showInfo(std::ostream & o) const
{
	o << "Asteroid (" << _x << ", " << _y << ")";
}

Asteroid::Asteroid(int x, int y) : AItem(x, y)
{
	g_ofs << "* Asteroid created *" << std::endl;
}

Asteroid::~Asteroid(void)
{
	g_ofs << "* Asteroid dead *" << std::endl;
}

Asteroid & Asteroid::operator=(Asteroid const & src)
{
	if (this != &src)
	{

	}
	return (*this);
}

Asteroid::Asteroid(Asteroid const & src)
{
	*this = src;
}

