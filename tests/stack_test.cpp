/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 09:49:18 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/26 11:44:29 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/stack.hpp"
#include <stack>

#define tmp std

template<typename T>
struct Mutant_Stack : public tmp::stack<T>
{
    typedef typename tmp::stack<T>::container_type::iterator iterator;
    Mutant_Stack(tmp::stack<T> & s)
    :tmp::stack<T>(s)
    {
        iterator it = this->c.begin();
        for (; it != this->c.end(); it++)
            std::cout << *it << "  ";
        std::cout << std::endl;
    }
};

int main()
{

    std::cout << "\n/*--------------------------------------------------------*/" << std::endl;
	std::cout << "/*                      stack tests                       */" << std::endl;
	std::cout << "/*--------------------------------------------------------*/" << std::endl;
    tmp::stack<int> s1;
    tmp::stack<int> s2(s1);
    tmp::stack<int> s3;
    s3 = s2;

    std::cout << "\n************* empty **************" << std::endl;
    std::cout << "before: " << s3.empty() << std::endl;
    for (int i = 0; i < 10; i++)
        s3.push(i);
    std::cout << "after: " << s3.empty() << std::endl;

    std::cout << "\n************* size **************" << std::endl;
    std::cout << "size of s2: " << s2.size() << std::endl;
    std::cout << "size of s3: " << s3.size() << std::endl;

    std::cout << "\n************* top **************" << std::endl;
    std::cout << "top in s3:" << s3.top() << std::endl;

    std::cout << "\n************* push **************" << std::endl;
    std::cout << "size before push :" << s1.size() << std::endl;
    for (int i = 69; i < 100; i++)
        s1.push(i);
    std::cout << "size atmper push: " << s1.size() << std::endl;

    std::cout << "\n************* pop **************" << std::endl;
    std::cout << "size before pop: " << s1.size() << std::endl;
    for (int i = 0; i < 10; i++)
        s1.pop();
    std::cout << "size atmper push: " << s1.size() << std::endl;

    std::cout << "\n************* iter **************" << std::endl;
    {
        std::cout << "s1: " << std::endl;
        Mutant_Stack<int> ms(s1);
        std::cout << "s3: " << std::endl;
        Mutant_Stack<int> ms2(s3);
    }
    std::cout << "\n********** relational operators *********" << std::endl;
    std::cout << " == : " << (s1 == s2) << std::endl;
    std::cout << " != : " << (s1 != s2) << std::endl;
    std::cout << " < : " << (s1 < s2) << std::endl;
    std::cout << " <= : " << (s1 <= s2) << std::endl;
    std::cout << " > : " << (s1 > s2) << std::endl;
    std::cout << " >= : " << (s1 >= s2) << std::endl;
}