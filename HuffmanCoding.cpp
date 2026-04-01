#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman codes
void printCodes(Node* root, string str) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        cout << root->ch << ": " << str << endl;
    }

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Huffman coding function
void HuffmanCoding(unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes for each character
    for (auto pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build Huffman Tree
    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* root = pq.top();
    printCodes(root, "");
}

int main() {
    string text;
    cout << "Enter the text: ";
    getline(cin, text);

    // Count frequency of each character
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    cout << "\nHuffman Codes for characters:\n";
    HuffmanCoding(freqMap);

    return 0;
}