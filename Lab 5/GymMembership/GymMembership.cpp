

#include <iostream>
#include <string>
#include<vector>
#include<iomanip>
using namespace std;

const double BASIC_RATE = 28.50, PREMIUM_RATE = 60.00;


struct Member {
    static int total_visits, active_members, last_id;
    int id, visits;
    string name;
    char type;

    Member(string name, char type) {
        this->name = name;
        this->type = type;
        this->visits = 0;
        active_members++;
        id = last_id++;
    }

    ~Member() {
        active_members--;
    }

    void visit(Member *person) {
        person->visits++;
        total_visits++;
    }

};

//Defines static variables
int Member::total_visits = 0;
int Member::active_members = 0;
int Member::last_id = 100000;

int main()
{
    vector<Member*> membersVec;

    Member* oprah = new Member("Oprah Winfrey", 'p');
    membersVec.push_back(oprah);
    Member* fluffy = new Member("Fluffy Iglesias", 'p');
    membersVec.push_back(fluffy);
    Member* charlie = new Member("Charlie Sheen", 'b');
    membersVec.push_back(charlie);
    Member* bill = new Member("Bill Gates", 'b');
    membersVec.push_back(bill);

    //Finds the Charlie object and erases it from the vector
    vector<Member*>::iterator position = find(membersVec.begin(), membersVec.end(), charlie);
    membersVec.erase(position);
    //Erases Charlie from the heap
    charlie->~Member();

    srand(time(NULL));
    int randomVisit = rand() % 20 + 5;
    for (int i = 0; i < randomVisit; i++) {
        oprah->visit(oprah);
    }

    randomVisit = rand() % 20 + 5;
    for (int i = 0; i < randomVisit; i++) {
        fluffy->visit(fluffy);
    }

    randomVisit = rand() % 20 + 5;
    for (int i = 0; i < randomVisit; i++) {
        bill->visit(bill);
    }

    cout << setw(20) << "Member" << setw(20) << "ID" << setw(20) << "# of Visits" << setw(20) << "Monthly Rate" << "\n";

    for (auto i : membersVec) {
        if (i->type == 'b') {
            cout << setw(20) << i->name << setw(20) << i->id << setw(20) << i->visits << setw(20) << "$28.50"<<"\n";
        }
        else {
            cout << setw(20) << i->name << setw(20) << i->id << setw(20) << i->visits << setw(20) << "$60" << "\n";
        }
        
    }

    cout << endl;
    cout << "Total Visits: " << Member::total_visits<< "    Total Members: " << Member::active_members<<"\n";

    

}


