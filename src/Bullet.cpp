/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:08 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bullet.hpp"
#include "AItem.hpp"

char Bullet::getCharacter(void) const
{
	return 'B';
}

Bullet * Bullet::clone(void) const
{
	return (new Bullet(*this));
}

void Bullet::showInfo(std::ostream & o) const
{
	o << "Bullet (" << _x << ", " << _y << ")" << std::endl;
}

// std::ostream & operator<<(std::ostream & o, Bullet const &)
// {
// 	o << "Bullet" << std::endl;
// 	return (o);
// }

Bullet::Bullet(int x, int y) : AItem(x, y)
{
	g_ofs << "* Bullet created *" << std::endl;
}

Bullet::~Bullet(void)
{
	g_ofs << "* Bullet dead *" << std::endl;
}

Bullet & Bullet::operator=(Bullet const & src)
{
	if (this != &src)
	{

	}
	return (*this);
}

Bullet::Bullet(Bullet const & src)
{
	*this = src;
}

