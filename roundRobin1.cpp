#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

class cpu {
    public: 
    int P, AT, BT, CT, TAT, WT, RT, remainingBT;
};

int main() {
    cout<<"Enter no of process and Quantum time: \n";
    int n, qt; 
    cin >> n >> qt;
    vector<cpu>algo(n);
    bool check[n], arr[n];
    cout<<"Enter at & Bt: \n";
    for (int i = 0; i < n; i++) {
        algo[i].P = i + 1;
        cin >> algo[i].AT >> algo[i].BT;
        algo[i].remainingBT = algo[i].BT;
        check[i] = false;
        arr[i] = false;
    }

    queue<int> ready;
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.AT < b.AT;
    });

    ready.push(0);
    check[0] = true;
    int total = 0,avg_tat=0,avg_wt=0;
    vector<pair<int,int>>v;
    while (!ready.empty()) {
        int idx = ready.front();
        v.push_back({idx,total});
        ready.pop();

        if (algo[idx].remainingBT > qt) {
            total += qt;
            algo[idx].remainingBT -= qt;
            

            for (int i = 0; i < n; i++) {
                if (!check[i] and algo[i].AT <= total) {
                    ready.push(i); 
                    check[i] = true;
                }
            }
            ready.push(idx);
        } 
        else {
            total += algo[idx].remainingBT;
            algo[idx].remainingBT = 0;
            algo[idx].CT = total;
            algo[idx].TAT = algo[idx].CT - algo[idx].AT;
            algo[idx].WT = algo[idx].TAT - algo[idx].BT;
            avg_tat+=algo[idx].TAT;
            avg_wt+=algo[idx].WT;
            
            for (int i = 0; i < n; i++) {
                if (!check[i] and algo[i].AT <= total) {
                    ready.push(i);
                    check[i] = true;
                }
            }
        }
    }
    for(auto i: v){
        if(!arr[i.first]){
            algo[i.first].RT = i.second - algo[i.first].AT;
            arr[i.first] = true;
        }
    }
    sort(algo.begin(), algo.end(), [](const cpu &a, const cpu &b) {
        return a.P < b.P;
    });
    for (int i = 0; i < n; i++) {
        cout << "P" << algo[i].P << "\t" << algo[i].AT << "\t" << algo[i].BT << "\t" << algo[i].CT << "\t" << algo[i].TAT << "\t" << algo[i].WT << "\t" << algo[i].RT << endl;
    }
    cout<<"avg_TAT=  "<<(float)avg_tat/n<<endl;
    cout<<"avg_WT=  "<<(float)avg_wt/n<<endl;


    return 0;
}
