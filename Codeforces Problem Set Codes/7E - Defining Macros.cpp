#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double D;
map<string,int>g;
string s;
char t[100010];
int n;
int calc(int l,int r) {
    int tot=0,i,x,y;
    for (i=r;i>=l;i--) {
        if (t[i]==')') tot++;
        if (t[i]=='(') tot--;
        if (!tot&&(t[i]=='+'||t[i]=='-')) {
            x=calc(l,i-1); y=calc(i+1,r);
            return x&&y&&(t[i]!='-'||y>1);
        }
    }
    for (i=r;i>=l;i--) {
        if (t[i]==')') tot++;
        if (t[i]=='(') tot--;
        if (!tot&&(t[i]=='*'||t[i]=='/')) {
            x=calc(l,i-1); y=calc(i+1,r);
            return x>1&&y>1&&(t[i]!='/'||y>2)?2:0;
        }
    }
    if (t[l]=='(') return calc(l+1,r-1)?3:0;
    string tmp(t+l,t+r+1);
    return g.count(tmp)?g[tmp]:3;
}
int G() {
    gets(t);
    int len=strlen(t),i=0,m=0;
    for (;t[i];i++) if (t[i]!=' '&&t[i]!='\n') t[m++]=t[i];
    t[m]=0;
    return calc(0,m-1);
}
int main(){
    int i;
    scanf("%d",&n);
    for (i=1;i<=n;i++) {
        scanf(" #%*s"); cin>>s;
        g[s]=G();
    }
    puts(G()?"OK":"Suspicious");
    return 0;
}
