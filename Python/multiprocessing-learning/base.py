import multiprocessing as mp
import threading as td


def job(a, b):
    print('%d + %d = %d' % (a, b, a + b))


def main():
    # t1 = td.Thread(target=job, args=(1, 2))
    # t1.start()
    p1 = mp.Process(target=job, args=(1, 2))
    p1.start()


if __name__ == '__main__':
    main()
