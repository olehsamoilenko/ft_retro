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


Renderer::Renderer() : _render_iterator(0), _player_press_key(0)
{

}

Renderer::~Renderer() {

}

Renderer::Renderer(Renderer const &inst) {
	*this = inst;
}

Renderer& Renderer::operator = (Renderer const &inst)
{
	_render_iterator = inst._render_iterator;
	return *this;
}

void	Renderer::_render_game(void)
{
	char hello[] = "GAME SCENE!";
	mvaddstr(GAME_SCENE_HEIGHT / 2, (GAME_SCENE_WIDTH - strlen(hello))/2, hello);
	box(_game, 0, 0);





	mvprintw(_render_iterator, 0, "X");
	wrefresh(_game);
}

void	Renderer::_render_info(void)
{
	char hello2[] = "PLAYER INFO!";
	mvaddstr( GAME_SCENE_HEIGHT + GAME_INFO_HEIGHT / 2, (GAME_INFO_WIDTH - strlen(hello2))/2, hello2);
	box(_info, 0, 0);
	wrefresh(_info);
}


void	Renderer::_init_game(void)
{
	this->_game = newwin(GAME_SCENE_HEIGHT, GAME_SCENE_WIDTH, 0, 0);
}


void	Renderer::_init_info(void)
{
	this->_info = newwin(GAME_INFO_HEIGHT, GAME_INFO_WIDTH, GAME_SCENE_HEIGHT, 0);
}


void	Renderer::render(Engine& engine)
{
	if (!initscr())
	{
		std::cout << "Error initialising ncurses" << std::endl;
		exit(1);
	}
	cbreak();
	curs_set(0);
	nodelay (stdscr, TRUE);
	keypad(stdscr, TRUE);

	refresh();

	this->_init_game();
	this->_init_info();
	_render_game();
	_render_info();

	std::clock_t old_time;
	std::clock_t new_time;
	std::clock_t delta_time;
	old_time = std::clock();


	while (_player_press_key != KEY_DOWN)
	{
		new_time = std::clock();

		delta_time = (new_time - old_time) / 1000;

		if (delta_time > 1000) {
			clear();
			refresh();

			old_time = new_time;
			_render_game();
			_render_info();

			int i = -1;
			while (++i < engine.getPlanes().getArrayLen()) {
				mvprintw(
						engine.getPlanes().getItem(i)->getX(),
						engine.getPlanes().getItem(i)->getY(),
						"X"
				);
			}

			_render_iterator++;
		}

		_player_press_key = getch();
	}



	delwin(_game);
	delwin(_info);

	endwin();
}
