#include <iostream>
#include <string>
#include <map>
#include <queue>

class Comparator {
public:
    bool operator() (const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) const {
        if(p1.second != p2.second) {
            return p1.second < p2.second;
        } else {
            return p1.first.compare(p2.first) > 0;
        }
    }
};

int main() {
    FILE* file = fopen("../file.txt", "rb");
    if(file == nullptr) {
        printf("Not found");
        return 1;
    }

    std::string s;
    char buffer[4096];
    while(!feof(file)) {
        unsigned long read = fread(buffer, 1, sizeof(buffer), file);
        s.append(buffer, read);
    }
    fclose(file);

    std::map<std::string, int> countMap;
    std::priority_queue< std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, Comparator > countQueue;

    std::string cuv;
    for(std::string::iterator i = s.begin(); i != s.end(); i++) {
        if(*i != ' ' && *i != ',' && *i != '?' && *i != '!' && *i != '.') {
            cuv += *i;
        } else if(cuv.size()){
            transform(cuv.begin(), cuv.end(), cuv.begin(), ::tolower);
            auto search = countMap.find(cuv);
            if(search != countMap.end()) {
                countMap[cuv]++;
            } else {
                countMap[cuv] = 1; // add to map
            }
            cuv.clear();
        }
    }
    if(cuv.size()) {
        countMap[cuv] = 1; // add to map
    }

    for(std::map<std::string, int>::iterator i = countMap.begin(); i != countMap.end(); i++) {
        countQueue.push(std::pair<std::string, int>(i->first, i->second));
    }

    std::cout << '\n';
    while(!countQueue.empty()) {
        std::cout << countQueue.top().first << " => " << countQueue.top().second << '\n';
        countQueue.pop();
    }
    return 0;
}
