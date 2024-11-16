#include"point_couleur.hh"
#include<iostream>

couleur::couleur (entierCourt r, entierCourt v, entierCourt b) : _rouge(r), _vert(v), _bleu(b){}


std::string couleur::toString() const {
    return "( "+ std::to_string(_rouge) + " , " + std::to_string(_vert) + " , " +  " , " + std::to_string(_bleu) + " ) ";
}

//LES METHODE DE POINT :
point::point () : _x(0), _y(0){
    std::cout<<"constructeur par défaut point \n";
}
point::point ( int x, int y) : _x(x), _y(y){}

//pour definir un constructeur par defaut mais qui affiche : il faut definir son comportement
point::point( point const & p): _x(p._x) , _y(p._y)  {
    std::cout<<"constructeur par recopie point \n";
}
point::~point(){
    std::cout<<"destructeur point \n";
}

std::string point::toString() const {
    return "( " + std::to_string( _x) + " , " + std::to_string(_y) + " )";
}

bool  point::compare(point const & p) const {
    return p._x==_x && p._y==_y;
}

int point::getX() const {
    return  _x;
}
int point::getY() const {
    return _y;
}

void point::translater(point const & p ){
    _x+=p._x;
    _y+=p._y;
}


