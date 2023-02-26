/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:25:53 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/18 18:33:37 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
namespace ft
{
	/*--------------------------------------------------------*/
	/*                        equal                           */
	/*--------------------------------------------------------*/
	template< class InputIt1, class InputIt2 >
	bool equal( InputIt1 first1,
		InputIt1 last1,
		InputIt2 first2 )
	{
		for (; first1 != last1; ++first1, ++first2){
			if (!(*first1 == *first2)) {
				return false;
			}
		}
		return true;
	}


	template< class InputIt1,
		  class InputIt2,
		  class BinaryPredicate >
	bool equal( InputIt1 first1,
			InputIt1 last1,
			InputIt2 first2,
			BinaryPredicate comp)
	{
		for (; first1 != last1; ++first1, ++first2){
			if (!comp(*first1, *first2)) {
				return false;
			}
		}
		return true;
	}

	/*--------------------------------------------------------*/
	/*               lexicographical_compare                  */
	/*--------------------------------------------------------*/
	template< class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2 ){

		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}


	template< class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
								InputIt2 first2, InputIt2 last2, Compare comp ){

		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
}