#include <iostream>
#include "bst.hpp"
#include "map.hpp"

typedef ft::map<int, std::string>::value_type type;
typedef bst<int, std::string>::mapper_type it;
typedef bst<int, std::string>::Node* node;
int main()
{
    bst<int, std::string> tree;
    // type add = std::make_pair(1, "hello");
    
    tree.insert(new type(1, "hello"));
    tree.insert(new type(3, "hello"));
    tree.insert(new type(5, "hello"));
    tree.insert(new type(-1, "hello"));
    tree.insert(new type(12, "hello"));

    // it b = tree.begin();
    // for (; b != tree.end(); b++)
    // {
    //     std::cout << (*b)->first << std::endl;
    //     node n = tree.find(tree._root, (*b)->first);
    //     tree.remove(n);
    // }
    // node n = tree.find(tree._root, 1);
    tree.remove(12);
    tree.remove(1);
    tree.remove(-1);
    tree.remove(5);
    tree.remove(3);
    // n = tree.find(tree._root, 3);
    // tree.remove(n);
    // n = tree.find(tree._root, 5);
    // tree.remove(n);
    // n = tree.find(tree._root, -1);
    // std::cout << n << std::endl;
    // tree.remove(n);
    // n = tree.find(tree._root, 12);
    // tree.remove(n);
    tree.Inorder(tree._root);
    std::cout << tree.size() << std::endl;
}
// int main()
// {
//     // std::pair<int, std::string> p;
//     // // p.first = 12;
//     // // p.second = "hello";
//     // p.insert(

//     std::map<int, std::string> m;
//     m.insert(std::make_pair(12, std::string("hello")));
//     m.insert(std::make_pair(12, std::string("world")));
//     m.insert(std::make_pair(13, std::string("world")));
//     m.insert(std::make_pair(13, std::string("world")));
//     std::cout << m.size() << std::endl;

// }