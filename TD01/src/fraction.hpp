#pragma once
#include <iostream>

struct Fraction {
    unsigned int numerator;
    unsigned int denominator;

    // EX 5 : Opérations d'affectation
    Fraction& operator+=(Fraction const& a);
    Fraction& operator-=(Fraction const& a);
    Fraction& operator*=(Fraction const& a);
    Fraction& operator/=(Fraction const& a);

    // EX 6 : Conversion
    float to_float() const;
    operator float() const;

    //void display();
};

std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

Fraction operator+(Fraction const& f1, Fraction const& f2);
Fraction operator-(Fraction const& f1, Fraction const& f2);
Fraction operator*(Fraction const& f1, Fraction const& f2);
Fraction operator/(Fraction const& f1, Fraction const& f2);

// EX 3-4 : Egalité et comparaison
bool operator==(Fraction const& f1, Fraction const& f2);
bool operator!=(Fraction const& f1, Fraction const& f2);
bool operator<(Fraction const& f1, Fraction const& f2);
bool operator<=(Fraction const& f1, Fraction const& f2);
bool operator>(Fraction const& f1, Fraction const& f2);
bool operator>=(Fraction const& f1, Fraction const& f2);