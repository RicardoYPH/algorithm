#include <iostream>  
#include <string.h>  
#include <stdio.h>  
  
using namespace std;  
typedef long long LL;  
  
const int N=25;  
  
LL x[N],y[N];  
LL tmpx,tmpy,n,k;  
  
void Init()  
{  
    x[1]=2;y[1]=1;  
    for(int i=2;i<20;i++)  
    {  
        x[i]=2*x[i-1]+3*y[i-1];  
        y[i]=x[i-1]+2*y[i-1];  
    }  
}  
  
int main()  
{  
    Init();  
    while(cin>>n)  
    {  
        if(n==0) break;  
        for(int i=17;i>=0;i--)  
        {  
            if(x[i]%2==0&&x[i]*x[i]<=2*n+2)  
            {  
                tmpx=x[i]/2;  
                tmpy=y[i];  
                break;  
            }  
        }  
        k=(tmpx*tmpx-1)/3;  
        cout<<6*k+1<<" "<<tmpx*tmpy<<endl;  
    }  
    return 0;  
}  
