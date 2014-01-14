
#ifndef PIXEL_H
#define PIXEL_H

#include <string>
#include <vector>
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
   * Empty Constructor
   */
  Pixel ( );

  /**
   * Constructor without Energy
   */
   Pixel (float p_position_x,float p_position_y, float p_size_x, float p_size_y );

   /**
   * Constructor with Energy
   */

   Pixel (float p_position_x,float p_position_y, float p_size_x, float p_size_y, float energy );

  /**
   * Empty Destructor
   */
  virtual ~Pixel ( );

private:
  //
  // Private attributes
  //

  float p_position_x; // x Position des Pixels
  float p_position_y; // y Position des Pixels
  float p_size_x; // Breite in x
  float p_size_y; // Breite in y
  std::vector<Pixel*> p_neighbourspixelpointer; // vector in dem Pointer auf alle Nachtbarn stehen
  float p_energy; // positionierte Energie in diesem vector

  //
  //Private Functions
  //
  /**
   * Wird von Konstruktoren aufgerufen
   */
   void initAttributes ( float p_position_x,float p_position_y, float p_size_x, float p_size_y, float energy) ;

public:

  //
  // Needed funktions
  //
   /**
   *Addiert energy auf den vorhandenen p_energy Wert
   * @param  energy
   */
  void addP_energy(float energy);

  //
  // Private attribute accessor methods
  //
  /**
   * Set the value of p_position_x
   * @param new_var the new value of p_position_x
   */
  void setP_position_x ( float new_var )   {
      p_position_x = new_var;
  }

  /**
   * Get the value of p_position_x
   * @return the value of p_position_x
   */
  float getP_position_x ( )   {
    return p_position_x;
  }

  /**
   * Set the value of p_position_y
   * @param new_var the new value of p_position_y
   */
  void setP_position_y ( float new_var )   {
      p_position_y = new_var;
  }

  /**
   * Get the value of p_position_y
   * @return the value of p_position_y
   */
  float getP_position_y ( )   {
    return p_position_y;
  }

  /**
   * Set the value of p_size_x
   * @param new_var the new value of p_size_x
   */
  void setP_size_x ( float new_var )   {
      p_size_x = new_var;
  }

  /**
   * Get the value of p_size_x
   * @return the value of p_size_x
   */
  float getP_size_x ( )   {
    return p_size_x;
  }

  /**
   * Set the value of p_size_y
   * @param new_var the new value of p_size_y
   */
  void setP_size_y ( float new_var )   {
      p_size_y = new_var;
  }

  /**
   * Get the value of p_size_y
   * @return the value of p_size_y
   */
  float getP_size_y ( )   {
    return p_size_y;
  }



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
   * Set the value of p_energy
   * @param new_var the new value of p_energy
   */
  void setP_energy ( float new_var )   {
      p_energy = new_var;
  }

  /**
   * Get the value of p_energy
   * @return the value of p_energy
   */
  float getP_energy ( )   {
    return p_energy;
  }


  //
  //Ausgabe aller wichtigen Daten in Konsole x,y delta x,y  und Energie
  //
  void toString(){
    cout << "x:" << p_position_x << "  DeltaX:" << p_size_x  <<"  y:" << p_position_y <<"   DeltaY:" <<p_size_y << "  Energie:"<< p_energy<< endl;
}


};





#endif // PIXEL_H
