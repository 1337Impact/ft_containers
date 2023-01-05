/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:32:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/05 10:36:59 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iterator>

namespace ft
{
template< class Iter >
struct iterator_traits
{
public:
    typedef typename Iter::value_type			value_type;
    typedef typename Iter::difference_type		difference_type;
    typedef typename Iter::pointer				pointer;
    typedef typename Iter::reference			reference;
    typedef typename Iter::iterator_category	iterator_category;
};
}

// template <class T>
// class iterator_traits<T*>
// {
// public:
//     typedef typename Iter::value_type			value_type;
//     typedef typename Iter::difference_type		difference_type;
//     typedef typename Iter::pointer				pointer;
//     typedef typename Iter::reference			reference;
//     typedef typename Iter::iterator_category	iterator_category;
// };

// template <class T>
// class iterator_traits<const T*>
// {
// public:
//     typedef typename Iter::value_type			value_type;
//     typedef typename Iter::difference_type		difference_type;
//     typedef typename Iter::pointer				pointer;
//     typedef typename Iter::reference			reference;
//     typedef typename Iter::iterator_category	iterator_category;
// };
// }