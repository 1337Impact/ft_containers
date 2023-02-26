/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:04:27 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/26 12:25:46 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <utility>
#include "_tree.hpp"
#include <vector>
#include <stdexcept>
#include "_map_iter.hpp"
#include "../utility/pair.hpp"
#include "../utility/iterator.hpp"
#include "../utility/algorithm.hpp"


namespace ft
{


	/*--------------------------------------------------------*/
	/*                        ft::map                         */
	/*--------------------------------------------------------*/

	template<
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Allocator = std::allocator<ft::pair<const Key, T> >  
	> class map
	{
		public:
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const key_type, mapped_type>		value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef	_tree<Key, T, Allocator>					tree_type;
			typedef	typename tree_type::Node					node;
			typedef	MapIterator<tree_type, node>				iterator;
			typedef	MapIterator<const tree_type, node>			const_iterator;
			typedef	ft::reverse_iterator<iterator>				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
		
		/*                   value_compare                  */
		class value_compare
		{
			public:
				Compare comp;
				value_compare (Compare c) : comp(c) {}
				public:
				typedef bool result_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
		};

		private:
			tree_type		_tree;
			Compare			_cmp;
			allocator_type	_alloc;

		public:

			//Constructors/Destructor
			map()
			:_tree(), _cmp(), _alloc()
			{
			}
	
			explicit map( const Compare& comp, const Allocator& alloc = Allocator() )
			:_tree(), _cmp(comp), _alloc(alloc)
			{}

			template< class InputIt >
			map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
			:_tree(), _cmp(comp), _alloc(alloc){
				for (; first != last; first++)
				{
					this->insert(*first);
				}
			}
		
			map( const map& other )
			:_tree(other._tree), _cmp(other._cmp), _alloc(other._alloc)
			{
			}

			~map()
			{
				clear();
			}

			//Operator=
			const map &operator = (const map&other)
			{
				this->_cmp = other._cmp;
				this->_alloc = other._alloc;
				this->clear();
				const_iterator _it = other.begin();
				for (; _it != other.end(); _it++)
					this->insert(*_it);
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
			mapped_type &at(const key_type& key){
				node *res = _tree.find(_tree._root, key);
				if (!res)
					throw std::out_of_range("out ofd range!");
				return res->value->second;
			}
		
			const mapped_type& at (const key_type& key) const{		
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

			ft::pair<iterator, bool> insert( const value_type& value ){
				ft::pair<iterator, bool> ret;
				node *tmp = _tree.find(_tree._root, value.first);
				if (!tmp)
				{
					pointer _new = _alloc.allocate(1);
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
			
			//Modifiers
			iterator insert( iterator pos, const value_type& value ){
				node *tmp = _tree.find(_tree._root, value.first);
				if (!tmp)
				{
					iterator next(pos);
					++next;
					pointer _new = _alloc.allocate(1);
					if (value.first > pos->first && value.first < next->first)
					{
						node *_pos_n = pos.base();
						return iterator(this->_tree.insert_in_p(_pos_n, _new));
					}
					else
					{
						return iterator(this->_tree.insert(_new));
					}
				}
				return iterator(tmp);
			}
		
			template< class InputIt >
			void insert( InputIt first, InputIt last ){
				for (; first != last; first++)
					this->insert(*first);
			}

			size_type erase (const key_type& k){
				node *node = _tree.find(_tree._root, k);
				if (node)
				{
					_alloc.destroy(node->value);
					_alloc.deallocate(node->value, 1);
					_tree.remove(k);
				}
				return(_tree.size());
			}
		
			void erase (iterator position){
				this->erase(position->first);
			}
		
			void erase (iterator first, iterator last){
				for (; first != last; first++)
						this->erase(first);
			}

			void swap (map& x){	
				map _tmp(this->_cmp, this->_alloc);
				_tree.swap(x._tree);
				this->_cmp = x._cmp;
				this->_alloc = x._alloc;
				x._cmp = _tmp._cmp;
				x._alloc = _tmp._alloc;
			}

			void clear( void ){
				this->_tree.clear(_alloc);
			}

			// Iterators
			iterator begin()
			{
				return iterator(_tree.begin(), &(this->_tree));
			}
			
			iterator end()
			{
				return iterator(_tree.end(), &(this->_tree));
			}

			const_iterator begin() const
			{
				return const_iterator(_tree.begin(), &(this->_tree));
			}
			
			const_iterator end() const
			{
				return const_iterator(_tree.end(), &(this->_tree));
			}
			
			reverse_iterator rbegin()
			{
				return reverse_iterator(--this->end());
			}
			
			reverse_iterator rend()
			{
				return reverse_iterator(--this->begin());
			}
			
			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(--this->end());
			}
			
			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(--this->begin());
			}

			//Observers
			key_compare key_comp() const{
				return this->_cmp;
			}
			
			value_compare value_comp() const{
				value_compare val(this->_cmp);
				return val;
			}

			//Operations
			iterator find(const key_type& key){
				node *n = _tree.find(_tree._root, key);
				if (n)
					return iterator(n, &(this->_tree));
				else
					return this->end();
			}

			const_iterator find (const key_type& key) const
			{
				node *n = _tree.find(_tree._root, key);
				if (n)
					return const_iterator(n, &(this->_tree));
				else
					return this->end();
			}

			size_type count (const key_type& key) const{
				node *n = _tree.find(_tree._root, key);
				if (n)
					return (1);
				else
					return (0);
			}
			
			iterator lower_bound (const key_type& key){ 
				iterator _it = this->begin();
				while (_it != this->end() && this->_cmp(_it->first, key))
				{
					_it++;
				}
				return (_it);
			}
			
			const_iterator lower_bound (const key_type& key) const{
				const_iterator _it = this->begin();
				while (_it != this->end() && this->_cmp(_it->first, key))
				{
					_it++;
				}
				return (_it);
			}

			iterator upper_bound (const key_type& key){ 
				iterator _it = this->begin();
				while (_it != this->end() && this->_cmp(_it->first, key))
				{
					_it++;
				}
				if (_it->first == key)
					_it++;
				return (_it);
			}
		
			iterator upper_bound (const key_type& key) const{ 
				iterator _it = this->begin();
				while (_it != this->end() && this->_cmp(_it->first, key))
				{
					_it++;
				}
				if (_it->first == key)
					_it++;
				return (_it);
			}

			ft::pair<iterator,iterator> equal_range (const key_type& key)
			{
				ft::pair<iterator,iterator> ret;
				iterator _it = this->lower_bound(key);
				if (_it->first == key)
				{
					ret = ft::make_pair(_it, ++_it);
				}
				else{
					ret = ft::make_pair(_it, _it);
				}
				return ret;
			}
		
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& key) const;


			//Allocator
			allocator_type get_allocator() const{
				return (this->_alloc);
			}
	};
		/*--------------------------------------------------------*/
		/*                 Non-member functions                   */
		/*--------------------------------------------------------*/

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){

			return ((lhs.size() == rhs.size())
			&& ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs ){

			return (!(lhs == rhs));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ){
		
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
				const ft::map<Key,T,Compare,Alloc>& rhs ){
		
		return (ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){

		return !(lhs > rhs);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
                 const ft::map<Key,T,Compare,Alloc>& rhs ){

		return !(lhs < rhs);
	}
}