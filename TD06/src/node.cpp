#include <iostream>
#include <vector>
#include "node.hpp"

void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value){
    Node* newNode { new Node };
    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

bool Node::is_leaf() const {
    if (left == nullptr && right == nullptr)
    {
        return true;
    }
    else {
        return false;
    }
}

void Node::insert(int value){
    if (value < this->value) 
    {
        if (left == nullptr) 
        {
            left = create_node(value);
        } 
        else {
            left->insert(value);
        }
    } 
    else {
        if (right == nullptr) 
        {
            right = create_node(value);
        } 
        else {
            right->insert(value);
        }
    }
}

int Node::height() const{
    if (this == nullptr) 
    {
        return 0;
    } 
    else {
        int left_height {};
        int right_height {};

        if (left == nullptr)
        {
            left_height = 0;
        }
        else {
            left_height = left->height();
        }

        if (right == nullptr)
        {
            right_height = 0;
        }
        else {
            right_height = right->height();
        }

        return 1 + std::max(left_height, right_height);
    }
}

void Node::delete_childs(){
    if (left) 
    {
        left->delete_childs();
        delete left;
        left = nullptr;
    }

    if (right) 
    {
        right->delete_childs();
        delete right;
        right = nullptr;
    }
}

void Node::display_infixe() const{
    if (left) 
    {
        left->display_infixe();
    }

    std::cout << " " << value << " ";

    if (right) 
    {
        right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> nodes;
    nodes.push_back(this);

    if (left) 
    {
        auto left_nodes = left->prefixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }

    if (right) 
    {
        auto right_nodes = right->prefixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }

    return nodes;
}

std::vector<Node const*> Node::postfixe() const{
    std::vector<Node const*> nodes;
    nodes.push_back(this);

    if (left) 
    {
        auto left_nodes = left->postfixe();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }

    if (right) 
    {
        auto right_nodes = right->postfixe();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }

    return nodes;
}

Node*& most_left(Node*& node){
    if (node->left) 
    {
        return most_left(node->left);
    } 
    else {
        return node;
    }
}

bool remove(Node*& node, int value){
    if (!node) {
        return false;
    }

    if (value == node->value && node->is_leaf()) {
        // On supprime le nœud courant
        delete node;
        // Comme on a une référence sur le pointeur du nœud courant, on le met à jour avec nullptr
        // Ainsi le parent du nœud courant aura un pointeur vers nullptr
        node = nullptr;
        // on retourne true car la suppression a été effectuée
        return true;
    }

    if (value < node->value) 
    {
        return remove(node->left, value);
    }
    else if (value > node->value)
    {
        return remove(node->right, value);
    }
    else {
        if (node->is_leaf())
        {
            delete node;
            node = nullptr;
        }
        else if (!node->left)
        {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        else if (!node->right)
        {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        else {
            Node*& next = most_left(node->right);
            node->value = next->value;
            remove(next, next->value);
        }
        return true;
    }
}

void delete_tree(Node* node){
    if (!node) 
    {
        return;
    }
        
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}