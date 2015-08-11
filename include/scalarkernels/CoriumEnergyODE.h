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

#ifndef CORIUMENERGYODE_H
#define CORIUMENERGYODE_H


#include "ODEKernel.h"
#include "MaterialPropertiesMCCI.h"

//Forward Declarations
class CoriumEnergyODE;

template<>
InputParameters validParams<CoriumEnergyODE>();

/**
 *
 */
class CoriumEnergyODE : public ODEKernel
{
public:
  CoriumEnergyODE(const InputParameters & parameters);
  virtual ~CoriumEnergyODE();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

  VariableValue & _mass_concrete;
  VariableValue & _corium_temp;
  Real _Tdec;
  Real _Qdecay;
  Real _ht;
  Real _Sconcrete;
//  VariableValue & _y;
  const MaterialPropertiesMCCI & _corium;
  const MaterialPropertiesMCCI & _concrete;
};


#endif /* CORIUMENERGYODE_H */
