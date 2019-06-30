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
#include "Renderer.hpp"

//int		main(void)
//{
//	Engine e(5);
//
//	// e.push(new Plane());
//	// e.push(new Plane());
//	// e.push(new Plane());
//
//	g_ofs << e.getPlanes();
//	e.nextStep();
//	g_ofs << e.getPlanes();
//
//	// c.kill(0);
//	// c.kill(1);
//	// // c.kill(2);
//	// c.kill(3);
//
//
//
//	// g_ofs << c;
//	system("leaks ft_retro > leaks.txt");
//
//	return (0);
//}


int		main(void)
{


	Engine *engine = new Engine();

//	 e->push(new Plane());
//	 e->push(new Plane());
//	 e->push(new Plane());

	Renderer *gameRender = new Renderer();

	gameRender->render(*engine);

	return (0);
}