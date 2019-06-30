/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkachano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:42:41 by mkachano          #+#    #+#             */
/*   Updated: 2019/06/30 13:42:43 by mkachano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>

#ifndef RENDERER_HPP
#define RENDERER_HPP


class Renderer {

public:
	Renderer();
	~Renderer();
	Renderer(const Renderer &inst);
	Renderer  &operator = (Renderer const &inst);

	static const int GAME_SCENE_WIDTH = 100;
	static const int GAME_SCENE_HEIGHT = 45;
	static const int GAME_INFO_WIDTH = 100;
	static const int GAME_INFO_HEIGHT = 5;

	void    render(void);

private:
	WINDOW *_game;
	WINDOW *_info;

	int		_render_iterator;
	int		_player_press_key;

	void _render_game(void);
	void _render_info(void);

	void _init_game(void);
	void _init_info(void);

};


#endif
