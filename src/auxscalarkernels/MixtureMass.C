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
/**
This function computes the density of the fluid.
**/
#include "MixtureMass.h"

template<>
InputParameters validParams<MixtureMass>()
{
  InputParameters params = validParams<AuxScalarKernel>();
  params.addCoupledVar("concrete_mass", "Mass of erobed concrete");
  return params;
}

MixtureMass::MixtureMass(const InputParameters & parameters) :
    AuxScalarKernel(parameters),
    _concrete_mass(coupledScalarValue("concrete_mass"))
{}

Real
MixtureMass::computeValue()
{
    return _u_old[_i] + _concrete_mass[_i];
}
