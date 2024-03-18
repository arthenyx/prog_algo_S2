#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>


// void Fraction::display() {
//     std::cout << numerator << "/" << denominator;
// }

// EX 2 : Affichage
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator << "/" << fraction.denominator;
    return os;
}


// EX 5 : Opérations d'affectation
Fraction operator+=(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator-=(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

Fraction operator*=(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}

Fraction operator/=(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}


Fraction operator+(Fraction const& f1, Fraction const& f2) {
    return f1 += f2;
}

Fraction operator-(Fraction const& f1, Fraction const& f2) {
    return f1 -= f2;
}

Fraction operator*(Fraction const& f1, Fraction const& f2) {
    return f1 *= f2;
}

Fraction operator/(Fraction const& f1, Fraction const& f2) {
    return f1 /= f2;
}


// EX 3-4 : Egalité et comparaison
bool operator==(Fraction const& f1, Fraction const& f2){
    return f1.numerator * f2.denominator == f1.denominator * f2.numerator;
}

bool operator!=(Fraction const& f1, Fraction const& f2){
    return !(f1 == f2);
}

bool operator<(Fraction const& f1, Fraction const& f2){
    return f1.numerator * f2.denominator < f1.denominator * f2.numerator;
}

bool operator<=(Fraction const& f1, Fraction const& f2){
    return !(f2 < f1);
}

bool operator>(Fraction const& f1, Fraction const& f2){
    return f1 > f2;
}

bool operator>=(Fraction const& f1, Fraction const& f2){
    return !(f1 < f2);
}


// EX 6 : Conversion
float Fraction::to_float() const{
    return static_cast<float>(numerator)/static_cast<float>(denominator);
}

Fraction::operator float() const{
    return to_float();
}
