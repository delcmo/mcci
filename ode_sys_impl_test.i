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

[Functions]
  # ODEs
  [./exact_x_fn]
    type = ParsedFunction
    value = (-1/3)*exp(-t)+(4/3)*exp(5*t)
  [../]
[]

# NL
[Variables]
  [./x]
    family = SCALAR
    order = FIRST
    initial_condition = 1
  [../]
  [./y]
    family = SCALAR
    order = FIRST
    initial_condition = 2
  [../]
[]

[ScalarKernels]
  [./td1]
    type = ODETimeDerivative
    variable = x
  [../]

  [./ode1]
    type = ImplicitODEx
    variable = x
    y = y
  [../]

  [./td2]
    type = ODETimeDerivative
    variable = y
  [../]
  
  [./ode2]
    type = ImplicitODEy
    variable = y
    x = x
  [../]
[]

[Postprocessors]
  active = 'exact_x l2err_x x y'

  [./x]
    type = ScalarVariable
    variable = x
    component = 0
    execute_on = timestep
  [../]
  
  [./y]
    type = ScalarVariable
    variable = y
    component = 0    
    execute_on = timestep
  [../]

  [./exact_x]
    type = PlotFunction
    function = exact_x_fn
    execute_on = timestep_end
    point = '0 0 0'
  [../]

  [./l2err_x]
    type = ScalarL2Error
    variable = x
    function = exact_x_fn
  [../]
[]

[Executioner]
  type = Transient
  start_time = 0
  dt = 0.01
  num_steps = 100

  # Preconditioned JFNK (default)
  solve_type = 'PJFNK'
[]

[Outputs]
  exodus = true
  vtk = true
  output_on = 'initial timestep_end'
  [./console]
    type = Console
    perf_log = true
    output_on = 'timestep_end failed nonlinear'
  [../]
[]
