import multiprocessing as mp
import threading as td


def job(a, b, q):
    res = 0
    for i in range(100):
        res += a + b ** 2
    q.put(res)


def main():
    # t1 = td.Thread(target=job, args=(1, 2))
    # t1.start()
    q = mp.Queue()
    p1 = mp.Process(target=job, args=(1, 2, q))
    p2 = mp.Process(target=job, args=(1, 2, q))
    p1.start()
    p2.start()
    p1.join()
    p2.join()
    res1 = q.get()
    res2 = q.get()
    print(res1 + res2)


if __name__ == '__main__':
    main()
