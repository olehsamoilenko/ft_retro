/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:08 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plane.hpp"
#include "AItem.hpp"

char Plane::getCharacter(void) const
{
	return 'P';
}

Plane * Plane::clone(void) const
{
	return (new Plane(*this));
}

void Plane::showInfo(std::ostream & o) const
{
	o << "Plane (" << _x << ", " << _y << ")";
}

Plane::Plane(int x, int y) : AItem(x, y)
{
	g_ofs << "* Plane created *" << std::endl;
}

Plane::~Plane(void)
{
	g_ofs << "* Plane dead *" << std::endl;
}

Plane & Plane::operator=(Plane const & src)
{
	if (this != &src)
	{

	}
	return (*this);
}

Plane::Plane(Plane const & src)
{
	*this = src;
}

