/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Engine.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 11:22:04 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/30 11:22:05 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_HPP
# define ENGINE_HPP

#include "Actor.hpp"
#include "Container.hpp"

class Engine
{
	public:
		Engine(void);
		Engine(Engine const &);
		Engine & operator=(Engine const &);
		virtual ~Engine(void);

		Container const & getPlanes(void) const;
		Container const & getAsteroids(void) const;
		Container const & getBullets(void) const;
		Actor * getActor(void) const;
		void nextStep(void);
		void shoot(void);

	private:
		Actor *		_actor;
		Container	_planes;
		Container	_asteriods;
		Container	_bullets;
};

#endif
