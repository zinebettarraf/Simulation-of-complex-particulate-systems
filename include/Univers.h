#include <string>
#include <bits/stdc++.h>
#include "Particule.h"



using namespace std;

#ifndef UniversH
#define UniversH

class Univers
{
    public:
        int dim;
        int nbrParticules;
        deque<Particule> collection;
        Univers(int nbrParticules, int dim);
        Univers(const Univers & other);
        void updatePositions(double delta_t);
        void updateForces( );
        void updateSpeeds(double delta_t);
        void displayUniversState();
};

#endif