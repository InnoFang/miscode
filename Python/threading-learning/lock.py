import threading


def job1():
    global A
    global lock
    lock.acquire()
    for i in range(10):
        A += 1
        print('Job1 ', A)
    lock.release()


def job2():
    global A
    global lock
    lock.acquire()
    for i in range(10):
        A += 10
        print('Job2 ', A)
    lock.release()


def main():
    thread1 = threading.Thread(target=job1)
    thread2 = threading.Thread(target=job2)
    thread1.start()
    thread2.start()
    thread1.join()
    thread2.join()

if __name__ == '__main__':
    A = 0
    lock = threading.Lock()
    main()