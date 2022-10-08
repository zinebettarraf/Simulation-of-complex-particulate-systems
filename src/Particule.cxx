#include <iostream>
#include <random>
#include <chrono>

#include<set>
#include<list>
#include<deque>
#include<vector>
#include "Vecteur.h"
#include "Particule.h"


using namespace std ; 




Particule :: Particule (){
    random_device rd;  // the seed value 
    mt19937 mt(rd()); // random number
    uniform_real_distribution<double> dist(0.0,1.0);   // distribution uniform sur a ,b 
    uniform_real_distribution<double> massdistribution(0.0,0.01);  // pb mass
    position=Vecteur(2);
    speed=Vecteur(2);
    force = dist(mt) ;
    mass =massdistribution(mt);
    id  = rand()%10;
    type = "No type";
    }
Particule :: Particule(int dim,Vecteur speedpar){
    // creer des particules uniformes 
    random_device rd;  // the seed value 
    mt19937 mt(rd()); // random number
    uniform_real_distribution<double> dist(0.0,1.0);   // distribution uniform sur a ,b 
    uniform_real_distribution<double> massdistribution(0.0,0.01);  // pb mass
    position=Vecteur(dim);
    speed=Vecteur(speedpar);
    force = dist(mt) ;
    mass =massdistribution(mt);
    id  = rand()%10;
    type = "No type";
}
 Particule ::  Particule (Vecteur positionpar,Vecteur speedpar,double masspar,string typepar,double idpar){
     position=Vecteur(positionpar);
     mass=masspar;
     id=idpar;
     type=typepar;
     speed=Vecteur(speedpar);
 }


void  Particule ::  display(){
    cout<<"position :";positionDisplay();
    cout<<"speed :";speedDisplay();
}
void  Particule ::  positionDisplay(){
    position.display();
}
void  Particule :: speedDisplay(){
    speed.display();
}
void  Particule ::  forceDisplay(){
    force.display();

}
void  Particule :: updateForce(Particule & p){
    Vecteur distance_orientee= position - p.position;
    double distance = distanceParicles(position,p.position);
    if(distance==0) return;
    force= Vecteur(force + distance_orientee*((mass*p.mass)/pow(distance,3)));
}
void  Particule ::  computeF(deque<Particule> & tab){
    for(auto it:tab)  updateForce(it);
    

}
void  Particule :: updatePosition(double delta_t){
    position = position + (speed + force*delta_t*(0.5/mass))*delta_t;
}
void  Particule ::  updateSpeed(double delta_t){
    speed = speed + (force+oldForce)*(delta_t*0.5/mass);
}





