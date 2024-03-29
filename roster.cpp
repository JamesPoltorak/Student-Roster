// ClassRoster.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <regex>
#include "student.h"
#include "roster.h"
using namespace std;



int main()
{
	int classRosterIndex = 0;
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,James,Poltorak,jpoltor@wgu.edu,26,130,24,2,SOFTWARE"
	};

	Roster classRoster;

	cout << "Course: Scripting and Programming Applications (C867)" << endl;
	cout << "Programming language used: C++" << endl;
	cout << "Student ID: 000917864" << endl;
	cout << "Name: James Poltorak" << endl << endl;

	for (int i = 0; i < 5; i++)
	{

		string str = studentData[i];
		vector<string> vect;

		stringstream ss(str);
		string newStudent[9];
		int j = 0;

		while (ss.good())
		{
			string substr;
			getline(ss, substr, ',');
			vect.push_back(substr);

			//cout << substr << endl;

			newStudent[j] = substr;
			j++;


		}
		//cout << newStudent[8] << endl;

		Degree degree = SECURITY;
		if (newStudent[8] == "SECURITY")
		{
			degree = SECURITY;
		}
		else if (newStudent[8] == "SOFTWARE")
		{
			degree = SOFTWARE;
		}
		else if (newStudent[8] == "NETWORK")
		{
			degree = NETWORKING;
		}




		//cout << newStudent << endl;



		//cout << studentData[i] << endl;
		classRoster.add(newStudent[0], newStudent[1], newStudent[2], newStudent[3], stoi(newStudent[4]), stoi(newStudent[5]), stoi(newStudent[6]), stoi(newStudent[7]), degree);
		classRosterIndex++;
	}


	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < 5; i++)
	{
		classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}

	classRoster.printByDegreeProgram(SOFTWARE); 
	classRoster.remove("A3");
	classRoster.remove("A3");

	classRoster.~Roster();

	system("PAUSE");

    return 0;
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree studentDegree)
{
	int daysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	//int k = 0;

	switch (studentDegree)
	{
	case Degree::NETWORKING:
		classRosterArray[classRosterIndex] = new networkStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, studentDegree);
		classRosterIndex++;
		break;
	case Degree::SECURITY:
		classRosterArray[classRosterIndex] = new securityStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, studentDegree);
		classRosterIndex++;
		break;
	case Degree::SOFTWARE:
		classRosterArray[classRosterIndex] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, studentDegree);
		classRosterIndex++;
		break;

	}
}

void Roster::printAll()
{
	for (int i = 0; i < 5; i++)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printInvalidEmails()
{
	cout << "Invalid emails are: " << endl;
	for (int i = 0; i < 5; i++)
	{
		string emailAddress = classRosterArray[i]->getEmailAddress();

		bool space = emailAddress.find(" ") != -1;
		bool atSign = emailAddress.find("@") != -1;
		bool period = emailAddress.find(".") != -1;

		bool realEmail = !space && atSign && period;

		if (realEmail == false)
		{
			cout << emailAddress << endl;
		}

		//cout << "-" << emailAddress << "-" << endl;
	}
	cout << endl;
}

void Roster::printDaysInCourse(string studentID)
{
	for (int i = 0; i < 5; i++)
	{
		string ID = classRosterArray[i]->getStudentID();
		if (ID == studentID)
		{
			int* days = classRosterArray[i]->getDays();

			int averageDays = ((days[0] + days[1] + days[2]) / 3);

			cout << "Average days in course for student " << studentID << " is " << averageDays << endl;
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int degreeType)
{
	for (int i = 0; i < 5; i++)
	{
		Degree degrees = classRosterArray[i]->getDegreeProgram();
		//cout << degrees << endl;

		if (degrees == degreeType)
		{
			classRosterArray[i]->print();
		}
	}

}

void Roster::remove(string ID)
{
	
	for (int i = 0; i < rosterStudents; i++)
	{
		/*string id = classRosterArray[i]->getStudentID();

		if (id == ID)
		{
			classRosterArray[i] = nullptr;
			cout << "Removing student: " << ID << endl;
			rosterStudents--;
			return;
		} */

		if (classRosterArray[i] != nullptr)
		{
			string id = classRosterArray[i]->getStudentID();

			if (id == ID)
			{
				classRosterArray[i] = nullptr;
				cout << "Removing student: " << ID << endl;
				rosterStudents--;
				return;
			}
		}
		
	}
	cout << "There is no student in the list with that Student ID." << endl;
}

Roster::~Roster() {};