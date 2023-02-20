#include<bits/stdc++.h>
using namespace std;
vector<int> fibo(47);
pair<long long,long long> encodeFibonacci(int n){
    long long ans=0;int h=0;bool flag=true;int i=46;
    while(n){
        
        while(i>=2 && fibo[i]>n){
            i--;
        }
        if(flag){
            h=i-1;
            flag=false;
        }
        ans|=(1LL<<(i-2));
        n-=fibo[i];
    }
    ans|=(1LL<<h);
    return {ans,h};
    
}
void print(vector<vector<int>> &a){
    int n=a.size();int m=a[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<vector<int>> MatrixMultiplication(vector<vector<int>> &a,vector<vector<int>> &b){
int n=a.size();
int m=a[0].size();
int k=b[0].size();
vector<vector<int>> ans(n,vector<int>(k,0));
for(int i=0;i<n;i++){
    for(int j=0;j<k;j++){
        for(int l=0;l<m;l++){
                 ans[i][j]+=a[i][l]*b[l][j];

        }
    }
}
return ans;

}
// below method find fibonacci number fast doubling in below method.
pair<int,int> NthFibonacci(int n){
if(n==0){
    return {0,1};
}
auto p=NthFibonacci(n>>1);
int c= p.first*(2*p.second - p.first);
int d=p.first*p.first + p.second*p.second;
if(n&1){
    return {d,c+d};
}
else{
    return {c,d};
}

}
int NthNumberOfFibonacci(int n){

vector<vector<int>> P;
P={{0,1},{1,1}};
vector<vector<int>> res;
res={{1,0},{0,1}};
while(n>0){
    if(n&1){
        res=MatrixMultiplication(res,P);

    }
  //  print(res);
    P=MatrixMultiplication(P,P);
   // print(P);
    n>>=1;
}
return res[1][0];

}
int main(){
    // below method check to find multiplication of matrix
    /*int n,m;
   cin>>n>>m;
   vector<vector<int>> a(n,vector<int> (m,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>a[i][j];
    }
   }
   cin>>n>>m;
   vector<vector<int>> b(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>b[i][j];
    }
   }
   vector<vector<int>> c;
   c=MatrixMultiplication(a,b);
   print(c); */
   int t;
   cin>>t;
    
   for(int i=0;i<47;i++){
    
    fibo[i]=NthFibonacci(i).first;
   }
   while(t--){
     int n;
   cin>>n;
//    cout<<NthNumberOfFibonacci(n)<<endl;
//    cout<<NthFibonacci(n).first<<endl;
//    cout<<fibo[n]<<endl;
   auto p=encodeFibonacci(n);
int ans=0;
cout<<p.second<<endl;
    for(long long i=0;i<=p.second;i++){
        cout<<((p.first>>i)&1LL);
        if(((p.first>>i)&1LL)){
                 ans+=fibo[i+2];
                 
        }
    }
    ans-=fibo[p.second+2];
   cout<<endl;
    
    cout<<ans<<endl;
    cout<<endl;
   }
     
   
   return 0;


}