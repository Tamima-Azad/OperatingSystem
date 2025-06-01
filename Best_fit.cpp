#include<bits/stdc++.h>
using namespace std;
void firstFit(int blk,vector<int>memory,int pr,vector<int>process){
    //sort(process.rbegin(),process.rend());
    vector<int> allocation(blk, -1);
    vector<bool>b(blk,false);
    for(int i=0;i<pr;i++){
        int bestidx=-1;
        for(int j=0;j<blk;j++){
            if(memory[j]>=process[i] and b[j]==false){
                allocation[i]=j;
                b[j]=true;
                memory[j]-=process[i];
                break;
                
            }
        }
    }
    cout<<"First fit:"<<endl;
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (b[i] != -1)
            cout << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated" << endl;
    }
    // Calculate Internal Fragmentation
     int IF = 0;
     for (int j = 0; j < blk; j++) {
         if (b[j]) {
            IF += memory[j];
         }
     }
     cout << "\nTotal Internal Fragmentation: " << IF << endl;
 
    // Calculate External Fragmentation
     int EF = 0;
     for (int j = 0; j < blk; j++) {
         if (!b[j]) {
            EF += memory[j];
         }
     }
 
     cout << "Total External Fragmentation: " << EF << endl;
 

}
int main(){
    cout<<"Enter number of memory blocks: ";
    int blocks; cin>>blocks;;
    vector<int> memory(blocks, -1);
    for(int i=0;i<blocks;i++){
        cout<<"Block "<<i+1<<": ";
        int block; cin>>block;
        //cout<<"Block "<<i+1<<":"<<block<<endl;
        memory[i] = block;
    }
    cout<<"Enter No of process: ";
    int process; cin>>process;
    vector<int> processes(process, -1);
    for(int i=0;i<process;i++){
        cout<<"Process "<<i+1<<": ";
        int proc; cin>>proc;
        //cout<<"Process "<<i+1<<":"<<proc<<endl;
        processes[i] = proc;
    }
    vector<int> allocation(process, -1);
    firstFit(blocks,memory,process,processes);

}
