#include <iostream>
#include "StudentsCompare.h"

int main() {
    Student student1;
    student1.setName("Emanuel");
    student1.setMathGrade(9.2);
    student1.setEnglishGrade(3.5);
    student1.setHistoryGrade(7.4);
    Student student2;
    student2.setName("Timi");
    student2.setMathGrade(4.2);
    student2.setEnglishGrade(5.5);
    student2.setHistoryGrade(7.4);
    std::cout << compareNames(student1, student2) << std::endl;
    std::cout << compareMathGrades(student1, student2) << std::endl;
    std::cout << compareEnglishGrades(student1, student2) << std::endl;
    std::cout << compareHistyoryGrades(student1, student2) << std::endl;
    std::cout << compareAverageGrades(student1, student2) << std::endl;
    return 0;
}
