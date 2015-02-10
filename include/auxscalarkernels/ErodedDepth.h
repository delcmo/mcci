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

#ifndef ERODEDDEPTH_H
#define ERODEDDEPTH_H

#include "AuxScalarKernel.h"
#include "MaterialPropertiesMCCI.h"

class ErodedDepth;

template<>
InputParameters validParams<ErodedDepth>();

class ErodedDepth : public AuxScalarKernel
{
public:

  ErodedDepth(const std::string & name, InputParameters parameters);

protected:
  virtual Real computeValue();
    VariableValue & _eroded_mass;
    const MaterialPropertiesMCCI & _concrete;
};

#endif // ERODEDDEPTH_H
