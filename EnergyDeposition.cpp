#include "EnergyDeposition.h"

#define min(x,y) ((x)>(y)?(y):(x))

double EnergyDeposition::getEnergyDeposition ( double delta_position, double energy )
{
    // muss noch bearbeitet werden. wie genau aussieht.
	double ENERGYLOSS;
	if (energy <= 1.)
	{
        ENERGYLOSS = 1.;
	}
	else
	{
		ENERGYLOSS = min(energy,(energy==0)?0:1./energy);
	}
            return ENERGYLOSS*delta_position;
}


