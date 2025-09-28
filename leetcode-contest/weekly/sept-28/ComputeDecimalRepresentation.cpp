#include<bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> decimalRepresentation(int n) {

    vector<int> components;
           int place = 0;  // Represents the current digit's place (units, tens, etc.)

           // Loop until n becomes 0
           while (n > 0) {
               int digit = n % 10;  // Extracting the last digit

               if (digit != 0) {
                   // Multiply digit by 10^place to get the base-10 component
                   int component = digit * pow(10, place);
                   components.push_back(component);  // Add to result
               }

               n /= 10;      // Move to next digit
               place++;      // Move to next place (tens, hundreds, etc.)
           }

           sort(components.rbegin(), components.rend());

           return components;
}

   int main(){
       int n =537;
       decimalRepresentation(n);
   }
