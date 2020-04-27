//trainSorting2.cpp


#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include<stdio.h> 
#include<stdlib.h> 
#include <algorithm>  

using namespace std;

const int MAX = 2000;
//arrays for the longest increasing subsequence and longest decreasing
int increasingSub [MAX];
int decreasingSub[MAX];

//vector for the inputs
std::vector<int> carWeights;

int longestSubsequence(int n)  
{  
    //find longest increasing subsequence and longest decreasing subsequence for each index/car

    for(int i = n - 1; i >= 0; i--) {

        for (int j = i; j <= n - 1; j++) {
            if(carWeights[i] < carWeights[j]) { //increasing
                if(increasingSub[i] < (1 + increasingSub[j])) {
                    increasingSub[i] = 1 + increasingSub[j];
                }
            } else if (carWeights[i] > carWeights[j]) {
                if(decreasingSub[i] < 1 + decreasingSub[j]) {
                    decreasingSub[i] = 1 + decreasingSub[j];
                }
            }
            
        }

    }

    return 0;
} 


int main () {
    
    int size;
    int a;
    cin >> size;

    for (int i = 0; i < size; i++) {
        //initialize it to one because a subsequence of an index needs to have at least 
        //1 char
        increasingSub[i] = 1;
        decreasingSub[i] = 1;
    }

    if(size == 0) {
        cout<<0<<endl;
    } else {

        //store input into a array
        while(cin >> a) {
            carWeights.push_back(a);
            
            if(carWeights.size() >= size) {
                break;
            }
        }
        //finds longest increasing/decreasing subsequence for each car
        longestSubsequence(size);

        int output = 0;

        for (int i = 0; i < size; i++) {
            int maxDecreasing = 0;
            int maxIncreasing = 0;

            int current = carWeights[i];

            for(int j = i + 1; j < size; j++) {
                int next = carWeights[j];
                if(current < next) { //if it is increasing
                    if(increasingSub[j] > maxIncreasing) {
                        maxIncreasing = increasingSub[j];       
                    }
                } else if (current > next) { //if it is decreasing
                    if(decreasingSub[j] > maxDecreasing) {
                        maxDecreasing = decreasingSub[j];
                    }
                }
            }
            

            int x = maxDecreasing + maxIncreasing + 1;


            if(x > output) {
                output = x;
            }

        }

        cout<<output<<endl;

    }

    return 0;
}



 