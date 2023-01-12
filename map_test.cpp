/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 08:34:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/12 11:55:42 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.hpp"
#include "map.hpp"
#include <map>

#define tmp std

int main()
{
    // ft::map<int, std::string> m;
    // ft::map<int, std::string>::value_type value(12, "hello world");
    // m.insert(value);
    // m.insert(std::make_pair(13, std::string("hello world")));
    // m.insert(std::make_pair(10, std::string("hello world")));
    // m.insert(std::make_pair(5, std::string("hello world")));
    // m.insert(std::make_pair(11, std::string("hello world")));
    // // std::cout << m.at(13) << std::endl;

    // bst<int, std::string> t;

    // bst<int, std::string> n = std::pair<int, std::string>(10, std::string("hello world"));
    // t.insert(&n);
    // t.insert(std::make_pair(5, std::string("hello world")));
    // t.insert(std::make_pair(3, std::string("hello world")));
    // t.insert(std::make_pair(15, std::string("hello world!")));
    // t.insert(std::make_pair(14, std::string("hello world")));
    // t.insert(std::make_pair(20, std::string("hello world")));
    // std::cout << "********************" << std::endl;
    // std::cout << t.size() << std::endl;
    // bst<int, std::string>::Node *r = t.find(t._root, 15);
    // std::cout << r->value.second << std::endl;
    // t.remove(t._root, r);
    // t.Inorder(t._root);



    // typedef tmp::map<int, std::string>::iterator iter;

    tmp::map<int, std::string> m;
    m.insert(std::make_pair(4, "40!"));
    m.insert(std::make_pair(1, "10!"));
    m.insert(std::make_pair(3, "30!"));
    m.insert(std::make_pair(6, "60!"));
    m.insert(std::make_pair(2, "20!"));
    m.insert(std::make_pair(5, "50!"));
    std::cout << "********************" << std::endl;
    // m.clear();
    m.erase(m.begin());
    m.erase(m.begin());
    m.erase(m.begin());
    m.erase(m.begin());
    m.erase(m.begin());
    m.erase(m.begin());
    
    
    std::cout << m.size() << std::endl;
    // for (; it != m.end(); it++)
        // std::cout << it->first << "    " << it->second << std::endl;
    // std::cout << (it == m.end()) << std::endl;
    // iter  it = m.end();
    // it--;
    // it++;
    // it--;
    // std::cout << it->first << "    " << it->second << std::endl;

}