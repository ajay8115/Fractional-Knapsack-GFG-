#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define kk '\n'
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool comp(Item a, Item b)
    {
        double r1 =  (double)a.value / (double)a.weight;
        double r2 =  (double)b.value / (double)b.weight;

        return (r1 < r2);
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int w, Item a[], int n)
    {
        sort(a, a + n, comp);
        double cost = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i].weight <= w)
            {
                cost += (a[i].value);
                w -= a[i].weight;
            }
            else
            {
                cost += ((double)(a[i].value) / (double)a[i].weight) * (double)w;
                break;
            }
        }

        return cost;
    }
};
 