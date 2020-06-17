#pragma once

#include "student.h"

class softwareStudent : public Student
{
public:
	Degree degreeTypes = SOFTWARE;

	using Student::Student;
	Degree getDegreeProgram() override;
};