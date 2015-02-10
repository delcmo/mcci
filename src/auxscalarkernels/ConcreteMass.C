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
#include "ConcreteMass.h"

template<>
InputParameters validParams<ConcreteMass>()
{
  InputParameters params = validParams<AuxScalarKernel>();
  params.addCoupledVar("concrete_mass_erobed", "Mass of erobed concrete");
  return params;
}

ConcreteMass::ConcreteMass(const std::string & name, InputParameters parameters) :
    AuxScalarKernel(name, parameters),
    _concrete_mass(coupledScalarValue("concrete_mass_erobed"))
{}

Real
ConcreteMass::computeValue()
{
    return _u_old[_i] - _concrete_mass[_i];
}
