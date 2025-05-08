#include<iostream>
using namespace std;
const int maxn=1000;
int a[maxn],m[maxn];   //a为余数数组，m是mod的数组 
int exgcd(int a,int b,int&x,int&y)
{
	if(b==0){
		x=1,y=0;
		return a;
	}
	int ans=exgcd(b,a%b,x,y);
	int temp=x;
	x=y;
	y=temp-a/b*y;
	return ans;
}

int china(int n)
{
	int M=1;
	int i,mi,x0,y0,d,ans=0;
	for(i=0;i<n;i++)
	M*=m[i];   //m数组存的是模，这些数字两两互质，所以直接相乘得出来的数字便是最小公倍数
	for(i=0;i<n;i++){
		mi=M/m[i];   //根据中国剩余定理的性质
		exgcd(mi,m[i],x0,y0);   //eg：33*28*a%23=1，因为互质，所以gcd=1，所以利用扩展欧几里得求得出来的x0便是a
		ans=(ans+mi*x0*a[i])%M;   //根据同余的性质，最后的结果就是余数*mod*mi的加和 
	} 
	if(ans<0) ans+=M;
	return ans; 
}

int main()
{
	
}
