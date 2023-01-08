/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 08:34:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/08 09:08:04 by mbenkhat         ###   ########.fr       */
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
    // t.insert(std::make_pair(10, std::string("hello world")));
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

    tmp::map<int, std::string> m;
    m.insert(std::make_pair(20, "20!"));
    m.insert(std::make_pair(50, "50!"));
    m.insert(std::make_pair(60, "60!"));
    m.insert(std::make_pair(12, "12!"));
    // std::cout << m.at(20) << std::endl;
    // std::cout << m.at(50) << std::endl;
    tmp::map<int, std::string>::iterator it = m.begin();
    // for ()
    // it++;
    tmp::map<int, std::string>::iterator it2 = it;
    it++;
    // it2++;
    // std::cout << m.size() << std::endl;
    std::cout << it2->second << std::endl;
    
    // std::vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // std::vector<int>::iterator it = v.end();
    // std::vector<int>::iterator it2 = v.begin();
    // it++;
    // it2++;
    // std::cout << it.base() << std::endl;
    // std::cout << *it<< std::endl;
    // std::cout << it2.base() << std::endl;
    // std::cout << *it2 << std::endl;
}