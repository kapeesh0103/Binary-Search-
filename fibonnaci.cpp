#include<bits/stdc++.h>
using namespace std;
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
   while(t--){
     int n;
   cin>>n;
   cout<<NthNumberOfFibonacci(n)<<endl;
   }
    
   
   return 0;


}