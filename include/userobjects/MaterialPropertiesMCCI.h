#ifndef MATERIALPROPERTIESMCCI_H
#define MATERIALPROPERTIESMCCI_H

#include "GeneralUserObject.h"

// Forward Declarations
class MaterialPropertiesMCCI;

template<>
InputParameters validParams<MaterialPropertiesMCCI>();

class MaterialPropertiesMCCI : public GeneralUserObject
{
public:
  // Constructor
  MaterialPropertiesMCCI(const std::string & name, InputParameters parameters);

  // Destructor  
  virtual ~MaterialPropertiesMCCI(); 

  /**
   * Called when this object needs to compute something.
   */
  virtual void execute() {}

  /**
   * Called before execute() is ever called so that data can be cleared.
   */
  virtual void initialize(){}

  
  virtual void destroy();

  virtual void finalize() {};

//    // The interface for derived MaterialPropertiesMCCI objects to implement...
//    virtual Real pressure(Real rho=0., Real mom_norm=0., Real rhoE=0.) const;
    
    Real Cp() const;
    Real Rho() const;
    
protected:
    Real _Cp;
    Real _rho;
    // Prints an error message for non-implemented functions
    void error_not_implemented(std::string method_name) const;
};


#endif // MATERIALPROPERTIESMCCI_H
