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

#ifndef TEMPERATURECORIUM_H
#define TEMPERATURECORIUM_H

#include "AuxScalarKernel.h"
#include "MaterialPropertiesMCCI.h"

class TemperatureCorium;

template<>
InputParameters validParams<TemperatureCorium>();

class TemperatureCorium : public AuxScalarKernel
{
public:

  TemperatureCorium(const InputParameters & parameters);

protected:
  virtual Real computeValue();
    VariableValue & _E;
    VariableValue & _mixture_mass;
    VariableValue & _mixture_mass_old;
    VariableValue & _concrete_mass;
    const MaterialPropertiesMCCI & _corium;
    const MaterialPropertiesMCCI & _concrete;
};

#endif //TEMPERATURECORIUM_H
