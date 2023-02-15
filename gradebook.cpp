#include "gradebook.h"

Gradebook::Gradebook(){
    this->assignment_grades_total = 0.0;
    this->exam_grades_total = 0.0;
    this->lab_grades_total = 0.0;
    this->project_grades_total = 0.0;
}

Gradebook::Gradebook(std::string inputFile){

}

// Return the student's cumulative grade for all graded labs
double Gradebook::Get_Lab_Grade() {
    if (labs.size() == 0) {
	return 100.0;
    }

    return (this->lab_grades_total / (MAX_LAB_GRADE * labs.size())) * 100;
}

// Return the student's cumulative grade for all graded assignments
double Gradebook::Get_Assignment_Grade() {
    if (assignments.size() == 0) {
	return 100.0;
    }

    return (this->assignment_grades_total / (MAX_ASSIGNMENT_GRADE * assignments.size())) * 100;
}

// Return the student's cumulative grade for all graded exams
double Gradebook::Get_Exam_Grade() {
    if (exams.size() == 0) {
	return 100.0;
    }

    return (this->exam_grades_total / (MAX_EXAM_GRADE * exams.size())) * 100;
}

// Return the student's cumulative grade for all graded projects
double Gradebook::Get_Projects_Grade() {
    if (projects.size() == 0) {
	return 100.0;
    }

    return (this->project_grades_total / (MAX_PROJECT_GRADE * projects.size())) * 100;
}

double Gradebook::get_assignment_grade(std::string category, std::string name){
    return 0; 
}

double Gradebook::get_category_grade(std::string category){
    return 0;
}

double Gradebook::get_total_grade(){
    return 0;
}

void Gradebook::add_grade(std::string category,std::string name, double grade){}
