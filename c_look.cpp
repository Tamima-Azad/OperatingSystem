#include<bits/stdc++.h>
using namespace std;
int main(){
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
        sum+=h-track[n-1]+track[0]-track[n-1]+track[0]-x;
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
        sum=abs(h-track[n-1])+track[n-1]-track[0]+x-track[0];

        cout<<sum<<endl;
    } 
    return 0;
}