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

class Engine
{
	public:
		Engine(void);
		Engine(Engine const &);
		Engine & operator=(Engine const &);
		virtual ~Engine(void);

		// nextStep

	private:
		// container bullets
		// container enemies
		// container asteroids
};

#endif
