#include<bits/stdc++.h>
using namespace std;
class cpu{
    public:
   int  p,AT,BT,CT,TAT,WT;
};
int main(){
    int n;cin>>n;
    vector<cpu>algo(n);
    for(int i=0;i<n;i++){
        algo[i].p=i+1;
        cin>>algo[i].AT>>algo[i].BT;
    }
    sort(algo.begin(),algo.end(),[](const cpu &a,const cpu &b){
        return a.AT<b.AT;
    });
    int cnt=0;
    for(int i=0;i<n;i++){
        if(algo[i].AT>cnt){
            cnt=algo[i].AT;
        }
        cnt+=algo[i].BT;
        algo[i].CT=cnt;
    }
    int avg_tat=0,avg_wt=0;
    for(int i=0;i<n;i++){
        algo[i].TAT=algo[i].CT-algo[i].AT;
        algo[i].WT=algo[i].TAT-algo[i].BT;
        avg_tat+=algo[i].TAT;
        avg_wt+=algo[i].WT;
    }
    for(int i=0;i<n;i++){
        cout<<"p"<<algo[i].p<<" "<<algo[i].AT<<" "<<algo[i].BT<<" "<<algo[i].TAT<<" "<<algo[i].WT<<endl;
    }
    cout<<endl;
    cout<<"AVG TAT= "<<(float)avg_tat/n<<endl;
    cout<<"AVG WT= "<<(float)avg_wt/n<<endl;
    return 0;
}