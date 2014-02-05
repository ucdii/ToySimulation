
#ifndef PARTICLE_H
#define PARTICLE_H

#include <string>
#include "Vec2.h"


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
  Particle ( double P_energy, Vec2& position, Vec2& direction );

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

  double energy; // Energie des Partikels
  Vec2 position; // Aufenthaltsort des Partikels
  Vec2 direction; // Flugrichtung des Partikels

  //
  //Private Functions
  //
  /**
   * Wird von Konstruktoren aufgerufen
   */
  void initAttributes ( double P_energy, Vec2& position, Vec2& direction ) ;

public:

  /**
   * Addiere zur aktuellen Position delta_position * Einheitsvektor direction
   * @param  delta_position
   */
  void move (double delta_position );

  //
  // Private attribute accessor methods
  //


  /**
   * Set the value of energy
   * @param new_var the new value of energy
   */
  void setP_energy ( double new_var )   {
      energy = new_var;
  }

  /**
   * Add the value of
   * @param new_var to value of energy
   */
  void addP_energy ( double new_var )   {
      energy += new_var;
  }

  /**
   * Get the value of energy
   * @return the value of energy
   */
  double getP_energy ( )   {
    return energy;
  }

  /**
   * Set the value of position
   * @param new_var the new value of position
   */
  void setP_position ( Vec2& new_var )   {
      position = new_var;
  }

  /**
   * Get the value of position
   * @return the value of position
   */
  Vec2 getP_position ( )   {
    return position;
  }

  /**
   * Set the value of direction
   * @param new_var the new value of direction
   */
  void setP_direction ( Vec2& new_var )   {
      direction = new_var;
  }

  /**
   * Get the value of direction
   * @return the value of direction
   */
  Vec2 getP_direction ( )   {
    return direction;
  }



};

#endif // PARTICLE_H
