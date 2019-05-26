#include <iostream>
#include "MissType.h"
#include "Answer.h"

using namespace std;

Answer::Answer(bool missP) {
        miss = missP;
    }
Answer::Answer(MissType missTypeP) {
    miss = true;
    missType = missTypeP;
}

bool Answer::getMiss() {
    return miss;
}

MissType Answer::getMissType() {
    return missType;
}
