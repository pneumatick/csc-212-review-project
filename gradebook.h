#ifndef REVIEWPROJECT_GRADEBOOK_H
#define REVIEWPROJECT_GRADEBOOK_H

#include <iostream>
#include <vector>

// Category name constants
const std::string LABS = "labs";
const std::string ASSIGNMENTS = "assignments";
const std::string PROJECTS = "projects";
const std::string EXAMS = "exams";

// I haven't checked to see what the maximum points available for each 
// category are yet, so I'm just setting them to 1 as a placeholder.
const double MAX_LAB_GRADE = 1.0;
const double MAX_ASSIGNMENT_GRADE = 1.0;
const double MAX_PROJECT_GRADE = 1.0;
const double MAX_EXAM_GRADE = 1.0;

class Gradebook{

private:
    // Total points that the student has received for all assignments in each 
    // category (not a percentage).
    double lab_grades_total;
    double assignment_grades_total;
    double project_grades_total;
    double exam_grades_total;

    std::vector<std::pair<std::string,double>> labs;
    std::vector<std::pair<std::string,double>> assignments;
    std::vector<std::pair<std::string,double>> projects;
    std::vector<std::pair<std::string,double>> exams;

public:
    Gradebook();
    Gradebook(std::string inputFile);
    double Get_Lab_Grade();
    double Get_Assignment_Grade();
    double Get_Projects_Grade();
    double Get_Exam_Grade();
    double get_assignment_grade(std::string category, std::string name);
    double get_category_grade(std::string category);
    double get_total_grade();
    void add_grade(std::string category, std::string name, double grade);

};

#endif //REVIEWPROJECT_GRADEBOOK_H
