#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"

class Roster
{
public:
	int rosterStudents = 5;
	int classRosterIndex = 0;
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree studentDegree);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(int degreeProgram);

	~Roster();
};