#pragma once
#include"element.hh"

class objetramassable : public element{
    public:
        objetramassable(Position const & p, Taille const & t, int points) ;
        int getPoint() const ;
        std::string toString() const override;

    private :
        int _points;

};
