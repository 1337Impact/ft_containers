/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 08:34:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/08 21:21:30 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.hpp"
#include "map.hpp"
#include <map>

#define tmp ft

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
    // typedef tmp::map<int, std::string>::iterator iter;

    // tmp::map<int, std::string> m;
    // m.insert(std::make_pair(50, "50!"));
    // m.insert(std::make_pair(60, "60!"));
    // m.insert(std::make_pair(12, "12!"));
    // m.insert(std::make_pair(20, "20!"));
    // std::pair<iter, bool> p = m.insert(std::make_pair(20, "20!"));
    std::cout << "********************" << std::endl;
    // iter it = m.end();
    // std::cout << m[120] << std::endl;
    // std::cout << m.size() << std::endl;

    // iter  it = m.begin();
    // iter  it2 = m.begin();
    // it++;
    // std::cout << it->first << std::endl;
    // std::cout << it2->first << std::endl;
    // std::cout << it2->first << std::endl;
    // std::cout << (it == it2) << std::endl;
    // for (; it != m.end(); it++)
    //     std::cout << it->first << "    " << it->second << std::endl;

    std::vector<int> v(12);
    std::vector<int>::iterator it = v.begin();
    std::vector<int>::iterator it2 = v.begin();
    std::cout << (it == it2) << std::endl;
    
        
}