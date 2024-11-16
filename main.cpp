#include <iostream>
#include"figure.hh"
#include"carte.hh"
#include"obstacle.hh"
#include"objetramassable.hh"
#include"personnage.hh"

using namespace std;

int main()
{
  /*  point p;
    point p1(1,5);
    point p3(p1);


    couleur c(0,76,78);
    triangle t1( p,p1,p3);
    rectangle r1(p,p1);
    segment s1( p, p3);
    t1.afficher();;
    r1.afficher();
    s1.afficher();
    std::cout<<"t1 a le meme origine que r1  ? "<<std::boolalpha<<t1.memeorigine(r1)<<std::endl;

    t1.tranlation(p1);
    std::cout<<"triangle apres translation : ";
    t1.afficher();
    std::cout<<std::endl;

    point p2 (4,4);
    rectangle r2(p, p2);
    std::cout<<"en utilisant est carre1 :\n r1 est carré ? "<<std::boolalpha<<r1.estcarre1()<<std::endl;
    std::cout<<"r2 est carré ? "<<std::boolalpha<<r2.estcarre1()<<std::endl;
    std::cout<<"en utilisant estcarre2 : "<<boolalpha<<t1.estcarre2()<<" "<<s1.estcarre2()<<"\n";

    Position po(5,2);
    Position po2(po);
    Taille t(3,8);
    personnage per(po,t,"assia");
    obstacle obs(po,t);
    objetramassable obj(po,t,12);
    carte map(2,7);
    map.ajouterPersonnage(per);
    map.ajouterObstacle(obs);
    map.ajouterObjet(obj);
    map.afficherpersonnages();


    testerIntersection(map);*/

    // Création de la carte
    carte map(10, 10);  // Une carte de 10x10

    // Création de plusieurs personnages
    Position pos1(5, 5);
    Taille taillePersonnage(1, 1);
    personnage per1(pos1, taillePersonnage, "Assia");
    personnage per2(Position(3, 3), taillePersonnage, "moi");

    // Création d'un obstacle
    Position posObstacle(6, 5) , posObj(5,6) , posObj1(4,5);  // Un obstacle juste à droite du personnage
    Taille tailleObstacle(1, 1) ;
    obstacle obs(posObstacle, tailleObstacle);
    map.ajouterObstacle(obs);  // Ajouter l'obstacle à la carte

    objetramassable obj1(posObj,tailleObstacle,6);
    objetramassable obj(posObj1,tailleObstacle,14);
    // Ajouter les personnages à la carte
    map.ajouterPersonnage(per1);
    map.ajouterPersonnage(per2);
    map.ajouterObjet(obj);
    map.ajouterObjet(obj1);

    // Test du déplacement d'Assia
    cout << "Position initiale d'Assia : ";
    cout<<per1.toString();
    map.ramassertout(per1);

    // Déplacement d'Assia vers la droite (dx = 1, dy = 0)
    map.deplacer( deplacement::est,per1);  // Déplacement à droite
    cout<<per1.toString();

    cout << "Position initiale de moi : ";
    cout<<per2.toString();

    map.deplacer( deplacement::sud,per2);  // Déplacement vers le bas
    cout<<per2.toString();




    return 0;
}
