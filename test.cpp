/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:16:36 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/05 17:23:02 by mbenkhat         ###   ########.fr       */
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

#define tmp std


#include <iterator>
int main()
{
    tmp::vector<test> tt(4, test(69));
    tt.reserve(10);

    std::cout << "**********************" << std::endl;
    tmp::vector<test> t2(5, test(13));
    
    std::cout << t2.capacity() << std::endl;
    std::cout << t2.data() << std::endl;

    std::cout << "**********************" << std::endl;
    t2.insert(t2.begin()+1, tt.begin(), tt.end());
    // t2.insert(t2.begin()+1, 6, test(68));
    std::cout << "**********************" << std::endl;
    std::cout << "value of b: " << (*(t2.begin() + 7)).b << std::endl;

    std::cout << t2.capacity() << std::endl;
    std::cout << t2.size() << std::endl;
    std::cout << t2.data() << std::endl;
    
    return (0);
}