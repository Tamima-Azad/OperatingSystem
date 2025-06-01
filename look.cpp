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
        for(int i=0;i<n;i++){
            if(track[i]<h){
               // cout<<track[i]<<" ";
               sum+=abs(track[i]-h);
               h=track[i];
            }
        }
        // sum+=abs(0-h);
        // h=0;
        // cout<<endl;

        for(int i=0;i<n;i++){
            if(track[i]>h){
                //cout<<track[i]<<" ";
                sum+=abs(track[i]-h);
                h=track[i];
            }
        }
        cout<<"Toward lower,Head movement= "<<sum<<endl;
    }
    int idx=0;
    if(d==1){
        sort(track.begin(),track.end());
        for(int i=0;i<n;i++){
            if(track[i]>h){
                //cout<<track[i]<<" ";
                sum+=abs(track[i]-h);
                h=track[i];
                idx=i;
            }
        }
        cout<<h<<endl;
        // sum+=abs(199-track[n-1]);
        // h=199;
        // cout<<endl;
        //cout<<"The order of track to be traversed is: "<<h<<" ";
        for(int i=idx;i>=0;i--){
            if(track[i]<h){
                //cout<<track[i]<<" ";
                sum+=abs(track[i]-h);
                h=track[i];
            }
        }
        cout<<"Toward Higher,Head movement= "<<sum<<endl;
    }
    
    


    
    return 0;
}