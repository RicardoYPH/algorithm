#include <iostream>
#include <cmath>
using namespace std;

int factor(long a,long b);	//求公因数
void put(long a,long b,long c);		//按格式要求输出

int main()
{
	long a1,b1,a2,b2;	//输入数据
	cin>>a1;cin.get();
	cin>>b1;
	cin>>a2;cin.get();
	cin>>b2;

	long fact=factor(a1,b1);	//求最大公因数，化简
	a1/=fact;
	b1/=fact;
	fact=factor(a2,b2);
	a2/=fact;
	b2/=fact;

	long c11=a1/b1,a11=a1%b1,c22=a2/b2,a22=a2%b2;	//求带整数的格式

	long aa,bb,cc;	//运算结果
	put(a11,b1,c11);	//加法
	cout<<" + ";
	put(a22,b2,c22);
	cout<<" = ";
	bb=b1*b2;
	aa=a1*b2+a2*b1;
	fact=factor(aa,bb);	//约简输出
	aa/=fact;
	bb/=fact;
	cc=aa/bb;
	aa%=bb;
	put(aa,bb,cc);
	cout<<endl;

	put(a11,b1,c11);	//减法
	cout<<" - ";
	put(a22,b2,c22);
	cout<<" = ";
	bb=b1*b2;
	aa=a1*b2-a2*b1;
	fact=factor(aa,bb);	//约简输出
	aa/=fact;
	bb/=fact;
	cc=aa/bb;
	aa%=bb;
	put(aa,bb,cc);
	cout<<endl;

	put(a11,b1,c11);	//乘法
	cout<<" * ";
	put(a22,b2,c22);
	cout<<" = ";
	bb=b1*b2;
	aa=a1*a2;
	fact=factor(aa,bb);	//约简输出
	aa/=fact;
	bb/=fact;
	cc=aa/bb;
	aa%=bb;
	put(aa,bb,cc);
	cout<<endl;

	put(a11,b1,c11);	//除法
	cout<<" / ";
	put(a22,b2,c22);
	cout<<" = ";
	if(a2==0)	//非法
		cout<<"Inf\n";
	else	//合法
	{
		bb=b1*a2;
		aa=a1*b2;
		if(aa<0&&bb<0||aa>0&&bb<0)	//调整符号
		{
			aa*=-1;
			bb*=-1;
		}
		fact=factor(aa,bb);	//约简输出
		aa/=fact;
		bb/=fact;
		cc=aa/bb;
		aa%=bb;
		put(aa,bb,cc);
		cout<<endl;
	}

	return 0;
}

int factor(long a,long b)
{
	if(a%b==0)
		return b;
	if(b%a==0)
		return abs(a);
	long fact=1;	//因数
	long limit=(long)sqrt((double)min(abs(a),abs(b))+2);	//限制
	for(long i=2;i<=limit;i++)
	{
		if(a%i==0&&b%i==0)
			while(a%i==0&&b%i==0)
			{
				a/=i;
				b/=i;
				fact*=i;
			}
	}
	return fact;
}

void put(long a,long b,long c)
{
	int flag=0;
	if(c<0||a<0)
		flag=1;
	if(flag==1)
		cout<<"(";
	if(c==0&&a==0)
	{
		cout<<0;
		return;
	}
	if(c!=0)
	{
		cout<<c;
		if(a!=0)
			cout<<" ";
	}
	if(a!=0)
	{
		if(c<0)
			cout<<abs(a)<<"/"<<b;
		else
			cout<<a<<"/"<<b;
	}
	if(flag==1)
		cout<<")";
}

