#include <iostream>
#include "gradebook.h"

int main(int argc, char*argv[]) {
    bool exit = false;
    std::string value;
    // Create a gradebook with data from a text file
    Gradebook grades(argv[1]);

    while(!exit){
        std::cout<<"Input the number for the menu choice you want executed: "<<std::endl;
        std::cout<<"1. Get the grade from a specific assignment."<<std::endl;
        std::cout<<"2. Get the grade for a specific group of assignments "<<std::endl;
        std::cout<<"3. Get your total grade. "<<std::endl;
        std::cout<<"4. Add a grade to a specific group of assignments. "<<std::endl;
        std::cout<<"5. To exit program. "<<std::endl;

        std::cin>>value;

        if(value == "1"){
            //Figured this format for these variables is simple enough, option# then category (c) or name (n)
            std::string opt1_c;
            std::cout << "Enter either lab, assignment, project, or exam for the category of the assignment you are looking for:" << std::endl;
            std::cin >> opt1_c;

            std::string opt1_n;
            std::cout << "Input the name of the assignment:" << std::endl;
            std::cin >> opt1_n;

            std::cout<<grades.get_assignment_grade(opt1_c, opt1_n)<<std::endl;
        }
        else if(value == "2"){
            std::string opt2_c;
            std::cout << "Enter either lab, assignment, project, or exam for the category you want the total grade for:" << std::endl;
            std::cin >> opt2_c;

            std::cout << grades.get_category_grade(opt2_c) << '%' << std::endl;
        }
        else if (value == "3"){
            std::cout<< grades.get_total_grade()<<std::endl;
        }
        else if(value == "4"){
            std::string opt4_c;
            std::string opt4_n;
            std::string opt4_g;

            std::cout << "Enter either lab, assignment, project, or exam for the category for the assignment you're adding:" << std::endl;
            std::cin >> opt4_c;

            std::cout << "Input the name of the assignment you're adding:" << std::endl;
            std::cin >> opt4_n;

            std::cout << "Input the grade of the assignment you're adding:" << std::endl;
            std::cin >> opt4_g;

            grades.add_grade(opt4_c, opt4_n, std::stod(opt4_g), argv[1]);
        }
        else if(value == "5"){
            exit = true;
        }
        else{
            std::cout<<"Invalid input try again" <<std::endl;
        }

    }
    return 0;
}