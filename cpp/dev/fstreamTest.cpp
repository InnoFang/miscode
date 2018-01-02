#include<fstream>
using namespace std;
ifstream fin("fstreamTest.in");
ofstream fout("fstreamTest.out");
int main()
{
	int a,b;
	while(fin>>a>>b)
		fout<<a+b<<endl;
	return 0;	
} 
