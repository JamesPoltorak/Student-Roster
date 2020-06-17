#pragma once

#include "student.h"

class networkStudent : public Student
{
public:
	Degree degreeTypes = NETWORKING;

	using Student::Student;
	Degree getDegreeProgram() override;
};