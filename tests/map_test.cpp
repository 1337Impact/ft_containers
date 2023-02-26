/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 08:34:37 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/26 12:35:25 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../containers/map.hpp"
#include <map>

#define tmp ft

template<typename It>
void print_map(It begin, It end)
{
	for (; begin != end; begin++)
		std::cout << begin->first << "    " << begin->second << std::endl;
}

int main()
{
	std::cout << "\n/*--------------------------------------------------------*/" << std::endl;
	std::cout << "/*                         map tests                      */" << std::endl;
	std::cout << "/*--------------------------------------------------------*/" << std::endl;

	/*            Constructor/destructor             */
	tmp::map<int, std::string> m;
	tmp::map<int, std::string> m2(m);
	tmp::map<int, std::string> m3;
	m3 = m;
	
	/*              Capacity             */
	std::cout << "*************** Capacity ***************" << std::endl;
	std::cout << "empty(): " << m.empty() << std::endl; 
	std::cout << "size(): " << m.size() << std::endl; 
	std::cout << "max_size(): " << m.max_size() << std::endl;

	/*              Modifiers             */
	std::cout << "\n*************** Modifiers ***************" << std::endl;
	std::cout << "=> insert element into the map:" << std::endl;
	m.insert(tmp::make_pair(10, "this is 10"));
	m.insert(tmp::make_pair(5, "this is 5"));
	m.insert(tmp::make_pair(15, "this is 15"));
	m.insert(tmp::make_pair(42, "this is 42"));
	m.insert(tmp::make_pair(24, "this is 24"));
	m.insert(tmp::make_pair(1, "this is 1"));
	m.insert(tmp::make_pair(-20, "this is -20"));
	std::cout << "\n=> current map elements:" << std::endl;
	
	m.erase(15);
	m.erase(24);
	print_map(m.begin(), m.end());
	std::cout << "\n=> map after erasing 15 and 24" << std::endl;
	print_map(m.begin(), m.end());

	std::cout << "\n=> swap m with m2:" << std::endl;
	m.swap(m2);
	std::cout << "m after swap:" << std::endl;
	print_map(m.begin(), m.end());
	std::cout << "\nm2 after swap:" << std::endl;

	print_map(m2.begin(), m2.end());
	m = m2;
	std::cout << "\n=> clear m2:" << std::endl;
	m2.clear();
	print_map(m2.begin(), m2.end()); //m2 after clear
	
	
	/*              Element access             */
	std::cout << "\n*************** Element access ***************" << std::endl;
	std::cout << "operator[10]: " << m[10]  << std::endl;
	std::cout << "operator[69]: " << (m[69] = "holla")  << std::endl;

	std::cout << "\nat 10: " << m.at(10) << std::endl;
	std::cout << "at 69: " << (m.at(10) = "holla again") << std::endl;

	/*              Observers             */
	std::cout << "\n*************** Observers ***************" << std::endl;
	{//value comare tests
		std::map<char,int> mymap;

		std::map<char,int>::key_compare mycomp = mymap.key_comp();

		mymap['a']=100;
		mymap['b']=200;
		mymap['c']=300;

		std::cout << "mymap contains:\n";

		char highest = mymap.rbegin()->first;     // key value of last element

		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mycomp((*it++).first, highest) );

		std::cout << '\n';
	}
	{ //key comp tests
		std::map<char,int> mymap;

		mymap['x']=1001;
		mymap['y']=2002;
		mymap['z']=3003;

		std::cout << "mymap contains:\n";

		std::pair<char,int> highest = *mymap.rbegin();

		std::map<char,int>::iterator it = mymap.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( mymap.value_comp()(*it++, highest) );
	}


	/*              Operations             */
	std::cout << "\n*************** Operations ***************" << std::endl;
	//find
	std::cout << "find(10): " << m.find(10)->first << "  " << m.find(10)->second << std::endl;
	//count
	std::cout << "\ncount(10): " << m.count(10) << std::endl;
	std::cout << "count(11): " << m.count(11) << std::endl;
	//lower_bound
	std::cout << "\nlower_bound of 10: " << m.lower_bound(10)->first << std::endl;
	std::cout << "lower_bound of 10: " << m.upper_bound(10)->first << std::endl;
	//upper_bound
	std::cout << "\nupper_bound of 11: " << m.lower_bound(11)->first << std::endl;
	std::cout << "upper_bound of 11: " << m.upper_bound(11)->first << std::endl;
	//equal_range
	std::cout << "\nequal_range(10): " << m.equal_range(10).first->first << std::endl;
	std::cout << "equal_range(11): " << m.equal_range(11).first->first << std::endl;


	/*              Allocator             */
	std::cout << "\n*************** Allocator ***************" << std::endl;
	//get_allocator
	m.get_allocator();

	/*              Iterators             */
	std::cout << "\n*************** Iterators ***************" << std::endl;
	std::cout << "begin(): " << m.begin()->first << " " << m.begin()->second << std::endl;
	std::cout << "end() - 1: " << (--m.end())->first << " " << (--m.end())->second << std::endl;

	std::cout << "\nIterate through map using iterators: " << std::endl;
	tmp::map<int, std::string>::iterator it = m.begin();
	for(; it != m.end(); it++)
	{
		std::cout << it->first << "  " << it->second << std::endl;
	}
	std::cout << "\nrbegin(): " << m.rbegin()->first << " " << m.rbegin()->second << std::endl;
	std::cout << "rend() - 1: " << (--m.rend())->first << " " << (--m.rend())->second << std::endl;
	std::cout << "\nIterate through map using reverse iterators: " << std::endl;
	tmp::map<int, std::string>::reverse_iterator rit = m.rbegin();
	for(; rit != m.rend(); rit++)
	{
		std::cout << rit->first << "  " << rit->second << std::endl;
	}
} 