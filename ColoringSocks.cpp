//coloringsocks.cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int numSocks;
	int capacity;
	int maxColorDiff;

	cin >> numSocks >> capacity >> maxColorDiff;

	vector<int> socksColors (numSocks);

	for(int i = 0; i < numSocks; i++) {
		cin >> socksColors[i];
	}

	sort(socksColors.begin(), socksColors.end());

	int socksInMachine = 1;
	int lowestColor = socksColors[0];
	int numMachines = 1;

	for(int i = 1; i < numSocks; i++) {
		if(socksInMachine >= capacity || socksColors[i] - lowestColor > maxColorDiff) {
			numMachines++;
			lowestColor = socksColors[i];
			socksInMachine = 1;
		} else {
			socksInMachine++;
		}

	}

	cout << numMachines << endl;



	return 0;
}