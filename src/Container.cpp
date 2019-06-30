/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:48:30 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:48:32 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Container.hpp"
#include "AItem.hpp"

int Container::getCount() const
{
	return (_arrayLen);
}

int Container::getArrayLen(void) const
{
	return (_arrayLen);
}

AItem * Container::getItem(int n) const
{
	if (n < 0 || n > _arrayLen)
		return (0);
	else
		return (_items[n]);
}

int Container::push(AItem* item)
{
	if (_arrayLen == 0)
	{
		_items = new AItem*[1];
		_items[0] = item;
	}
	else
	{
		int i = -1;
		while (++i < _arrayLen)
		{
			if (_items[i] == item)
			{
				std::cout << "*item already exist in container*" << std::endl;
				return (_arrayLen);
			}
		}
		i = -1;
		while (++i < _arrayLen)
		{
			if (_items[i] == nullptr)
			{
				_items[i] = item;
				return (_arrayLen);
			}
		}
		AItem ** tmp = new AItem*[_arrayLen + 1];
		i = -1;
		while (++i < _arrayLen)
			tmp[i] = _items[i];
		tmp[_arrayLen] = item;
		delete [] _items;
		_items = tmp;
	}
	_arrayLen += 1;
	return (_arrayLen);
}

bool Container::kill(int id)
{
	if (id < 0 || id >= _arrayLen || _items[id] == nullptr)
		return (false);
	else
	{
		delete _items[id];
		_items[id] = nullptr;
		return (true);
	}
}

std::ostream & operator<<(std::ostream & o, Container const & src)
{
	o << "Container (" << src.getArrayLen() << " elements):" << std::endl;
	int i = -1;
	while (++i < src.getArrayLen())
	{
		AItem * item;
		o << "\t";
		// o << *src.getItem(i);
		if ( (item = src.getItem(i)) != nullptr )
			item->showInfo(o);
		else
			o << "empty" << std::endl;
		// o << std::endl;
	}
	return (o);
}

Container::Container(void) : _arrayLen(0)
{

}

Container::~Container(void)
{
	int i = -1;
	if (_arrayLen != 0)
	{
		while (++i < _arrayLen)
			delete _items[i];
		delete [] _items;
	}
}

Container & Container::operator=(Container const & src)
{
	if (this != &src)
	{
		int i = -1;
		if (_arrayLen != 0)
		{
			while (++i < _arrayLen)
				delete _items[i];
			delete [] _items;
			_arrayLen = src._arrayLen;
			_items = new AItem*[_arrayLen];
			i = -1;
			while (++i < _arrayLen)
				_items[i] = src._items[i]->clone();
		}
	}
	return (*this);
}

Container::Container(Container const & src)
{
	*this = src;
}