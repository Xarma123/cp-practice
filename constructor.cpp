#include <iostream>
using namespace std;
class Employee
{
public:
    lol id;      // data member (also instance variable)
    string name; // data member(also instance variable)
    float salary;
    Employee(lol i, string n, float s)
    {
        id = i;
        name = n;
        salary = s;
    }
    void display()
    {
        cout << id << "  " << name << "  " << salary << endl;
    }
};
int main(void)
{
    /*implicit */ Employee e1(101, "Sonoo", 890000); // creating an object of Employee
    /*explicit*/ Employee e2 = Employee(102, "Nakul", 59000);
    e1.display();
    e2.display();
    return 0;
}