#include "Vecteur.h"
using namespace std;
#include <random>
#include <iostream>



Vecteur :: Vecteur(int dim){
    random_device rd;  
    mt19937 mt(rd()); 
    uniform_real_distribution<double> dist(0.0,1.0);
    d = dim;
    tab = new double[dim];
    for (int i = 0; i< d; i++)
        tab[i] = dist(mt);
}
/* Vecteur :: Vecteur(){
    Vecteur(2);
} */
Vecteur :: Vecteur(){
    Vecteur v =Vecteur(2);
    d=2;
    tab=v.tab;
}
Vecteur :: Vecteur(const Vecteur & other){
    d = other.d;
    tab = new double[d];
    for (int i = 0; i< d; i++)
        tab[i] = other.tab[i];
}

Vecteur Vecteur::operator +(const Vecteur & other ){
    Vecteur  v = Vecteur(d);
    v.tab = new double[d];
    for (int i = 0; i< d; i++)
        v.tab[i] = tab[i] + other.tab[i];
    return v;
}
Vecteur Vecteur::operator -(const Vecteur & other ){
    Vecteur  v = Vecteur(d);
    v.tab = new double[d];
    for (int i = 0; i< d; i++)
        v.tab[i] = tab[i] - other.tab[i];
    return v;
}
Vecteur Vecteur::operator *(double  lambda){
    Vecteur  v = Vecteur(d);
    v.tab = new double[d];
    for (int i = 0; i< d; i++)
        v.tab[i] = tab[i]*lambda;
    return v;
}
void Vecteur::display(){
    cout << "{";
    for (int i = 0; i< d-1; i++)
        cout << tab[i] <<",";
    cout << tab[d-1]<<"}" << endl;
}
Vecteur Vecteur::operator +(double lambda ){
    Vecteur  v = Vecteur(d);
    v.tab = new double[d];
    for (int i = 0; i< d; i++)
        v.tab[i] = tab[i]+lambda;
    return v;
}
Vecteur Vecteur::operator *(const Vecteur & other){
    Vecteur  v = Vecteur(d);
    v.tab = new double[d];
    for (int i = 0; i< d; i++)
        v.tab[i] = tab[i]*other.tab[i];
    return v;
}
