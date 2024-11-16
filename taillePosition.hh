#pragma once
#include<iostream>
#include<string>
using coordonnee = int;

class Position{
public:
    Position(coordonnee x, coordonnee y);
    Position(Position const & p);
    coordonnee getx() const ;
    coordonnee gety() const ;
    void setx(coordonnee x);
    void sety(coordonnee y);
    bool comparaison(Position const & p);
    std::string toString() const ;

private:
    coordonnee _x;
    coordonnee _y;

};


class Taille {
public:
    Taille(coordonnee h, coordonnee l);
    coordonnee getHauteur() const;
    coordonnee getLargeur() const;
    void setHauteur(coordonnee h);
    void setLargeur(coordonnee l);
    std::string toString() const ;

private:
    coordonnee _largeur;
    coordonnee _hauteur;
};


void test1();
