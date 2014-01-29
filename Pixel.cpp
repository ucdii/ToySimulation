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

Pixel::Pixel ( double position_x,double position_y, double size_x, double size_y ) {
initAttributes(position_x, position_y, size_x, size_y, 0);
}
Pixel::Pixel ( double position_x,double position_y, double size_x, double size_y , double energy) {
initAttributes(position_x, position_y, size_x, size_y, energy);
}

   /**
   * Destructor
   */
Pixel::~Pixel ( ) { }

   /**
   * Funktion wird von Constructoren aufgerufen und erstellt die privaten Variablen
   */

void Pixel::initAttributes (double position_x,double position_y, double size_x, double size_y, double energy ) {
    setP_position_x(position_x);
    setP_position_y(position_y);
    setP_size_x(size_x);
    setP_size_y(size_y);
    setP_energy(energy);
}

   /**
   * Funktion addiert energy auf den privaten Wert p_energy der Pixelklasse
   */

void Pixel::addP_energy(double energy){
   double new_energy = p_energy+energy ;//getP_energy+p_energy;
    setP_energy(new_energy);
}

