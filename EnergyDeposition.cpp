#include "EnergyDeposition.h"



float EnergyDeposition::getEnergyDeposition ( float delta_position )
{
    // muss noch bearbeitet werden. wie genau aussieht.
            float ENERGYLOSS = 5;
            float DISTANCE = 1;
            return (ENERGYLOSS*delta_position/DISTANCE);
}


