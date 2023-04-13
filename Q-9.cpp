#include<iostream>
#include<Windows.h>
#include<string>
using namespace std;

//=> PERSON
class Person {
private:
	string name;
	string age;
	string addr;
protected:
	void input1() {
		cout << "Enter name = "; cin >> name;
		cout << "enter age = "; cin >> age;
		cout << "Enter Address  ="; cin >> addr;
	}
	void output1() {
		cout << "Name is = " << name << endl;
		cout << "Age is = " << age << endl;
		cout << "Address is = " << addr << endl;
	}
};
//--> Student Work
class Student :public Person {
private :
	int rollno;
protected:
	void input2() {
		input1();
		cout << "Enter Roll No = "; cin >> rollno;
	}
	void output2() {
		output1();
		cout << "Roll No is = " << rollno << endl;
	}
};
//---->Math Student
class MathStudent :public Student {
private:
	string coursename;
public:
	void input3() {
		input2();
		cout << "Enter Math Course Name = "; cin >> coursename;
	}
	void output3() {
		output2();
		cout << "Course Name is = " << coursename << endl;
	}
};
//----> CS Student
class CSStudent :public Student {

};
//--> Employee Work
class Employee:public Person {

};
//----> Professor
class Professor :public Employee {

};
//------> Department Chairman
class DepartmentChair :public Professor {

};
//----> Staff
class Staff :public Employee {

};
//------> Manager
class Manager :public Staff {

};
//------> IT Worker
class ITWorker :public Staff {

};
int main()
{
	MathStudent obj1;
	obj1.input3();
	obj1.output3();

	system("pause");
	return 0;
}
