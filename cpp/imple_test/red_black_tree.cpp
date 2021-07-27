#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;

template <typename T>
class Node
{
private:
    T value;
    Node* left;
    Node* right;
    bool is_root;

public:
    Node(T value = 0, Node* left = nullptr, Node* right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }

    Node* GetLeft(){
        return this->left;
    }
    Node* GetRight(){
        return this->right;
    }

    void SetLeft(Node* new_left){
        this->left = new_left;
    }
    void SetRight(Node* new_right){
        this->right = new_right;
    }
};

template <typename T>
class Tree{
private:
    Node<T>* root;
public:
    Tree(T root_val = 0){
        root = new Node<T>(value);
    }

    Node<T>* GetRoot(){
        return this->root;
    }
    
};

template <typename T>
class RBT : public Tree 
{
private:
    int numNodes;
    Node<T>* dummy;



};


class RBT {

private:
    int num_b;
    

public:
    RBT(){

    }

    void 



}




int main() {




}