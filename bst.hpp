/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 20:17:36 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/08 21:21:56 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>

#define LEFT  1
#define RIGHT 2

template <class Key, class T>
class bst
{
public:
    typedef Key                 key_type;
    typedef T                   value_type;
    typedef std::pair<const Key, T>   pair_type;
    typedef pair_type*          pointer;
    typedef size_t              size_type;
    typedef	std::vector<pointer>	vector_type;
	typedef typename vector_type::iterator vector_iterator;
	struct Node
	{
		pointer     value;
        int         pos;
        size_type   index;
		Node    *parent;
		Node    *l_ch;
		Node    *r_ch;
		Node(pointer val)
		:value(val), pos(0), index(0), parent(0), l_ch(0), r_ch(0)
		{
		}
		~Node()
		{
		}
	};
public:
    Node* _root;
    size_type _size;
    vector_type _v;
	vector_iterator v_it;
    

    bst():_root(0), _size(0){}
    bst(const bst & other):_root(other._root), _size(0), _v(){
        this->tree_mapper(this->_root);
        v_it = _v.begin(); 
    }
    ~bst(){}

    Node* insert(Node* root, Node* child)
	{
		if (!root){
            child->index = _size;
            _size++;
			return child;
		}
		else if (root->value->first < child->value->first)
		{
			root->r_ch = insert(root->r_ch, child);
            root->r_ch->parent = root;
            root->r_ch->pos = RIGHT;
		}
		else if (root->value->first > child->value->first)
		{
			root->l_ch = insert(root->l_ch, child);
            root->l_ch->parent = root;
            root->l_ch->pos = LEFT;
		}
		return root;
	}
	std::pair<bool, size_type> insert( pointer value )
	{
        Node *tmp = this->find(_root, value->first);
        if (tmp == NULL)
        {
            Node *a_node = new Node(value);
            if (!_root)
                _root = this->insert(_root, a_node);
            else
                this->insert(_root, a_node);
            return (std::make_pair(1, a_node->index));
        }
        return (std::make_pair(0, tmp->index));
	}
    Node *find(Node *root, const key_type& value)
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

    Node *find_min(Node* root)
    {
        Node* current = root;
    
        while (current && current->l_ch != NULL)
            current = current->l_ch;
    
        return current;
    }
 
    void remove(Node *root, Node *_node)
    {
        if (!_node)
            return ;
        if (_node->l_ch == NULL){
            if (_node->pos == LEFT)
                _node->parent->l_ch = _node->r_ch;
            else if (_node->pos == RIGHT)
                _node->parent->r_ch = _node->r_ch;
        }
        else if (_node->r_ch == NULL){
            if (_node->pos == LEFT)
                _node->parent->l_ch = _node->l_ch;
            else if (_node->pos == RIGHT)
                _node->parent->r_ch = _node->l_ch;
        }
        else
        {
            Node* temp = find_min(root->r_ch);
            _node->value = temp->value;
            remove(root->r_ch, temp);
        }
    }
    void Inorder(Node* root)
    {
        if (!root) {
            return;
        }
        Inorder(root->l_ch);
        std::cout << root->value->first << "  " << root->value->second << std::endl;
        Inorder(root->r_ch);
    }

    size_type size( void )
    {
        return (_size);
    }

    void tree_mapper(Node* root)
    {
        if (!root) {
            return ;
        }
        tree_mapper(root->l_ch);
		_v.push_back(root->value);
        tree_mapper(root->r_ch);
    }
};