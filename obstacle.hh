#pragma once
#include"element.hh"
#include<string>
class obstacle : public element{
    public:
        obstacle(Position const & p, Taille const & t) ;
        std::string toString () const override;
};
