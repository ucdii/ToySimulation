#include "Particle.h"

   /**
   *  Constructor
   */

Particle::Particle ( double P_energy, Vector3D p_position, Vector3D p_direction ) {
    initAttributes(P_energy, p_position, p_direction );
}
   /**
   *  Emty Constructor
   */

Particle::Particle(){
    Vector3D vektor1 = Vector3D();
    initAttributes(0,vektor1,vektor1);
   }
   /**
   *  Desruktor
   */
   Particle::~Particle ( ) { }

   /**
   *  Funktion bewegt Particle um delta_position in richtung der p_direktion und schreibt p_position
   *  von Particle auf neuen Wert.
   */
void Particle::move(double delta_position){
    Vector3D norm_direction = p_direction.norm();
    double new_xposition = p_position.getX() + norm_direction.getX()* delta_position;
    double new_yposition = p_position.getY() + norm_direction.getY()* delta_position;
    double new_zposition = p_position.getZ() + norm_direction.getZ()* delta_position;

    p_position = Vector3D(new_xposition, new_yposition, new_zposition);
}

   /**
   *  private Funktion, wird von den Construktoren aufgerufen um Werte den
   */

void Particle::initAttributes ( double p_Energy, Vector3D p_Position, Vector3D p_Direction ) {
    setP_energy(p_Energy);
    setP_position(p_Position);
    setP_direction(p_Direction);
}

