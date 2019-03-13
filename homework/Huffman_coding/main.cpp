#include <iostream>
#include <exception>

// Huffman tree node
struct Node {
    char data;  // character
    int freq;   // frequency
    Node* left;
    Node* right;

    Node(char data = ' ', int freq = 0, Node* left = nullptr, Node* right = nullptr)
        : data(data), freq(freq), left(left), right(right) {}
};

template<typename T>
void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

// Minimum priority queue
class MinPQ {
private:
    int capacity;   // Queue capacity
    Node** heap;    // Min heap
    int size;       // Heap size

public:
    MinPQ(Node* a[], int N) {
        capacity = N;
        heap = new Node*[N];
        size = N;
        for (int i = 0; i < N; i++) {
            heap[i] = a[i];
        }
        // Build min heap
        for (int i = size / 2 - 1; i >= 0; i--) {
            sink(i);
        }
    }

    ~MinPQ() {
        if (heap != nullptr) {
            delete[] heap;
        }
    }

    void push(Node* elem) {
        if (size == capacity) {
            return;
        }
        heap[size] = elem;
        swim(size);
        size++;
    }

    Node* pop() {
        if (size == 0) {
            return nullptr;
        }
        Node* min = heap[0];
        heap[0] = heap[size - 1];
        size--;
        sink(0);
        return min;
    }

    Node* top() {
        if (size == 0) {
            return nullptr;
        }
        return heap[0];
    }

    int qSize() {
        return size;
    }

private:
    void swim(int k) {
        // Target: k
        // Parent: r = (k - 1) / 2
        while (k > 0) {
            int p = (k - 1) / 2;
            if (heap[k]->freq < heap[p]->freq) {
                swap(heap[k], heap[p]);
                k = p;
            }
            else {
                break;
            }
        }
    }

    void sink(int r) {
        // r: sub-tree root
        // Left child: 2 * r + 1
        // Right child: 2 * r + 2
        int last = size - 1;
        while (2 * r + 1 <= last) {
            int j = 2 * r + 1;
            if (j + 1 <= last && heap[j + 1]->freq < heap[j]->freq) {
                j++;
            }
            if (heap[j]->freq < heap[r]->freq) {
                swap(heap[j], heap[r]);
                r = j;
            }
            else {
                break;
            }
        }
    }

};

int HuffmanBits(Node* a[], int N) {
    MinPQ minPQ(a, N);
    int bits = 0;
    while (minPQ.qSize() > 1) {
        Node* h = new Node;
        h->left = minPQ.pop();
        h->right = minPQ.pop();
        h->freq = h->left->freq + h->right->freq;
        bits += h->freq;
        minPQ.push(h);
    }
    // return the root of the tree
    return bits;
}

int main() {
    int N;
    std::cin >> N;
    Node** a = new Node*[N];
    for (int i = 0; i < N; i++) {
        char data;
        int freq;
        std::cin >> data >> freq;
        Node* node = new Node(data, freq);
        a[i] = node;
    }
    std::cout << HuffmanBits(a, N) << std::endl;
}