#include <iostream>

using namespace std;

struct MemoryBlock {
    int id;
    int size;
    bool allocated;
};

class MemoryManager {
private:
    MemoryBlock memory;
    int processId;

public:
    MemoryManager(int totalSize) {
        memory.id = 1;
        memory.size = totalSize;
        memory.allocated = false;
        processId = 1;
    }

    void allocateFirstFit(int processSize) {
        if (!memory.allocated && memory.size >= processSize) {
            memory.allocated = true;
            cout << "Process " << processId << " allocated with size " << processSize << " using First Fit" << endl;
            if (memory.size > processSize) {
                MemoryBlock newBlock;
                newBlock.id = processId + 1;
                newBlock.size = memory.size - processSize;
                newBlock.allocated = false;
                memory = newBlock;
            }
            processId++;
        } else {
            cout << "No suitable block found for process with size " << processSize << endl;
        }
    }

    void allocateBestFit(int processSize) {
        int bestFitIndex = -1;
        int bestFitSize = memory.size + 1;
        if (!memory.allocated && memory.size >= processSize) {
            bestFitSize = memory.size - processSize;
            bestFitIndex = 0;
        }

        if (bestFitIndex != -1) {
            memory.allocated = true;
            cout << "Process " << processId << " allocated with size " << processSize << " using Best Fit" << endl;
            if (memory.size > processSize) {
                MemoryBlock newBlock;
                newBlock.id = processId + 1;
                newBlock.size = memory.size - processSize;
                newBlock.allocated = false;
                memory = newBlock;
            }
            processId++;
        } else {
            cout << "No suitable block found for process with size " << processSize << endl;
        }
    }

    void allocateWorstFit(int processSize) {
        int worstFitIndex = -1;
        int worstFitSize = -1;
        if (!memory.allocated && memory.size >= processSize) {
            worstFitSize = memory.size - processSize;
            worstFitIndex = 0;
        }

        if (worstFitIndex != -1) {
            memory.allocated = true;
            cout << "Process " << processId << " allocated with size " << processSize << " using Worst Fit" << endl;
            if (memory.size > processSize) {
                MemoryBlock newBlock;
                newBlock.id = processId + 1;
                newBlock.size = memory.size - processSize;
                newBlock.allocated = false;
                memory = newBlock;
            }
            processId++;
        } else {
            cout << "No suitable block found for process with size " << processSize << endl;
        }
    }

    void printMemory() {
        cout << "Memory Status:" << endl;
        cout << "Block " << memory.id << " - Size: " << memory.size << " - Allocated: " << (memory.allocated ? "Yes" : "No") << endl;
    }
};

int main() {
    int totalMemorySize;
    cout << "Enter the total memory size: ";
    cin >> totalMemorySize;
    MemoryManager manager(totalMemorySize);

    int choice;
    do {
        cout << "\nMemory Allocation Strategies:" << endl;
        cout << "1. First Fit Allocation" << endl;
        cout << "2. Best Fit Allocation" << endl;
        cout << "3. Worst Fit Allocation" << endl;
        cout << "4. Print Memory Status" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int processSize;
        switch (choice) {
            case 1:
                cout << "Enter process size: ";
                cin >> processSize;
                manager.allocateFirstFit(processSize);
                break;
            case 2:
                cout << "Enter process size: ";
                cin >> processSize;
                manager.allocateBestFit(processSize);
                break;
            case 3:
                cout << "Enter process size: ";
                cin >> processSize;
                manager.allocateWorstFit(processSize);
                break;
            case 4:
                manager.printMemory();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

