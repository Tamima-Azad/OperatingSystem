#include <bits/stdc++.h>
using namespace std;

void bestFit(int blk, vector<int> memory, int pr, vector<int> process) {
    vector<int> allocation(pr, -1); // -1 means not allocated yet
    vector<int> remainingBlockSize = memory; // Copy of memory blocks to track remaining space
    vector<bool> blockAllocated(blk, false); // To mark allocated blocks

    for (int i = 0; i < pr; i++) {
        int bestIdx = -1;
        for (int j = 0; j < blk; j++) {
            if (remainingBlockSize[j] >= process[i]) {
                if (bestIdx == -1 || remainingBlockSize[j] < remainingBlockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            remainingBlockSize[bestIdx] -= process[i];
            blockAllocated[bestIdx] = true;
        }
    }

    cout << "Best fit:\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < pr; i++) {
        cout << i + 1 << "\t\t" << process[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated" << endl;
    }

    // Calculate Internal Fragmentation
    int internalFragmentation = 0;
    for (int j = 0; j < blk; j++) {
        if (blockAllocated[j]) {
            internalFragmentation += remainingBlockSize[j];
        }
    }
    cout << "\nTotal Internal Fragmentation: " << internalFragmentation << endl;

    // Calculate External Fragmentation
    int externalFragmentation = 0;
    for (int j = 0; j < blk; j++) {
        if (!blockAllocated[j]) {
            externalFragmentation += remainingBlockSize[j];
        }
    }
    cout << "Total External Fragmentation: " << externalFragmentation << endl;
}

int main() {
    cout << "Enter number of memory blocks: ";
    int blocks;
    cin >> blocks;
    vector<int> memory(blocks);

    for (int i = 0; i < blocks; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> memory[i];
    }

    cout << "Enter No of processes: ";
    int process;
    cin >> process;
    vector<int> processes(process);

    for (int i = 0; i < process; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> processes[i];
    }

    bestFit(blocks, memory, process, processes);
}
