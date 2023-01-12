/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:04:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/12 11:54:02 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <utility>
#include "bst.hpp"
#include <vector>
#include <iterator>
#include <stdexcept>
#include "map_iter.hpp"


namespace ft
{
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
	typedef	typename bst<Key, T>::Node				node;
	typedef	MapIterator<tree_type, node>				iterator;
	typedef	MapIterator<tree_type const, node const>	const_iterator;
	typedef	std::reverse_iterator<iterator>				reverse_iterator;
	typedef	std::reverse_iterator<const_iterator>		const_reverse_iterator;
	


private:
	size_type		_size;
	allocator_type	_alloc;
	bst<Key, T>		_tree;
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
		return (this->_tree._size == 0);
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
		node *res = _tree.find(_tree._root, key);
		if (!res)
			throw std::out_of_range("out ofd range!");
		return res->value->second;
	}
	const mapped_type& at (const key_type& key) const
	{		
		node *res = _tree.find(_tree._root, key);
		if (!res)
			throw std::out_of_range("out of range!");
		return res->value->second;
	}

	mapped_type& operator[] (const key_type& key){
		node *res = _tree.find(_tree._root, key);
		if (res)
			return res->value->second;
		else{
			this->insert(value_type(key, mapped_type()));
			return at(key);
		}
	}

	
	std::pair<iterator, bool> insert( const value_type& value )
	{
		std::pair<iterator, bool> ret;
		node *tmp = _tree.find(_tree._root, value.first);
		if (!tmp)
		{
			// alocate node
			value_type *_new = _alloc.allocate(1);
			_alloc.construct(_new, value);

			ret.first = iterator(_tree.insert(_new), &_tree);
			ret.second = true;
		}
		else{
			ret.first = iterator(tmp, &_tree);
			ret.second = false;
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

	size_type erase (const key_type& k)
	{
		node *node = _tree.find(_tree._root, k);
		if (node)
		{
			_alloc.destroy(node->value);
			_alloc.deallocate(node->value, 1);
			_tree.remove(k);
		}
		return(_tree.size());
	}
	void erase (iterator position)
	{
		this->erase(position->first);
	}
	void erase (iterator first, iterator last)
	{
		for (; first != last; first++)
				this->erase(first);
	}

	void swap (map& x)
	{	
		map tmp;
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

	void clear()
	{
		this->erase(this->begin(), this->end());
	}

	iterator find(const key_type& key)
	{
		node *n = _tree.find(_tree._root, key);
		if (n)
			return iterator(n, &(this->_tree));
		else
			return this->end();
	}
	const_iterator find (const key_type& k) const;

	// Iterators
	iterator begin()
	{
		return iterator(_tree.find_min(this->_tree._root), &(this->_tree));
	}
	iterator end()
	{
		return iterator(_tree.end(), &(this->_tree));
	}
	const_iterator begin() const
	{
		return const_iterator(_tree.find_min(this->_tree._root), &(this->_tree));
	}
	const_iterator end() const
	{
		return const_iterator(_tree.end(), &(this->_tree));
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(this->end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(this->begin());
	}
	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(this->end());
	}
	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(this->begin());
	}
};
}