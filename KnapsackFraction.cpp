#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int value, weight;
};

// Comparator function to sort items by value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter value and weight of each item:\n";
    for(int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    // Sort items based on ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    for(int i = 0; i < n; i++) {
        if(capacity == 0)
            break;

        if(items[i].weight <= capacity) {
            // Take whole item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take fraction of item
            totalValue += items[i].value * ((double)capacity / items[i].weight);
            capacity = 0;
        }
    }

    cout << "Maximum value in knapsack = " << totalValue << endl;

    return 0;
}