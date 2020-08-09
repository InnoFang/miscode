import tensorflow as tf

x = tf.Variable(5.)
lr = 0.1
epoch = 50

# loss_function = ( x + 1 ) ^ 2, use the 'Gradient Descent' to find the minimum value of the loss function

for i in range(epoch):
    with tf.GradientTape() as tape:
        loss = tf.square(x + tf.constant(1.))
        grad = tape.gradient(loss, x)

    x.assign_sub(lr * grad)
    print("After {} epoch, w is {}, loss, is {}".format(i, x.value(), loss))
