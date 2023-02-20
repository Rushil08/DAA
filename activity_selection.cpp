#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> vect;
    cout << "enter number of activities: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter start and finish time: ";
        int a, b;
        cin >> a >> b;
        vect.push_back(make_pair(b, a));
    }
    sort(vect.begin(), vect.end());
    int i = 0;
    cout << "(" << vect[i].second << "," << vect[i].first << ")"
         << " ";
    for (int j = 1; j < n; j++)
    {
        if (vect[j].second >= vect[i].first)
        {
            cout << "(" << vect[j].second << "," << vect[j].first << ")"
                 << " ";
            i = j;
        }
    }
}
