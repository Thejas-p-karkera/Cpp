#include <iostream>
#include <vector>
using namespace std;

class Heap 
{
    vector<int> heap;

    void heapifyUp(int index) {
        if (index == 0) return; // Root node
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            swap(heap[parent], heap[index]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty!" << endl;
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    void printHeap() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    Heap heap;

    int keys[] = { 10, 20, 30, 40, 50, 25 };

    for (int key : keys) {
        heap.insert(key);
    }

    cout << "Heap after insertion: ";
    heap.printHeap();

    heap.deleteMax();
    cout << "Heap after deleting max: ";
    heap.printHeap();

    return 0;
}
