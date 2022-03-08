#include "Student.h"
#include <cstring>

void Student::setName(const char *name) {
    strcpy(this->name, name);
}

void Student::setMathGrade(float grade) {
    this->mathGrade = grade;
}

void Student::setEnglishGrade(float grade) {
    this->englishGrade = grade;
}

void Student::setHistoryGrade(float grade) {
    this->historyGrade = grade;
}

const char *Student::getName() const {
    return name;
}

const float Student::getMathGrade() const {
    return mathGrade;
}

const float Student::getEnglishGrade() const {
    return englishGrade;
}

const float Student::getHistoryGrade() const {
    return historyGrade;
}

const float Student::getAverageGrade() const {
    float sum = (mathGrade + englishGrade + historyGrade)/3;
    return sum;
}
