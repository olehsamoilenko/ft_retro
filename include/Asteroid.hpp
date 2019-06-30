/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Asteroid.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:11 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:13 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASTEROID_HPP
# define ASTEROID_HPP

#include "AItem.hpp"

class Asteroid : public AItem
{
	public:
		Asteroid(int x, int y);
		Asteroid(Asteroid const &);
		Asteroid & operator=(Asteroid const &);
		virtual ~Asteroid(void);

		Asteroid * clone(void) const;
		void showInfo(std::ostream & o) const;
		void moveLeft(void);
		char getCharacter(void) const;

	private:
		Asteroid(void);
};

#endif
