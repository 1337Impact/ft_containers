#include <vector>
#include <iostream>
#include <memory>
#include "vector.hpp"

class test
{
private:
    /* data */
public:
    int b;
    test(/* args */);
    test(int n):b(n){}
    test(const test&t){
        // b = new int();
        // *b = *(t.b);
        std::cout << "copy constructed\n";
    }
    void print(){
        std::cout << "printed" << std::endl;
    }
    ~test();
};
test::test(/* args */)
{
    // b = new int();
    std::cout << "constructed\n";
}
test::~test()
{
    // delete b;
    std::cout << "distructed\n";
}



int main()
{
    // std::cout << "********* ft ********" << std::endl;
    // ft::vector<test> v(10);
    // v.clear();
    std::cout << "********* std ********" << std::endl;
    // std::vector<test> v1;
    // std::vector<test> v2;
    // v1.push_back(test(42));
    // v2.push_back(test(69));
    // std::cout << (v1.front()).b << std::endl;
    ft::vector<int> v1(3, 98);
    int * d = v1.data();
    std::cout << *(d+1) << std::endl;

    

    // std::cout << "*********" << std::endl;
    // v2.resize(3);
    // std::cout << "capacity: " << v2.capacity() << std::endl;
    // std::cout << "size: " << v2.size() << std::endl;





    // v2.reserve(4);
    // std::allocator<test> n;
    // std::allocator<test>::pointer t = n.allocate(10);
    // // std::cout << t[0] << std::endl;
    // // (t[0])(test());
    // n.construct(t, test());
    // test *t = 


    std::cout << "end\n";



    // std::allocator<test> n;
    // test *t_ptr;
    // {
    // t_ptr = n.allocate(2);
    // n.construct(t_ptr);
    // n.destroy(t_ptr);
    // // n.construct(t_ptr + 1);
    // std::cout << t_ptr << std::endl;
    // }


    // std::cout << n.address() << std::endl;
    // n.construct(n.address());
    // std::allocator<int> aloc
    // std::cout << v.size() << std::endl;
    // std::vector<int> v(2);
    // std::vector<int> v2(v);
    // v[0] = 69;
    // v2[0] = 10;
    // std::cout << v2.capacity() << std::endl;
    // std::cout << v2[0] << std::endl; 

}