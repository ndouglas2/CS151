/*Programming Chellenge 6- A program that can filter a file
* Author: Nate Douglas
* Module: 9
* Project: 1
* Problem Statement: Create a program that takes an input file, and filters it into an output file in proper sentance caps
* Algorithm:
* 1. Prompt the user for the name of the input file. If Q is detected, quit the program.
* 2. Prompt for the output file name.
* 3. Check to see if these file names are valid. If so, continue on.
* 4. Create a while loop that loops through each line, ending on a period.
* 5. If it is the first character of a line, capitalize it. 
* 6. Otherwise, lowercase it. 
* 7. Output all of these characters to the output file. Followed by a . because getline skips it, and endl for readability
* 8. Close both files. 
*
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
    string in_file_name;
    string out_file_name;
    ifstream input_stream;
    ofstream output_stream;

    //Logic to recieve input for file names and check to see if they are real
    while (true) {
        cout << "Please enter the name of the input file ('q' to quit): ";
        getline(cin, in_file_name);
        if ( in_file_name == "Q" || in_file_name == "q") { //quits if q is input
            return 0;
        }
        cout << "Please enter the name of the output file: ";
        getline(cin, out_file_name);

        input_stream.open(in_file_name, ios::in);
        output_stream.open(out_file_name, ios::out);
        if (input_stream && output_stream) { //breaks the loop if files are valid
            break;
        }
        cout << "Sorry, I can't find that file" << endl << endl;
        input_stream.clear();
        //output_stream.clear(); Necessary?
    }

    string line;

    while (getline(input_stream, line, '.')) { //Loops through the file, ending each line on a period
        for (int i = 0; i < line.length(); i++) {
            if (i == 0) {
                output_stream.put(toupper(line[0])); //Converts the first character input into a capital
            }
            else {
                output_stream.put(tolower(line[i])); //Lowercases all others
            }
        }
        output_stream << "."<<endl;
    }

    //Closes up shop
    input_stream.close();
    output_stream.close();
    return 0;
}

