import tensorflow as tf

print ('\nYour GPU is :', end=" ")
hello = tf.constant('Hello, TensorFlow!')
sess = tf.Session()

print()
#Creates a gra ph.
a = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[2, 3], name='a')
b = tf.constant([1.0, 2.0, 3.0, 4.0, 5.0, 6.0], shape=[3, 2], name='b')
c = tf.matmul(a, b)
#Creates a session with log_device_placement set to True.
sess = tf.Session(config=tf.ConfigProto(log_device_placement=True))
#Runs the op.
print (sess.run(c))


