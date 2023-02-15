//
// Created by ser94 on 2/14/2023.
//

#ifndef REVIEWPROJECT_GRADEBOOK_H
#define REVIEWPROJECT_GRADEBOOK_H

#include <iostream>
#include <vector>

class Gradebook{

private:
    double max_lab_grade;
    double max_assignment_grade;
    double max_projects_grade;
    double max_exam_grade;
    std::vector<std::pair<std::string,double>> labs;
    std::vector<std::pair<std::string,double>> assignments;
    std::vector<std::pair<std::string,double>> projects;
    std::vector<std::pair<std::string,double>> exams;

public:
    Gradebook();
    Gradebook(std::string inputFile);
    void Set_Max_Lab_Grade(double value);
    double Get_Max_Lab_Grade();

    void Set_Max_Assignment_Grade(double value);
    double Get_Max_Assignment_Grade();

    void Set_Max_Projects_Grade(double value);
    double Get_Max_Projects_Grade();

    void Set_Max_Exam_Grade(double value);
    double Get_Max_Exam_Grade();

    void getAssignmentGrade(std::string category, std::string name);

    void getCategoryGrade(std::string category);

    void getTotalGrade();

    void addGrade(std::string category,std::string name, double grade);

};

#endif //REVIEWPROJECT_GRADEBOOK_H
