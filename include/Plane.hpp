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

// delete
# include <fstream>
extern std::ofstream g_ofs;
// delete

#include "IItem.hpp"

class Plane : public IItem
{
	public:
		Plane(void);
		Plane(Plane const &);
		Plane & operator=(Plane const &);
		virtual ~Plane(void);

		Plane * clone(void) const;
		// void meleeAttack() const; // bonus
};

std::ostream & operator<<(std::ostream & o, Plane const &);

#endif
