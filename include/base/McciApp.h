#ifndef MCCIAPP_H
#define MCCIAPP_H

#include "MooseApp.h"

class McciApp;

template<>
InputParameters validParams<McciApp>();

class McciApp : public MooseApp
{
public:
  McciApp(InputParameters parameters);
  virtual ~McciApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MCCIAPP_H */
