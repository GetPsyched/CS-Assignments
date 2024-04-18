#include <iostream>
#include <vector>

using namespace std;

struct Block {
	int size;
	bool hole;
	int allocated;

	int fragmented() {
		return size - allocated;
	}
};

int findFirstFit(vector<Block> &blocks, int size) {
	int n = blocks.size();
	int found = -1;
	for(int i = 0; i < n; ++i)
		if(blocks[i].hole && blocks[i].size >= size) {
			found = i;
			break;
		}

	return found;
}

int findBestFit(vector<Block>& blocks, int size) {
	int n = blocks.size();
	int minFound = -1, minFoundIdx = -1;
	for(int i = 0; i < n; ++i)
		if(blocks[i].hole && blocks[i].size >= size)
			if(minFound == -1 || blocks[i].size < minFound) {
				minFound = blocks[i].size;
				minFoundIdx = i;
			}

	return minFoundIdx;
}

int findWorstFit(vector<Block>& blocks, int size) {
	int n = blocks.size();
	int maxFound = -1, maxFoundIdx = -1;

	for(int i = 0; i < n; ++i)
		if(blocks[i].hole && blocks[i].size >= size)
			if(maxFound == -1 || blocks[i].size > maxFound) {
				maxFound = blocks[i].size;
				maxFoundIdx = i;
			}

	return maxFoundIdx;
}

void handleAllocation(vector<Block>& blocks, int idx, int size) {
	if(idx == -1) {
		cout << "Failed to allocated memory\n";
		return;
	}

	blocks[idx].allocated = size;
	blocks[idx].hole = false;

	cout << "Memory allocated to block: " << idx << " with external fragmentation of: " << blocks[idx].fragmented() << "\n";
}

void printMemoryLayout(vector<Block> blocks) {
	for(int i = 0; i < blocks.size(); ++i)
		cout << "| Allocated: " << blocks[i].allocated << ", Fragment: " << blocks[i].fragmented() << " ";
	cout << "|\n";
}

void calculateCompaction(vector<Block> blocks) {
	int used = 0;
	int free = 0;

	for(int i = 0; i < blocks.size(); ++i)
		if(blocks[i].hole) {
			free += blocks[i].size;
		} else {
			used += blocks[i].size - blocks[i].fragmented();
			free += blocks[i].fragmented();
		}

	cout << "-----------------------------------------\n";
	cout << "-------- Used = " << used << " ----------------------\n";
	cout << "-----------------------------------------\n";
	cout << "-------- Free = " << free << " ---------------------\n";
	cout << "-----------------------------------------\n";
}

/*
6
10 1
20 0
30 1
40 1
50 0
60 1
3
0 8
1 30
2 20
*/

int
main() {
	int nBlocks;
	cout << "Enter number of blocks: ";
	cin >> nBlocks;

	vector<Block> blocks(nBlocks);

	for(int i = 0; i < nBlocks; ++i) {
		Block block;

		cout << "Enter size of block " << i << ": ";
		cin >> block.size;

		cout << "Is this block a hole?: (1/0): ";
		cin >> block.hole;

		block.allocated = 0;

		blocks[i] = block;
	}

	cout << "Memory layout before allocation: \n";
	printMemoryLayout(blocks);

	int nAllocs;
	cout << "Enter number of allocations: ";
	cin >> nAllocs;

	for(int i = 0; i < nAllocs; ++i) {
		cout << "0. First fit\n";
		cout << "1. Best fit\n";
		cout << "2. Worst fit\n";

		cout << "Enter type of allocation: ";
		int type;
		cin >> type;

		cout << "Enter allocation size: ";
		int size;
		cin >> size;

		switch(type) {
			case 0:
				handleAllocation(blocks, findFirstFit(blocks, size), size);
				break;
			case 1:
				handleAllocation(blocks, findBestFit(blocks, size), size);
				break;
			case 2:
				handleAllocation(blocks, findWorstFit(blocks, size), size);
				break;
		}
	}

	cout << "\nMemory layout after allocation: \n\n";
	printMemoryLayout(blocks);

	cout << "\nMemory layout after compaction: \n\n";
	calculateCompaction(blocks);

	return 0;
}
