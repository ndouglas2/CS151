/*homework1 project 2.cpp
* Author: Nate Douglas
* Module: 1
* Project: Homework 1
* Problem Statement: 
*
* Algorithm/Plan:
* 1. Create separate files for the header and initialization of the Country class
* 2. Create methods for constructing the country objects, as well as getting their values
* 3. In Main, initialize the objects for each country in alphabetical order, and add them to the vector
* 4. Sort the vector in ascending order of area
* 5. Format the output into a proper report

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Country.h"
using namespace std;

vector<Country> countries;


int main()
{
    //All Country objects in alphabetical order, and inserts them into the vector
    Country argentina("Argentina", 45258, 1073234);
    countries.insert(countries.begin(), argentina);

    Country bolivia("Bolivia", 11696, 424052);
    countries.insert(countries.begin(), bolivia);

    Country brazil("Brazil", 212845, 3287086);
    countries.insert(countries.begin(), brazil);

    Country chile("Chile", 19206, 291855);
    countries.insert(countries.begin(), chile);

    Country columbia("Columbia", 51115, 440715);
    countries.insert(countries.begin(), columbia);

    Country ecuador("Ecuador", 17705, 106851);
    countries.insert(countries.begin(), ecuador);

    Country falklands("Falkland Islands", 3, 4700);
    countries.insert(countries.begin(), falklands);

    Country frenchGuiana("French Guiana", 290, 32253);
    countries.insert(countries.begin(), frenchGuiana);

    Country guyana("Guyana", 787, 82978);
    countries.insert(countries.begin(), guyana);

    Country paraguay("Paraguay", 7145, 157056);
    countries.insert(countries.begin(), paraguay);

    Country peru("Peru", 33108, 496093);
    countries.insert(countries.begin(), peru);

    Country suriname("Suriname", 586, 63252);
    countries.insert(countries.begin(), suriname);

    Country uruguay("Uruguay", 3475, 68037);
    countries.insert(countries.begin(), uruguay);

    Country venezuela("Venezuela", 28102, 353748);
    countries.insert(countries.begin(), venezuela);

    //As with the first excersise I had trouble figuring out how to dynamically sort the vector, so this is a method I found using lambda expressions
    sort(countries.begin(), countries.end(), [](const Country& lhs, const Country& rhs) {
        return lhs.area < rhs.area;
        });

    int popTotal = 0;
    int areaTotal = 0;

    //Formatted Output
    cout << "\n" << "\n";
    cout << setw(10)<< "Country " <<setw(17) << right << " Population " << setw(9) << right << " Area "<<"\n";
    cout << setfill('-') << setw(36) << "-" << endl;
    cout << setfill(' ');
    for (auto it = countries.begin(); it != countries.end(); it++) {
        cout <<setw(17)<<left<<it->countryName << " "<<setw(8)<<right<< it->pop << " " << setw(8) << right << it->area << "\n";
        popTotal += it->pop;
        areaTotal += it->area;
    }
    cout << setfill('-') << setw(36) << "-" << endl;
    cout << setfill(' ');
    cout << "Total: " <<setw(19)<<right<< areaTotal << " " <<setw(8)<<right<< popTotal;
    cout << "\n" << "\n";

}

