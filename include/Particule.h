#include <string>
#include <bits/stdc++.h>
#include "Vecteur.h"

using namespace std;

#ifndef ParticuleH
#define ParticuleH
 
class Particule {
    public :
    Vecteur position; 
    Vecteur speed;
    double mass ;
    Vecteur force;
    Vecteur oldForce;
    string type;
    double id;
    int dim;
    Particule (Vecteur positionpar,Vecteur speedpar,double masspar,string typepar,double idpar);
    Particule ();
    Particule(int dim,Vecteur speedpar);
    void display();
    void positionDisplay();
    void speedDisplay();
    void forceDisplay();
    void computeF(deque<Particule> & tab);
    void updatePosition(double delta_t);
    void updateSpeed(double delta_t);
    void updateForce(Particule & p);

};

inline double distanceParicles (Vecteur position1,Vecteur position2){
    double s = 0;
    for(int i = 0; i < position1.d; i++)
        s+=pow(position1.tab[i]-position2.tab[i],2);
    return sqrt(s);
}


#endif