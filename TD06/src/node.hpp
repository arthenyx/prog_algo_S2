#pragma once

#include <vector>

struct Node {
    int value;
    Node* left { nullptr };
    Node* right { nullptr };

    bool is_leaf() const;
    void Node::insert(int value);
    int Node::height() const;
    void Node::delete_childs();
    void Node::display_infixe() const;
    std::vector<Node const*> Node::prefixe() const;
    std::vector<Node const*> Node::postfixe() const;
    Node*& most_left(Node*& node);
    bool remove(Node*& node, int value);
    void delete_tree(Node* node);
};

Node* create_node(int value);
void delete_tree(Node* tree);