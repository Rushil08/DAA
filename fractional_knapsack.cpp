#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> vect1, pair<int, int> vect2)
{
    int r1 = vect1.first / vect1.second;
    int r2 = vect2.first / vect2.second;
    if (r1 == r2)
    {
        return vect1.first > vect2.first;
    }
    else
    {
        return r1 > r2;
    }
}

int main()
{
    vector<pair<int, int>> vect;
    cout << "enter number of activities: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight: ";
        int a, b;
        cin >> a >> b;
        vect.push_back(make_pair(a, b));
    }
    cout << "Enter max weight of sack: ";
    double max, cur;
    cin >> max;
    cur = max;
    sort(vect.begin(), vect.end(), comp);
    double profit = 0;
    for (int i = 0; i < n; i++)
    {
        if (vect[i].second <= cur)
        {
            profit += vect[i].first;
            cur -= vect[i].second;
        }
        else
        {
            profit += vect[i].first * (cur / vect[i].second);
            break;
        }
    }
    cout << " profit: " << profit;
}