#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Product{
    string id;
    int sales;
};

// Returns true if a is ranked higher than b
bool better(const Product& a, const Product& b)
{
    if(a.sales != b.sales)
        return a.sales > b.sales;

    return a.id < b.id;
}

// Min-heap comparator (worst product stays on top)
struct Compare
{
    bool operator()(const Product& a, const Product& b) const
    {
        if(a.sales != b.sales)
            return a.sales > b.sales;

        return a.id < b.id;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Product> products;

    for(int i = 0; i < n; i++)
    {
        string id;
        int sales;

        cin >> id >> sales;

        Product p;
        p.id = id;
        p.sales = sales;

        products.push_back(p);
    }

    int k;
    cin >> k;

    priority_queue<Product, vector<Product>, Compare> minheap;

    for(auto p : products)
    {
        if(minheap.size() < k)
        {
            minheap.push(p);
        }
        else if(better(p, minheap.top()))
        {
            minheap.pop();
            minheap.push(p);
        }
    }

    vector<Product> final;

    while(!minheap.empty())
    {
        final.push_back(minheap.top());
        minheap.pop();
    }

    sort(final.begin(), final.end(), better);

    for(auto p : final)
    {
        cout << p.id << " " << p.sales << endl;
    }

    return 0;
}