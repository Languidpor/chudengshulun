#include<iostream>
using namespace std;
const int maxn=1000;
int a[maxn],m[maxn];   //aΪ�������飬m��mod������ 
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
	M*=m[i];   //m��������ģ����Щ�����������ʣ�����ֱ����˵ó��������ֱ�����С������
	for(i=0;i<n;i++){
		mi=M/m[i];   //�����й�ʣ�ඨ�������
		exgcd(mi,m[i],x0,y0);   //eg��33*28*a%23=1����Ϊ���ʣ�����gcd=1������������չŷ�������ó�����x0����a
		ans=(ans+mi*x0*a[i])%M;   //����ͬ������ʣ����Ľ����������*mod*mi�ļӺ� 
	} 
	if(ans<0) ans+=M;
	return ans; 
}

int main()
{
	
}
