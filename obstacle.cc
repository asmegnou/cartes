#include"obstacle.hh"

obstacle::obstacle(Position const & p, Taille const & t) : element(p,t){}



std::string obstacle::toString() const {
    return "obs "+ element::toString()+ "\n";
 }
