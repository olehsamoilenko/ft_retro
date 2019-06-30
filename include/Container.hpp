/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Container.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:48:35 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:48:36 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Container_HPP
# define Container_HPP

# include <iostream>

class IItem;

class Container
{
	public:
		Container(void);
		Container(Container const & src);
		Container & operator=(Container const & src);
		~Container(void);

		int getArrayLen() const;
		int getCount() const;
		IItem * getItem(int id) const;
		int push(IItem * item);

	private:
		int _arrayLen;
		IItem ** _items;
		// void _show(void);
};

std::ostream & operator<<(std::ostream & o, Container const &);

#endif
