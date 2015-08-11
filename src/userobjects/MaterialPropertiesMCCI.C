#include "MaterialPropertiesMCCI.h"
#include "MooseError.h"

template<>
InputParameters validParams<MaterialPropertiesMCCI>()
{
  InputParameters params = validParams<UserObject>();
    params.addParam<Real>("Cp", 0, "  heat capacity at constant pressure");
    params.addParam<Real>("rho", 0, " material density");    
    return params;
}

MaterialPropertiesMCCI::MaterialPropertiesMCCI(const InputParameters & parameters) :
  GeneralUserObject(parameters),
    _Cp(getParam<Real>("Cp")),
    _rho(getParam<Real>("rho"))
{}

MaterialPropertiesMCCI::~MaterialPropertiesMCCI()
{
  // Destructor, empty
}

void
MaterialPropertiesMCCI::destroy()
{
}

//Real MaterialPropertiesMCCI::pressure(Real rho, Real vel_norm, Real rhoE) const
//{
//    this->error_not_implemented("pressure");
//    return 0.;
//}

Real MaterialPropertiesMCCI::Cp() const
{
    return _Cp;
}

Real MaterialPropertiesMCCI::Rho() const
{
    return _rho;
}

void MaterialPropertiesMCCI::error_not_implemented(std::string method_name) const
{}
