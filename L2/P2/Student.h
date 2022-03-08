class Student {
    char name[20];
    float mathGrade;
    float englishGrade;
    float historyGrade;
public:
    void setName(const char* name);
    void setMathGrade(float grade);
    void setEnglishGrade(float grade);
    void setHistoryGrade(float grade);
    const char* getName() const;
    const float getMathGrade() const;
    const float getEnglishGrade() const;
    const float getHistoryGrade() const;
    const float getAverageGrade() const;
};
