using namespace std;

#ifndef VecteurH
#define VecteurH

class Vecteur {
    public :
    int d; //dimension   
    double* tab;
    Vecteur (int dim);
    Vecteur ();
    Vecteur(const Vecteur & other);
    Vecteur operator +(const Vecteur & other );
    Vecteur operator *(double lambda );
    Vecteur operator +(double lambda );
    Vecteur operator *(const Vecteur & other);
    Vecteur operator -(const Vecteur & other );
    void display();
};

#endif