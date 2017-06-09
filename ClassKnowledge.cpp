//https://www.hackerrank.com/challenges/virtual-functions
//resource: Hackerrank

#include <iostream>
#include <cstring>

using namespace std;

class Person
{
	public:
		char name[100];
		int age;
		Person(){};
		virtual void getdata() {};
		virtual void putdata() {};
		~Person();
};

class Professor: public Person
{
	private:
		int publications;
		static int id1;
		int idp;
	public:
		Professor() {
			id1++;
			idp = id1;
		}
		void getdata() {
			cin >> name >> age >> publications;
		}
		void putdata()
		{
			cout << name << " " << age << " " << publications << " " << idp << endl;
		}
		~Professor();
	
};
int Professor::id1 = 0;

class Student: public Person
{
	private:
		int mark[6];
		static int id2;
		int ids;
	public:
		Student() {
			id2++;
			ids = id2;
		}
		void getdata() {
			cin >> name >> age;
			for (int i=0; i<6; i++) cin >> mark[i];
		}
		void putdata() {
			int sum = 0;
			for (int i=0; i<6; i++) sum += mark[i];
			cout << name << " " << age << " " << sum << " " << ids << endl;
		}
		~Student();
};
int Student::id2 = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
