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


Renderer::Renderer() : _render_iterator(0), _player_press_key(0), _speed(200)
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

void	Renderer::_render_game(Engine& engine)
{
	box(_game, 0, 0);

	// RENDER PLANES
	int i = -1;
	while (++i < engine.getPlanes().getArrayLen()) {
		if (engine.getPlanes().getItem(i))
		{
			mvaddch(
					engine.getPlanes().getItem(i)->getX(),
					engine.getPlanes().getItem(i)->getY(),
					engine.getPlanes().getItem(i)->getCharacter() | COLOR_PAIR(1)
			);
		}
	}

	i = -1;
	while (++i < engine.getAsteroids().getArrayLen()) {
		if (engine.getAsteroids().getItem(i))
		{
			mvaddch(
					engine.getAsteroids().getItem(i)->getX(),
					engine.getAsteroids().getItem(i)->getY(),
					engine.getAsteroids().getItem(i)->getCharacter() | COLOR_PAIR(1)
			);
		}
	}

	i = -1;
	while (++i < engine.getBullets().getArrayLen()) {
		if (engine.getBullets().getItem(i))
		{
			mvaddch(
					engine.getBullets().getItem(i)->getX(),
					engine.getBullets().getItem(i)->getY(),
					engine.getBullets().getItem(i)->getCharacter() | COLOR_PAIR(1)
			);
		}
	}

	mvaddch(
			engine.getActor()->getX(),
			engine.getActor()->getY(),
			engine.getActor()->getCharacter() | COLOR_PAIR(1)
	);

	wrefresh(_game);
}


void	Renderer::_update_speed(int key_press, Engine& engine)
{
	if (key_press == 43) {
		if (_speed > 100)
			_speed -= 100;
	}

	if (key_press == 45) {
		if (_speed < 900)
			_speed += 100;
	}
	_render_info(engine);
}

void	Renderer::_update_player_move(int key_press, Engine& engine)
{
	if (key_press == KEY_DOWN) {
		engine.getActor()->moveDown();
	}

	if (key_press == KEY_UP) {
		engine.getActor()->moveUp();
	}

	if (key_press == 32) {
		engine.shoot();
	}
}

void	Renderer::_render_info(Engine& engine)
{
	box(_info, 0, 0);
	mvwprintw(_info, 1, 1, "live: %d", engine.getActor()->getLives());
	mvwprintw(_info, 2, 1, "score: %d", engine.getActor()->getScore());
	mvwprintw(_info, 3, 1, "speed: %d", (1000 - _speed));

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
void	Renderer::_render_final(Engine& engine)
{
	char hello[] = "=======================================";
	char hello2[] = " YOUR SCORE ";
	mvaddstr(GAME_SCENE_HEIGHT / 2, (GAME_SCENE_WIDTH - strlen(hello))/2, hello);
	mvaddstr(GAME_SCENE_HEIGHT / 2 + 1, (GAME_SCENE_WIDTH - strlen(hello2))/2, hello2);
	mvwprintw(_game, GAME_SCENE_HEIGHT / 2 + 2, (GAME_SCENE_WIDTH / 2) - 1, "%d", engine.getActor()->getScore());
	mvaddstr(GAME_SCENE_HEIGHT / 2 + 3, (GAME_SCENE_WIDTH - strlen(hello))/2, hello);
	wrefresh(_game);

	int c = 0;
	while (c != 27) {
		c = getch();

		if (c == 32)
			break;
	}
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
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	scrollok(stdscr, TRUE);
	refresh();

	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_BLACK);
	attron(COLOR_PAIR(2));


	this->_init_game();
	this->_init_info();

	wbkgd(_game, COLOR_PAIR(1));
	wbkgd(_info, COLOR_PAIR(1));


	_render_game(engine);
	_render_info(engine);

	std::clock_t old_time;
	std::clock_t new_time;
	std::clock_t delta_time;

	old_time = std::clock();


	while (_player_press_key != 27)
	{
		_update_speed(_player_press_key, engine);
		_update_player_move(_player_press_key, engine);

		new_time = std::clock();
		delta_time = (new_time - old_time) / 1000;

		if ((int)delta_time > _speed) {
			clear();
			refresh();
			old_time = new_time;
			_render_game(engine);
			_render_info(engine);
			engine.nextStep();
			_render_iterator++;
		}

		if (engine.getActor()->getLives() == 0) {
			_player_press_key = 27;
		} else {
			_player_press_key = getch();
		}

	}


	clear();
	refresh();

	attron(COLOR_PAIR(1));
	_render_final(engine);


	delwin(_game);
	delwin(_info);

	clear();
	getch();
	endwin();

	endwin();
}
