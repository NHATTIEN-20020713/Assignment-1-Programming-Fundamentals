/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 1
* Programming Fundamentals Spring 2023
* Author: Vu Van Tien
* Date: 02.02.2023
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "study_in_pink1.h"

using namespace std;

void sa_tc_01() {
    cout << "----- Sample Testcase 01 -----" << endl;
    string input_file("sa_tc_01_input");
    int HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3;
    if (!readFile(input_file, HP1, HP2, EXP1, EXP2, M1, M2, E1, E2, E3)) {
        return;
    }

    if(HP1 < 0) HP1 = 0;
    else if(HP1 > 666) HP1 = 666;

    if(HP2 < 0) HP2 = 0;
    else if(HP2 > 666) HP2 = 666;

    if(EXP1 < 0) EXP1 = 0;
    else if(EXP1 > 600) EXP1 = 600;

    if(EXP2 < 0) EXP2 = 0;
    else if(EXP2 > 600) EXP2 = 600;

    if(M1 < 0) M1 = 0;
    else if(M1 > 3000) M1 = 3000;

    if(M2 < 0) M2 = 0;
    else if(M2 > 3000) M2 = 3000;

    if(E1 < 0 || E1 > 99) E1 = -99;
    if(E2 < 0 || E2 > 99) E2 = -99;
    if(E3 < 0 || E3 > 99) E3 = -99;

    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", E1: " << E1 << endl;
    int result = firstMeet(EXP1, EXP2, E1);
    cout << "EXP1: " << EXP1 << ", EXP2: " << EXP2 << ", result: " << result << endl;

    cout << "----- Sample Testcase 05 -----" << endl;
    //int E3 = 59, HP1 = 400, EXP1 = 600, HP2 = 350, EXP2 = 500;
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", HP2: " << HP2 << ", EXP2: " << EXP2 << endl;
    int task3 = chaseTaxi(HP1, EXP1, HP2, EXP2, E3);
    cout << "E3: " << E3 << ", HP1: " << HP1 << ", EXP1: " << EXP1 << ", HP2: " << HP2 << ", EXP2: " << EXP2 << ", task3: " << task3 << endl;
}

int main(int argc, const char * argv[]) {
    sa_tc_01();

    return 0;
}