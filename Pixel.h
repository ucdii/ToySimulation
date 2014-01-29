
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
   Pixel (double p_position_x,double p_position_y, double p_size_x, double p_size_y );

   /**
   * Constructor with Energy
   */

   Pixel (double p_position_x,double p_position_y, double p_size_x, double p_size_y, double energy );

  /**
   * Empty Destructor
   */
  virtual ~Pixel ( );

private:
  //
  // Private attributes
  //

  double p_position_x; // x Position des Pixels
  double p_position_y; // y Position des Pixels
  double p_size_x; // Breite in x
  double p_size_y; // Breite in y
  std::vector<Pixel*> p_neighbourspixelpointer; // vector in dem Pointer auf alle Nachtbarn stehen
  double p_energy; // positionierte Energie in diesem vector

  //
  //Private Functions
  //
  /**
   * Wird von Konstruktoren aufgerufen
   */
   void initAttributes ( double p_position_x,double p_position_y, double p_size_x, double p_size_y, double energy) ;

public:

  //
  // Needed funktions
  //
   /**
   *Addiert energy auf den vorhandenen p_energy Wert
   * @param  energy
   */
  void addP_energy(double energy);

  //
  // Private attribute accessor methods
  //
  /**
   * Set the value of p_position_x
   * @param new_var the new value of p_position_x
   */
  void setP_position_x ( double new_var )   {
      p_position_x = new_var;
  }

  /**
   * Get the value of p_position_x
   * @return the value of p_position_x
   */
  double getP_position_x ( )   {
    return p_position_x;
  }

  /**
   * Set the value of p_position_y
   * @param new_var the new value of p_position_y
   */
  void setP_position_y ( double new_var )   {
      p_position_y = new_var;
  }

  /**
   * Get the value of p_position_y
   * @return the value of p_position_y
   */
  double getP_position_y ( )   {
    return p_position_y;
  }

  /**
   * Set the value of p_size_x
   * @param new_var the new value of p_size_x
   */
  void setP_size_x ( double new_var )   {
      p_size_x = new_var;
  }

  /**
   * Get the value of p_size_x
   * @return the value of p_size_x
   */
  double getP_size_x ( )   {
    return p_size_x;
  }

  /**
   * Set the value of p_size_y
   * @param new_var the new value of p_size_y
   */
  void setP_size_y ( double new_var )   {
      p_size_y = new_var;
  }

  /**
   * Get the value of p_size_y
   * @return the value of p_size_y
   */
  double getP_size_y ( )   {
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
  void setP_energy ( double new_var )   {
      p_energy = new_var;
  }

  /**
   * Get the value of p_energy
   * @return the value of p_energy
   */
  double getP_energy ( )   {
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
