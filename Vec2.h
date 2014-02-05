
#ifndef VECT2_H
#define VECT2_H

#include <string>
#include <math.h>

/**
  * class Vec2
  *
  */

class Vec2
{
public:
  //
  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Vec2 ();


  /**
   * Constructor
   */
  Vec2 (double x, double y);

  /**
   * Empty Destructor
   */
  virtual ~Vec2 ( );

  private:
    //
    // Private attributes
    //

  double x;
  double y;

  //
  //Private Functions
  //

  /**
   * private Funktion die vom Konstruktor aufgerufen wird
   */
  

  public:

  /**
   * Gibt normierte Kopie zurück.
   * @return Vec2
   */
  Vec2 norm ( );

  //
  // Private attribute accessor methods
  //


  /**
   * Set the value of x
   * @param new_var the new value of x
   */
  void setX ( double new_var )   {
      x = new_var;
  }

  /**
   * Get the value of x
   * @return the value of x
   */
  double getX ( )   {
    return x;
  }

  /**
   * Set the value of y
   * @param new_var the new value of y
   */
  void setY ( double new_var )   {
      y = new_var;
  }

  /**
   * Get the value of y
   * @return the value of y
   */
  double getY ( )   {
    return y;
  }

};

#endif // VECT2_H
