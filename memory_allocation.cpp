#include<bits/stdc++.h>
using namespace std;
void firstFit(int blk,vector<int>memory,int pr,vector<int>process){
    vector<int> allocation(blk, -1);
    vector<bool>b(blk,false);
    int IF=0,EF= accumulate(memory.begin(), memory.end(),0);
    //cout<<EF<<endl;
    for(int i=0;i<pr;i++){
        for(int j=0;j<blk;j++){
            if(memory[j]>=process[i] and b[j]==false){
                allocation[i]=j;
                b[j]=true;
                IF+=memory[j]-process[i];
                EF-=memory[j];
                memory[j]-=process[i];
                break; } } }
    cout<<"\nFirst fit:"<<endl;
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)  cout << allocation[i] + 1 << endl;
        else cout << "Not Allocated" << endl;
    }
      cout << "Total Internal Fragmentation: " << IF << endl;
     cout << "Total External Fragmentation: " << EF << endl;
}

void bestFit(int blk, vector<int> memory, int pr, vector<int> process) {
    vector<int> allocation(pr, -1);
    vector<bool> b(blk, false);
    int IF = 0, EF = accumulate(memory.begin(), memory.end(), 0);
    for (int i = 0; i < pr; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blk; j++) {
            if (memory[j] >= process[i] and !b[j]) {
                if (bestIdx == -1 || memory[j] < memory[bestIdx])  bestIdx = j; }
        }
        if (bestIdx != -1 && !b[bestIdx]) {
            allocation[i] = bestIdx;
            IF += memory[bestIdx] - process[i];
            EF -= memory[bestIdx];
            memory[bestIdx] -= process[i];
            b[bestIdx] = true;}}
    cout << "\nBest fit:\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1) cout << allocation[i] + 1 << endl;
        else  cout << "Not Allocated" << endl;
    }
    cout << "Total Internal Fragmentation: " << IF << endl;
    cout << "Total External Fragmentation: " << EF << endl;
}

void worstFit(int blk, vector<int> memory, int pr, vector<int> process) {
    vector<int> allocation(pr, -1);
    vector<bool> b(blk, false);
    int IF = 0, EF = accumulate(memory.begin(), memory.end(), 0);
    for (int i = 0; i < pr; i++) {
        int worstIdx = -1;
        for (int j = 0; j < blk; j++) {
            if (memory[j] >= process[i] and !b[j]) {
                if (worstIdx == -1 || memory[j] > memory[worstIdx])  worstIdx = j;}
        }
        if (worstIdx != -1 && !b[worstIdx]) {
            allocation[i] = worstIdx;
            IF += memory[worstIdx] - process[i];
            EF -= memory[worstIdx];
            memory[worstIdx] -= process[i];
            b[worstIdx] = true;}
    }
    cout << "\nWorst fit:\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1) cout << allocation[i] + 1 << endl;
        else   cout << "Not Allocated" << endl;}
    cout << "Total Internal Fragmentation: " << IF << endl;
    cout << "Total External Fragmentation: " << EF << endl;
}

void nextFit(int blk,vector<int>memory,int pr,vector<int>process){
    vector<int> allocation(pr, -1);
    vector<bool> b(blk, false);
    int IF = 0, EF = accumulate(memory.begin(), memory.end(), 0),lastIndex = 0;
    for (int i = 0; i < pr; i++) {
    int j = lastIndex, count = 0;
    while (count < blk) {
        if (memory[j] >= process[i] && !b[j]) {
            allocation[i] = j;
            b[j] = true;
            IF += memory[j] - process[i];
            EF -= memory[j];
            memory[j] -= process[i];
            lastIndex = (j + 1) % blk;
            break;}
        j = (j + 1) % blk;
        count++;}
    }
    cout << "\nNext fit:\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)  cout << allocation[i] + 1 << endl;
        else  cout << "Not Allocated" << endl; }
    cout << "Total Internal Fragmentation: " << IF << endl;
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
    bestFit(blocks,memory,process,processes);
    worstFit(blocks,memory,process,processes);
    nextFit(blocks,memory,process,processes);
    return 0;

}
