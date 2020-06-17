#pragma once

#include "student.h"

class securityStudent : public Student
{
public:
	Degree degreeTypes = SECURITY;

	using Student::Student;
	Degree getDegreeProgram() override;
};