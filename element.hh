#pragma once
#include"taillePosition.hh"
#include<iostream>
#include<string>

class element {
    public :
        element(const Position &p,const  Taille &t);
        const Taille & accestaille() const;
        const Position & accesposition() const ;
        void setPos(Position p);
        void setTaille(Taille t);
        //virtual nous permet de redéfinir la  methode dans les sous classe
        virtual std::string toString() const ;
        bool contientposition(const Position  & p ) const ;


    private :
        Position _position;
        Taille _taille;
};

