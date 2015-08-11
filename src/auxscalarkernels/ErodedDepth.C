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
#include "ErodedDepth.h"

template<>
InputParameters validParams<ErodedDepth>()
{
  InputParameters params = validParams<AuxScalarKernel>();
  params.addRequiredCoupledVar("eroded_mass", "Eroded mass of concrete");
  params.addRequiredParam<UserObjectName>("concrete", "Material properties of concrete");
  return params;
}

ErodedDepth::ErodedDepth(const InputParameters & parameters) :
    AuxScalarKernel(parameters),
    _eroded_mass(coupledScalarValue("eroded_mass")),
    _concrete(getUserObject<MaterialPropertiesMCCI>("concrete"))
{}

Real
ErodedDepth::computeValue()
{
    return _u_old[_i] + _eroded_mass[_i] / _concrete.Rho();
}
