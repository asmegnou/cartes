#include "carte.hh"


carte::carte(int hauteur, int largeur) :rectangle(point(0,0) , point(largeur,hauteur))  {}

void carte::ajouterPersonnage(personnage const & p){
    _personnages.push_back(p);
}
void carte::ajouterObstacle(obstacle const & obs){
    _obstacles.push_back(obs);

}
void carte::ajouterObjet(objetramassable const & obj){
    _objetramassable.push_back(obj);
}

void carte::afficherpersonnages() const {
    std::cout<<"taile de la carte : "<<hauteur()<<" x "<<largeur()<<std::endl;
    std::cout<<"Personnages : ";
    //envoyer l'objet par reference constante pour ne pas faire des recopie inutile
    for(const auto & p : _personnages){
        std::cout<<p.toString()<<"\n";
    }
}

bool intervalIntersect (coordonnee x1, coordonnee y1,coordonnee x2, coordonnee y2)
{
    return !(y1 < x2 || y2 < x1);
}

bool carte::intersectionelements(const element &e1, const element &e2) const{
    //acceder a position et taille des deux element
    Position  pos1 = e1.accesposition() ,  pos2 = e2.accesposition();
    Taille taille1 = e1.accestaille() , taille2 = e2.accestaille();

    //calculer les extrimité
    coordonnee e1_x = pos1.getx(), e1_y =pos1.gety(), e2_x = pos2.getx(), e2_y =pos2.gety();
    coordonnee e1_h = taille1.getHauteur(), e1_l =taille1.getLargeur(),  e2_h = taille2.getHauteur(), e2_l =taille2.getLargeur();


    bool intersectX = intervalIntersect(e1_x,e1_l, e2_x, e2_l);
    bool intersectY = intervalIntersect(e1_y,e1_h, e2_y, e2_h);
    return intersectX && intersectY;

}

void testerIntersection(const carte &maCarte) {
    // Création de deux éléments qui s'intersectent
    element elem1(Position(10, 10), Taille(20, 20)); // Rectangle de (10,10) à (30,30)
    element elem2(Position(15, 15), Taille(20, 20)); // Rectangle de (15,15) à (35,35)

    // Création de deux éléments qui ne s'intersectent pas
    element elem3(Position(50, 50), Taille(20, 20)); // Rectangle de (50,50) à (70,70)
    element elem4(Position(80, 80), Taille(10, 10)); // Rectangle de (80,80) à (90,90)

    // Test d'intersection
    std::cout << "Test 1: elem1 et elem2 (intersection attendue) -> "
              << (maCarte.intersectionelements(elem1, elem2) ? "VRAI" : "FAUX") << std::endl;

    std::cout << "Test 2: elem1 et elem3 (pas d'intersection attendue) -> "
              << (maCarte.intersectionelements(elem1, elem3) ? "VRAI" : "FAUX") << std::endl;

    std::cout << "Test 3: elem3 et elem4 (pas d'intersection attendue) -> "
              << (maCarte.intersectionelements(elem3, elem4) ? "VRAI" : "FAUX") << std::endl;

    std::cout << "Test 4: elem2 et elem4 (pas d'intersection attendue) -> "
              << (maCarte.intersectionelements(elem2, elem4) ? "VRAI" : "FAUX") << std::endl;
}



bool carte::deplacementpossible(const  personnage &p , const deplacement &dep) const {
    Position pos = p.accesposition();
    switch(dep){
        case deplacement::nord:  pos.sety(pos.gety()+1);  break;
        case deplacement::est:   pos.setx(pos.getx()+1);  break;
        case deplacement::ouest: pos.setx(pos.getx()-1); break;
        case deplacement::sud:   pos.sety(pos.gety()-1);    break;
        default : return false;
    }

    //maintenant position est modifié on vas verifier si elle ne depasse pas les limite de carte
    if( pos.getx()<0 || pos.gety()<0 ||
        pos.getx() >= largeur() ||
        pos.gety() >= hauteur() ){
        return false;
    }
    //maintenant on vas verifier si la position n'est pas occupe par aucun autre element
    for(const auto & e : _personnages){
        if(e.contientposition( pos)){
            return false;
        }
    }
    for(const auto & e : _obstacles){
        if(e.contientposition( pos)){
            return false;
        }
    }
    for(const auto & e : _objetramassable){
        if(e.contientposition( pos)){
            return false;
        }
    }

    return true ;
}

void carte::deplacer(const deplacement & dep,  personnage & p  ){
    //tout d'abord verifier si le personnage existe bien dans la liste des personnage
    //auto it = std::find(_personnages.begin(), _personnages.end(), p);
    //ERREUR : il faut que la classe personnage supporte l'opérateur == , ON A PAS ENCORE FAIT CECI EN COURS
    //dans ce cas on suppose que le personnage passé en parametre est bien présent dans la carte
    //le personnage est bien present
    //if(it != _personnages.end()){
        if(deplacementpossible(p, dep)){
            Position pos = p.accesposition();
            switch(dep){
                case deplacement::nord: pos.sety(pos.gety()+1);
                                        p.setPos(pos);
                                        break;

                case deplacement::est:  pos.setx(pos.getx()+1);
                                        p.setPos(pos);
                                        break;

                case deplacement::ouest: pos.setx(pos.getx()-1);
                                         p.setPos(pos);
                                         break;

                case deplacement::sud:   pos.sety(pos.gety()-1);
                                         p.setPos(pos);
                                         break;
                default : std::cout<<"";
            }
            std::cout<<"deplacement effectuer avec succès\n";
        }else{
            std::cout<<"impossible de deplacer le personnage  \n";
        }
    /*}else{
        std::cout<<"impossible de déplacer le personnage il n'est pas présent dans la carte \n";
    }*/
}

bool carte::ramassagepossible(const personnage& p, const objetramassable& obj) const  {
    // Accéder aux positions du personnage et de l'objet
    Position pos_personnage = p.accesposition();
    Position pos_objet = obj.accesposition();

    // Vérifier si les positions sont voisines (toucher)
    int dx = std::abs(pos_personnage.getx() - pos_objet.getx());
    int dy = std::abs(pos_personnage.gety() - pos_objet.gety());

    // Le personnage peut ramasser l'objet si les positions sont voisines
    if ((dx == 0 && dy == 1) || (dx == 1 && dy == 0) || (dx == 0 && dy == 0)) {
        return true; // L'objet est adjacent ou sur la même position que le personnage
    }

    // Sinon, le ramassage n'est pas possible
    return false;
}

void carte::ramassertout( personnage &p) {
    // Parcourir tous les objets dans la collection _objetramassable
    for ( auto  it = _objetramassable.begin(); it != _objetramassable.end();) {
        // Vérifier si le personnage peut ramasser l'objet
        if (ramassagepossible(p, *it)) {
            std::cout << "Ramassage de l'objet : " << (*it).toString() << std::endl;
            p.ramasser(*it);
            it = _objetramassable.erase(it);
        } else {
            std::cout << "L'objet n'est pas ramassé." << std::endl;
            ++it;
        }
    }
}

