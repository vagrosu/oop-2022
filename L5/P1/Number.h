class Number
{
    // add data members
    char* value;
    unsigned base;
public:
    Number(const char * value, int base); // where base is between 2 and 16
    ~Number();

    // add operators and copy/move constructor
    char operator[](unsigned index);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
    char* GetValue();
};

Number operator+(const Number& l, const Number& r);
