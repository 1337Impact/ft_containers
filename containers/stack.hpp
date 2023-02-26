/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:32 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/18 12:19:50 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "vector.hpp"


namespace ft
{


template <class T, class Container = ft::vector<T> >
class stack
{
	public:
		typedef typename Container::value_type		value_type;
		typedef Container							container_type;
		typedef typename Container::size_type		size_type;


		// Constructor/Destructor
		explicit stack (const container_type& ctnr = container_type())
		:c(ctnr){
		}
		
		stack( const stack& other )
		:c(other.c){
		}
		
		~stack(){
		}

		stack& operator=( const stack& other ){
			this->c = other.c;
			return *this;
		}

		//Member functions
		bool empty() const{
			return (this->c.empty());
		}

		size_type size() const{
			return (this->c.size());
		}

		value_type& top(){
			return this->c[this->c.back()];
		}

		const value_type& top() const{
			return this->c[this->c.back()];
		}

		void push (const value_type& val){
			this->c.push_back(val);
		}

		void pop(){
			this->c.pop_back();
		}
		
	protected:
		container_type c;



	//Non-member functions
	template<typename stack_type, typename container_type>
	friend bool operator==(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c == rhs.c);
	}

	template<typename stack_type, typename container_type>
	friend bool operator!=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c != rhs.c);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c < rhs.c);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c <= rhs.c);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c > rhs.c);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>=(stack<stack_type, container_type> const &lhs, stack<stack_type, container_type> const &rhs) {
		return (lhs.c >= rhs.c);
	}
};

} // namespace ft
