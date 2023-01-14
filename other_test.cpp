/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 13:13:33 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/14 13:26:38 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.hpp"
#include <utility>

#define tmp ft

int main()
{
    //pair
    {
        std::cout << "**********pair***********" << std::endl;
        tmp::pair<int, std::string> p(1, std::string("hello world"));
        tmp::pair<int, std::string> p2 = p;
        std::cout << p.first << "  " << p.second << std::endl;
        std::cout << p2.first << "  " << p2.second << std::endl;
        std::cout << "*pair operators" << std::endl;
        std::cout << (p2 == p) << std::endl;
        std::cout << (p2 != p) << std::endl;
        std::cout << (p2 > p) << std::endl;
        std::cout << (p2 >= p) << std::endl;
        std::cout << (p2 < p) << std::endl;
        std::cout << (p2 <= p) << std::endl;
    }
    //make_pair
    {
        std::cout << "**********make_pair***********" << std::endl;
        tmp::pair<int, std::string> p = tmp::make_pair(2, std::string("hello world"));
        std::cout << p.first << "  " << p.second << std::endl;
    }
}