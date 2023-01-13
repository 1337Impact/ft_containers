/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:17:36 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/13 09:40:27 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

template <class Key, class T>
class bst
{
public:
    typedef Key                         key_type;
    typedef T                           value_type;
    typedef std::pair<const Key, T>     pair_type;
    typedef pair_type*                  pointer;
    typedef size_t                      size_type;
    typedef	std::vector<pointer>	    vector_type;
	typedef typename vector_type::iterator mapper_type;
	struct Node
	{
		pointer     value;
		Node    *parent;
		Node    *l_ch;
		Node    *r_ch;
		Node()
		:value(0), parent(0), l_ch(0), r_ch(0)
		{
		}
		Node(pointer val)
		:value(val), parent(0), l_ch(0), r_ch(0)
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
    Node *_end;
    // Node *_begin;

    bst():_root(0), _size(0), _first_n(0), _last_n(0), _end(0){
        _end = new Node();
    }
    bst(const bst & other)
    :_root(other._root), _size(other._size), _first_n(other._first_n), _last_n(other._last_n){
        _end = new Node();
    }
    ~bst(){
        delete _end;
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

        else if (n == _first_n)
            this->_first_n = this->_first_n->parent;
        else if (n == _last_n)
            this->_last_n = this->_last_n->parent;
    }

    Node *find(Node *root, const key_type& value) const
    {
        if (!root)
            return 0;
		else if (root->value->first == value){
			return root;
		}
		else if (root->value->first < value)
		{
			return find(root->r_ch, value);
		}
		else if (root->value->first > value)
		{
			return find(root->l_ch, value);
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
            if (root->l_ch == NULL && root->r_ch == NULL)
                return NULL;
            else if (root->l_ch == NULL) {
                Node* temp = root->r_ch;
                update_first_last(root);
                free(root);
                return temp;
            }
            else if (root->r_ch == NULL) {
                Node* temp = root->l_ch;
                update_first_last(root);
                free(root);
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

    Node *find_min(Node* root) constf
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
    Node *end() const
    {
        _end->parent = _last_n;
        return _end;
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
};