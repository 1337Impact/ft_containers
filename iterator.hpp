/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:12:59 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/05 10:28:31 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
template< class Iter >
class reverse_iterator
: public Iter
{
public:
    typedef Iter        iterator_type;
    typedef typename Iter:: iterator_category;

public:
    reverse_iterator()
    {
        
    }
    explicit reverse_iterator( iterator_type x );
    template< class U >
    reverse_iterator( const reverse_iterator<U>& other );
};
}