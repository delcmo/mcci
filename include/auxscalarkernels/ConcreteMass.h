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

#ifndef CONCRETEMASS_H
#define CONCRETEMASS_H

#include "AuxScalarKernel.h"

class ConcreteMass;

template<>
InputParameters validParams<ConcreteMass>();

class ConcreteMass : public AuxScalarKernel
{
public:

  ConcreteMass(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeValue();
  VariableValue & _concrete_mass;
  
};

#endif // CONCRETEMASS_H
