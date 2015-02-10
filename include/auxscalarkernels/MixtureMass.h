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

#ifndef MIXTUREMASS_H
#define MIXTUREMASS_H

#include "AuxScalarKernel.h"

class MixtureMass;

template<>
InputParameters validParams<MixtureMass>();

class MixtureMass : public AuxScalarKernel
{
public:

  MixtureMass(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeValue();
  VariableValue & _concrete_mass;
  
};

#endif // MIXTUREMASS_H
