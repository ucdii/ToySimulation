#include "Pixel.h"


   /**
   * Constructor
   */

Pixel::Pixel ( Vec2& pPosition, Vec2& pSize ) : position(pPosition), size(pSize) , energy(0) {}
Pixel::Pixel ( Vec2& pPosition, Vec2& pSize, double pEnergy) : position(pPosition), size(pSize), energy(pEnergy) {}

   /**
   * Destructor
   */
Pixel::~Pixel ( ) { }

Vec2 Pixel::getPosition() {return position; }
Vec2 Pixel::getSize() { return size; }

bool Pixel::getPositionIsInside(Vec2& pos)
{
            //Abmessugnen des betrachteten Pixels
			double xmin = pos.getX();
			double ymin = pos.getY();
            double xmax = xmin + getSize().getX();
            double ymax = ymin + getSize().getY();

            //Ort des 3DVektors
            double x = position.getX();
            double y = position.getY();
            //Schaut ob projektion von 3D Vektor auf x-y ebene in betrachtetem Pixel ist
            return xmin<= x && xmax >= x&& ymin <=y && ymax >= y;
}

   /**
   * Funktion addiert energy auf den privaten Wert energy der Pixelklasse
   */

void Pixel::addP_energy(double pEnergy){
	energy += pEnergy;
}

