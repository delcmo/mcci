#include "McciApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

#include "CoriumEnergyODE.h"
#include "MaterialPropertiesMCCI.h"
#include "TemperatureCorium.h"
#include "ErodedMassConcrete.h"
#include "MixtureMass.h"
#include "ConcreteMass.h"
#include "ErodedDepth.h"

template<>
InputParameters validParams<McciApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

McciApp::McciApp(const std::string & name, InputParameters parameters) :
    MooseApp(name, parameters)
{
  srand(processor_id());

  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  McciApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  McciApp::associateSyntax(_syntax, _action_factory);
}

McciApp::~McciApp()
{
}

extern "C" void McciApp__registerApps() { McciApp::registerApps(); }
void
McciApp::registerApps()
{
  registerApp(McciApp);
}

void
McciApp::registerObjects(Factory & factory)
{
    registerScalarKernel(CoriumEnergyODE);
    registerAux(TemperatureCorium);
    registerAux(ErodedMassConcrete);
    registerAux(MixtureMass);
    registerAux(ConcreteMass);
    registerAux(ErodedDepth);
    registerUserObject(MaterialPropertiesMCCI);
}

void
McciApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
