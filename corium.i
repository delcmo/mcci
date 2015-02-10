[Mesh]
  type = GeneratedMesh
  dim = 2
  xmin = 0
  xmax = 1
  ymin = 0
  ymax = 1
  nx = 1
  ny = 1
#  elem_type = QUAD4
[]

# NL
[Variables]
  [./E]
    family = SCALAR
    order = FIRST
    initial_condition = 200
  [../]
[]

[AuxVariables]
  [./temp_corium]
    family = SCALAR
    order = FIRST
    initial_condition = 2.
  [../]
  
  [./mixture_mass]
    family = SCALAR
    order = FIRST
    initial_condition = 4.
  [../]
  
  [./concrete_mass_eroded]
    family = SCALAR
    order = FIRST
    initial_condition = 0.
  [../]
 
 [./concrete_mass]
    family = SCALAR
    order = FIRST
    initial_condition = 4.
 [../]
 
 [./eroded_depth]
    family = SCALAR
    order = FIRST
    initial_condition = 0.
 [../]
[]

[UserObjects]
  [./corium]
    type = MaterialPropertiesMCCI
    Cp = 2.
  [../]
  
  [./concrete]
    type = MaterialPropertiesMCCI
    Cp = 0.1
  [../]
[]

[ScalarKernels]
  [./td1]
    type = ODETimeDerivative
    variable = E
  [../]

  [./ode1]
    type = CoriumEnergyODE
    variable = E
    concrete_mass = concrete_mass_eroded
    corium_temp = temp_corium
    Tdec = 1.
    Qdecay = 20.
    ht_coeff_corium_to_concrete = 1.
    Sconcrete = 1.
    corium = corium
    concrete = concrete 
  [../]
[]

[AuxScalarKernels]
  [./TempCoriumAK]
    type = TemperatureCorium
    variable = temp_corium
    E = E
    mixture_mass = mixture_mass
    concrete_mass = concrete_mass_eroded
    corium = corium
    concrete = concrete
  [../]

  [./ErodedConcreteMassAK]
    type = ErodedMassConcrete
    variable = concrete_mass_eroded
    corium_temp = temp_corium
    Tdec = 1.
    ht_coeff_corium_to_concrete = 2.
    Sconcrete = 1.
    Hdec = 0.1
  [../]
 
  [./MixtureMassAK]
    type = MixtureMass
    variable = mixture_mass
    concrete_mass = concrete_mass_eroded
  [../]
 
 [./ConcreteMassAK]
    type = ConcreteMass
    variable = concrete_mass
    concrete_mass_erobed = concrete_mass_eroded
 [../]
 
 [./ErodedDepthAK]
    type = ErodedDepth
    variable = eroded_depth
    eroded_mass = concrete_mass_eroded
    concrete = concrete
 [../]
[]

[Executioner]
  type = Transient
  start_time = 0
  dt = 0.01
  num_steps = 2
  solve_type = 'PJFNK'
[]

[Outputs]
  exodus = true
  output_on = 'initial timestep_end'
  [./console]
    type = Console
    perf_log = true
    output_on = 'timestep_end failed nonlinear'
  [../]
[]
