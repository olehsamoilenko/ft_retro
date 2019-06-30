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
	const int width = 50;
	const int height = 20;
	const int lines = 50;
	const int cols = 50;


	if (!initscr())
	{
		std::cout << "Error initialising ncurses" << std::endl;
		exit(1);
	}

	curs_set(0);
	refresh();


	int offsetx = (lines - width) / 2;
	int offsety = (cols - height) / 2;

	this->_window = newwin(height, width, offsety, offsetx);

	char hello[] = "Hello, world!";

	mvaddstr(lines / 2, (cols - strlen(hello))/2, hello);
	box(_window, 0, 0);

	wrefresh(_window);
	getch();

	delwin(_window);
	endwin();
}
