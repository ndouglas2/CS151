

#include <iostream>
using namespace std;

void first(int** ptr_to_ptr) {
    int a = 5;
    *ptr_to_ptr = &a;
}

void second(int** dummy) {
    int b = 99;
}
int* third() {
    int x = 29;
    return &x;
}

//void fourth() {
//    int y;
//    cout << "In fourth(), the value of y is " << y << endl << endl;
//}


int main()
{
    int* int_ptr, * never_used;

    first(&int_ptr);
    int value = *int_ptr;

    cout << "Part 1:" << endl
         << " Return from first(), *int_ptr is " << value << endl;

    second(&never_used);
    value = *int_ptr;

    cout << " Return from second(), *int_ptr is " << value << endl<<endl;

    int_ptr = third();
    cout << "Part 2:" << endl
        << " Returned value of " << int_ptr << " from third()" << endl
        << " Value in that address is " << *int_ptr << endl;

    cout << " Setting memory at " << int_ptr << " to 109" << endl;
    *int_ptr = 109;

    //Produces Compiler error if run.
    //fourth();

    int counter = 0;
    int arraySize = 10000;
    int* ptr;


    do {
        ptr = new(nothrow) int[arraySize];
        counter++;
    } while (ptr != nullptr);

    cout << "Allocations made: " << counter << "\n";
}


