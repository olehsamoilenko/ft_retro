/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkachano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:42:12 by mkachano          #+#    #+#             */
/*   Updated: 2019/06/30 13:42:18 by mkachano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"
#include <iostream>


Renderer::Renderer() : _some_data(0)
{

}

Renderer::~Renderer() {

}

Renderer::Renderer(Renderer const &inst) {
	*this = inst;
}

Renderer& Renderer::operator = (Renderer const &inst)
{
	_some_data = inst._some_data;
	return *this;
}

void	Renderer::render(void)
{
	const int width = GAME_SCENE_WIDTH;
	const int height = GAME_SCENE_HEIGHT;

	if (!initscr())
	{
		std::cout << "Error initialising ncurses" << std::endl;
		exit(1);
	}

	curs_set(0);
	refresh();

	this->_game = newwin(height, width, 0, 0);
	char hello[] = "GAME SCENE!";
	mvaddstr(height / 2, (width - strlen(hello))/2, hello);
	box(_game, 0, 0);

	this->_info = newwin(GAME_INFO_HEIGHT, GAME_INFO_WIDTH, GAME_SCENE_HEIGHT, 0);
	char hello2[] = "PLAYER INFO!";
	mvaddstr( GAME_SCENE_HEIGHT + GAME_INFO_HEIGHT / 2, (GAME_INFO_WIDTH - strlen(hello2))/2, hello2);
	box(_info, 0, 0);



	wrefresh(_game);
	wrefresh(_info);
	getch();

	delwin(_game);
	endwin();
}
