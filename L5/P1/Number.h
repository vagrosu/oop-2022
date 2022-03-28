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
    Number operator=(int value);
    Number operator=(const char *value);

    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase() const; // returns the current base
    char* GetValue() const;
};

Number operator+(const Number& l, const Number& r);
Number operator-(const Number& l, const Number& r);
bool operator>(const Number& l, const Number& r);
bool operator<(const Number& l, const Number& r);
