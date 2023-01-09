/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:16:36 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/09 08:49:52 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"

// template <typename T>
class test
{
private:
    /* data */
public:
    int b;
    test(/* args */)
    {
        std::cout << "constructed\n";
    }
    test(int n):b(n){std::cout << "constructed with value " << b << std::endl ;}
    test(const test&t):b(t.b){
        std::cout << "copy constructed\n";
    }
    void print(){
        std::cout << "printed" << std::endl;
    }
    test & operator= (const test & other)
    {
        this->b  = other.b;
        std::cout << "assign called" << std::endl;
        return *this;
    }
    // test & operator++(int val, int v2)
    // {
    //     std::cout << "++ called => " << val << std::endl;
    //     return *this;
    // }
    std::string get_b(){
        std::string b("hello world");
        std::cout << "called" << std::endl;
        return b;
    }
    const std::string get_b() const
    {
        std::cout << "const called" << std::endl;
        const std::string b("hello world");
        return b;
    }
 
    ~test()
    {
        std::cout << "distructed\n";
    }
};

void take_it(test & obj = (test a = test()))
{
    test &ref = obj;
}

#define tmp std


#include <iterator>
int main()
{
    test t(13);
    take_it(t);
    
    return (0);
}