#ifndef SIMULATION_H
#define SIMULATION_H

#include <string>
#include <vector>

#include "Particle.h"
#include "Sensor.h"
#include "EnergyDeposition.h"

/**
  * class Simulation
  *
  */

class Simulation
{
public:
  //
  // Constructors/Destructors
  //


  /**
   * Empty Constructor
   */
  Simulation ( );
   /**
   *Constructor all attributes or only given Sensor
   */
  Simulation(Sensor, double, Particle);

  Simulation(Sensor);

  /**
   * Empty Destructor
   */
  virtual ~Simulation ( );

  private :

   //
   // Private attributes
   //

  Sensor p_sensor;
  double p_delta_position;
  Particle p_particle;

  //
  //Private Functions
  //

  /**
   * private Funktion die vom Konstruktor aufgerufen wird
   */
  void initAttributes (Sensor , double, Particle) ;

  public:
  /**
   * Führt Simulation für bestimmte Anfangsbedingungen für Teilchen durch.
   * In jedem Simulationsschritt wird:
   *  - Teilchenposition mit Particle->move() geändert
   *  - Energiedeposition berechnet (über interface EnergyDeposition)
   * - Teilchenenergie entsprechend veringert
   * - Energiedeposition zum entsprechen Pixel (über Sensor->getPixel() bestimmt)
   * addiert
   * @param  start_energy
   * @param  start_position
   * @param  start_direction
   */
  void run (double start_energy, Vec2 start_position, Vec2 start_direction );



  /**
   * Ausgabe der Energiedeposition für jedes Pixel mit Pixelparametern in pipebarer
   * Form zur weiteren Verarbeitung.
   */
  void printEnergies ( );


  /**
   * Ausgabe von Bounding Box und Anzahl Pixeln.
   */
  void printSensorProperties ( );


  //
  // Private attribute accessor methods
  //


  /**
   * Set the value of p_sensor
   * @param new_var the new value of p_sensor
   */
  void setP_sensor ( Sensor new_var )   {
      p_sensor = new_var;
  }

  /**
   * Get the value of p_sensor
   * @return the value of p_sensor
   */
  Sensor getP_sensor ( )   {
    return p_sensor;
  }


  /**
   * Set the value of p_delta_position
   * @param new_var the new value of p_delta_position
   */
  void setP_delta_position ( double new_var )   {
      p_delta_position = new_var;
  }

  /**
   * Get the value of p_delta_position
   * @return the value of p_delta_position
   */
  double getP_delta_position ( )   {
    return p_delta_position;
  }

  /**
   * Set the value of p_particle
   * @param new_var the new value of p_particle
   */
  void setP_particle ( Particle new_var )   {
      p_particle = new_var;
  }

  /**
   * Get the value of p_particle
   * @return the value of p_particle
   */
  Particle getP_particle ( )   {
    return p_particle;
  }


};

#endif // SIMULATION_H
