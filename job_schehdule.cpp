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
        cout << "Enter profit and deadline: ";
        int a, b;
        cin >> a >> b;
        vect.push_back(make_pair(a, b));
    }
    sort(vect.begin(), vect.end(), greater<pair<int, int>>());
    int slots[10] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; vect[i].second - j >= 0; j++)
        {
            if (slots[vect[i].second - j] == 0)
            {
                slots[vect[i].second - j] = vect[i].first;
                break;
            }
        }
    }
    int profit = 0;
    for (int i = 0; i < 10; i++)
    {
        profit += slots[i];
    }
    cout << "profit= " << profit;
}
