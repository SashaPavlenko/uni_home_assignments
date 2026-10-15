# Numerical Methods – Lab Assignments

University coursework for a Numerical Analysis course, written in Python (2021–2022) with `numpy`, `sympy`, `pandas` and `matplotlib`.

| Folder | Topic | Methods |
|---|---|---|
| `nonlinear_equations/` | Root finding | Secant, bisection, fixed-point iteration |
| `numerical_integration/` | Quadrature | Midpoint, trapezoidal, Simpson; Runge rule and a priori error estimate; series-based handling of a singular integrand |
| `ode_solvers/` | Initial value problems | Explicit Euler, predictor-corrector Euler, Heun, 3rd-order Runge–Kutta (scalar ODE and a system) |
| `interpolation/` | Polynomial interpolation | Lagrange, Newton (finite differences), Hermite (divided differences), error estimate |

Run scripts from the repository root, e.g. `python -m nonlinear_equations.secant_method`.

```
pip install -r requirements.txt
```
