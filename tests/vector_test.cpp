/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:08:13 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/26 11:39:43 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/vector.hpp"
#include <vector>

#define tmp ft



int main()
{
	std::allocator<std::string> _tmp_alloc;

	std::cout << "\n/*--------------------------------------------------------*/" << std::endl;
	std::cout << "/*                      vector tests                      */" << std::endl;
	std::cout << "/*--------------------------------------------------------*/" << std::endl;
	tmp::vector<std::string> v;
	tmp::vector<std::string> v2(_tmp_alloc);
	tmp::vector<std::string> v3(20, "42");
	tmp::vector<std::string> v4(v3);

	v = v3;
	std::cout << "\n************* Capacity **************" << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "max_size: " << v.max_size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	v.resize(10);
	std::cout << "=>resize called!" << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "is empty: " << v.empty() << std::endl;
	v.reserve(20);
	std::cout << "=>reserve called!" << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;

	std::cout << "\n************* Element access **************" << std::endl;
	std::cout << "Element index 5: " << v[5] << std::endl;
	std::cout << "Element at 5: " << v.at(5) << std::endl;
	std::cout << "Front called: " << v.front() << std::endl;
	std::cout << "Back called: " << v.back() << std::endl;
	std::cout << "data called: " << v.data() << std::endl;

	std::cout << "\n************* Modifiers **************" << std::endl;
	v.assign(10, "69");
	std::cout << "=>assign called!" << std::endl;
	std::cout << "New size: " << v.size() << std::endl;
	std::cout << "New capcity: " << v.size() << std::endl;
	std::cout << "=>push back!" << std::endl;
	v.push_back("pushed");
	std::cout << "=>pop back!" << std::endl;
	v.pop_back();
	std::cout << "New size: " << v.size() << std::endl;
	std::cout << "New capcity: " << v.size() << std::endl;
	std::cout << "=>insert!" << std::endl;
	v.insert(v.begin(), "test");
	v.insert(v.begin(), 5, "more tests");
	std::cout << "New size: " << v.size() << std::endl;
	std::cout << "New capcity: " << v.size() << std::endl;
	std::cout << "=>erase!" << std::endl;
	v.erase(v.begin());
	std::cout << "=>swap!" << std::endl;
	v.swap(v4);
	std::cout << "=>clear!" << std::endl;
	v.clear();

	std::cout << "\n************* Allocator **************" << std::endl;
	v.get_allocator();

	std::cout << "\n/*--------------------------------------------------------*/" << std::endl;
	std::cout << "/*                      Iterator tests                     */" << std::endl;
	std::cout << "/*--------------------------------------------------------*/" << std::endl;
	

	tmp::vector<int> v5;
	// fill the vector
	for (int i = 0; i <= 42; i++)
		v5.push_back(i);
	
	std::cout << "\n************* Iterator **************" << std::endl;
	std::cout << "begin: " << *(v5.begin()) <<  std::endl;
	std::cout << "end - 1: " << *(v5.end() - 1) <<  std::endl;
	std::cout << "=>iterate the container!" << std::endl;
	tmp::vector<int>::iterator it = v5.begin();
	for (; it != v5.end(); it++)
		std::cout << *it << "  ";
	std::cout << std::endl;

	std::cout << "\n************* Reverse Iterator **************" << std::endl;
	tmp::vector<int>::reverse_iterator rit = v5.rbegin();

	for (; rit != v5.rend(); rit++)
		std::cout << *rit << "  ";
	std::cout << std::endl;
	std::cout << "reverse begin: " << *(v5.rbegin()) <<  std::endl;
	std::cout << "reverse end: " << *(v5.rend() - 1) <<  std::endl;
	
	std::cout << "\n/*--------------------------------------------------------*/" << std::endl;
	std::cout << "/*                 Non-member functions                   */" << std::endl;
	std::cout << "/*--------------------------------------------------------*/" << std::endl;
	std::cout << "operator==: " << (v==v3) << std::endl; 
	std::cout << "operator!=: " << (v!=v3) << std::endl; 
	std::cout << "operator<: " << (v<v3) << std::endl; 
	std::cout << "operator<=: " << (v<=v3) << std::endl; 
	std::cout << "operator>: " << (v>v3) << std::endl; 
	std::cout << "operator>=: " << (v>=v3) << std::endl;
}