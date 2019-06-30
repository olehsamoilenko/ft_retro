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

int		main(void)
{
	Engine *engine = new Engine();
	Renderer *gameRender = new Renderer();
	gameRender->render(*engine);
	return (0);
}