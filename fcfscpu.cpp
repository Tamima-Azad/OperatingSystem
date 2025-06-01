#include<bits/stdc++.h>
using namespace std;
vector<pair<int,vector<int>>>v;
void inp(int n){
    cout<<"follow this sequence to give input\n";
    cout<<"arrival time-process order-burst time"<<endl;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({a,{b,c}});
    }
}
void gantt(int n){
    cout<<"Gantt chart\n";
    for(int i=0;i<n;i++){
        cout<<v[i].second[0]<<' ';
    }
    cout<<endl;
}
void CT(int n){
    v[0].second[2]=v[0].first+v[0].second[1];
    int sum=v[0].first+v[0].second[1];
    for(int i=1;i<n;i++){
        v[i].second[2]=sum+v[i].second[1]+v[i].second[5];
        //sum+=(v[i].second[1]+v[i].second[5]);
        sum=v[i].second[2];
        // cout<<v[i].second[2]<<' ';
    }
    // cout<<endl;
}
void TAT(int n){
    for(int i=0;i<n;i++){
        v[i].second[3]=v[i].second[2]-v[i].first;
        // cout<<v[i].second[3]<<' ';
    }
    // cout<<endl;
}
void WT(int n){
    for(int i=0;i<n;i++){
        v[i].second[4]=v[i].second[3]-v[i].second[1];
        // cout<<v[i].second[4]<<' ';
    }
    // cout<<endl;
}
void idle(int n){
    v[0].second[5]=(v[0].first-0);
    int sum=v[0].first+v[0].second[1];
    for(int i=1;i<n;i++){
        if(v[i].first<sum){
            v[i].second[5]=0;
            sum+=v[i].second[1];
        }
        else{
            v[i].second[5]=(v[i].first-sum);
            sum+=v[i].second[1]+v[i].second[5];
        }
    }
}
void print(int n){
    vector<pair<int,vector<int>>>v1;
    for(int i=0;i<n;i++){
        v1.push_back({v[i].second[0],{v[i].first,v[i].second[1],v[i].second[2],v[i].second[3],v[i].second[4],v[i].second[5]}});
    }
    sort(v1.begin(),v1.end());
    cout<<"PO "<<"AT "<<"BT "<<"CT "<<"TT "<<"WT "<<"IT "<<endl;
    for(int i=0;i<n;i++){
        if(v1[i].first<10)cout<<' '<<v1[i].first<<' ';
        else cout<<v1[i].first<<' ';
        for(int j=0;j<6;j++){
            if(v1[i].second[j]>10)cout<<v1[i].second[j]<<' ';
            else cout<<' '<<v1[i].second[j]<<' ';
        }
        cout<<endl;
    }
}
int main ()
{
    cout<<"how many process do you have?"<<endl;
    int n;
    cin>>n;
    inp(n);
    sort(v.begin(),v.end());
    gantt(n);
    idle(n);
    CT(n);
    TAT(n);
    WT(n);
    print(n);
    return 0;
}