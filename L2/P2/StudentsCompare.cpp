#include "StudentsCompare.h"

int compareNames(Student student1, Student student2) {
    if(strcmp(student1.getName(), student2.getName()) == 0) {
        return 0;
    }
    if(strcmp(student1.getName(), student2.getName()) > 0) {
        return 1;
    }
    return -1;
}

int compareMathGrades(Student student1, Student student2) {
    if(student1.getMathGrade() == student2.getMathGrade()) {
        return 0;
    }
    if(student1.getMathGrade() > student2.getMathGrade()) {
        return 1;
    }
    return -1;
}

int compareEnglishGrades(Student student1, Student student2) {
    if(student1.getEnglishGrade() == student2.getEnglishGrade()) {
        return 0;
    }
    if(student1.getEnglishGrade() > student2.getEnglishGrade()) {
        return 1;
    }
    return -1;
}

int compareHistyoryGrades(Student student1, Student student2) {
    if(student1.getHistoryGrade() == student2.getHistoryGrade()) {
        return 0;
    }
    if(student1.getHistoryGrade() > student2.getHistoryGrade()) {
        return 1;
    }
    return -1;
}

int compareAverageGrades(Student student1, Student student2) {
    if(student1.getAverageGrade() == student2.getAverageGrade()) {
        return 0;
    }
    if(student1.getAverageGrade() > student2.getAverageGrade()) {
        return 1;
    }
    return -1;
}
