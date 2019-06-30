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

#include "AItem.hpp"

class Plane : public AItem
{
	public:
		Plane(void);
		Plane(Plane const &);
		Plane & operator=(Plane const &);
		virtual ~Plane(void);

		Plane * clone(void) const;
		void showInfo(std::ostream & o) const;
};

// std::ostream & operator<<(std::ostream & o, Plane const &);

#endif
