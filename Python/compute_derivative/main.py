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
        return self.name == other.name and self.value == other.value

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
        return self.inputs[0].compute_value() + \
                sum(-1 * inp.compute_value()
                    for inp in self.inputs)

    def compute_derivative(self, to_variable):
        return self.inputs[0].compute_derivative() + \
                sum(-1 * inp.compute_derivative()
                    for inp in self.inputs)


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
        a, b = [inp.commpute_value() for inp in self.inputs]
        return a / b

    def compute_derivative(self, to_variable):
        a, b = [inp.commpute_value() for inp in self.inputs]
        da, db = [inp.compute_derivative(to_variable) for inp in self.inputs]
        return (da * b - db * a) / (b ** 2)


class Power(Operator):
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

if __name__ == '__main__':
    print(Add([Variable('x'), Constant(5)]).compute_derivative(Variable('x')))
