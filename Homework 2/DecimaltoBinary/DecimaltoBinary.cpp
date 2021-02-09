/*DecimaltoBinary.cpp
* Author: Nate Douglas
* Module: 2
* Project: Project 1
* Problem Statement:Create a function that converts a decimal number to binary
*
* Algorithm/Plan:
* 1. initialize necessary variables of originalNum, remainder and binary
* 2. Create a do while loop where the condition is remainder / 2 != 0
* 3. Divide the originalNum by 2 and take its modulo, adding the modulo result to binary
* 4. Store originalNum / 2 in remainder, then use that going forward.
* 5. Continue through the loop until the condition is met.
* 6. Print the binary output.

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int originalNum = 0;
    int remainder = 0;
    string binary = "";

    cout << "Welcome to my binary converter. Please enter a whole number and press Enter. -1 will exit the program."<<"\n";

    do {

        binary = "";
        cout << "Please enter your number: " << "\n";
        cin >> originalNum;
        
        remainder = originalNum / 2;
        binary += to_string(originalNum % 2);

        do {
            //Inserts the string at the BEGINNING of binary, otherwise the string would be reversed in the end.
            binary.insert(0, to_string(remainder % 2));
            remainder = remainder / 2;
        } while (remainder != 0);

        cout << originalNum << " in binary is: " << binary << "\n" << "\n";

    } while (originalNum != -1);
    

}

