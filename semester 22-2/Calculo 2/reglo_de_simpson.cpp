#include <bits/stdc++.h>
#define e 2.71828182845904523536
#define f(x) 1/pow(e,x*x)
using namespace std;

double sum(int a, double point, int k,int n,int b){
    if(k==0) return f(a)+sum(a,point,k+1,n,b);
    if(n==k) return f(b);
    return 2*(f(a+point*k))+sum(a,point,k+1,n,b);
}
int main(){
    double a,b,n;
    cin>>a>>b>>n;
    double point=(b-a)/n;
    cout<<"La derivada definida es: "<<(sum(a,point,0,n,b)/2)*point<<endl;
}
