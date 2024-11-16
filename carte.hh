#pragma once
#include"figure.hh"
#include"element.hh"
#include"obstacle.hh"
#include"objetramassable.hh"
#include"personnage.hh"
#include"taillePosition.hh"
#include<list>

enum class deplacement{
    nord,sud,est,ouest
};

class carte : public rectangle{
    public :
        carte(int hauteur, int largeur);
        void ajouterPersonnage(personnage const & p);
        void ajouterObstacle(obstacle const & obs);
        void ajouterObjet(objetramassable const & obj);
        void afficherpersonnages() const ;
        bool intersectionelements(const element &e1 , const element &e2) const ;
        bool deplacementpossible(const  personnage &p , const deplacement &dep) const ;
        void deplacer(const deplacement & dep , personnage &p );
        bool ramassagepossible(const personnage &p, const objetramassable& obj) const ;
        void ramassertout( personnage &p);

    private :
        std::list<personnage> _personnages;
        std::list<obstacle> _obstacles;
        std::list<objetramassable> _objetramassable;


};

bool intervalIntersect(coordonnee x1, coordonnee y1,coordonnee x2, coordonnee y2 );
void testerIntersection(const carte &maCarte);
