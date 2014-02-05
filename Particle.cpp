#include "Particle.h"

   /**
   *  Constructor
   */

Particle::Particle ( double P_energy, Vec2& position, Vec2& direction ) : energy(P_energy), position(position), direction(direction) {}
Particle::Particle() : energy(0){ }
Particle::~Particle ( ) { }

   /**
   *  Funktion bewegt Particle um delta_position in richtung der p_direktion und schreibt position
   *  von Particle auf neuen Wert.
   */
void Particle::move(double delta_position){
    Vec2 norm_direction = direction.norm();
    double new_xposition = position.getX() + norm_direction.getX()* delta_position;
    double new_yposition = position.getY() + norm_direction.getY()* delta_position;

    position = Vec2(new_xposition, new_yposition);
}

