/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:04:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/08 21:22:16 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <utility>
#include "bst.hpp"
#include <vector>
#include <stdexcept>


namespace ft
{

template <class Iter>
class MapIterator
{
public:
	typedef Iter 					tree_type;
	typedef	typename Iter::pair_type pair_type;
	typedef typename Iter::Node 	node;
	typedef pair_type&				reference;
	typedef pair_type*				pointer;
	typedef std::ptrdiff_t 			difference_type;
	typedef typename tree_type::mapper	iterator_mapper;
	

public:
	tree_type _tree;
	iterator_mapper mapper;
	
public:
	MapIterator(){}
	MapIterator(const tree_type &tree ):_tree(tree)
	{
	}
	// MapIterator(const iterator_mapper &mapper ):_tree(tree)
	// {
	// }
	MapIterator(const MapIterator &other)
	:_tree(other._tree){}
	~MapIterator(){}
	MapIterator & operator = (const MapIterator &other)
	{
		this->_tree = other._tree;
		return (*this);
	}
	bool operator==(const MapIterator & other)
	{
		return (this->_tree.v_it == other._tree.v_it);
	}
	bool operator!=(const MapIterator & other)
	{
		return (this->_tree.v_it != other._tree.v_it);
	}
	reference operator*(void)
	{
		return (*(*this->_tree.v_it));
	}
	pointer operator->()
	{
		return (*(this->_tree.v_it.base()));
	}
	
	MapIterator operator++ (int)
	{
		MapIterator<tree_type> tmp(*this);
		this->_tree.v_it++;
		return (tmp);
	}
	MapIterator operator++ (void)
	{
		++this->_tree.v_it;
		return (*this);
	}
	MapIterator operator-- (int)
	{
		MapIterator<tree_type> tmp(*this);
		this->_tree.v_it--;
		return (tmp);
	}
	MapIterator operator-- (void)
	{
		--this->_tree.v_it;
		return (*this);
	}
// {
	MapIterator operator+( int nbr )
	{
		MapIterator<tree_type> tmp(*this);
		tmp._tree.v_it = this->_tree.v_it + nbr;
		return tmp;
	}

	// MapIterator operator-( int nbr )
	// {
	// 	MapIterator<tree_type> tmp(this->_tree);
	// 	tmp.v_it = v_it - nbr;
	// 	return tmp;
	// }

	// difference_type operator-(const MapIterator &other)
	// {
	// 	return (this->v_it - other.v_it);
	// }

	// bool operator < (const MapIterator &obj)
	// {
	// 	return this->v_it < obj.v_it;
	// }
	// bool operator > (const MapIterator &obj)
	// {
	// 	return this->v_it > obj.v_it;
	// }
	// bool operator <= (const MapIterator &obj)
	// {
	// 	return this->v_it <= obj.v_it;
	// }
	// bool operator >= (const MapIterator &obj)
	// {
	// 	return this->v_it >= obj.v_it;
	// }
	// MapIterator operator+= (const int nbr)
	// {
	// 	this->v_it += nbr;
	// 	return (*this);
	// } 
	// MapIterator operator-= (const int nbr)
	// {
	// 	this->v_it -= nbr;
	// 	return (*this);
	// }
	// pair_type operator[] (const int nbr)
	// {
	// 	return (*(v_it + nbr));
	// }
// }
};

template<
	class Key,
	class T,
	class Compare = std::less<Key>,
	class Allocator = std::allocator<std::pair<const Key, T> >  
> class map
{
public:
	typedef Key                                      key_type;
	typedef T                                        mapped_type;
	typedef std::pair<const key_type, mapped_type>        value_type;
	typedef Compare                                  key_compare;
	typedef Allocator                                allocator_type;
	typedef typename allocator_type::reference       reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer         pointer;
	typedef typename allocator_type::const_pointer   const_pointer;
	typedef typename allocator_type::size_type       size_type;
	typedef typename allocator_type::difference_type difference_type;
	typedef	bst<Key, T>								tree_type;
	typedef	MapIterator<tree_type>	iterator;
	typedef	MapIterator<tree_type const>	const_iterator;
	


public:
	size_type		_size;
	allocator_type	_alloc;
	bst<Key, T>		_tree;
	typedef typename bst<Key, T>::Node t_node;
public:
	map()
	:_size(0), _alloc(), _tree()
	{
	}
	explicit map( const Compare& comp, const Allocator& alloc = Allocator() );
	template< class InputIt >
	map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );
	map( const map& other );
	const map &operator = (const map&other)
	{
		this->_alloc = other._alloc;
		this->_tree = other._tree;
		this->_size = other._size;
		return *this;
	}



	// Capacity
	bool empty() const{
		return (_tree._root == nullptr);
	}
	size_type size() const{
		return (_tree.size());
	}
	size_type max_size() const{
		return (_alloc.max_size());
	}
	
	//Element access
	mapped_type &at(const key_type& key)
	{
		t_node *res = _tree.find(_tree._root, key);
		if (!res)
			throw std::out_of_range("out of range!");
		return res->value->second;
	}
	const mapped_type& at (const key_type& key) const
	{		
		t_node *res = _tree.find(_tree._root, key);
		if (!res)
			throw std::out_of_range("out of range!");
		return res->value->second;
	}

	mapped_type& operator[] (const key_type& key){
		t_node *res = _tree.find(_tree._root, key);
		if (res)
			return res->value->second;
		else{
			this->insert(value_type(key, mapped_type()));
			return at(key);
		}
	}

	
	std::pair<iterator, bool> insert( const value_type& value )
	{
		value_type *_new = _alloc.allocate(1);
		_alloc.construct(_new, value);
		std::pair<iterator, bool> ret;
		std::pair<bool, size_type> res = _tree.insert(_new);
		if (res.first)
		{
			ret.first = this->begin() + res.second;
			ret.second = 1;
		}
		else
		{
			ret.first = this->begin() + res.second;
			ret.second = 0;
		}
		return ret;
	}
	
	// Modifiers
	// iterator insert( iterator pos, const value_type& value );
	template< class InputIt >
	void insert( InputIt first, InputIt last )
	{
		for (; first != last; first++)
			this->insert(*first);
	}

	void erase (iterator position)
	{
		this->erase(position->first);
	}
	size_type erase (const key_type& k)
	{
		t_node *node = _tree.find(_tree._root, k);
		_tree.remove(_tree._root, node);
	}
	void erase (iterator first, iterator last)
	{
		for (; first != last; first++)
			this->erase(first);
	}
	void swap (map& x)
	{	
		map tmp;
		// *this = x;
		// x = tmp;
		tmp._size = this->_size;
		tmp._alloc = this->_alloc;
		tmp._tree = this->_tree;
		this->_size = x._size;
		this->_alloc = x._alloc;
		this->_tree = x._tree;
		x._size = tmp._size;
		x._alloc = tmp._alloc;
		x._tree = tmp._tree;
	}
	// void clear()
	// {
		
	// }

	
	iterator begin()
	{
		return iterator(_tree);
	}
	iterator end()
	{
		return iterator(_tree) + _tree.size();
	}
	size_type size( void )
	{
		return (_tree.size());
	}
};
}