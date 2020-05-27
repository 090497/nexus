// ----------------------------------------------------------------------------
// nexus | IonGun.h
//
// This class is the primary generator for events consisting in the decay 
// of a radioactive ion. The user must specify via configuration parameters
// the atomic number, mass number and energy level of the isotope of interest.
//
// The NEXT Collaboration
// ----------------------------------------------------------------------------

#ifndef ION_GUN_H
#define ION_GUN_H

#include <G4VPrimaryGenerator.hh>

class G4Event;
class G4GenericMessenger;
class G4ParticleDefinition;


namespace nexus{

  class BaseGeometry;

  class IonGun: public G4VPrimaryGenerator
  {
  public:
    // Constructor
    IonGun();
    // Destructor
    ~IonGun();

    // This method is invoked at the beginning of the event,
    // setting a primary vertex that contains the chosen ion
    void GeneratePrimaryVertex(G4Event*);

  private:
    G4ParticleDefinition* IonDefinition();

 private:
    G4int atomic_number_, mass_number_;
    G4double energy_level_;
    G4bool decay_at_time_zero_;
    G4String region_;
    G4GenericMessenger* msg_;
    const BaseGeometry* geom_;
  };

} // end namespace nexus

#endif
