#include<bits/stdc++.h>
using namespace std;
int main(){
    int p,r; cin>>p>>r;
    int allocation[p][r], max_need[p][r], available[r];
    cout<<"Enter Allocation Matrix:\n";
    for(int i=0; i<p; i++){
        cout<<"For Process P"<<i<<": ";
        for(int j=0; j<r; j++){
            cin>>allocation[i][j];
        }
    }
    cout<<"Enter Max Need Matrix:\n";
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            cin>>max_need[i][j];
        }
    }
    cout<<"Enter Available Resources: ";
    for(int i=0;i<r;i++){
        cin>>available[i];
    }
    int current_need[p][r];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
            current_need[i][j]=max_need[i][j]-allocation[i][j];
        }
    }

    vector<bool>finised(p,false);
    vector<int>seq;
    int cnt=0;
    while(cnt<p){
        bool found=false;
        for(int i=0;i<p;i++){
            if(!finised[i]){
                bool can_allocate=true;
                for(int j=0;j<r;j++){
                    if(current_need[i][j]>available[j]){
                        can_allocate=false;
                        break;
                    }
                }
                if(can_allocate){
                    for(int j=0;j<r;j++){
                        available[j]+=allocation[i][j];
                        cout<<available[j]<<" ";
                    }
                    finised[i]=true;
                    seq.push_back(i);
                    cnt++;
                    found=true;
                }
            }
        }
        if(!found){
            break;
        }
    }
    if(cnt==p){
        cout<<"Deadlock is not found\n";
        cout<<"Safe seq is: ";
        for(int i=0;i<seq.size();i++){
            cout<<"P"<<seq[i]<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<"Deadlock is found\n";
    }

}