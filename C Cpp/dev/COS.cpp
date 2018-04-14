#include <iostream> 
using namespace std; 

int main () {
	double x;
	while (cin >> x){
		double COS = 1;						 // cos 的值，弧度制 
		double flag = -1;					 // 符号位 
		double de = 1; 						 // 分母
		double mo = 1; 						 // 分子 
		int fac = 1;   						 // 控制分母的阶乘 
		for (int i = 1; ; i++) {
			de *= x * x; 					 // 每次加 x 的平方 
			mo *= (fac * 2) * (fac * 2 - 1); // 下一个分母=当前分母*2n* (2n - 1) 
			fac += 1; 
			double fraction = de / mo; 		 // 分式 
			if (fraction < 1e-10) break; 	 // 如果分式小于该数，视为无穷小，忽略不记 
			COS += flag * fraction; 		 // 添加分式
			flag *= -1;						 // 更新符号位 
		}
		cout << COS << endl;
	}
	return 0;
}
