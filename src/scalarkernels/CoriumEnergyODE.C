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

#include "CoriumEnergyODE.h"

template<>
InputParameters validParams<CoriumEnergyODE>()
{
  InputParameters params = validParams<ODEKernel>();
  params.addCoupledVar("concrete_mass", "eroded mass of concrete");
  params.addCoupledVar("corium_temp", "Corium temperature");    
  params.addRequiredParam<Real>("Tdec", "Decomposition temperature of concrete");    
  params.addRequiredParam<Real>("Qdecay", "");
  params.addRequiredParam<Real>("ht_coeff_corium_to_concrete", "heat transfer coefficient between corium and concrete");
  params.addRequiredParam<Real>("Sconcrete", "");
  params.addRequiredParam<UserObjectName>("corium", "Material properties of corium");
  params.addRequiredParam<UserObjectName>("concrete", "Material properties of concrete");
  return params;
}

CoriumEnergyODE::CoriumEnergyODE(const std::string & name, InputParameters parameters) :
    ODEKernel(name, parameters),
    _mass_concrete(coupledScalarValue("concrete_mass")),
    _corium_temp(coupledScalarValue("corium_temp")),
    _Tdec(getParam<Real>("Tdec")),
    _Qdecay(getParam<Real>("Qdecay")),
    _ht(getParam<Real>("ht_coeff_corium_to_concrete")),
    _Sconcrete(getParam<Real>("Sconcrete")),
    _corium(getUserObject<MaterialPropertiesMCCI>("corium")),
    _concrete(getUserObject<MaterialPropertiesMCCI>("concrete"))
{
}

CoriumEnergyODE::~CoriumEnergyODE()
{
}

Real
CoriumEnergyODE::computeQpResidual()
{
    // Heat transfer to concrete
    Real ht_flux = _ht * ( _corium_temp[_i] - _Tdec ) * _Sconcrete;
    
    // Decay heat, radiation to air and heat flux to concete
    Real heat_source_sink = -_Qdecay + ht_flux;
    
    // Heat transfered from mass concrete
    Real ht_concrete = _mass_concrete[_i] * _concrete.Cp() * ( _corium_temp[_i] - _Tdec );
    
    // Return value:
    return heat_source_sink + ht_concrete;
//  return -3. * _u[_i] - 2. * _y[_i];
}

Real
CoriumEnergyODE::computeQpJacobian()
{
  return 0.;
//  return -3.;
}

Real
CoriumEnergyODE::computeQpOffDiagJacobian(unsigned int jvar)
{
    return 0.;
//  if (jvar == _y_var)
//    return -2.;
//  else
//    return 0.;
}
