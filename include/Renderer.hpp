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

#ifndef RENDERER_HPP
#define RENDERER_HPP

#define GAME_SCENE_WIDTH 100
#define GAME_SCENE_HEIGHT 45

#define GAME_INFO_WIDTH 100
#define GAME_INFO_HEIGHT 5

class Renderer {

public:
	Renderer();
	~Renderer();
	Renderer(const Renderer &inst);
	Renderer  &operator = (Renderer const &inst);
	void    render( void );

private:
	WINDOW *_window;
	WINDOW *_info;
	int 	_some_data;

};


#endif
