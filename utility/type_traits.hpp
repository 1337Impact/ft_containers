/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:01:50 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/17 15:15:23 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft
{
    /*--------------------------------------------------------*/
    /*                      enable_if                         */
    /*--------------------------------------------------------*/
    template<bool B, class T = void>
    struct enable_if {};
    
    template<class T>
    struct enable_if<true, T> { typedef T type; };

    /*--------------------------------------------------------*/
    /*                      is_integral                       */
    /*--------------------------------------------------------*/


    template <class _Tp> struct _is_integral_base                     {static const bool      value = false;};
	template <>          struct _is_integral_base<bool>              {static const bool      value = true;};
	template <>          struct _is_integral_base<char>              {static const bool      value = true;};
	template <>          struct _is_integral_base<signed char>       {static const bool      value = true;};
	template <>          struct _is_integral_base<unsigned char>     {static const bool      value = true;};
	template <>          struct _is_integral_base<wchar_t>           {static const bool      value = true;};
	template <>          struct _is_integral_base<char16_t>          {static const bool      value = true;};
	template <>          struct _is_integral_base<char32_t>          {static const bool      value = true;};
	template <>          struct _is_integral_base<short>             {static const bool      value = true;};
	template <>          struct _is_integral_base<unsigned short>    {static const bool      value = true;};
	template <>          struct _is_integral_base<int>               {static const bool      value = true;};
	template <>          struct _is_integral_base<unsigned int>      {static const bool      value = true;};
	template <>          struct _is_integral_base<long>              {static const bool      value = true;};
	template <>          struct _is_integral_base<unsigned long>     {static const bool      value = true;};
	template <>          struct _is_integral_base<long long>         {static const bool      value = true;};
	template <>          struct _is_integral_base<unsigned long long>{static const bool      value = true;};
    
    template< class T >
    struct is_integral : public _is_integral_base<T>
    {};
}
