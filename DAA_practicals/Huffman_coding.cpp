#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Tree node for Huffman encoding
struct TreeNode {
    char data;
    int frequency;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data, int frequency)
        : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(TreeNode* a, TreeNode* b)
    {
        return a->frequency > b->frequency;
    }
};

// Generate the Huffman tree
TreeNode* buildHuffmanTree(const string& text)
{
    // Calculate frequency of each character in the input text
    unordered_map<char, int> frequencyMap;
    for (char ch : text) {
        frequencyMap[ch]++;
    }

    // Create a priority queue to store the tree nodes
    priority_queue<TreeNode*, vector<TreeNode*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : frequencyMap) {
        pq.push(new TreeNode(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        TreeNode* left = pq.top();
        pq.pop();
        TreeNode* right = pq.top();
        pq.pop();

        // Create a new internal node with the combined frequency
        TreeNode* newNode = new TreeNode('$', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    // Return the root of the Huffman tree
    return pq.top();
}

// Generate the Huffman codes for each character
void generateHuffmanCodes(TreeNode* root, string code, unordered_map<char, string>& huffmanCodes)
{
    if (root == nullptr) {
        return;
    }

    // Leaf node contains a character
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCodes[root->data] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Encode the input string using Huffman codes
string encodeString(const string& text, unordered_map<char, string>& huffmanCodes)
{
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCodes[ch];
    }
    return encodedString;
}

int main()
{
    string inputText = "Huffman encoding algorithm";

    // Build the Huffman tree
    TreeNode* root = buildHuffmanTree(inputText);

    // Generate Huffman codes for each character
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    // Encode the input string
    string encodedString = encodeString(inputText, huffmanCodes);

    // Output the encoded string
    cout << "Encoded string: " << encodedString << endl;

    return 0;
}
