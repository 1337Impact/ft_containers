#include <iostream>
#include "map.hpp"

// template <class T>
// struct node
// {
//     T data;
//     node<T> *left_child;
//     node<T> *right_child;
//     node(){}
//     // node(const node<T> &obj){std::cout << "hi";}
//     ~node(){}
// };


// template <class T>
// class bst
// {
// private:
//     node<T> *root;
// public:
//     bst():root(0){}
//     ~bst(){}
//     void insert(const node<T> &child)
//     {
//         if (!root)
//             root = new node<T>(child);
//         else{
//             if (child.data <= root->data)
//             {
//                 root->left_child = 
//             }
//         }
//     }
// };

struct t_tree
{
    int data;
    t_tree *parent;
    t_tree *left_child;
    t_tree *right_child;
    t_tree(int val):data(val),left_child(0), right_child(0), parent(0){}
};
t_tree *insert(t_tree *root, t_tree *child)
{
    if (!root) //last node
    {
        return child;
    }
    else if(child->data < root->data)
    {
        root->left_child = insert(root->left_child, child);
    }
    else if(child->data > root->data)
    {
        root->right_child = insert(root->right_child, child);
    }
    return root;
}


int main()
{
    t_tree root = 13;
    t_tree child = 12;
    t_tree child2 = 50;
    t_tree child3 = 60;
    insert(0, &root);
    insert(&root, &child);
    insert(&root, &child2);
    insert(&root, &child3);
    std::cout << root.left_child->data << std::endl;
    std::cout << root.right_child->data << std::endl;
    std::cout << root.right_child->right_child->data << std::endl;
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