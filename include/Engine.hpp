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

#include "Container.hpp"

class Engine
{
	public:
		Engine(int height, int width, int planes);
		Engine(Engine const &);
		Engine & operator=(Engine const &);
		virtual ~Engine(void);

		Container const & getPlanes(void) const;
		
		void nextStep(void);

	private:
		Engine(void);
		int _winHeight;
		int _winWidth;
		// container bullets
		Container _planes;
		// container asteroids
};

#endif
