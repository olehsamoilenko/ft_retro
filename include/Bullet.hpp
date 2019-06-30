/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bullet.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:11 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:13 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLET_HPP
# define BULLET_HPP

#include "AItem.hpp"

class Bullet : public AItem
{
	public:
		Bullet(int x, int y);
		Bullet(Bullet const &);
		Bullet & operator=(Bullet const &);
		virtual ~Bullet(void);

		Bullet * clone(void) const;
		void showInfo(std::ostream & o) const;
		char getCharacter(void) const;

	private:
		Bullet(void);
};

#endif
