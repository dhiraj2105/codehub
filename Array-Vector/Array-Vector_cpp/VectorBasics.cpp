#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Creating a vector to hold integer elements
    vector<int> vec;

    // Adding elements to the vector
    vec.push_back(10); // Adds 10 to the vector
    vec.push_back(20); // Adds 20 to the vector
    vec.push_back(30); // Adds 30 to the vector

    // Displaying the vector
    cout << "Initial Vector: ";
    for (int num : vec)
    {
        cout << num << " "; // Prints each element in the vector
    }
    cout << endl;

    // Accessing elements from the vector
    int firstElement = vec.at(0); // Gets the first element (index 0)
    cout << "First Element: " << firstElement << endl;

    // Modifying an element in the vector
    vec.at(1) = 25; // Changes the element at index 1 to 25
    cout << "Vector after modification: ";
    for (int num : vec)
    {
        cout << num << " "; // Prints each element in the vector
    }
    cout << endl;

    // Removing an element from the vector
    vec.erase(vec.begin() + 2); // Removes the element at index 2
    cout << "Vector after removal: ";
    for (int num : vec)
    {
        cout << num << " "; // Prints each element in the vector
    }
    cout << endl;

    // Checking the size of the vector
    int size = vec.size(); // Gets the current size of the vector
    cout << "Size of Vector: " << size << endl;

    // Iterating over the elements of the vector
    cout << "Iterating over Vector:" << endl;
    for (int num : vec)
    {
        cout << num << endl; // Prints each element in the vector
    }

    // Clearing all elements from the vector
    vec.clear(); // Removes all elements from the vector
    cout << "Vector after clearing: " << vec.size() << " elements left." << endl;

    return 0; // Return statement indicating successful execution
}