
#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
#include "Vector3D.h"


  /**
  * class Particle
  *
  */

class Particle
{

public:
   //
   //Constuctor/Destrucor
   //


  /**
   * Constructor
   */
  Particle ( double P_energy, Vector3D p_position, Vector3D p_direction );

  /**
   * Empty Constructor
   */
  Particle ();

  /**
   * Empty Destructor
   */
  virtual ~Particle ( );

  private:

  //
  // Private attributes
  //

  double p_energy; // Energie des Partikels
  Vector3D p_position; // Aufenthaltsort des Partikels
  Vector3D p_direction; // Flugrichtung des Partikels

  //
  //Private Functions
  //
  /**
   * Wird von Konstruktoren aufgerufen
   */
  void initAttributes ( double P_energy, Vector3D p_position, Vector3D p_direction ) ;

public:

  /**
   * Addiere zur aktuellen Position delta_position * Einheitsvektor p_direction
   * @param  delta_position
   */
  void move (double delta_position );

  //
  // Private attribute accessor methods
  //


  /**
   * Set the value of p_energy
   * @param new_var the new value of p_energy
   */
  void setP_energy ( double new_var )   {
      p_energy = new_var;
  }

  /**
   * Add the value of
   * @param new_var to value of p_energy
   */
  void addP_energy ( double new_var )   {
      p_energy += new_var;
  }

  /**
   * Get the value of p_energy
   * @return the value of p_energy
   */
  double getP_energy ( )   {
    return p_energy;
  }

  /**
   * Set the value of p_position
   * @param new_var the new value of p_position
   */
  void setP_position ( Vector3D new_var )   {
      p_position = new_var;
  }

  /**
   * Get the value of p_position
   * @return the value of p_position
   */
  Vector3D getP_position ( )   {
    return p_position;
  }

  /**
   * Set the value of p_direction
   * @param new_var the new value of p_direction
   */
  void setP_direction ( Vector3D new_var )   {
      p_direction = new_var;
  }

  /**
   * Get the value of p_direction
   * @return the value of p_direction
   */
  Vector3D getP_direction ( )   {
    return p_direction;
  }



};

#endif // PARTICLE_H
