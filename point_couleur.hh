#pragma once
#include<iostream>
using entierCourt =  unsigned short int;

class  couleur {

    public :
        couleur(entierCourt r,entierCourt v, entierCourt b);
        std::string toString() const ;
    private :
        entierCourt _rouge;
        entierCourt _vert;
        entierCourt _bleu;
};


class point {
public :
    point();
    point( int x, int y);
    point( point const & p);
    ~point();
    std::string toString() const ;
    //methode retourne vrai si les deux point sont egale
    bool compare(point const & p ) const ;
    int getX() const ;
    int getY() const ;
    void translater(point const & p) ;


private :
    int _x;
    int _y;
};
