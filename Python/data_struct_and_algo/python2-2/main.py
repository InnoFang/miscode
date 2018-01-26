# ('Jim', 16, 'male', 'jim@gmail.com')
# ('Lilei', 15, 'female', 'lilei@gmail.com')
# ('Tom', 17, 'male', 'tom@gmail.com')

student = ('Jim', 16, 'male', 'jim@gmail.com')

# plan 1
NAME, AGE, SEX, EMAIL = range(4)

print(student[NAME], student[AGE], student[SEX], student[EMAIL])


# plan 2
from collections import namedtuple

Student = namedtuple('Student', ['name', 'age', 'sex', 'email'])

s = Student('Jim', 16, 'male', 'jim@gmail.com')

print(s.name, s.age, s.sex, s.email)

print(isinstance(s, tuple))