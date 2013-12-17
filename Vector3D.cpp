#include "Vector3D.h"

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
   *  public Funktion die einen Vektor auf die länge 1 normiert
   */
Vector3D Vector3D::norm() {
    if(x ==0 && y == 0 && z == 0)
    {cout << "Direction is null vektor you cant find a norm. Exit Programm"<< endl;
    exit(0);
    }
    else{
    double norm =sqrt(x*x+y*y+z*z);
    double newX = x/norm;
    double newY = y/norm;
    double newZ = z/norm;
    return Vector3D(newX, newY, newZ);
    }
}

   /**
   *  private Funktion die von Konstruktoren aufgerufen wird
   */
void Vector3D::initAttributes (double x, double y, double z ) {

        setX(x);
        setY(y);
        setZ(z);
}

