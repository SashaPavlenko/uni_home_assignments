import sympy as sy
import math
from sympy import cos, sqrt, pprint
from numerical_integration import quadrature as funcs

# --------------------------------------------------------
# Constants
omega = 11
EPS = 1E-4

# --------------------------------------------------------
# Function selection.

# index = 0: the function from the assignment variant.
# index = 1: the cosine function.
# index = 2: a constant function.
# --------------------------------------------------------
index = 0

AB = [
    (1.4, 3.),
    (0, math.pi),
    (0, math.pi),
]

F = [
    lambda x: sqrt(x*x+1)*cos(omega*x),
    lambda x: cos(x),
    lambda x: 1,

]

a, b = AB[index]
f = F[index]

# --------------------------------------------------------
# Compute the integral with different methods.
# --------------------------------------------------------

x = sy.Symbol('x')

l = [
    sy.Integral(f(x), (x, a, b)).evalf(),
    funcs.int_rect(f, 811, a, b),
    funcs.trapez(f, 1209, a, b),
    funcs.int_rect(f, 76, a, b),
]

s = """\
Интеграл, посчитанный средствами sympy: {0} 
Интеграл, посчитанный методом средних прямоугольников: {1} 
Интеграл, посчитанный методом трапеций: {2}
Интеграл, посчитанный методом Симсона: {3}\
""".format(*l)

title = "Рассмотрим вычисления интеграла разными методами."
print(title, s, sep='\n', end='\n\n')

# --------------------------------------------------------
# Absolute error.
# --------------------------------------------------------

I_exact = 0.246387535667679
f_check = lambda f_int, n: f_int(f, n, a, b)

l = [
    I_exact - f_check(funcs.int_rect, 811),
    I_exact - f_check(funcs.trapez, 1209),
    I_exact - f_check(funcs.Simpson, 76),
]

s = """\
Абсолютная погрешность метода средних прямоугольников: {0:e}
Абсолютная погрешность метода трапеций: {1:e}
Абсолютная погрешность метода Симпсона: {2:e}\
""".format(*l)

title = "Рассмотрим абсолютную погрешность."
print(title, s, sep='\n', end='\n\n')

# --------------------------------------------------------
# Compare the theoretical estimate with the Runge rule.
# --------------------------------------------------------

runge_n1 = funcs.Runge(a, b, 1, EPS, f, funcs.int_rect)
runge_n2 = funcs.Runge(a, b, 1, EPS, f, funcs.trapez)
runge_n3 = funcs.Runge(a, b, 1, EPS, f, funcs.Simpson)

eval_n1 = funcs.exac_loss(a, b, 1, EPS, f, funcs.int_rect)
eval_n2 = funcs.exac_loss(a, b, 1, EPS, f, funcs.trapez)
eval_n3 = funcs.exac_loss(a, b, 1, EPS, f, funcs.Simpson)

s = f"""\
ПРАВИЛО РУНГЕ
int_rect: n = {runge_n1}
trapez: n = {runge_n2}
Simpson: n = {runge_n3}

НЕ ПРАВИЛО РУНГЕ (оценка)
int_rect: n = {eval_n1}
trapez: n = {eval_n2}
Simpson: n = {eval_n3}\
"""

title = "Сравним оценку с правилом Рунге."
print(title, s, sep='\n', end='\n\n')
