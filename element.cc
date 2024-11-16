#include"element.hh"
#include"taillePosition.hh"
#include<iostream>
#include<string>

element::element(const Position & p ,const  Taille & t) : _position(p), _taille(t) {}

const Position & element::accesposition() const{
    return _position;
}

const Taille & element::accestaille() const {
    return _taille;
}

std::string element::toString() const {
    return  _position.toString() + _taille.toString();
}

bool element::contientposition( const Position   & p ) const {
    coordonnee x = p.getx();
    coordonnee y = p.gety();
    return (x>=_position.getx() && y>=_position.gety() &&
            x<=_position.getx()+_taille.getLargeur() && y<=_position.gety()+_taille.getHauteur());

}

void  element::setPos(Position p){
    _position.setx(p.getx());
    _position.sety(p.gety());
}

void element::setTaille(Taille t){
    _taille.setHauteur(t.getHauteur());
    _taille.setLargeur(t.getLargeur());
}
