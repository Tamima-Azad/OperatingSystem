#include<bits/stdc++.h>
using namespace std;
int main(){
    // cout<<"Enter total traks in the disk: ";
    // int t; cin>>t;
    cout<<"Eneter total request track order: ";
    int n; cin>>n;
    vector<int> track(n, -1);
    cout<<"Enter the track order: ";
    for(int i=0;i<n;i++){
        cin>>track[i];
    }
    cout<<"Enter the initial head position: ";
    int h;cin>>h;
    cout<<"to toward lower value enter 1\n to toward higher value enter 2: ";
    int d; cin>>d;
    int sum=0;
    if(d==1){
        sort(track.begin(),track.end(),greater<int>());
        int x=0;
        for(int i=0;i<n;i++){
            if(track[i]>h){
                x=track[i];
                
            }
        }
        sum+=h+199;
        cout<<endl;
        sum+=abs(199-x);
        cout<<sum<<endl;
    }
    if(d==2){
        int x=0;
        sort(track.begin(),track.end());
        for(int i=0;i<n;i++){
            if(track[i]<h){
                x=track[i];    
            }
        }
        sum=abs(h-199)+199+x;

        cout<<sum<<endl;
    }
    


    
    return 0;
}