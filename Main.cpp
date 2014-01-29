#include <iostream>
#include <fstream>

#include "Simulation.h"

#define PROGRAM_EXIT_OK 0
#define PROGRAM_EXIT_ERROR 1

int main()
{

    // einlesen der Pixel aus Sensordaten.txt
    ifstream Sensordaten;
    Sensordaten.open ("Sensordaten.txt", ios_base::in );

    // Anzahl der Pixel die als erstes ind er Tabelle gegeben werden
    unsigned int numberofpixels;
    Sensordaten >> numberofpixels;

    // erstellen des sensors
    Sensor sensor;
    // überprüft ob Datei geöffnet werden kann
    if (Sensordaten.is_open()) {
            // Anzahl der Pixel die als erstes ind er Tabelle gegeben werden

            double sensor_x, sensor_y, sensor_z;
            Sensordaten >> sensor_x;
            Sensordaten >> sensor_y;
            Sensordaten >> sensor_z;

            cout << "Sensor Properties are read. Beginning bulding Snesor Pixels..."<< endl;
            // Definition der Sensor Properties
            sensor = Sensor(sensor_x, sensor_y, sensor_z, numberofpixels);

            for(unsigned int i = 1; i <= numberofpixels; i++){
                  // Deklaration der einzelenen Elemente die in den Pixel array geschrieben werden sollen
                  double p_x, p_y, p_size_x,p_size_y;
                  // Einlesen der parameter
                  Sensordaten >> p_x;
                  Sensordaten >> p_y;
                  Sensordaten >> p_size_x;
                  Sensordaten >> p_size_y;
                  // erstellen des neuen Pixels
                  Pixel *pixel = new Pixel(p_x, p_y, p_size_x, p_size_y);
                  // Hinzufügen des Pixels und überprüfung näachster Nachbarn
                  sensor.addP_sensorpixelpointer(pixel);

            }
            cout << "All Pixels are loaded"<< endl;

          }
         else{
           cout << "Konnte Sensordaten.txt nicht laden ..."  << endl;
           return PROGRAM_EXIT_ERROR;
         }
    Sensordaten.close();

    double energy, position_x, position_y, position_z, direction_x, direction_y, direction_z;
    // Einlesen der Anfangsbedingungen über Console
    cout << "Choose start  Energy, Position and Direction of the Particle" << endl;
    cout << "Fist the Energy: ";
    cin >> energy;
    cout << "Input the Postition of the Partikle(x,y,z):";
    cin >> position_x >> position_y >> position_z;
    Vector3D position = Vector3D(position_x, position_y, position_z);
    cout << "Input the Direction of the Partikle(x,y,z):";
    cin >> direction_x >> direction_y >> direction_z;
    Vector3D direction = Vector3D(direction_x, direction_y, direction_z);

    Simulation simulation = Simulation(sensor);
    //Simulation wird mit Funktion run durchgeführt
    simulation.run(energy, position, direction);
    // Ausgabe der Sensor Properties
    simulation.printSensorProperties();
    simulation.printEnergies();
}
