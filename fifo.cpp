#include<bits/stdc++.h>
using namespace std;
int main(){
    //cout<<"Enter no of page\n";
    int n,m;cin>>n;
    vector<int>v(n);
    //cout<<"Enter pages: \n";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>m;
    queue<int>q;
    unordered_set<int>s;
    int c=0;
    int arr[m][n];
    for(int i=0;i<n;i++){
        int page=v[i];
        if(s.find(page)==s.end()){
           // cout<<page<<" ";
           

            if(s.size()==m){
               
                int f=q.front();
               // cout<<f<<" ";
                q.pop();
                s.erase(f);
            }
            //cout<<"M ";
            s.insert(page);
            q.push(page);
            c++;
            
            
        }
      
        
        cout<<endl;
    }
    cout<<"page fault/miss: "<<c<<endl;
    cout<<"Page Hit: "<<n-c<<endl;
}
