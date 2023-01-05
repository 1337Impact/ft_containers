/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:32 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/12/20 15:20:23 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <deque>

template <class T, class Container = deque<T> >
class stack
{
public:
	typedef Container							container_type;
	typedef typename Container::value_type		value_type;
	typedef typename Container::size_type		size_type;
	// typedef typename Container::reference		reference;
	// typedef typename Container::const_reference	const_reference;

	explicit stack (const container_type& ctnr = container_type())
	{
		/
	}
	stack( const stack& other )
	{
	}
};
