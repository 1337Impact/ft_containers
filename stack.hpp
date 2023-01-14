/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:58:32 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/14 11:22:58 by mbenkhat         ###   ########.fr       */
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
		:this->c(other.c){
		}
		
		~stack(){
		}

		//Member functions
		bool empty() const{
			return (this->c.empty());
		}

		size_type size() const{
			return (this->c.size());
		}

		value_type& top(){
			this->c[this->c.back()];
		}

		const value_type& top() const{
			this->c[this->c.back()];
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
	friend bool operator==(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container == rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator!=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container != rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container < rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator<=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container <= rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container > rhs.container);
	}

	template<typename stack_type, typename container_type>
	friend bool operator>=(Stack<stack_type, container_type> const &lhs, Stack<stack_type, container_type> const &rhs) {
		return (lhs.container >= rhs.container);
	}
};

}

} // namespace ft
