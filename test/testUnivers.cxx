#include "Univers.h"


int main(){
    int dim=2;
    int nbrParticules = pow(2,5);
    Univers u = Univers(nbrParticules, dim);
    cout<< "La dimension de l'univers est : "<<dim<<"\n";
    cout<<"Le nombre de particules de l'univers est : "<<nbrParticules<<"\n";
    double delta_t =0.5 ;
    double t_end=10;
    double t=0;
    while(t<t_end){
        t+=delta_t;
        cout<< "L'état du systeme à l'instant : " << t <<"  est : \n";
        u.displayUniversState();
        u.updateForces();
        u.updatePositions(delta_t);
        u.updateSpeeds(delta_t);
        t+=delta_t;
    }
    return 0;
}