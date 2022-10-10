# -*- coding: utf-8 -*-

"""
Node <- Constant, Variable, Operator
                            Operator <- Add, Multiply, Divide, Pow, ...
"""


class Node:
    def __init__(self, name, value=0):
        self.name = name
        self.value = value

    def compute_value(self):
        pass

    def compute_derivative(self, to_variable):
        pass

    def __eq__(self, other):
        return self.name == other.name

    def __str__(self):
        return str(self.name)

    def __repr__(self):
        return self.__str__()


class Constant(Node):
    def __init__(self, value):
        super().__init__(value, value)

    def compute_value(self):
        return self.value

    def compute_derivative(self, to_variable):
        return 0


class Variable(Node):
    def compute_value(self):
        return self.value

    def compute_derivative(self, to_variable):
        return 1 if to_variable.name == self.name else 0


class Operator(Node):
    opt2str = {"Add": "+", "Sub": "-", "Mul": "*", "Div": "/", "Pow": "^"}

    def __init__(self, inputs, name):
        self.inputs = inputs
        self.name = f"Opt {name} of {inputs}"

    def __str__(self):
        return f"({self.opt2str[self.name.split(' ')[1]].join(map(str, self.inputs))})"


class Add(Operator):
    def __init__(self, inputs):
        super().__init__(inputs, name="Add")

    def compute_value(self):
        return sum(inp.compute_value() 
                   for inp in self.inputs)

    def compute_derivative(self, to_variable):
        return sum(inp.compute_derivative(to_variable)
                   for inp in self.inputs)


class Sub(Operator):
    def __init__(self, inputs):
        super().__init__(inputs, name="Sub")

    def compute_value(self):
        a, b = self.inputs
        return a.compute_value() - b.compute_value()

    def compute_derivative(self, to_variable):
        a, b = self.inputs
        return a.compute_derivative(to_variable) - b.compute_derivative(to_variable)


def product(items):
    res = 1
    for i in items:
        res *= i
    return res


class Mul(Operator):
    def __init__(self, inputs):
        super().__init__(inputs, name="Mul")

    def compute_value(self):
        return product(inp.compute_value()
                       for inp in self.inputs)

    def compute_derivative(self, to_variable):
        return sum(
            inp.compute_derivative(to_variable)
            * product(
                other_inp.compute_value()
                for other_inp in self.inputs
                if other_inp != inp)
            for inp in self.inputs)


class Div(Operator):
    def __init__(self, inputs):
        super().__init__(inputs, name="Div")

    def compute_value(self):
        a, b = [inp.compute_value() for inp in self.inputs]
        return a / b

    def compute_derivative(self, to_variable):
        a, b = [inp.compute_value() for inp in self.inputs]
        da, db = [inp.compute_derivative(to_variable) for inp in self.inputs]
        return (da * b - db * a) / (b ** 2)


class Pow(Operator):
    def __init__(self, inputs):
        super().__init__(inputs, name="Pow")

    def compute_value(self):
        x, n = self.inputs
        n = n.value
        return x.compute_value() ** n

    def compute_derivative(self, to_variable):
        x, n = self.inputs
        n = n.value
        return n * (x.compute_value() ** (n - 1)) * x.compute_derivative(to_variable)


def wrapper_opt(opt, self, other, r=False):
    opt2class = {"add": Add, "sub": Sub, "mul": Mul, "div": Div, "pow": Pow}
    if not isinstance(other, Node):
        other = Constant(other) 
    inputs = [other, self] if r else [self, other]
    node = opt2class[opt](inputs=inputs)
    return node


Node.__add__ = lambda self, other: wrapper_opt("add", self, other)
Node.__sub__ = lambda self, other: wrapper_opt("sub", self, other)
Node.__mul__ = lambda self, other: wrapper_opt("mul", self, other)
Node.__truediv__ = lambda self, other: wrapper_opt("div", self, other)
Node.__pow__ = lambda self, other: wrapper_opt("pow", self, other)
Node.__radd__ = lambda self, other: wrapper_opt("add", self, other, r=True)
Node.__rmul__ = lambda self, other: wrapper_opt("mul", self, other, r=True)
Node.__rtruediv__ = lambda self, other: wrapper_opt("div", self, other, r=True)


if __name__ == '__main__':
    x = Variable('x')
    y = Variable('y')
    five = Constant(5)

    # y = x + 5, dy/dx
    print('y = x + 5, compute dy/dx = ', end='')
    print(Add([x, five]).compute_derivative(x))
    print()

    function = 3 * (x ** 2) + 5 * x * y + 6 / x - 8 * y ** 2 + 10

    x.value = 18
    y.value = 2
    print('y = ', end='')
    print(function)
    print('compute value: ', end='')
    print(function.compute_value())
    print('compute derivative x: ', end='')
    print(function.compute_derivative(x))
