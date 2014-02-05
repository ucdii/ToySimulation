
#ifndef ENERGYDEPOSITION_H
#define ENERGYDEPOSITION_H

#include <string>

class EnergyDeposition
{
public:


  /**
   * Verschiedene Modelle implementierbar.
   * @param  current_energy
   * @param  delta_position
   */
 static double getEnergyDeposition (double delta_position, double energy );
};

#endif // ENERGYDEPOSITION_H
