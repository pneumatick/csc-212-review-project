//
// Created by ser94 on 2/14/2023.
//
#import "gradebook.h"

Gradebook::Gradebook(){
    this->max_assignment_grade = 0;
    this->max_exam_grade = 0;
    this->max_lab_grade =0;
    this->max_projects_grade = 0;
}

Gradebook::Gradebook(std::string inputFile){

}
void Gradebook::Set_Max_Lab_Grade(double value) {
    this->max_lab_grade = value;
}

double Gradebook::Get_Max_Lab_Grade() {
    return this->max_lab_grade;
}

void Gradebook::Set_Max_Assignment_Grade(double value) {}

double Gradebook::Get_Max_Assignment_Grade() {}

void Gradebook::Set_Max_Exam_Grade(double value) {}

double Gradebook::Get_Max_Exam_Grade() {}

void Gradebook::Set_Max_Projects_Grade(double value) {}

double Gradebook::Get_Max_Projects_Grade() {}

void Gradebook::getAssignmentGrade(std::string category, std::string name){}

void Gradebook::getCategoryGrade(std::string category){}

void Gradebook::getTotalGrade(){}

void Gradebook::addGrade(std::string category,std::string name, double grade){}