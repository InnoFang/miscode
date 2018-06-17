import threading


def main():
    print(threading.active_count())
    print(threading.enumerate())
    print(threading.current_thread())


if __name__ == '__main__':
    main()
