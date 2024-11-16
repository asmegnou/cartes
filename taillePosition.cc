#include "taillePosition.hh"
#include<iostream>
#include<string>

using namespace std;
Position::Position(coordonnee x, coordonnee y):_x(x),_y(y){}
Position::Position(Position const & p ): _x(p._x) , _y(p._y){}

coordonnee Position::getx() const{
    return _x;
}

coordonnee Position::gety() const {
    return _y;
}

void Position::setx(coordonnee x){
    _x=x;
}

void Position::sety(coordonnee y){
    _y=y;
}

bool Position::comparaison(Position const &p){
    return p._x== this->_x && p._y== this->_y;
}

Taille::Taille(coordonnee h, coordonnee l) : _largeur(l), _hauteur(h){}

coordonnee Taille::getHauteur() const {
    return _hauteur;
}

coordonnee Taille::getLargeur() const {
    return _largeur;
}

void Taille::setHauteur(coordonnee h){
    _hauteur=h;
}

void Taille::setLargeur(coordonnee l){
    _largeur=l;
}



void test1(){
    Position p(5,2);
    Position p2(p);
    Taille t(3,8);
    cout<<"x :"<<p.getx()<<"\ny:"<<p.gety()<<"\n";
    cout<<boolalpha<<p.comparaison(p2)<<"\n";
    cout<<"hauteur :"<<t.getHauteur()<<"\nlargeur: "<<t.getLargeur()<<"\n";
}

//il faut caster
std::string Taille::toString() const {
    return "[ "+ std::to_string(this->_hauteur) + " ,  "+std::to_string(this->_largeur) + " ]";
}

std::string Position::toString() const {
    return "( " + std::to_string( _x) + " , " + std::to_string(_y) + " )";
}
