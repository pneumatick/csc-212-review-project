#include <iostream>
#include "gradebook.h"

int main(int argc, char*argv[]) {
    bool exit = false;  // Menu exit condition
    std::string value;
    // Create a gradebook with data from a text file
    Gradebook grades(argv[1]);
    std::string user_input_category;
    std::string user_input_name;
    double user_input_grade;

    while(!exit){
        //  Main menu
        std::cout<<"Input the number for the menu choice you want executed: "<<std::endl;
        std::cout<<"1. Get the grade from a specific assignment."<<std::endl;
        std::cout<<"2. Get the grade for a specific group of assignments "<<std::endl;
        std::cout<<"3. Get your total grade. "<<std::endl;
        std::cout<<"4. Add a grade to a specific group of assignments. "<<std::endl;
        std::cout<<"5. To exit program. "<<std::endl;

        std::cin>>value;

        // Sub menus
        if(value == "1"){   // Grade for single assignment
            std::cout << "Input the category of the assignment you are looking for:" << std::endl;
            std::cin >> user_input_category;

            std::cout << "Input the name of the assignment:" << std::endl;
            std::cin >> user_input_name;

            std::cout << "Grade for assignment " << user_input_name << " in category " << user_input_category << ":\n"
                                     << grades.get_assignment_grade(user_input_category, user_input_name) << "%\n\n";
        }
        else if(value == "2"){  // Grade for entire category
            std::cout << "Input the name of the category you want the total grade for:" << std::endl;
            std::cin >> user_input_category;

            std::cout << "Grade for category " << user_input_category << ":\n" << grades.get_category_grade(user_input_category) << "%\n\n";
        }
        else if (value == "3"){ // Grade for overall course
            std::cout << "Overall course grade:\n" << grades.get_total_grade() << "\n\n";
        }
        else if(value == "4"){  // Add new grade to gradebook
            std::cout << "Input the name of the category for the assignment you're adding:" << std::endl;
            std::cin >> user_input_category;

            std::cout << "Input the name of the assignment you're adding:" << std::endl;
            std::cin >> user_input_name;

            std::cout << "Input the grade of the assignment you're adding:" << std::endl;

            grades.add_grade(user_input_category, user_input_name, user_input_grade);
        }
        else if(value == "5"){  // Exit program
            exit = true;
        }
        else{   // Invalid user input
           std::cout<<"Invalid input try again" <<std::endl;
        }

    }
    return 0;
}
