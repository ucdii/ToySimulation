
#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include "Pixel.h"
#include "Vec2.h"



/**
  * class Sensor
  *
  */

class Sensor
{
public:

  //
  // Constructors/Destructors
  //


	Sensor() {}

  /**
   * Constructor
   */
   Sensor(Vec2& pSize, unsigned int N);

  /**
   * Empty Destructor
   */
  virtual ~Sensor ( );

 private:
   //
   // Private attributes
   //

  Vec2 size;
  std::vector<Pixel*> p_sensorpixelpointer;


  //
  //Private Functions
  //
  /**
   * Überprüft ob position innerhalb der Bounding Box des Detektors liegt.
   * @return bool
   * @param  position
   */
  bool withinSensor (Vec2& position );


  /**
   * Berechnet nächste Nachbarn von Pixel pixel und schreibt in p_neighbours von
   * pixel und den Nachbarn von pixel
   * @param  pixel
   */
  void calculateNeighbours (Pixel *pixel, unsigned int size_sensorpointer );
  /**
   * Wird von Konstruktoren verwendet
   */
  void initAttributes ( Vec2 size, unsigned int N) ;



 public:
  /**
   * Gibt Pixel des Sensors zurück innerhalb welchen sich position befindet.
   * @return Pixel
   * @param  position
   * @param  last_pixel
   */
  Pixel * getPixel (Vec2& position);

  /**
   **************************************************************
   **************************************************************
   *Berechnet Anzahl der elemente in p_sensorpointer            *
   *Schreibt newp_sensorpixel in p_sensorpixelpointer           *
   *mit dem das Programm aufgerufen wurde                       *
   *Ermittelt die Nachbarn und schreibt diese in                *
   *p_neighbourspixelpointer des jeweils anderen                *
   *!!vllt wird newp_neighboursPixel ungünstig überschrieben... *
   **************************************************************
   **************************************************************
   */
  void addP_sensorpixelpointer ( Pixel* newp_sensorpixel )   {
      unsigned int size_sensorpointer = p_sensorpixelpointer.size();
      p_sensorpixelpointer.push_back(newp_sensorpixel);
      //calculateNeighbours(newp_sensorpixel, size_sensorpointer );
  }


  //
  // Private attribute accessor methods
  //


  /**
   * Set the value of size
   * @param new_var the new value of size
   */
  void setSize ( Vec2&  pSize )   {
      size = pSize;
  }

  /**
   * Get the value of p_size_x
   * @return the value of p_size_x
   */
  Vec2 getSize ( )   {
    return size;
  }

 std::vector<Pixel*> getP_sensorpixelpointer (){
      return (p_sensorpixelpointer);
  }


};

#endif // SENSOR_H
