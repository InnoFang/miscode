import numpy as np

f = lambda x: np.sum(x ** 2)

def numerical_gradient(f, x):
    h = 1e-4
    grad = np.zeros_like(x)

    for idx in range(x.size):
        # f(x + h)      
        fxh1 = f( x[idx] + h )

        # f(x - h)
        fxh2 = f( x[idx] - h )

        # grad = ( f( x +  h ) - f( x - h ) ) / ( 2 * h )
        grad[idx] = ( fxh1 - fxh2 ) / ( 2 * h )
    return grad

def gradient_descent(f, init_x, learning_rate=0.1, step_num=100):
    x = init_x

    for _ in range(step_num):
        grad = numerical_gradient(f, x)
        x -= grad * learning_rate
    
    return x


if __name__ == '__main__':
    print(gradient_descent(f, np.array([-3., 4.])))
    