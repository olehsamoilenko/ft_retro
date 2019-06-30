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

Asteroid * Asteroid::clone(void) const
{
	return (new Asteroid(*this));
}

char Asteroid::getCharacter(void) const
{
	return 'A';
}

void Asteroid::moveLeft(int limitX, int limitY)
{
	AItem::moveLeft(limitX, limitY);
	if (_y < 0)
		_y = limitY;
}

void Asteroid::showInfo(std::ostream & o) const
{
	o << "Asteroid (" << _x << ", " << _y << ")" << std::endl;
}

// std::ostream & operator<<(std::ostream & o, Asteroid const &)
// {
// 	o << "Asteroid" << std::endl;
// 	return (o);
// }

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

