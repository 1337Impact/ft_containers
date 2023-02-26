/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _map_iter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 08:12:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/25 09:52:34 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <iterator>
// #include "iterator_traits.hpp"

template <class T,class T2>
class MapIterator
{
	public:
		typedef T 								tree_type;
		typedef T2 								value_type;
		typedef	typename tree_type::pair_type 	pair_type;
		typedef value_type						node;
		typedef pair_type*						pointer;
		typedef pair_type&						reference;
		typedef std::ptrdiff_t 					difference_type;
		typedef std::bidirectional_iterator_tag	iterator_category;

	public:
		tree_type *_tree;
		node* _root;
		
	public:
		MapIterator():_tree(0), _root(0)
		{
		}
		MapIterator(node* n, tree_type  *tree):_tree(tree), _root(n)
		{
		}
		MapIterator(const MapIterator &other)
		:_tree(other._tree), _root(other._root){}
		~MapIterator(){}
		MapIterator & operator = (const MapIterator &other)
		{
			this->_tree = other._tree;
			this->_root = other._root;
			return (*this);
		}
		bool operator==(const MapIterator & other)
		{
			return (this->_root == other._root);
		}
		bool operator!=(const MapIterator & other)
		{
			return (this->_root != other._root);
		}
		reference operator*(void) const
		{
			return (*(this->_root->value));
		}
		pointer operator->() const
		{
			return (this->_root->value);
		}
		
		MapIterator operator++ (int)
		{
			MapIterator<tree_type, value_type> tmp(*this);
			this->_root = this->_tree->next_node(this->_root);
			return (tmp);
		}
		MapIterator operator++ ()
		{
			this->_root = _tree->next_node(this->_root);
			return (*this);
		}
		MapIterator operator-- (int)
		{
			MapIterator<tree_type, value_type> tmp(*this);
			this->_root = this->_tree->previous_node(this->_root);
			return (tmp);
		}
		MapIterator operator-- ()
		{
			this->_root = this->_tree->previous_node(this->_root);
			return (*this);
		}

		node* base( void ) const{
			return (this->_root);
		}
};
