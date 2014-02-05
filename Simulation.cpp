#include "Simulation.h"

#include<iostream>
#include <cstddef>

   /**
   *  Empty Constructor
   */

Simulation::Simulation ( ) {
initAttributes( Sensor(), 0, Particle());
}

   /**
   *  Constructor with all attributes or only given Sensor
   */

Simulation::Simulation (Sensor sensor, double delta_position, Particle particle ) {
initAttributes( sensor, delta_position, particle);
}

Simulation::Simulation ( Sensor sensor) {
initAttributes( sensor, 0, Particle());
}

   /**
   *  Destructor
   */
Simulation::~Simulation ( ) { }

   /**
   *  public Funktion die Sensoreigenschaften (Breite in x y und y Richtung) auf Konsole ausgibt
   */
void Simulation::printSensorProperties ( )
{
    cout << "Sensor Properties:" << endl;
    cout << "x:" << p_sensor.getSize().getX() << "  y=" << p_sensor.getSize().getY()<< endl;
}

   /**
   *  public Funktion für alle Pixel die Energie ausgibt
   */

void Simulation::printEnergies ( )
{
    std::vector<Pixel*> pixels = p_sensor.getP_sensorpixelpointer();

    for (unsigned int i = 0 ; i < pixels.size(); i++){
         pixels[i]->toString(false);// i in 100 geänert!
   }

}

   /**
   *  public Funktion die die Simuation startet Ihr muss eine Startenergie, -Position und Richtung angegeben werden
   */
void Simulation::run (double start_energy, Vec2& start_position, Vec2& start_direction ){
  // Deklaration unseres Starktpartikels
  Particle teilchen = Particle(start_energy, start_position, start_direction) ;

  // Finde kleinste Seitenkante


        std::vector<Pixel*> pixels = p_sensor.getP_sensorpixelpointer();
        double minimum = pixels[0]->getSize().getX( );


        for (unsigned int i = 0 ; i < pixels.size(); i++){
                if (pixels[i]->getSize().getX() < minimum) {
                    minimum = pixels[i]->getSize().getX();
                }
                if (pixels[i]->getSize().getY() < minimum) {
                    minimum = pixels[i]->getSize().getY();
                }
        }

        // Iterationsschritte werden auf 1/20 der kleinsten Seitenlänge gesetzt
        p_delta_position = minimum/20;


  // Teilchen wird bewegt bis Energie 0 ist
  for(;;)
  {

	  auto tEnergy = teilchen.getP_energy();
	  if (tEnergy <= 0)
	  {
		  simulationResult = SimulationResult::Absorbed;
		  break;
	  }

        // Teilchen wird um delta_position bewegt
        teilchen.move(p_delta_position);
        // Pointer auf neues Pixel wird bestimmt und dann wird diesem Pixel der ernergydeposit hinzugefügt falls sich dieser noch
        // im Sensor befindet

		auto deposit = EnergyDeposition::getEnergyDeposition(p_delta_position,tEnergy);

        if(p_sensor.getPixel(teilchen.getP_position()) != NULL) {
            p_sensor.getPixel(teilchen.getP_position())->addP_energy(deposit);
        } else {
			simulationResult = SimulationResult::WentThrough;	
            break;
        }


         // Die abgegebene Energie wird dem Teilchen entzogen
        teilchen.addP_energy(-deposit);
  }
}





   /**
   *  private Funktion die von Konstruktoren aufgerufen wird
   */
void Simulation::initAttributes ( Sensor sensor , double delta_position, Particle particle) {
    setP_sensor(sensor);
    setP_delta_position(delta_position);
    setP_particle(particle);
}



