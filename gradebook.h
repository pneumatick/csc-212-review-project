#ifndef REVIEWPROJECT_GRADEBOOK_H
#define REVIEWPROJECT_GRADEBOOK_H

#include <iostream>
#include <vector>
#include <fstream>

// Category name constants
const std::string LABS = "lab";
const std::string ASSIGNMENTS = "assignment";
const std::string PROJECTS = "project";
const std::string EXAMS = "exam";

// Category maximum total value constants
const double MAX_LAB_GRADE = 20.0;
const double MAX_ASSIGNMENT_GRADE = 50.0;
const double MAX_PROJECT_GRADE_1 = 150.0;
const double MAX_PROJECT_GRADE_2 = 350.0; 
const double MAX_EXAM_GRADE = 100.0;

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
    // Creates a gradebook with data from a text file
    Gradebook(std::string inputFile);
    double Get_Lab_Grade();
    double Get_Assignment_Grade();
    double Get_Projects_Grade();
    double Get_Exam_Grade();
    void output_category_grades(std::string category);
    // Outputs a list of all elements in a category and their points achieved.
    void output_category_overview(std::string category);
    double get_assignment_grade(std::string category, std::string name);
    double get_category_grade(std::string category);
    // void get_all_grades();
    // void get_all_totals();
    double get_total_grade();
    void add_grade(std::string category, std::string name, double grade);
    // Remove a grade from the grade book
    void remove_grade(std::string category, std::string name);
    // Change the grade of an element in the grade book
    void update_grade(std::string category, std::string name, double grade);
    void close(std::string filename);

};

#endif //REVIEWPROJECT_GRADEBOOK_H
