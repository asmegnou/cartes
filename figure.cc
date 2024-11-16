#include"figure.hh"
#include"point_couleur.hh"
#include<iostream>
#include<string>
#include<cmath>
//METHODE SUR LES FORME GEOMETRIQUE :
//on met la couleur par defaut A blanc
figuregeometrique::figuregeometrique( point const &o) : _couleur(couleur(0,0,0)), _point0(o){
    std::cout<<"constructeur de figure geometrique \n";
}

figuregeometrique::~figuregeometrique(){
    std::cout<<"dextructeur de figure geometrique \n";

}

triangle::triangle( point const &  o, point const &  p1, point const &  p2): figuregeometrique(o), _point1(p1), _point2(p2){
    std::cout<<"constructeur de triangle \n";
}

triangle::~triangle(){
    std::cout<<"destructeur de triangle\n";
}
rectangle::rectangle( point const & o, point const & opp): figuregeometrique(o), _pointOpp(opp){
    std::cout<<"constructeur de rectangle \n";
}

rectangle::~rectangle(){
    std::cout<<"destructeur de rectangle\n";
}

segment::segment( point const &  o, point const &  ext ): figuregeometrique(o),_pointExtrem(ext){
    std::cout<<"constructeur de segment \n";
}

segment::~segment(){
    std::cout<<"destructeur de segment\n";
}


//redefinition de la methode afficher dans differente sous class :

void triangle::afficher() const {
    std::cout<<"figure "<<typefigure();
    std ::cout<<"couleur : "<< _couleur.toString()<<std::endl;
    std::cout<<"point 0 "<<_point0.toString()<<std::endl;
    std::cout<<"point 1 "<<_point1.toString()<<std::endl;
    std::cout<<"point 2 "<<_point2.toString()<<std::endl;

}

void rectangle::afficher() const {
    std::cout<<"figure "<<typefigure();
    std::cout<<"couleur : "<< _couleur.toString()<<std::endl;
    std::cout<<"point 0 "<<_point0.toString()<<std::endl;
    std::cout<<"point opposé : "<<_pointOpp.toString()<<std::endl;
}
void segment::afficher() const {
    std::cout<<"figure "<<typefigure();
    std::cout<<"couleur : "<< _couleur.toString()<<std::endl;
    std::cout<<"point 0 "<<_point0.toString()<<std::endl;
    std::cout<<"point extreme : "<<_pointExtrem.toString()<<std::endl;
}


//denition de la methode memeorigine

bool figuregeometrique::memeorigine(figuregeometrique const & f) const {
    return _point0.compare(f._point0);
}


void triangle::tranlation(const point &p){
    _point0.translater(p);
    _point1.translater(p);
    _point2.translater(p);
}

void rectangle::tranlation(const point &p){
    _point0.translater(p);
    _pointOpp.translater(p);
}

void segment::tranlation(const point &p){
    _point0.translater(p);
    _pointExtrem.translater(p);
}

//il est carre si la hauteur = largeur
bool rectangle::estcarre1() const {
    int hauteur = abs(_pointOpp.getY() - _point0.getY());
    int largeur = abs(_pointOpp.getX() - _point0.getX());
    return hauteur == largeur;
}

bool rectangle::estcarre2() const {
    return estcarre1();
}

bool triangle::estcarre2() const {
    return false;
}

bool segment::estcarre2() const {
    return false;
}

std::string figuregeometrique::typefigure() const {
   return "fig ";
}

std::string segment::typefigure() const {
   return "seg ";
}

std::string triangle::typefigure() const {
    return "tri ";
}

std::string rectangle::typefigure() const {
    return "rec ";
}


int rectangle::hauteur() const {
    return std::abs(_pointOpp.getY() - _point0.getY());  // Calcul de la hauteur
}

int rectangle::largeur() const {
    return abs(_pointOpp.getX()-_point0.getX()); //calcule largeur
}
