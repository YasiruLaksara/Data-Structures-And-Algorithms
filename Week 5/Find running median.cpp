#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    vector<int> numbers; // creating  a vector to store the integers
    string input;
    cout << "Enter the set of integers as a comma-separated array: ";
    getline(cin, input);

    stringstream ss(input);
    string pivot;
    while (getline(ss, pivot, ',')) { // reading integers from the comma-separated input
        int x = stoi(pivot);
        numbers.push_back(x); // adding the integer to the vector

        // sorting  the vector array 
        sort(numbers.begin(), numbers.end());

        // Method to calculate the median
        int size = numbers.size();
        double median;
        if (size % 2 == 0) {
            median = double(numbers[size/2]+(numbers[size/2-1])) / 2;
        } else {
            median = double(numbers[size/2]);
        }
        cout <<"Sorted "<< "[ ";
        for (int i=0;i<size;i++){    //Displaying Sorted vector at each step
            cout<< numbers[i];

            if (i != size - 1) {
                cout << ", ";
            }
            
           
        }
        cout << " ]";
        cout<<endl;

        // output the  median with one decimal place at each step
        cout << fixed << setprecision(1) <<"Median = " << median << endl;
        cout<<endl;
    }

    return 0;
}

