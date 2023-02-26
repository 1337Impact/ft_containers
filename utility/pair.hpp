/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 11:24:30 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/17 18:37:23 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft
{

	/*--------------------------------------------------------*/
	/*                       std::pair                        */
	/*--------------------------------------------------------*/
	template<
		class T1,
		class T2
	> struct pair{
		public:
			typedef T1	first_type;
			typedef T2	second_type;
		public:
			first_type 	first;
			second_type second;

		pair()
		:first(), second(){
			
		}

		pair (const first_type& a, const second_type& b)
		:first(a), second(b){
			
		}

		template<class U, class V>
		pair (const pair<U,V>& pr)
		:first(pr.first), second(pr.second){
			
		}

		pair& operator= (const pair& pr){
			this->first = pr.first;
			this->second = pr.second;
			return *this;
		}
	};

	/*--------------------------------------------------------*/
	/*                       make_pair                        */
	/*--------------------------------------------------------*/
	template< class T1, class T2 >
	pair<T1, T2> make_pair( T1 t, T2 u ){
		return (pair<T1, T2>(t, u));
	}


	/*--------------------------------------------------------*/
	/*                       operators                        */
	/*--------------------------------------------------------*/

	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first <= rhs.first && lhs.second <= rhs.second);
	}

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first > rhs.first && lhs.second > rhs.second);
	}

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
		return (lhs.first >= rhs.first && lhs.second >= rhs.second);
	}

} // namespace ft