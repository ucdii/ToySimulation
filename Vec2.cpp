#include "Vec2.h"

#include <iostream>
using namespace std;

// Constructors/Destructors
//

   /**
   *  Constructor
   */
Vec2::Vec2 ( double x, double y) : x(x), y(y) {}

Vec2::Vec2() : x(0), y(0){}

   /**
   *  Destructor
   */

Vec2::~Vec2 ( ) { }


   /**
   *  public Funktion die einen Vektor auf die Länge 1 normiert
   */
Vec2 Vec2::norm()
{
	double norm2 = x*x+y*y;
	if (norm2 == 0.f) return Vec2(1,0);
	auto norm = sqrt(norm2);
	double newX = x/norm;
	double newY = y/norm;
	return Vec2(newX, newY);
}

