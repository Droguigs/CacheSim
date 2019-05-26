#ifndef ANSWER_H_INCLUDED
#define ANSWER_H_INCLUDED

#include <iostream>
#include "MissType.h"

using namespace std;

class Answer{
private:
    bool miss;
    MissType missType;
public:
    Answer(bool missP);
    Answer(MissType missTypeP);
};

#endif // ANSWER_H_INCLUDED
