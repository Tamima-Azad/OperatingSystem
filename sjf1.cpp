#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const char nl = '\n';
struct cpu
{
    int pid, at, bt, ct, tat, wt;
    bool ok = false;
};
bool cmp(cpu &a, cpu &b)
{
    return a.at < b.at;
}
bool cmp1(cpu &a, cpu &b)
{
    return a.pid < b.pid;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<cpu> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i].pid = i + 1;
        cin >> a[i].at >> a[i].bt;
    }
    sort(a.begin(), a.end(), cmp);
    int cnt = 0;
    int a1 = 0, a2 = 0;
    int c = 0;
    set<int> b;
    while (b.size() < n)
    {
        for (int i = 0; i < n; ++i)
        {
            int mini = a[i].bt;
            int ind = i;
            if (a[i].ok)
                continue;
            for (int j = 0; j < n; ++j)
            {
                if (a[j].at <= cnt and a[j].bt < mini and !a[j].ok)
                {
                    mini = a[j].bt;
                    ind = j;
                }
            }
            // cerr << ind << ' ';
            cnt += a[ind].bt;
            a[ind].ct = cnt;
            a[ind].tat = a[ind].ct - a[ind].at;
            a1 += a[ind].tat;
            a[ind].wt = a[ind].tat - a[ind].bt;
            a2 += a[ind].wt;
            a[ind].ok = true;
            b.insert(ind);
        }
    }
    sort(a.begin(), a.end(), cmp1);
    for (int i = 0; i < n; ++i)
    {
        cout << "p" << a[i].pid << ' ' << a[i].at << ' ' << a[i].bt << ' ' << a[i].ct << ' ' << a[i].tat << ' ' << a[i].wt << nl;
    }
    cout << (float)a1 / n << ' ' << (float)a2 / n << nl;

    return 0;
}