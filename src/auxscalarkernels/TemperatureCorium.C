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
#include "TemperatureCorium.h"

template<>
InputParameters validParams<TemperatureCorium>()
{
  InputParameters params = validParams<AuxScalarKernel>();
  params.addRequiredCoupledVar("E", "Corium energy");
  params.addRequiredCoupledVar("mixture_mass", "Mass of corium-concrete mixture");
  params.addRequiredCoupledVar("concrete_mass", "Mass of concrete");
  params.addRequiredParam<UserObjectName>("corium", "Material properties of corium");
  params.addRequiredParam<UserObjectName>("concrete", "Material properties of concrete");
  return params;
}

TemperatureCorium::TemperatureCorium(const std::string & name, InputParameters parameters) :
    AuxScalarKernel(name, parameters),
    _E(coupledScalarValue("E")),
    _mixture_mass(coupledScalarValue("mixture_mass")),
    _mixture_mass_old(coupledScalarValueOld("mixture_mass")),
    _concrete_mass(coupledScalarValue("concrete_mass")),
    _corium(getUserObject<MaterialPropertiesMCCI>("corium")),
    _concrete(getUserObject<MaterialPropertiesMCCI>("concrete"))
{}

Real
TemperatureCorium::computeValue()
{    
    // Compute mixture heat capacity:
    Real Cp = ( _concrete_mass[_i] * _concrete.Cp() + _mixture_mass[_i] * _corium.Cp() ) / _mixture_mass[_i];
    
    return _E[_i] / ( Cp * _mixture_mass[_i] );
}
