#include"objetramassable.hh"

objetramassable::objetramassable(Position const & p, Taille const & t, int points) : element(p,t), _points(points){}

int objetramassable::getPoint() const {
    return _points;
}


std::string objetramassable::toString() const  {
    return "obj" + element::toString() + " "+std::to_string(_points) +" pts\n";
}
