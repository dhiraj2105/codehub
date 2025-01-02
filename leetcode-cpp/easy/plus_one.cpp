#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{

    int n = digits.size();

    // reverse loop
    for (int i = n - 1; i >= 0; i--)
    {
        // when digit is less then 9 , increment by 1
        if (digits[i] < 9)
        {
            digits[i]++;
            return digits;
        }
        // when digit is 9 then update it to 0
        else
        {
            digits[i] = 0;
        }
    }
    // this will only work when upper loop exits without returning which means array have 9 only and then we will put 1 in begining of array
    // so suppsoe array is 9 , then
    // digits[1] = 9 => 0 , because of the else{} part
    // digits[0] = 1 => 2
    digits.insert(digits.begin(), 1);

    return digits;
}

int main()
{
    /*
        You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

        Increment the large integer by one and return the resulting array of digits.
    */
    // vector<int> digits = {1, 2, 3};
    vector<int> digits = {1, 9};
    vector<int> result = plusOne(digits);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}