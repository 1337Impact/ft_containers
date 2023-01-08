/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:04:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/08 09:06:03 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <utility>
#include "bst.hpp"
#include <vector>


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
	typedef std::ptrdiff_t difference_type;
	typedef	std::vector<pair_type>	vector_type;
	typedef typename vector_type::iterator vector_iterator;

private:
	tree_type _tree;
	vector_type _v;
	vector_iterator v_it;

    void tree_mapper(node* root)
    {
        if (!root) {
            return ;
        }
        tree_mapper(root->l_ch);
		_v.push_back(root->value);
        tree_mapper(root->r_ch);
    }
public:
	MapIterator(){}
	MapIterator(tree_type tree):_tree(tree), _v()
	{
		tree_mapper(tree._root);
		v_it = _v.begin();
	}
	MapIterator(const MapIterator &other)
	:_tree(other._tree), _v(other._v), v_it(other.v_it){}
	~MapIterator(){}
	MapIterator & operator = (const MapIterator &other)
	{
		this->_tree = other._tree;
		this->_v = other._v;
		this->v_it = other.v_it;
		return *this;
	}
	bool operator==(const MapIterator & other)
	{
		return v_it == other.v_it;
	}
	bool operator!=(const MapIterator & other)
	{
		return v_it != other.v_it;
	}
	reference operator*(void)
	{
		return (*v_it);
	}
	pointer operator->()
	{
		return (v_it.base());
	}
	
	MapIterator operator++ (int)
	{
		MapIterator<tree_type> tmp(*this);
		v_it++;
		return (tmp);
	}
	MapIterator operator++ (void)
	{
		++v_it;
		return (*this);
	}
	MapIterator operator-- (int)
	{
		MapIterator<tree_type> tmp(*this);
		v_it--;
		return (tmp);
	}
	MapIterator operator-- (void)
	{
		--v_it;
		return (*this);
	}

	MapIterator operator+( int nbr )
	{
		MapIterator<tree_type> tmp(*this);
		tmp.v_it = this->v_it + nbr;
		return tmp;
	}

	MapIterator operator-( int nbr )
	{
		MapIterator<tree_type> tmp(this->_tree);
		tmp.v_it = v_it - nbr;
		return tmp;
	}

	difference_type operator-(const MapIterator &other)
	{
		return (this->v_it - other.v_it);
	}

	bool operator < (const MapIterator &obj)
	{
		return this->v_it < obj.v_it;
	}
	bool operator > (const MapIterator &obj)
	{
		return this->v_it > obj.v_it;
	}
	bool operator <= (const MapIterator &obj)
	{
		return this->v_it <= obj.v_it;
	}
	bool operator >= (const MapIterator &obj)
	{
		return this->v_it >= obj.v_it;
	}
	MapIterator operator+= (const int nbr)
	{
		this->v_it += nbr;
		return (*this);
	} 
	MapIterator operator-= (const int nbr)
	{
		this->v_it -= nbr;
		return (*this);
	}
	pair_type operator[] (const int nbr)
	{
		return (*(v_it + nbr));
	}
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
	


private:
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

	// std::pair<iterator, bool> insert( const value_type& value );
	void insert( const value_type& value )
	{
		_tree.insert(value);
		_size++;
	}
	// iterator insert( iterator pos, const value_type& value );
	// 	template< class InputIt >
	// void insert( InputIt first, InputIt last );

	mapped_type &at(const key_type& key)
	{
		t_node *res = _tree.find(_tree._root, key);
		return res->value.second;
	}
	iterator begin()
	{
		return iterator(_tree);
	}
	iterator end()
	{
		return iterator(_tree) + _size;
	}
	size_type size( void )
	{
		return (_size);
	}
};
}