#include <iostream>
#include <vector>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;
};

// 1. Surchargez l'opérateur == pour la structure Card (deux cartes sont égales si elles ont la même valeur et la même couleur).
bool operator==(Card const& a, Card const& b){
    return a.kind == b.kind && a.value == b.value;
}

// 2. et 3. Écrire une méthode hash pour la structure Card qui retourne un entier.
size_t hash(Card const& card){
    size_t kind_value = static_cast<size_t>(card.kind);
    size_t value_value = static_cast<size_t>(card.value);

    size_t card_hash = kind_value * 13 + value_value;

    return card_hash;
}

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return ::hash(card);
        }
    };
}

std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

std::string card_name(Card const& card) {
    std::string name {};

    unsigned int card_value {(static_cast<unsigned int>(card.value)+2) % 14};

    if (card_value < 10) {
        name += '0' + card_value;
    }else if (card_value == 10) {
        name += "10";
    }else if (card_value == 11) {
        name += 'V';
    }else if (card_value == 12) {
        name += 'Q';
    }else if (card_value == 13) {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart) {
        name += "Heart";
    }else if (card.kind == CardKind::Diamond) {
        name += "Diamond";
    }else if (card.kind == CardKind::Club) {
        name += "Club";
    }else if (card.kind == CardKind::Spade) {
        name += "Spade";
    }
    return name;
}

int main(){
    // 4. Utiliser la fonction get_cards pour générer une liste de 100 cartes aléatoires. Utiliser une table de hachage std::unordered_map pour compter le nombre de fois que chaque carte apparaît dans la liste et afficher le résultat.
    std::vector<Card> cartes = get_cards(100);
    std::unordered_map<Card, int> occurrences_cartes {};

    for (size_t i = 0; i < cartes.size(); i++)
    {
        auto it = occurrences_cartes.find(cartes[i]);

        if (it == occurrences_cartes.end()) 
        {
            occurrences_cartes[cartes[i]] = 1;
        } 
        else 
        {
            occurrences_cartes[cartes[i]]++;
        }
    }

    for (const auto& carte : occurrences_cartes)
    {
        std::cout << card_name(carte.first) << " : " << carte.second << std::endl;
    }
     
}