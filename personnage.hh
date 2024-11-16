#pragma once
#include"element.hh"
#include"taillePosition.hh"
#include"objetramassable.hh"
#include<string>

class personnage : public element{
    public:
    personnage(Position const & p, Taille const & t, std::string nom) ;
    int getPoint() const ;
    std::string getNom() const;
    std::string toString() const override;
    void  ramasser(objetramassable const & obj );

    private:
        int _points;
        std::string _nom;

};
