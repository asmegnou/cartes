#pragma once
#include"point_couleur.hh"
#include<string>

//on définie la class figuregeometrique  en tant que classe abstraite  parceque elle ne vas jamais etre instancier
//pour cela la methode afficher on la definit en virtual pure

//je ne vais pas mettre la couleur dans le constructeur parceque plustard pou definir carte j'ai besoin de couleur ce qui n'est pas demandé
//dans ce cas je vais faire un setter pour cela pour definir la couleur hors du constructeur et et mettre une couleur par default blanc parexample
//lors du contructeur
class figuregeometrique{
    public :
        figuregeometrique ( point const & o);
        ~figuregeometrique ();
        void setCouleur(couleur c );
        virtual void afficher() const = 0;
        bool  memeorigine(figuregeometrique const & f) const;
        virtual void tranlation(point const & p ) = 0 ;
        virtual bool estcarre2() const = 0;
        virtual std::string typefigure () const ;
     //on mets les attribut a protected pour pouvoir les appelé dans les sous classe
     protected:
        couleur _couleur;
        point _point0;
};


//definir afficher avec override
class segment : public figuregeometrique{
    public:
        segment( point const & o , point const & ext);
        ~segment();
        void afficher () const override;
        void tranlation(point const & p ) override;
        bool estcarre2() const override;
        std::string typefigure () const override;
    private:
        point _pointExtrem;
};

class triangle :public figuregeometrique{
    public:
        triangle ( point const & o , point  const & p1, point  const & p2 );
        ~triangle ();
        void afficher () const override;
        void tranlation(point const & p ) override;
        bool estcarre2() const override;
        std::string typefigure () const override;


    private:
        point _point1  , _point2;

};


class rectangle : public figuregeometrique{
    public :
        rectangle( point const &  o , point  const & opp);
        ~rectangle();
        void afficher () const override;
        void tranlation(point const & p ) override;
        bool estcarre1() const ;
        bool estcarre2() const override;
        std::string typefigure () const override;
        int hauteur() const;
        int largeur() const;

    private :
        point _pointOpp;
};


