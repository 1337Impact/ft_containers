/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 08:34:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/13 09:16:49 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bst.hpp"
#include "map.hpp"
#include <map>

#define tmp std

int main()
{
    // typedef tmp::map<int, std::string>::iterator iter;
    // typedef tmp::map<int, std::string>::const_iterator citer;
    // struct ModCmp {
    //     bool operator()(const int lhs, const int rhs) const
    //     {
    //         return (lhs % 97) < (rhs % 97);
    //     }
    // };
    tmp::map<int, std::string> m;
    m.insert(std::make_pair(4, "40!"));
    m.insert(std::make_pair(1, "10!"));
    m.insert(std::make_pair(3, "30!"));
    m.insert(std::make_pair(6, "60!"));
    m.insert(std::make_pair(2, "20!"));
    m.insert(std::make_pair(5, "50!"));
    std::cout << "********************" << std::endl;
    // m.clear();
    // const tmp::map<int, std::string> cp(m);
    // std::cout << it->first << std::endl;
    
    m.value_comp();
    
    // std::cout << m.size() << std::endl;
    // citer it = cp.begin();
    // it++;
    // for (; it != cp.end(); it++)
        // std::cout << it->first << "    " << it->second << std::endl;
    // std::cout << (it == m.end()) << std::endl;
    // iter  it = m.end();
    // it--;
    // it++;
    // it--;
    // std::cout << it->first << "    " << it->second << std::endl;

}