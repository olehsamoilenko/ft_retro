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

Engine::Engine(void)
{
	// g_ofs << "* marine created *" << std::endl;
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
