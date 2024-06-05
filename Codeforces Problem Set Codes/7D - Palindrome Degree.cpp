#include <bits/stdc++.h>
using namespace std;
const int sz=5e6+5;
int h[sz],sum,l,r,a=3,len;
char s[sz];
int main(){
	gets(s+1);
	h[1]=sum=1;
	l=r=s[1];
	for(int i=2;s[i];i++,a*=3){
		l*=3;l+=s[i];
		r+=a*s[i];
		if(l==r)h[i]=h[i>>1]+1,sum+=h[i];
	}
	printf("%d",sum);
	return 0;
}
