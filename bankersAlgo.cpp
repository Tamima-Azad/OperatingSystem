#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    
    int process, resources; cin >> process >> resources;
    vector<int>allocation[process], maximum[process], current_res[process];
    for(int i = 0; i < process; i++){
        for(int j = 0; j < resources; j++){
            int x; cin >> x;
            allocation[i].push_back(x);
        }
    }
    for(int i = 0; i < process; i++){
        for(int j = 0; j < resources; j++){
            int x; cin >> x;
            maximum[i].push_back(x);
        }
    }
    vector<int> available, sequence;
    bool arr[process];
    
    for(int i = 0; i < resources; i++){
        int x; cin >> x;
        available.push_back(x);
        arr[i] = false;
    }
    for(int i = 0; i < process; i++){
        for(int j = 0; j < resources; j++){
            current_res[i].push_back(maximum[i][j] - allocation[i][j]);
        }
    }
    cout << "Current Resouces Need: \n";
    for(int i = 0; i < process; i++){
        for(int j = 0; j < resources; j++){
            cout << current_res[i][j] << " ";
        }
        cout << endl;
    }
    int cnt = 0;
    cout << "Available Resources: \n";
    for(int k = 0; k < process; k++){
        for(int i = 0; i < process; i++){
            int c = 0;
            for(int j = 0; j < resources and !arr[i]; j++){
                if(current_res[i][j] <= available[j]){
                    c++;
                }
            }
            if(c==resources){
                cnt++;
                arr[i] = true;
                sequence.push_back(i);
                for(int j = 0; j < resources; j++){
                    available[j] = available[j] + allocation[i][j];
                    cout << available[j] << " ";
                }
                cout << endl;
            }
        }
    }
    if(cnt==process){
        for(int j = 0; j < process; j++){
            if(j < process - 1)
            cout << "P" << sequence[j] << "->";
            else cout << "P" << sequence[j] << endl;
        }
    }
    else cout << "Deadlock" << endl;
    
return 0;
}