/*输入纳税人个人月收入，计算应纳个人所得税*/
#include <stdio.h>
int main()
{
	double salary; 	// 工资
	double taxRate;	// 税率 
	double deduction;// 扣除数 
	double tax;	//个人所得税税额 
	printf("输入月收入金额：");
	scanf("%lf", &salary);
	if(salary < 500)	// 级数 1 
	{
		taxRate = 5;
		deduction = 0;
	}
	else if(salary >= 500 && salary < 2000)  // 级数 2 
	{
		taxRate = 10;
		deduction = 25;
	}
	else if(salary >= 2000 && salary < 5000) // 级数 3 
	{
		taxRate = 15;
		deduction = 125;
	}
	else if(salary >= 5000 && salary < 20000)  // 级数 4 
	{
		taxRate = 20;
		deduction = 375;
	}
	else if(salary >= 20000 && salary < 40000) // 级数 5 
	{
		taxRate = 25;
		deduction = 1375;
	}
	else if(salary >= 40000 && salary < 60000) // 级数 6 
	{
		taxRate = 30;
		deduction = 3375;
	}
	else if(salary >= 60000 && salary < 80000) // 级数 7	
	{
		taxRate = 35;
		deduction = 6375;
	}
	else if(salary >= 80000 && salary < 100000)// 级数 8 
	{
		taxRate = 40;
		deduction = 10375;
	}
	else if(salary >= 100000)	// 级数 9 
	{
		taxRate = 45;
		deduction = 15375;
	}
	tax = (salary - 1600) * taxRate * 0.01 - deduction; // 计算个人所得税税额 
	printf("应纳个人所得税税额: %lf\n", tax);
	return 0;
}
