#include<bits/stdc++.h>
using namespace std;
void firstFit(int blk,vector<int>memory,int pr,vector<int>process){

    vector<int> allocation(blk, -1);
    vector<bool>b(blk,false);
    int IF=0;
    int EF= accumulate(memory.begin(), memory.end(), 0);
    for(int i=0;i<pr;i++){
        for(int j=0;j<blk;j++){
            if(memory[j]>=process[i] and b[j]==false){
                allocation[i]=j;
                b[j]=true;
                IF+=memory[j]-process[i];
                EF-=memory[j];
                memory[j]-=process[i];
                break;
            }
        }
    }
    cout<<"First fit:"<<endl;
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated" << endl;
    }
      cout << "\nTotal Internal Fragmentation: " << IF << endl;
 
     cout << "Total External Fragmentation: " << EF << endl;
 

}
int main(){
    cout<<"Enter number of memory blocks: ";
    int blocks; cin>>blocks;;
    vector<int> memory(blocks, -1);
    for(int i=0;i<blocks;i++){
        cout<<"Block "<<i+1<<": ";
        cin>>memory[i];
    }
    cout<<"Enter No of process: ";
    int process; cin>>process;
    vector<int> processes(process, -1);
    for(int i=0;i<process;i++){
        cout<<"Process "<<i+1<<": ";
       cin>> processes[i];
    }
    firstFit(blocks,memory,process,processes);

}
