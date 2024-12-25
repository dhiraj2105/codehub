#include <iostream>
using namespace std;

int main()
{
    // ===========================
    // 2D Array Example
    // ===========================

    // Declaration and Initialization of a 2D array
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};

    // Accessing elements in the 2D array
    cout << "2D Array Elements:" << endl;
    cout << "Element at (0, 1): " << arr2D[0][1] << endl; // Accessing element in 1st row, 2nd column
    cout << "Element at (1, 2): " << arr2D[1][2] << endl; // Accessing element in 2nd row, 3rd column

    // Traversing the 2D array using nested loops
    cout << "Traversing 2D Array:" << endl;
    for (int i = 0; i < 2; i++)
    { // Loop through rows
        for (int j = 0; j < 3; j++)
        {                               // Loop through columns
            cout << arr2D[i][j] << " "; // Print each element
        }
    }
    cout << endl;
    // ===========================
    // 3D Array Example
    // ===========================

    // Declaration and Initialization of a 3D array
    int arr3D[2][2][3] = {
        {{1, 2, 3}, {4, 5, 6}},
        {{7, 8, 9}, {10, 11, 12}}};

    // Accessing elements in the 3D array
    cout << "3D Array Elements:" << endl;
    cout << "Element at (0, 1, 2): " << arr3D[0][1][2] << endl; // Accessing element in 1st block, 2nd row, 3rd column
    cout << "Element at (1, 0, 1): " << arr3D[1][0][1] << endl; // Accessing element in 2nd block, 1st row, 2nd column

    // Traversing the 3D array using nested loops
    cout << "Traversing 3D Array:" << endl;
    for (int i = 0; i < 2; i++)
    { // Loop through blocks
        for (int j = 0; j < 2; j++)
        { // Loop through rows
            for (int k = 0; k < 3; k++)
            {                                  // Loop through columns
                cout << arr3D[i][j][k] << " "; // Print each element
            }
            cout << endl; // New line after each row
        }
        cout << "-----" << endl; // Separator between blocks
    }

    return 0; // End of the program
}