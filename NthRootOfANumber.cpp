#include<bits/stdc++.h>
using namespace std;
double eps=1e-6;
double multiply(double a,int b){
    double ans=1.0;
    for(int i=0;i<b;i++){
          ans=ans*a;
    }
    return ans;
}
int main(){
  int n,x;
  cin>>x>>n;
  double lo=1;double hi=x;double mid;
  while(hi-lo>eps){
     mid =(hi+lo)/2;
    if(multiply(mid,n)<x){
        lo=mid;

    }
    else{
        hi=mid;
    }
  }
  cout<<mid<<" "<<endl;
  return 0;
}