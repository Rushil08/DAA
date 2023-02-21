// write code for huffman encoding using priority queue

#include <iostream>
#include <queue>
#include <string>
#include <map>

using namespace std;

struct node
{
    char ch;
    int freq;
    node *left;
    node *right;
    node(char c, int f)
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct compare
{
    bool operator()(node *l, node *r)
    {
        return (l->freq > r->freq);
    }
};

void print(node *root, string str)
{
    if (!root)
        return;
    if (root->ch != '$')
        cout << root->ch << ": " << str << endl;
    print(root->left, str + "0");
    print(root->right, str + "1");
}

void huffman(string s)
{
    priority_queue<node *, vector<node *>, compare> pq;
    map<char, int> freq;
    for (int i = 0; i < s.length(); i++)
        freq[s[i]]++;
    for (auto i : freq)
        pq.push(new node(i.first, i.second));
    while (pq.size() != 1)
    {
        node *left = pq.top();
        pq.pop();
        node *right = pq.top();
        pq.pop();
        node *top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }
    print(pq.top(), "");
}

int main()
{
    string s;
    cin >> s;
    huffman(s);
    return 0;
}
