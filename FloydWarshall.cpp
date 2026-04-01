#include <iostream>
using namespace std;

#define INF 99999  // Represents no connection

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int dist[n][n];

    cout << "Enter adjacency matrix (use 99999 for INF):\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd-Warshall Algorithm
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print shortest distance matrix
    cout << "\nShortest distances between every pair of vertices:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}