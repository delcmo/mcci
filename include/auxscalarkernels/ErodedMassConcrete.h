/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

#ifndef ERODEDMASSCONCRETE_H
#define ERODEDMASSCONCRETE_H

#include "AuxScalarKernel.h"
#include "MaterialPropertiesMCCI.h"

class ErodedMassConcrete;

template<>
InputParameters validParams<ErodedMassConcrete>();

class ErodedMassConcrete : public AuxScalarKernel
{
public:

  ErodedMassConcrete(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeValue();
    VariableValue & _corium_temp;
    Real _Tdec;
    Real _ht_coeff_corium_to_concrete;
    Real _Sconcrete;
    Real _Hdec;
    
};

#endif //ERODEDMASSCONCRETE_H
