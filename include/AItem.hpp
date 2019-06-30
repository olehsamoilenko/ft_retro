/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AItem.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:40:29 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:40:31 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AITEM_HPP
# define AITEM_HPP

// # include <iostream>

// delete
# include <fstream>
extern std::ofstream g_ofs;
// delete

class AItem
{
	public:
		virtual ~AItem();
		virtual AItem* clone() const = 0;
		virtual void showInfo(std::ostream & o) const = 0;

		AItem(void);
		AItem(AItem const & src);
		AItem & operator=(AItem const & src);
		AItem(int x, int y);

		int getX(void) const;
		int getY(void) const;

		virtual void moveUp(int limitX, int limitY);
		virtual void moveDown(int limitX, int limitY);
		virtual void moveLeft(int limitX, int limitY);
		virtual void moveRight(int limitX, int limitY);

		virtual char getCharacter(void) const = 0;
	
	protected: // private ?
		int _x;
		int _y;
};

// std::ostream & operator<<(std::ostream & o, AItem const &);

#endif
