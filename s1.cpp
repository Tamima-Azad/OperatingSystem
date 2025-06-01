#include<bits/stdc++.h>
using namespace std;
class cpu{
    public:
    int p,at,bt,ct,tat,wt;
    bool ok=false;
};
int main(){
    int n;cin>>n;
    vector<cpu>a(n);
    for(int i=0;i<n;i++){
        a[i].p=i+1;
        cin>>a[i].at>>a[i].bt;
    }
    sort(a.begin(),a.end(),[](const cpu &a,const cpu &b){
        return a.at<b.at;
    });
    int cnt=0,avg_tat=0,avg_wt=0;
    set<int>b;
    while(b.size()<n){
        for(int i=0;i<n;i++){
            int mini=a[i].bt;
            int ind=i;
            if(a[i].ok){
                continue;
            }
            for(int j=0;j<n;j++){
                if(a[j].at<=cnt and a[j].bt<mini and !a[j].ok){
                    mini=a[j].bt;
                    ind=j;
                }
            }
            cnt+=a[ind].bt;
            a[ind].ct=cnt;
            a[ind].tat = a[ind].ct - a[ind].at;
            avg_tat+=a[ind].tat;
            a[ind].wt = a[ind].tat - a[ind].bt;
            avg_wt+=a[ind].wt;
            a[ind].ok=true;
            b.insert(ind);

        }
    }
    sort(a.begin(),a.end(),[](const cpu &a,const cpu &b){
        return a.p<b.p;
    });
    for (int i = 0; i < n; ++i)
    {
        cout << "p" << a[i].p<< ' ' << a[i].at << ' ' << a[i].bt << ' ' << a[i].ct << ' ' << a[i].tat << ' ' << a[i].wt << endl;
    }
    cout <<"avg_tat = "<< (float)avg_tat << '\n' <<"avg_wt = "<< (float)avg_wt/ n << endl;

    return 0;
}
    
