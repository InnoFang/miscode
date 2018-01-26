class people:
	name = ''
	age = 0
	__weight = 0
	def __init__(self, n, a, w):
		self.name = n
		self.age = a
		self.__weight = w

	def speak(self):
		print ('%s say, I am %d years old.' % (self.name, self.age))


class student(people):
	grade = ''
	def __init__(self, n, a, w, g):
		people.__init__(self, n, a, w)
		self.grade = g

	def speak(self):
		print ('% say, I am %d years old, I am at grade %d' % (self.name, self.age, self.grade))

class speaker():
	topic = ''
	name = ''
	def __init__(self, n, t):
		self.name = n
		self.topic = t
	def speak(self):
		print ('My name is %s, I am a speaker, the topic is %s' % (self.name, self.topic))

class sample(speaker, student):
	a = ''
	def __init__(self, name, age, weight, grade, topic):
		student.__init__(self, name, age, weight, grade)
		speaker.__init__(self, name, topic)

#################

class JustCounter:
	__secretCount = 0 # private 
	publicCount = 0

	def count(self):
		self.__secretCount += 1
		self.publicCount += 1
		print (self.__secretCount)

if __name__ == '__main__':
	# p = people('Inno', 19, 140)					# 类的简单使用
	# p = student('Inno', 19, 140, 9)				# 单继承
	p = sample("Tim", 25, 80, 4, "Hello, Python")	# 多继承
	p.speak()	#方法名同，默认调用的是在括号中排前地父类的方法

	#############

	"""
	类的私有属性
	__private_attrs：两个下划线开头，声明该属性为私有，不能在类地外部被使用或直接访问。在类内部的方法中使用时 self.__private_attrs。

	类的方法
	在类地内部，使用def关键字可以为类定义一个方法，与一般函数定义不同，类方法必须包含参数self,且为第一个参数

	类的私有方法
	__private_method：两个下划线开头，声明该方法为私有方法，不能在类地外部调用。在类的内部调用 self.__private_methods。
	"""
	counter = JustCounter()
	counter.count()
	counter.count()
	print ("result = ", counter.publicCount)
	# print ("result = ", counter.__secretCount) # wrong, an instance cannot access a private variable