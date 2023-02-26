/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:12:59 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/25 10:04:43 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{

	/*--------------------------------------------------------*/
	/*                  iterator_traits                       */
	/*--------------------------------------------------------*/

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

	template< class T >
	struct iterator_traits<T*>
	{
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef T*									pointer;
		typedef T&									reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};

	template< class T >
	struct iterator_traits<const T*>
	{
		typedef T									value_type;
		typedef ptrdiff_t							difference_type;
		typedef const T*							pointer;
		typedef const T&							reference;
		typedef std::random_access_iterator_tag		iterator_category;
	};


	/*--------------------------------------------------------*/
	/*                  reverse_iterator                      */
	/*--------------------------------------------------------*/

	template< class Iter >
	class reverse_iterator
	{
	public:
		typedef Iter       											iterator_type;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;

	private:
		iterator_type _it;
	public:

		/*              constructor/destructor            */
	
		reverse_iterator()
		:_it(){
		}
	
		explicit reverse_iterator( iterator_type x )
		:_it(x){
		}
	
		template< class U >
		reverse_iterator( const reverse_iterator<U>& other )
		:_it(other._it){
		}

		~reverse_iterator(){}
	
		/*              assignement operators            */

		template< class U >
		reverse_iterator& operator=( const reverse_iterator<U>& other ){
			this->_it = other._it;
			return *this;
		}

		// base
		iterator_type base() const{
			return (_it);
		}

		/*                *,-> operators               */
		reference operator*() const{
			return *(base());
		}
		pointer operator->() const{
			return (_it.operator->());
		}

		/*                [] operators               */

		reference operator[]( difference_type n ) const{
			return (_it[n]);
		}

		/*          increment/decrement operators         */
	
		reverse_iterator& operator++(){
			--_it;
			return *this;
		}
		reverse_iterator& operator--(){
			--_it;
			return *this;
		}
		reverse_iterator operator++( int ){
			reverse_iterator tmp(*this);
			_it--;
			return tmp;
		}
		reverse_iterator operator--( int ){
			reverse_iterator tmp(*this);
			_it++;
			return tmp;
		}

		/*          Addition/Subtraction operators         */
	
		reverse_iterator operator+( difference_type n ) const{
			return (reverse_iterator(_it - n));
		}
		reverse_iterator operator-( difference_type n ) const{
			return (reverse_iterator(_it + n));
		}
		reverse_iterator& operator+=( difference_type n ){
			_it -= n;
			return (*this);
		}
		reverse_iterator& operator-=( difference_type n ){
			_it += n;
			return (*this);
		}
	};
	/*--------------------------------------------------------*/
	/*                 Non-member functions                   */
	/*--------------------------------------------------------*/


	/*          compartion operators            */
	template <class Iterator>  bool operator== (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		
		return (lhs.base() == rhs.base());
	}
	
	template <class Iterator>  bool operator!= (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return (lhs.base() != rhs.base());
	}
	
	template <class Iterator>  bool operator<  (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return (lhs.base() < rhs.base());
	}

	template <class Iterator>  bool operator<= (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return (lhs.base() <= rhs.base());
	}

	template <class Iterator>  bool operator>  (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return (lhs.base() > rhs.base());
	}

	template <class Iterator>  bool operator>= (const reverse_iterator<Iterator>& lhs,
			const reverse_iterator<Iterator>& rhs){
		return (lhs.base() >= rhs.base());
	}
	
	
	/*          Addition/Subtraction operators         */
	template< class Iter >
	reverse_iterator<Iter> operator+( 
				typename reverse_iterator<Iter>::difference_type n,
				const reverse_iterator<Iter>& it ){
		
		return (reverse_iterator<Iter>(it.base() + n));
	}

	template< class Iter >
	reverse_iterator<Iter> operator-( 
				typename reverse_iterator<Iter>::difference_type n,
				const reverse_iterator<Iter>& it ){

		return (reverse_iterator<Iter>(it.base() - n));
	}
	
}