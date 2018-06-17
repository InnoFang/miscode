import multiprocessing as mp

# https://docs.python.org/3.5/library/array.html#module-array
# define shared-memory
value = mp.Value('d', 1)
array = mp.Array('i', [1, 2, 3])
