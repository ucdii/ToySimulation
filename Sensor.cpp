#include "Sensor.h"
//#include <cstddef>

#include "Timer.h"

   /**
   *  Empty Constructor
   */


   /**
   *  Constructor
   */
Sensor::Sensor(Vec2& pSize, unsigned int N) : size(pSize)
{
	p_sensorpixelpointer.reserve(N);
}
   /**
   *  Destructor
   */
Sensor::~Sensor ( ) { }


   /**
   *  public Funktion gibt Pointer auf Pixel des Sensors zurück indem der gegebene Vec2 liegt
   */

Pixel * Sensor::getPixel(Vec2& position)
{

	//myTimer.start();

    // überprüft ob position im Sensor ist  sonst wird NULL zurückgegeben
    if(withinSensor(position)){
    //Möglich: erst Nachbarn des letzten Pixels überprüfen! hier nicht gemacht!!

        unsigned int size_sensorpointer = p_sensorpixelpointer.size();
        for(unsigned int i = 0; i< size_sensorpointer; i++)
        {

            //Abmessugnen des betrachteten Pixels
			double xmin = p_sensorpixelpointer[i]->getPosition().getX();
            double ymin = p_sensorpixelpointer[i]->getPosition().getY();
            double xmax = xmin + p_sensorpixelpointer[i]->getSize().getX();
            double ymax = ymin + p_sensorpixelpointer[i]->getSize().getY();

            //Ort des 3DVektors
            double x = position.getX();
            double y = position.getY();
            //Schaut ob projektion von 3D Vektor auf x-y ebene in betrachtetem Pixel ist
            if(xmin<= x && xmax >= x&& ymin <=y && ymax >= y) {
                return (p_sensorpixelpointer[i]);

            }
        }
    } 

	//myTimer.stop();

	return NULL;
}



   /**
   *  private Funktion überprüft ob position noch innerhalb des Sensors liegt
   */

bool Sensor::withinSensor(Vec2& position)
{
        // Position
        double x = position.getX();
        double y = position.getY();

        if(x<= position.getX() && y<= position.getY()){
            return true;}
        else{
            cout << " Particle moved out of Sensor"<< endl;
            return false;}
}
   /**
   *  private Funktion berechnet Nachbarn und schreibt diese in das Pixel sebst und in sich selbst in den Nachbarpixel
   */
void Sensor::calculateNeighbours(Pixel *pixel1, unsigned int size_sensorpointer)
{
        // Eckdaten des Pixel von dem die Nachbarn bestimmt werden sollen

		double x1 = pixel1->getPosition().getX();
        double x2 = x1+pixel1->getSize().getX();
        double y1 = pixel1->getPosition().getY();
        double y2 = y1+pixel1->getSize().getY();


        // Vergleich mit allen anderen vorhandenen Pixeln im Sensor
        for(unsigned int i = 0 ; i < size_sensorpointer; i++)
        {
        // Daten des zu vergleichenden Pixels
        double xmin = p_sensorpixelpointer[i]->getPosition().getX();
        double ymin = p_sensorpixelpointer[i]->getPosition().getY();
        double xmax = p_sensorpixelpointer[i]->getSize().getX();
        double ymax = p_sensorpixelpointer[i]->getSize().getY();


         //Betrachtetes Pixel auf x1 Ebene? und zwischen y werten siehe unten
         if(x1==xmax&& y1 >=ymin  && y2 <= ymax)
            {pixel1->addP_neighbourspixelpointer(p_sensorpixelpointer[i]);
             p_sensorpixelpointer[i]->addP_neighbourspixelpointer(pixel1);
             continue;
            }
         //Betrachtetes Pixel auf x2 Ebene?
         if(x2==xmin&& y1 >=ymin  && y2 <= ymax)
            {pixel1->addP_neighbourspixelpointer(p_sensorpixelpointer[i]);
             p_sensorpixelpointer[i]->addP_neighbourspixelpointer(pixel1);
             continue;}
         //Betrachtetes Pixel auf y1 Ebene?
         if(y1 == ymax && x1 >= xmin && x2 <= xmax)
            {pixel1->addP_neighbourspixelpointer(p_sensorpixelpointer[i]);
             p_sensorpixelpointer[i]->addP_neighbourspixelpointer(pixel1);
             continue;}
         //Betrachtetes Pixel auf y2 Ebene?
         if(y2== ymin && x1 >= xmin && x2 <= xmax)
            {pixel1->addP_neighbourspixelpointer(p_sensorpixelpointer[i]);
             p_sensorpixelpointer[i]->addP_neighbourspixelpointer(pixel1);
             continue;}
        }
}


