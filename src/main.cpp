/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 10:43:17 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/30 10:43:19 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plane.hpp"
#include "Container.hpp"

int		main(void)
{
	Plane *tm1 = new Plane();
	Plane *tm2 = new Plane();
	Plane *tm3 = new Plane();

	Container c;
	c.push(tm1);
	c.push(tm2);
	c.push(tm3);
	g_ofs << c;


	return (0);
}
