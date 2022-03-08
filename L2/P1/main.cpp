#include <iostream>
#include "NumberList.h"

void useNumberLisExample() {
    NumberList list;
    list.Init();
    list.Add(4);
    list.Add(2);
    list.Add(1);
    list.Add(6);
    list.Add(14);
    list.Add(24);
    list.Add(44);
    list.Sort();
    list.Print();
}

int main() {

    useNumberLisExample();

    return 0;
}
