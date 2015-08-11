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
#include "ErodedMassConcrete.h"

template<>
InputParameters validParams<ErodedMassConcrete>()
{
  InputParameters params = validParams<AuxScalarKernel>();
  params.addRequiredCoupledVar("corium_temp", "Corium energy");
  params.addRequiredParam<Real>("Tdec", "Material properties of corium");
  params.addRequiredParam<Real>("ht_coeff_corium_to_concrete", "Material properties of corium");
  params.addRequiredParam<Real>("Sconcrete", "Material properties of corium");
  params.addRequiredParam<Real>("Hdec", "Material properties of corium");    
  return params;
}

ErodedMassConcrete::ErodedMassConcrete(const InputParameters & parameters) :
    AuxScalarKernel(parameters),
    _corium_temp(coupledScalarValue("corium_temp")),
    _Tdec(getParam<Real>("Tdec")),
    _ht_coeff_corium_to_concrete(getParam<Real>("ht_coeff_corium_to_concrete")),
    _Sconcrete(getParam<Real>("Sconcrete")),
    _Hdec(getParam<Real>("Hdec"))
{}

Real
ErodedMassConcrete::computeValue()
{    
    // Compute heat transfer to concrete from corium:
    Real Q = _ht_coeff_corium_to_concrete * ( _corium_temp[_i] - _Tdec );
    
    return Q * _Sconcrete * _dt / _Hdec;
}
