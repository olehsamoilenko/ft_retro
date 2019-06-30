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
#include "Engine.hpp"

int		main(void)
{
	Engine e(100, 10, 3);

	// e.push(new Plane());
	// e.push(new Plane());
	// e.push(new Plane());

	g_ofs << e.getPlanes();
	e.nextStep();
	g_ofs << e.getPlanes();

	// c.kill(0);
	// c.kill(1);
	// // c.kill(2);
	// c.kill(3);



	// g_ofs << c;
	system("leaks ft_retro > leaks.txt");

	return (0);
}
