
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
 static float getEnergyDeposition (float delta_position );
};

#endif // ENERGYDEPOSITION_H
