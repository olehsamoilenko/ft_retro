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

Container const & Engine::getPlanes(void) const
{
	return (_planes);
}

void Engine::nextStep(void)
{
	// g_ofs << _planes;
	int i = -1;
	while (++i < _planes.getArrayLen())
		_planes.getItem(i)->moveUp();
	// g_ofs << _planes;
}

Engine::Engine(int planes)
{
	int i = -1;
	while (++i < planes)
		_planes.push(new Plane());
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
