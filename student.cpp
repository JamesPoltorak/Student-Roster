#include "stdafx.h"
#include <iostream>

#include "student.h"
using namespace std;


//setter
void Student::setStudentID(string ID)
{
	studentID = ID;
	return;
}

void Student::setFirstName(string fName)
{
	firstName = fName;
	return;
}

void Student::setLastName(string lName)
{
	lastName = lName;
	return;
}

void Student::setEmailAddress(string email)
{
	emailAddress = email;
	return;
}

void Student::setAge(int studentAge)
{
	age = studentAge;
	return;
}

void Student::setDays(int* completeDays)
{
	for (int i = 0; i < 3; i++)
	{
		daysToComplete[i] = completeDays[i];
	}
	return;
}

void Student::setDegree(Degree degree)
{
	degreeType = degree;
	return;
}

//getter
string Student::getStudentID()
{
	return studentID;
}

string Student::getFirstName()
{
	return firstName;
}

string Student::getLastName()
{
	return lastName;
}

string Student::getEmailAddress()
{
	return emailAddress;
}

int Student::getAge()
{
	return age;
}

int* Student::getDays()
{
	return daysToComplete;
}

Degree Student::getDegree()
{
	return degreeType;
}

void Student::print()
{
	int* days = getDays();

	cout << "Student ID: " << studentID << endl;
	cout << "Full Name: " << firstName << " " << lastName << endl;
	cout << "Age: " << age << endl;
	cout << "Days spent per course: " << days[0] << ", " << days[1] << ", " << days[2] << endl;
	cout << "Degree Program: ";

	if (getDegree() == SECURITY)
	{
		cout << "SECURITY" << endl << endl;
	}
	else if (getDegree() == NETWORKING)
	{
		cout << "NETWORKING" << endl << endl;
	}
	else if (getDegree() == SOFTWARE)
	{
		cout << "SOFTWARE" << endl << endl;
	}
}

Student::Student(string ID, string fName, string lName, string email, int studentAge, int* completeDays, Degree degree)
{
	studentID = ID;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	age = studentAge;
	setDays(completeDays);
	degreeType = degree;	
}

Student::~Student() {}

Degree Student::getDegreeProgram()
{
	return Degree();
}