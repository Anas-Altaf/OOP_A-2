
#include<iostream>
#include<Windows.h>
using namespace std;
//=> PERSON
class Person {

};
//--> Student Work
class Student :public Person {

};
//---->Math Student
class MathStudent :public Student {

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

	system("pause");
	return 0;
}
