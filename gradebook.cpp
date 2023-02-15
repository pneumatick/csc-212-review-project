#include "gradebook.h"

Gradebook::Gradebook(){
    this->assignment_grades_total = 0.0;
    this->exam_grades_total = 0.0;
    this->lab_grades_total = 0.0;
    this->project_grades_total = 0.0;
}

Gradebook::Gradebook(std::string inputFile){

}

// Return the student's cumulative grade for all graded labs as a percentage
double Gradebook::Get_Lab_Grade() {
    if (labs.size() == 0) {
	return 100.0;
    }

    return (this->lab_grades_total / (MAX_LAB_GRADE * labs.size())) * 100;
}

// Return the student's cumulative grade for all graded assignments as a 
// percentage
double Gradebook::Get_Assignment_Grade() {
    if (assignments.size() == 0) {
	return 100.0;
    }

    return (this->assignment_grades_total / (MAX_ASSIGNMENT_GRADE * assignments.size())) * 100;
}

// Return the student's cumulative grade for all graded exams as a percentage
double Gradebook::Get_Exam_Grade() {
    if (exams.size() == 0) {
	return 100.0;
    }

    return (this->exam_grades_total / (MAX_EXAM_GRADE * exams.size())) * 100;
}

// Return the student's cumulative grade for all graded projects as a 
// percentage
double Gradebook::Get_Projects_Grade() {
    if (projects.size() == 0) {
	return 100.0;
    }

    return (this->project_grades_total / (MAX_PROJECT_GRADE * projects.size())) * 100;
}

// Return the grade of a specific assignment.
// Returns -1.0 if the category or assignment isn't found.
double Gradebook::get_assignment_grade(std::string category, std::string name){
    double grade = -1.0;
    std::vector<std::pair<std::string, double>> category_vector;

    if (category == LABS) {
	category_vector = this->labs;
    }
    else if (category == ASSIGNMENTS) {
   	category_vector = this->assignments; 
    }
    else if (category == PROJECTS) {
	category_vector = this->projects;
    }
    else if (category == EXAMS) {
	category_vector = this->exams;
    }
    else {
	return -1.0;
    }

    for (long unsigned int i = 0; i < category_vector.size(); i++) {
	if (category_vector[i].first == name) {
	    grade = category_vector[i].second;
	}
    }

    return grade;
}

// Is this redundant? If not, what does it do that the previous getters don't?
double Gradebook::get_category_grade(std::string category){
    return 0;
}

// Return the total cumulative grade for the class as a percentage
double Gradebook::get_total_grade(){
    return 0;
}

// Manually add a new grade to the respective category
void Gradebook::add_grade(std::string category,std::string name, double grade){

}
