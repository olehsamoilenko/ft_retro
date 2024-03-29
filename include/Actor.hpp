/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Actor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:11 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:13 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTOR_HPP
# define ACTOR_HPP

#include "AItem.hpp"

class Bullet;
class Container;

class Actor : public AItem
{
	public:
		Actor(int x, int y);
		Actor(Actor const &);
		Actor & operator=(Actor const &);
		virtual ~Actor(void);

		Actor * clone(void) const;
		void showInfo(std::ostream & o) const;

		char getCharacter(void) const;
		int getLives(void) const;
		int getScore(void) const;
		void setScore(AItem * plane);
		void moveUp(void);
		void moveDown(void);

		void takeDamage(AItem * plane);

		AItem * shoot(void) const;

	private:
		Actor(void);

		int _lives;
		int _score;
};

std::ostream & operator<<(std::ostream & o, Actor const &);


#endif
