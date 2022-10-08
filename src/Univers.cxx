#include <string>
#include <bits/stdc++.h>
#include "Univers.h"
#include "Particule.h"

using namespace std;

Univers :: Univers(int nbrParticules, int dim){
    // uniforme universe
    this->dim = dim;
    this-> nbrParticules = nbrParticules;
    Vecteur initSpeed = Vecteur(dim);
    for (int i = 0; i< nbrParticules; i++) collection.push_back(Particule(dim, initSpeed));
}

void Univers :: displayUniversState(){
    cout << "dimension  :" << dim << endl;
    cout << "number of particles  :" << nbrParticules << endl;

    cout << "les paricules : "<< endl ;
    for(auto it :collection) it.display();

    }
void Univers :: updatePositions(double delta_t){
    for(auto it :collection) it.updatePosition(delta_t);
}
void Univers :: updateForces(){
    
    for(auto it :collection){ it.computeF(collection);} 
}
void Univers :: updateSpeeds(double delta_t){
    for(auto it :collection) it.updateSpeed( delta_t);
}