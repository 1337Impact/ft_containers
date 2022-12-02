#include "iostream"
// implicit conversion
class test
{
private:
    /* data */
public:
    test(int n){std::cout << "int constructor called\n";};
    test(const std::string &str){std::cout << "std::string constructor called\n";};
    ~test(){};
};
int main(){ 
    test t = 69; // cpp compiler will make a inplicit conversion by calling test(int n) constructor
    test t2 = std::string("hello world"); // implicit conversion from string to test object
    // c++ compiler is able to compile from int to (test object) only cause test has (int constructor)
}

// Explicit Keyword
class test2
{
private:
    /* data */
public:
    explicit test2(int n){std::cout << "int constructor called\n";};
    explicit test2(const std::string &str){std::cout << "std::string constructor called\n";};
    ~test2(){};
};
int main(){ 
    test2 t = 69;
    //adding explicit keyword remove the implicit conversion
}