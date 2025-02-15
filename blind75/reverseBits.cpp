#include <bits/stdc++.h>
using namespace std;

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;         // Initialize the result to 0. This will store the reversed bits.
    for (int i = 0; i < 32; i++) // Loop through all 32 bits (assuming the input is a 32-bit integer).
    {
        // Shift result left by 1 (to make space for the next bit) and
        // OR it with the least significant bit of n (n & 1).
        result = (result << 1) | (n & 1);

        // Right shift n by 1 to process the next bit in the next iteration.
        n >>= 1;
    }

    // Return the reversed 32-bit result.
    return result;
}
int main()
{
    /*
    Reverse bits of a given 32 bits unsigned integer.

Note:

Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
    */
    uint32_t n = 100;
    cout << reverseBits(n) << endl;

    return 0;
}