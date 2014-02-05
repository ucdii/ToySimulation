
#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <vector>
#include "Vec2.h"
#include <iostream>

using namespace std;


  /**
  * class Pixel
  *
  */

class Pixel
{
public:

   //
   //Constuctor/Destrucor
   //

  /**
   * Constructor without Energy
   */
   Pixel (Vec2& position, Vec2& size);

   /**
   * Constructor with Energy
   */

   Pixel (Vec2& position, Vec2& size, double energy );

   Vec2 getPosition();
   Vec2 getSize();

  /**
   * Empty Destructor
   */
  virtual ~Pixel ( );

  bool getPositionIsInside(Vec2& pos);

private:
  //
  // Private attributes
  //

  Vec2 position, size;
  std::vector<Pixel*> p_neighbourspixelpointer; // vector in dem Pointer auf alle Nachtbarn stehen
  double energy; // positionierte Energie in diesem vector

  //
  //Private Functions
  //
  
public:

  //
  // Needed funktions
  //
   /**
   *Addiert energy auf den vorhandenen energy Wert
   * @param  energy
   */
  void addP_energy(double energy);

     /**
   **************************************************************
   **************************************************************
   *Schreibt newp_neighboursPixel in P_neighbourspixelpointer   *
   *mit dem das Programm aufgerufen wurde                       *
   *!!vllt wird newp_neighboursPixel ungünstig überschrieben... *
   **************************************************************
   **************************************************************
   */

  void addP_neighbourspixelpointer(Pixel *newp_neighbourspixel) {
        p_neighbourspixelpointer.push_back(newp_neighbourspixel);
  }

  /**
   * Set the value of energy
   * @param new_var the new value of energy
   */
  void setP_energy ( double new_var )   {
      energy = new_var;
  }

  /**
   * Get the value of energy
   * @return the value of energy
   */
  double getP_energy ( )   {
    return energy;
  }


  //
  //Ausgabe aller wichtigen Daten in Konsole x,y delta x,y  und Energie
  //
  void toString(bool printIfZero = true){
	if (!printIfZero && energy == 0) return;
	cout << "[" << position.getX() << "," << position.getY() << "] [" << size.getX() << "," << size.getY()  << "] -> "<< energy<< endl;
}


};





#endif // PIXEL_H
