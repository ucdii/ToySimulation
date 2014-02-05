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



   /**
   * Funktion addiert energy auf den privaten Wert energy der Pixelklasse
   */

void Pixel::addP_energy(double pEnergy){
	energy += pEnergy;
}

