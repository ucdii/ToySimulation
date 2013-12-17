
#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <string>
#include <math.h>

/**
  * class Vector3D
  *
  */

class Vector3D
{
public:
  //
  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Vector3D ();


  /**
   * Constructor
   */
  Vector3D (double x, double y, double z);

  /**
   * Empty Destructor
   */
  virtual ~Vector3D ( );

  private:
    //
    // Private attributes
    //

  double x;
  double y;
  double z;

  //
  //Private Functions
  //

  /**
   * private Funktion die vom Konstruktor aufgerufen wird
   */

  void initAttributes (double x, double y, double z) ;


  public:

  /**
   * Gibt normierte Kopie zurück.
   * @return Vector3D
   */
  Vector3D norm ( );

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

  /**
   * Set the value of z
   * @param new_var the new value of z
   */
  void setZ ( double new_var )   {
      z = new_var;
  }

  /**
   * Get the value of z
   * @return the value of z
   */
  double getZ ( )   {
    return z;
  }


};

#endif // VECTOR3D_H
