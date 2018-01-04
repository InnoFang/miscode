import threading
import time

class myThread(threading.Thread) :
	def __init__(self, threadID, name, counter):
		threading.Thread.__init__(self)
		self.threadID = threadID
		self.name = name
		self.counter = counter
	def run(self):
		print ("Thread Start : " + self.name)
		# Acquire Thread Lock
		threadLock.acquire()
		print_time(self.name, self.counter, 3)
		threadLock.release()

def print_time(threadName, delay, counter):
	while counter:
		time.sleep(delay)
		print ("%s: %s" % (threadName, time.ctime(time.time())))
		counter -= 1

if __name__ == "__main__":
	threadLock = threading.Lock()
	threads = []

	# create Thread
	thread1 = myThread(1, "Thread-1", 1)
	thread2 = myThread(2, "Thread-2", 2)

	# start Thread
	thread1.start()
	thread2.start()

	## add thread to thread list
	threads.append(thread1)
	threads.append(thread2)

	# wait all thread to stop
	for t in threads:
		t.join()
	print ("Exit Thread.")
