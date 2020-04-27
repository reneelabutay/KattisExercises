//tempRooms.cpp


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

struct Interval {
	int start;
	int end;
	int tempRange;
};


bool sortData(const Interval &i1, const Interval &i2) {
	if(i1.end < i2.end) return true;
	if(i1.end > i2.end) return false;

	if(i1.tempRange > i2.tempRange) return true;
	if(i1.tempRange < i2.tempRange) return false;

	return false;
}

int main() {

	vector<Interval> tempRooms;

	int numRooms;

	long long a, b;
	int size;
	cin >> size;
	
	if(size == 0) {

		numRooms = 0;
		cout<<numRooms<<endl;

	} else {

		numRooms = 1;

		while (cin >> a >> b) {

			Interval p;
			p.start = a;
			p.end = b;
			p.tempRange =  b - a;

			tempRooms.push_back(p);

			if(tempRooms.size() >= size) {
				break;
			}

		}

		sort(tempRooms.begin(), tempRooms.end(), sortData);


		int threshold = tempRooms[0].end;
		for(int i = 1; i < tempRooms.size(); i++) {			

			if(tempRooms[i].start > threshold) {
				numRooms++;
				threshold = tempRooms[i].end;
			}

		}

		cout<<numRooms<<endl;
	}



	return 0;
};