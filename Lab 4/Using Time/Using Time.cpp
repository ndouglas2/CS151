// 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#define Size 50

using namespace std;

int main()
{
    string days[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
    string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    time_t now;
    struct tm* tmp;
    char MY_TIME[Size];
    time(&now);
    tmp = localtime(&now);

    strftime(MY_TIME, sizeof(MY_TIME), "%D", tmp);
    printf("Month/Day/Year: %s", MY_TIME);
    cout << endl;

    strftime(MY_TIME, sizeof(MY_TIME), "%B %d, %G", tmp);
    printf("Month Day, Year: %s", MY_TIME);
    cout << endl;

    strftime(MY_TIME, sizeof(MY_TIME), "%d-%b-%G", tmp);
    printf("Day-Month-Year: %s", MY_TIME);
    cout << endl;

    strftime(MY_TIME, sizeof(MY_TIME), "%R", tmp);
    printf("24 Hour Time: %s", MY_TIME);
    cout << endl;

    strftime(MY_TIME, sizeof(MY_TIME), "%I:%M%p", tmp);
    printf("12 hour time with am/pm: %s", MY_TIME);
    cout << endl;

    struct tm* birthday; {
        int tm_year = 1997;
        int tm_mon = 07;
        int tm_mday = 10;
        int tm_hour = 8;
        int tm_min = 53;
        int tm_sec = 20;
        int tm_isdst = false;
    };
    
    /*time_t birth_time = mktime(birthday);
    cout << ctime(&birth_time) << endl << "I was born " << birth_time << " seconds after epoch!" << endl;*/
    //Throws an exception

}


