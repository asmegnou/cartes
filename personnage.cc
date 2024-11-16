#include"personnage.hh"
#include"objetramassable.hh"
#include<string>

personnage::personnage(Position const & p, Taille const & t, std::string nom) : element(p,t), _nom(nom) ,_points(0) {}

int personnage::getPoint() const{
    return _points;
}
std::string personnage::getNom() const{
    return _nom;
}

//redéfinition de la methode tostring
std::string personnage::toString() const {
    std::string baseStr = element::toString(); //recuperer le toString de element
    return "per" + baseStr + " " + std::to_string(_points)+" pts "+ _nom +"\n";
}

void personnage::ramasser(const objetramassable &obj){
    _points+= obj.getPoint();
}
