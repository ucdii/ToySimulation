
#ifndef SENSOR_H
#define SENSOR_H

#include <string>
#include <vector>
#include "Pixel.cpp "
//#include "Vector3D.cpp"



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


  /**
   * Empty Constructor
   */
  Sensor ( );

  /**
   * Constructor
   */
   Sensor(float p_size_x, float p_size_y, float  p_size_z, unsigned int N);

  /**
   * Empty Destructor
   */
  virtual ~Sensor ( );

 private:
   //
   // Private attributes
   //

  float p_size_x;
  float p_size_y;
  float p_size_z;
  std::vector<Pixel*> p_sensorpixelpointer;


  //
  //Private Functions
  //
  /**
   * Überprüft ob position innerhalb der Bounding Box des Detektors liegt.
   * @return bool
   * @param  position
   */
  bool withinSensor (Vector3D position );


  /**
   * Berechnet nächste Nachbarn von Pixel pixel und schreibt in p_neighbours von
   * pixel und den Nachbarn von pixel
   * @param  pixel
   */
  void calculateNeighbours (Pixel *pixel, unsigned int size_sensorpointer );
  /**
   * Wird von Konstruktoren verwendet
   */
  void initAttributes ( float size_x, float size_y, float size_z, unsigned int N) ;



 public:
  /**
   * Gibt Pixel des Sensors zurück innerhalb welchen sich position befindet.
   * @return Pixel
   * @param  position
   * @param  last_pixel
   */
  Pixel * getPixel (Vector3D position);

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
   * Set the value of p_size_z
   * @param new_var the new value of p_size_z
   */
  void setP_size_z ( float new_var )   {
      p_size_z = new_var;
  }

  /**
   * Get the value of p_size_z
   * @return the value of p_size_z
   */
  float getP_size_z ( )   {
    return p_size_z;
  }

  /**
   * Get p_sensorpixelpointer of privit attributes
   * @return the value of p_size_z
   */
 std::vector<Pixel*> getP_sensorpixelpointer (){
      return (p_sensorpixelpointer);
  }


};

#endif // SENSOR_H
