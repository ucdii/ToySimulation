#include "Sensor.h"
#include <cstddef>

   /**
   *  Empty Constructor
   */


Sensor::Sensor ( ) {
initAttributes(0,0,0,0); // letzer Wert wahrscheinlich ungünstig gewählt?
}

   /**
   *  Constructor
   */
Sensor::Sensor(double size_x, double size_y, double size_z, unsigned int N){
initAttributes(size_x,size_y,size_z, N);
}
   /**
   *  Destructor
   */
Sensor::~Sensor ( ) { }


   /**
   *  public Funktion gibt Pointer auf Pixel des Sensors zurück indem der gegebene Vector3D liegt
   */

Pixel * Sensor::getPixel(Vector3D position)
{

    // überprüft ob position im Sensor ist  sonst wird NULL zurückgegeben
    if(withinSensor(position)){
    //Möglich: erst Nachbarn des letzten Pixels überprüfen! hier nicht gemacht!!

        unsigned int size_sensorpointer = p_sensorpixelpointer.size();
        for(unsigned int i = 0; i< size_sensorpointer; i++)
        {

            //Abmessugnen des betrachteten Pixels
            double xmin = p_sensorpixelpointer[i]->getP_position_x();
            double ymin = p_sensorpixelpointer[i]->getP_position_y();
            double xmax = xmin + p_sensorpixelpointer[i]->getP_size_x();
            double ymax = ymin + p_sensorpixelpointer[i]->getP_size_y();

            //Ort des 3DVektors
            double x = position.getX();
            double y = position.getY();
            //Schaut ob projektion von 3D Vektor auf x-y ebene in betrachtetem Pixel ist
            if(xmin<= x && xmax >= x&& ymin <=y && ymax >= y) {
                return (p_sensorpixelpointer[i]);

            }
        }
    } else {
return NULL;
    }

	return NULL;
}



   /**
   *  private Funktion überprüft ob position noch innerhalb des Sensors liegt
   */

bool Sensor::withinSensor(Vector3D position)
{
        // Position
        double x = position.getX();
        double y = position.getY();
        double z = position.getZ();

        if(x<= p_size_x && y<= p_size_y && z <= p_size_z){
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

        double x1 = pixel1->getP_position_x();
        double x2 = x1+pixel1->getP_size_x();
        double y1 = pixel1->getP_position_y();
        double y2 = y1+pixel1->getP_size_y();


        // Vergleich mit allen anderen vorhandenen Pixeln im Sensor
        for(unsigned int i = 0 ; i < size_sensorpointer; i++)
        {
        // Daten des zu vergleichenden Pixels
        double xmin = p_sensorpixelpointer[i]->getP_position_x();
        double ymin = p_sensorpixelpointer[i]->getP_position_y();
        double xmax = p_sensorpixelpointer[i]->getP_size_x();
        double ymax = p_sensorpixelpointer[i]->getP_size_y();


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

   /**
   *  private Funktion die vom Constructor aufgerufen wird
   */

void Sensor::initAttributes (double size_x, double size_y, double size_z, unsigned int N ) {
    setP_size_x(size_x);
    setP_size_y(size_y);
    setP_size_z(size_z);
    p_sensorpixelpointer.reserve(N); // Reserviert N Pointer auf Pixel
}

