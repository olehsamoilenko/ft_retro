/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IItem.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osamoile <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 20:40:29 by osamoile          #+#    #+#             */
/*   Updated: 2019/06/28 20:40:31 by osamoile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IITEM_HPP
# define IITEM_HPP

class IItem
{
	public:
		virtual ~IItem() {}
		virtual IItem* clone() const = 0;
};

#endif
