#ifndef DATA_H
#define DATA_H
#endif // DATA_H
#include <QString>
#include <map>
#include<QString>
using namespace std;
class interests{
public:
    bool politics=false;
    bool business=false;
    bool technology=false;
    bool healthcare=false;
    bool science = false;
    bool entertainment = false;
    bool sports = false;
    interests(bool politics, bool business, bool technology, bool healthcare, bool science, bool entertainment, bool sports): politics(politics), business(business), technology(technology), healthcare(healthcare), science(science), entertainment(entertainment), sports(sports){}
};

extern map<QString, tuple<QString, bool,interests>> usernames;
