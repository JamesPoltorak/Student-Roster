#pragma once

#include <string>
#include "degree.h"
using namespace std;

class Student
{
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	Degree degreeType;

public:
	//setter
	void setStudentID(string ID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmailAddress(string email);
	void setAge(int studentAge);
	void setDays(int* completeDays);
	void setDegree(Degree degree);

	//getter
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDays();
	Degree getDegree();

	virtual void print();
	virtual Degree getDegreeProgram();
	
	Student(string ID, string fName, string lName, string email, int studentAge, int* completeDays, Degree degree);
	~Student();



};