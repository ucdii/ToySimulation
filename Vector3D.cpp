#include "Vector3D.h"

#include <iostream>
using namespace std;

// Constructors/Destructors
//

   /**
   *  Constructor
   */
Vector3D::Vector3D ( double x, double y, double z) {
initAttributes(x,y,z);
}

   /**
   *  Empty Constructor
   */
Vector3D::Vector3D(){
initAttributes (1, 1, 1);}

   /**
   *  Destructor
   */

Vector3D::~Vector3D ( ) { }


   /**
   *  public Funktion die einen Vektor auf die Länge 1 normiert
   */
Vector3D Vector3D::norm()
{
	double norm2 = x*x+y*y+z*z;
	if (norm2 == 0.f) return Vector3D(1,0,0);
	auto norm = sqrt(norm2);
	double newX = x/norm;
	double newY = y/norm;
	double newZ = z/norm;
	return Vector3D(newX, newY, newZ);
}

   /**
   *  private Funktion die von Konstruktoren aufgerufen wird
   */
void Vector3D::initAttributes (double x, double y, double z ) {

        setX(x);
        setY(y);
        setZ(z);
}

