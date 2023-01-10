/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 08:34:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/10 11:28:53 by mbenkhat         ###   ########.fr       */
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




    tmp::map<int, std::string> m;
    // m.insert(std::make_pair(-20, "50!"));
    m.insert(std::make_pair(1, "12!"));
    m.insert(std::make_pair(2, "12!"));
    m.insert(std::make_pair(3, "20!"));
    m.insert(std::make_pair(4, "50!"));
    m.insert(std::make_pair(5, "60!"));
    m.insert(std::make_pair(6, "60!"));
    std::cout << "********************" << std::endl;
    // m[20] = "hola";
    // std::cout << "size: " << m.size() << std::endl;
    m.erase(m.begin(), m.end());
    // m.erase(1);
    // m.erase(2);
    // m.erase(3);
    // m.erase(5);
    // std::cout << m.erase(5);
    // m.erase(6);
    // std::cout << "size: " << m.size() << std::endl;
    // iter  it2 = m.begin();
    // it2++;
    // std::cout << it->first << std::endl;
    // std::cout << it2->first << std::endl;
    // std::cout << it2->first << std::endl;
    // std::cout << (it == it2) << std::endl;
    // // it++;
    typedef tmp::map<int, std::string>::iterator iter;
    iter  it = m.begin();
    for (; it != m.end(); it++)
        std::cout << it->first << "    " << it->second << std::endl;
    // system("leaks test");
}