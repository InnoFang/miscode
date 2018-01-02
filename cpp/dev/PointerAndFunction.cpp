#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
	char name[10];
	int age;
} Student;
Student* createInfo(char name[], int age)
{
	Student *student = (Student*)malloc(sizeof(Student));
	if (NULL == student)
		return NULL;
	strcpy(student->name, name);
	student->age = age;
	return student;
}
/*
int main()
{	
	Student *student = createInfo("ZhangSan", 19);
	if (NULL == student)
		printf("Create failed");
	else 
	    printf("Student's name is %s, age is %d\n", student->name, student->age); // output : Student's name is ZhangSan, age is 19
	return 0;
} 
*/
#include <stdio.h>
int plus(int x, int y)
{
	return x + y;
}
int minus(int x, int y)
{
	return x - y;
}
int main()
{
	int (*calc)(int x, int y);
	int x, y, result;
	char o;
	scanf("%d%c%d", &x, &o, &y);
	if(o == '+')
		calc = plus;
	else if (o == '-')
		calc = minus;
	result = (*calc)(x, y);
	printf("= %d\n", result);
	return 0;
}

