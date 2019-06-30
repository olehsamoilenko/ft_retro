/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plane.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:44:11 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:44:13 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_HPP
# define PLANE_HPP

#include "AItem.hpp"

class Plane : public AItem
{
	public:
		Plane(int x, int y);
		Plane(Plane const &);
		Plane & operator=(Plane const &);
		virtual ~Plane(void);

		Plane * clone(void) const;
		void showInfo(std::ostream & o) const;

		char getCharacter(void) const;

	private:
		Plane(void);
};

#endif
