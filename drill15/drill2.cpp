#include "Simple_window.h"
#include "Graph.h"
#include <locale>

struct Person {
    Person() { }
    Person(string ff, string ll, int aa);

    string first_name() const { return first; }
    string last_name() const { return last; }
    int age() const { return a; }

private:
    string first;
    string last;
    int a;
};

Person::Person(string ff, string ll, int aa) : first{ff}, last{ll}, a{aa}
{
    if (aa < 0 || 150 < aa) error("Person(): invalid age");
    
    string nn = ff + ll;
    for (char c : nn) {
        if (!isalpha(c)) error("illegal character");
        }
}

istream& operator>>(istream& is, Person& p)
{
    string fname, sname;
    int age;
    is >> fname >> sname >> age;
    if (!is) return is;
    p = Person(fname,sname,age);
    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << "Name: " << p.first_name() << ' ' <<
        p.last_name() << ", age: " << p.age();
}


int main()
try {
    //Person{"kristof", "kovacs", 160};
    Person p {"kristof","kovacs", 20};
    cout << p.first_name() << p.last_name() << p.age() << endl;

    //vector<Person> persons;
    //Person p4;
    //while (cin>>p4)
    //    persons.push_back(p4);
    //for (int i = 0; i<persons.size(); ++i)
    //    cout << persons[i] << endl;


}
catch (exception& e) {
    cerr << "exception: " << e.what() << endl;
    keep_window_open();
}
catch (...) {
    cerr << "exception\n";
    keep_window_open();
}