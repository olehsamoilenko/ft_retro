/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:08 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Actor.hpp"
#include "AItem.hpp"

#include "Container.hpp"
#include "Bullet.hpp"
#include "Renderer.hpp"

void Actor::moveUp(void)
{
	if (_x > 1)
		AItem::moveUp();
}

void Actor::moveDown(void)
{
	if (_x < Renderer::GAME_SCENE_HEIGHT - 1)
		AItem::moveDown();
}

char Actor::getCharacter(void) const
{
	return ('A');
}

Actor * Actor::clone(void) const
{
	return (new Actor(*this));
}

void Actor::showInfo(std::ostream & o) const
{
	o << "Actor (" << _x << ", " << _y << ")" << std::endl;
}

AItem * Actor::shoot(void) const
{
	return (new Bullet(_x, _y));
}

Actor::Actor(int x, int y) : AItem(x, y)
{
	g_ofs << "* Actor created *" << std::endl;
}

Actor::Actor(void) //: AItem()
{

}

Actor::~Actor(void)
{
	g_ofs << "* Actor dead *" << std::endl;
}

Actor & Actor::operator=(Actor const & src)
{
	if (this != &src)
	{
		// ?
	}
	return (*this);
}

Actor::Actor(Actor const & src)
{
	*this = src;
}

