#include <iostream>
#include "node.hpp"

int main(){
    // 1. Créer un arbre binaire et insérer les valeurs suivantes: 5, 3, 7, 2, 4, 6, 8, 1, 9, 0.
    Node* root = create_node(5);

    root->insert(3);
    root->insert(7);
    root->insert(2);
    root->insert(4);
    root->insert(6);
    root->insert(8);
    root->insert(1);
    root->insert(9);
    root->insert(0);

    // 2. Afficher les valeurs des nœuds de l'arbre binaire dans l'ordre infixe.
    root->display_infixe();
    std::cout << std::endl;

    // 4. Afficher la somme des valeurs des nœuds de l'arbre binaire en utilisant la fonction prefixe qui retourne un vecteur contenant les nœuds parcourus dans l'ordre prefixe.
    int sum = 0;
    std::vector<Node const*> prefix_nodes = root->prefixe();
    for (Node const* node : prefix_nodes) 
    {
        sum += node->value;
    }
    std::cout << "Somme des valeurs des noeuds : " << sum << std::endl;

    // 5. Afficher la hauteur de l'arbre binaire.
    int height = root->height();
    std::cout << "Hauteur de l'arbre binaire : " << height << std::endl;

    delete_tree(root);
}