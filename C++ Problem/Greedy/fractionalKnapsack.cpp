// This is a greedy solution to the Fractional Knapsack problem implemented in C++

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct item
{
    int item_no;
    int profit;
    int weight;
    float ratio;
};

bool compareByRatio(const item &a, const item &b)
{
    return a.ratio > b.ratio;
}

int main()
{
    vector<item> list;
    int bag_capacity, total_items;

    cout << "Enter capacity of bag: ";
    cin >> bag_capacity;

    cout << "Enter total number of items available: ";
    cin >> total_items;

    for (int i = 1; i <= total_items; i++)
    {
        int p, w;
        float r;

        cout << "Enter details of item " << i << ":\n";
        cout << "Enter profit: ";
        cin >> p;
        cout << "Enter weight: ";
        cin >> w;

        r = (p / (float)w);

        item temp = {i, p, w, r};
        list.push_back(temp);
    }

    sort(list.begin(), list.end(), compareByRatio);

    vector<float> knapsack(total_items + 1, (-1));

    for (int i = 1; i <= total_items && bag_capacity >= 0; i++)
    {
        item temp = list.at(i - 1);
        if (temp.weight <= bag_capacity)
        {
            knapsack.at(temp.item_no) = (1);
            bag_capacity -= temp.weight;
        }
        else if (temp.weight > bag_capacity)
        {
            knapsack.at(temp.item_no) = ((float)bag_capacity / temp.weight);
            bag_capacity = 0;
        }
    }

    cout << "\nThe solution vector is: ";
    for (int i = 1; i <= total_items; i++)
    {
        cout << "\nItem no: " << i << ", inclusion: " << knapsack.at(i);
    }

    float max_profit = 0;

    for (int i = 1; i <= total_items; i++)
    {
        if (knapsack.at(i) > 0)
        {
            for (int j = 1; j <= total_items; j++)
            {
                if (list.at(j - 1).item_no == i)
                    max_profit += knapsack.at(i) * list.at(j - 1).profit;
            }
        }
    }

    cout << "\n\nThe maximum profit is: " << max_profit << "\n";

    return 0;
}