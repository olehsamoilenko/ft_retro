/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AItem.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:08 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AItem.hpp"

std::ofstream g_ofs("log.txt"); // here ?

int AItem::getX(void) const
{
	return (_x);
}

int AItem::getY(void) const
{
	return (_y);
}

void AItem::moveUp(void)
{
	_x -= 1;
}

void AItem::moveDown(void)
{
	_x += 1;
}

void AItem::moveLeft(void)
{
	_y -= 1;
}

void AItem::moveRight(void)
{
	_y += 1;
}

AItem::AItem(int x, int y)
{
	_x = x;
	_y = y;
}

AItem::AItem(void)
{

}


AItem::~AItem(void)
{

}

AItem & AItem::operator=(AItem const & src)
{
	if (this != &src)
	{
		_x = src._x;
		_y = src._y;
	}
	return (*this);
}

AItem::AItem(AItem const & src)
{
	*this = src;
}

