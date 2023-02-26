/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _tree.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:17:36 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/26 10:36:52 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include "../utility/pair.hpp"

template <class Key, class T, class Allocator>
class _tree
{
public:
	typedef Key							 	key_type;
	typedef T								value_type;
	typedef ft::pair<const Key, T>			pair_type;
	typedef pair_type*						pointer;
	typedef size_t							size_type;
	typedef	std::vector<pointer>			vector_type;
	typedef typename vector_type::iterator	mapper_type;
	typedef Allocator						alloc;
	struct Node
	{
		pointer	value;
		Node	*parent;
		Node	*l_ch;
		Node	*r_ch;
		Node()
		:value(0), parent(0), l_ch(0), r_ch(0)
		{
		}
		Node(pointer val)
		:value(val), parent(0), l_ch(0), r_ch(0)
		{
		}
		Node(const Node & other)
		:value(other.value), parent(other.parent), l_ch(other.l_ch), r_ch(other.r_ch)
		{
		}
		~Node()
		{
		}
	};
public:
	Node* _root;
	size_type _size;
	Node *_first_n;
	Node *_last_n;
	Node *_null_n;
	alloc _alloc;

	_tree():_root(0), _size(0), _first_n(0), _last_n(0), _null_n(0), _alloc(){
		_null_n = new Node();
	}
	_tree(const _tree & other)
	:_root(nullptr), _size(0), _first_n(nullptr), _last_n(nullptr), _null_n(nullptr), _alloc(other._alloc){
		this->_null_n = new Node();
		if (!(other.size()))
			return ;
		for (Node *n = other._first_n; n != other._null_n; n = other.next_node(n))
		{
			pointer _new_val = _alloc.allocate(1);
			_alloc.construct(_new_val, *(n->value));
			if (n == other._first_n)
			{
				this->_root = this->insert(_root, new Node(_new_val));
				this->_first_n = this->_root;
				this->_last_n = this->_root;
			}
			else{
				this->_last_n = this->insert_in_p(this->_last_n, _new_val);
			}
		}
	}
	~_tree(){
		delete _null_n;
	}

	_tree & operator = (const _tree & other)
	{
		this->_root = other._root;
		this->_size = other._size;
		this->_first_n = other._first_n;
		this->_last_n = other._last_n;
		return *this;
	}

	Node* insert(Node* root, Node* child)
	{
		if (!root){
			return child;
		}
		else if (root->value->first < child->value->first)
		{
			root->r_ch = insert(root->r_ch, child);
			root->r_ch->parent = root;
		}
		else if (root->value->first > child->value->first)
		{
			root->l_ch = insert(root->l_ch, child);
			root->l_ch->parent = root;
		}
		return root;
	}


	Node* insert( pointer value )
	{
		Node *a_node = new Node(value);
		if (!_root)
			_root = this->insert(_root, a_node);
		else
			this->insert(_root, a_node);
		update_first_last(a_node);
		this->_size++;
		return (a_node);
	}

	Node *insert_in_p(Node *pos, pointer value)
	{
		Node *a_node = new Node(value);
		if (!this->_root)
			
		a_node->parent = pos;
		a_node->r_ch = pos->r_ch;
		pos->r_ch = a_node;
		update_first_last(a_node);
		this->_size++;
		return (a_node);
	}

	void update_first_last(Node *n)
	{
		if (!(this->_first_n) || !(this->_last_n))
		{
			this->_first_n = n;
			this->_last_n = n;
		}
		else if (n->value->first > this->_last_n->value->first)
			this->_last_n = n;
		else if (n->value->first < this->_first_n->value->first)
			this->_first_n = n;
		else if (n == this->_first_n)
			_first_n = this->next_node(n);
		else if (n == this->_last_n)
			_last_n = this->previous_node(n);
	}

	Node *find(Node *root, const key_type& key) const
	{
		if (!root)
			return 0;
		else if (root->value->first == key){
			return root;
		}
		else if (root->value->first < key)
		{
			return find(root->r_ch, key);
		}
		else if (root->value->first > key)
		{
			return find(root->l_ch, key);
		}
		return (0);
	}

	Node* deleteNode(Node* root, key_type key)
	{
		if (root == NULL)
			return NULL;
		if (key < root->value->first)
			root->l_ch = deleteNode(root->l_ch, key);
		else if (key > root->value->first)
			root->r_ch = deleteNode(root->r_ch, key);
		else {
			this->update_first_last(root);
			if (root->l_ch == NULL && root->r_ch == NULL){
				return NULL;
			}
			else if (root->l_ch == NULL) {
				Node* temp = root->r_ch;
				delete root;
				return temp;
			}
			else if (root->r_ch == NULL) {
				Node* temp = root->l_ch;
				delete root;
				return temp;
			}
			Node* temp = find_min(root->r_ch);
			root->value = temp->value;
			root->r_ch = deleteNode(root->r_ch, temp->value->first);
		}
		return root;
	}

	void remove(key_type key)
	{
		this->_root = deleteNode(this->_root, key);
		this->_size--;
	}

	size_type size( void ) const
	{
		return (_size);
	}

	Node *find_min(Node* root) const
	{
		Node* current = root;
	
		while (current && current->l_ch != NULL)
			current = current->l_ch;
		return current;
	}

	Node *find_max(Node* root) const
	{
		Node* current = root;
	
		while (current && current->r_ch != NULL)
			current = current->r_ch;
		return current;
	}
	Node *begin() const
	{
		if (!_first_n)
			return _null_n;
		return _first_n;
	}
	Node *rbegin() const
	{
		if (!_first_n)
			return _null_n;
		return _first_n;
	}
	Node *end() const
	{
		_null_n->parent = _last_n;
		return _null_n;
	}

	Node *next_node(Node *n) const
	{
		if (n == _last_n)
			return this->end();
		else if (n == this->end())
			return nullptr;
		if (n->r_ch)
			return this->find_min(n->r_ch);
		Node* p = n->parent;
		while (p != NULL && n == p->r_ch){
			n = p;
			p = p->parent;
		}
		return p;
	}
	Node *previous_node(Node *n) const
	{
		if (n == _first_n)
		{
			_null_n->parent = _first_n;
			return _null_n;
		}
		if (n->l_ch)
			return this->find_max(n->l_ch);
		Node* p = n->parent;
		while (p != NULL && n == p->l_ch) {
			n = p;
			p = p->parent;
		}
		return p;
	}

	void print_first_last(void)
	{
		std::cout << _first_n->value->first << "  " << _first_n->value->last << std::endl;
		std::cout << _last_n->value->first << "  " << _last_n->value->last << std::endl;
	}

	void swap(_tree & _t){
		_tree tmp(*this);
		*this = _t;
		_t = tmp;
	}

	template <typename alloc>
	void clear( alloc _alloc ){
		Node *_n = this->_first_n;
		Node *_next;
		for (size_type i = 0; i < this->_size; i++)
		{
			_next = this->next_node(_n);
			_alloc.destroy(_n->value);
			_alloc.deallocate(_n->value, 1);
			_n = _next;
		}
		this->_root = nullptr;
		this->_first_n = nullptr;
		this->_last_n = nullptr;
		this->_size = 0;
	}

	void insert_last(Node *_n, Node *_new)
	{
		_n->r_ch = _new;
	}
};
