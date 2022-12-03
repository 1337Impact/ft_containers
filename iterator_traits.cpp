/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:32:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/12/03 15:48:30 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iterator>

template <class Iter>
class iterator_traits
{
public:
    typedef typename Iter::difference_type		difference_type;
    typedef typename Iter::value_type			value_type;
    typedef typename Iter::pointer				pointer;
    typedef typename Iter::reference			reference;
    typedef typename Iter::iterator_category	iterator_category;
};

template <class T> class iterator_traits<T*>;
template <class T> class iterator_traits<const T*>;
