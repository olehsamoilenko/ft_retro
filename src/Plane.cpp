/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:08 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plane.hpp"

std::ofstream g_ofs("log.txt"); // here ?

Plane * Plane::clone(void) const
{
	return (new Plane(*this));
}

std::ostream & operator<<(std::ostream & o, Plane const &)
{
	o << "Plane" << std::endl;
	return (o);
}

Plane::Plane(void)
{
	g_ofs << "* plane created *" << std::endl;
}

Plane::~Plane(void)
{
	g_ofs << "* plane dead *" << std::endl;
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

