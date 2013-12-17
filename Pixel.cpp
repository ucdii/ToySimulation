#include "Pixel.h"



   /**
   * Empty Constructor
   */
Pixel::Pixel ( ) {
initAttributes(0,0,0,0,0);
}
   /**
   * Constructor
   */

Pixel::Pixel ( float position_x,float position_y, float size_x, float size_y ) {
initAttributes(position_x, position_y, size_x, size_y, 0);
}
Pixel::Pixel ( float position_x,float position_y, float size_x, float size_y , float energy) {
initAttributes(position_x, position_y, size_x, size_y, energy);
}

   /**
   * Destructor
   */
Pixel::~Pixel ( ) { }

   /**
   * Funktion wird von Constructoren aufgerufen und erstellt die privaten Variablen
   */

void Pixel::initAttributes (float position_x,float position_y, float size_x, float size_y, float energy ) {
    setP_position_x(position_x);
    setP_position_y(position_y);
    setP_size_x(size_x);
    setP_size_y(size_y);
    setP_energy(energy);
}

   /**
   * Funktion addiert energy auf den privaten Wert p_energy der Pixelklasse
   */

void Pixel::addP_energy(float energy){
   float new_energy = p_energy+energy ;//getP_energy+p_energy;
    setP_energy(new_energy);
}

