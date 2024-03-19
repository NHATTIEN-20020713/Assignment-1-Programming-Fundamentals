#include "study_in_pink1.h"

bool readFile(
        const string & filename,
        int & HP1,
        int & HP2,
        int & EXP1,
        int & EXP2,
        int & M1,
        int & M2,
        int & E1,
        int & E2,
        int & E3
) {
    // This function is used to read the input file,
    // DO NOT MODIFY THIS FUNTION
    ifstream ifs(filename);
    if (ifs.is_open()) {
        ifs >> HP1 >> HP2
            >> EXP1 >> EXP2
            >> M1 >> M2
            >> E1 >> E2 >> E3;
        return true;
    }
    else {
        cerr << "The file is not found" << endl;
        return false;
    }
}

////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER BEGINS HERE
/// Complete the following functions
/// DO NOT modify any parameters in the functions.
////////////////////////////////////////////////////////////////////////

/*
0 <= HP <= 666
0 <= EXP <= 600
0 <= M <= 3000
0 <= E <= 99
*/

int nearestPerfectSquare(int &EXP1)
{
    double sqrtValue = sqrt(EXP1);
    int sqrtS = static_cast<int>(sqrtValue + 0.5);
    int S = sqrtS * sqrtS;

    return S;
}

int valueForIndex(int &E2)
{
    int firstDigit = E2/10;
    int secondDigit = E2%10;

    int sum = firstDigit + secondDigit;
    int index;
    index = sum%10;

    return index;
}

int compareTwoValue(int &num1, int &num2)
{
    int max;

    if(num1 > num2) max = num1;
    else max = num2;

    return max;
}

// Task 1
int firstMeet(int & exp1, int & exp2, int e1)
{
    // TODO: Complete this function
    if(e1 < 0 || e1 > 99)
    {
        return -99;
    }
    else
    {
        int D;
        D = e1 * 3 + exp1 * 7; // the number prepresent the Sherlock's decision
        if(e1 >= 0 && e1 <= 3)
        {
            if(e1 == 0)
            {
                exp2 = exp2 + 29;
                if(D % 2 == 0)
                {
                    exp1 = ceil(exp1 + (double)D/200);
                }
                else exp1 = ceil(exp1 - (double)D/100);
            }
            else if(e1 == 1)
            {
                exp2 = exp2 + 45;
                if(D % 2 == 0)
                {
                    exp1 = ceil(exp1 + (double)D/200);
                }
                else exp1 = ceil(exp1 - (double)D/100);
            }
            else if(e1 == 2)
            {
                exp2 = exp2 + 75;
                if(D % 2 == 0)
                {
                    exp1 = ceil(exp1 + (double)D/200);
                }
                else exp1 = ceil(exp1 - (double)D/100);
            }
            else if(e1 == 3)
            {
                exp2 = exp2 + 29 + 45 + 75;
                if(D % 2 == 0)
                {
                    exp1 = ceil(exp1 + (double)D/200);
                }
                else exp1 = ceil(exp1 - (double)D/100);
            }
        }
        else if(e1 >= 4 && e1 <= 19)
        {
            exp2 = ceil(exp2 + (double)e1/4 + 19);
            exp1 = exp1 - e1;
        }
        else if(e1 >= 20 && e1 <= 49)
        {
            exp2 = ceil(exp2 + (double)e1/9 + 21);
            exp1 = exp1 - e1;
        }
        else if(e1 >= 50 && e1 <= 65)
        {
            exp2 = ceil(exp2 + (double)e1/16 + 17);
            exp1 = exp1 - e1;
        }
        else if(e1 >= 66 && e1 <= 79)
        {
            exp2 = ceil(exp2 + (double)e1/4 + 19);
            if(exp2 > 200)
            {
                exp2 = ceil(exp2 + (double)e1/9 + 21);
            }
            exp1 = exp1 - e1;
        }
        else if(e1 >= 80 && e1 <= 99)
        {
            exp2 = ceil(exp2 + (double)e1/4 + 19);
            exp2 = ceil(exp2 + (double)e1/9 + 21);
            if(exp2 > 400)
            {
                exp2 = ceil(exp2 + (double)e1/16 + 17);
                exp2 = ceil(exp2 + (double)exp2*15/100);
            }
            exp1 = exp1 - e1;
        }

        if(exp1 < 0) exp1 = 0;
        else if(exp1 > 600) exp1 = 600;

        if(exp2 < 0) exp2 = 0;
        else if(exp2 > 600) exp2 = 600;
    }

    return exp1 + exp2;
}

// Task 2
int traceLuggage(int & HP1, int & EXP1, int & M1, int E2) 
{
    // TODO: Complete this function
    if(E2 < 0 || E2 > 99) return -99;

    else
    {
        // First road
        int S1;
        S1 = nearestPerfectSquare(EXP1);
        double P1; // probability to find the luggage
        if(EXP1 >= S1)
        {
            P1 = 1;
        }
        else P1 = (double)(EXP1/S1 + 80)/123;

        // Second road
        if(M1 == 0) // M1 = 0 at first and Sherlock walk to the end of road
        {
            HP1 = ceil(HP1 - (double)HP1*17/100);
            EXP1 = ceil(EXP1 + (double)EXP1*17/100);

            if(HP1 < 0) HP1 = 0;
            else if(HP1 > 666) HP1 = 666;

            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;
        }

        double P2; // probability to find the luggage
        // INT_MAX is the number that the events repeat until the paid money > 50% * M1_at_first
        const double M1_at_first = (double)M1; // const or not
        if(M1 > 0)
        {
            if(E2 % 2 != 0)
            {
                repeat : for(int i = 0; i < INT_MAX; i++)
                {
                    // First event in the second road
                    if(HP1 < 200)
                    {
                        HP1 = ceil(HP1 + (double)HP1*30/100);
                        M1 = M1 - 150;
                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                        {
                            HP1 = ceil(HP1 - (double)HP1*17/100);
                            if(HP1 < 0) HP1 = 0;
                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                            if(EXP1 > 600) EXP1 = 600;
                            break;
                        }
                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                        {
                            HP1 = ceil(HP1 - (double)HP1*17/100);
                            if(HP1 < 0) HP1 = 0;
                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                            if(EXP1 > 600) EXP1 = 600;
                            M1 = 0;
                            break;
                        }
                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                        {
                            // Second event in the second road
                            if(EXP1 < 400)
                            {
                                EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                                M1 = M1 - 200;
                                if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    break;
                                }
                                else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    M1 = 0;
                                    break;
                                }
                                else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                {
                                    // Third event in the second road
                                    if(EXP1 < 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 100;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                    else if(EXP1 >= 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 120;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                }
                            }
                            // Second event in the second road
                            else if(EXP1 >= 400)
                            {
                                EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                                if(EXP1 > 600) EXP1 = 600;
                                M1 = M1 - 120;
                                if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    break;
                                }
                                else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    M1 = 0;
                                    break;
                                }
                                else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                {
                                    // Third event in the second road
                                    if(EXP1 < 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 100;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                    else if(EXP1 >= 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 120;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if(HP1 >= 200)
                    {
                        HP1 = ceil(HP1 + (double)HP1*10/100);
                        if(HP1 > 666) HP1 = 666;
                        M1 = M1 - 70;
                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                        {
                            HP1 = ceil(HP1 - (double)HP1*17/100);
                            if(HP1 < 0) HP1 = 0;
                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                            if(EXP1 > 600) EXP1 = 600;
                            break;
                        }
                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                        {
                            HP1 = ceil(HP1 - (double)HP1*17/100);
                            if(HP1 < 0) HP1 = 0;
                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                            if(EXP1 > 600) EXP1 = 600;
                            M1 = 0;
                            break;
                        }
                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                        {
                            // Second event in the second road
                            if(EXP1 < 400)
                            {
                                EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                                M1 = M1 - 200;
                                if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    break;
                                }
                                else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    M1 = 0;
                                    break;
                                }
                                else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                {
                                    // Third event in the second road
                                    if(EXP1 < 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 100;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                    else if(EXP1 >= 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 120;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                }
                            }
                            // Second event in the second road
                            else if(EXP1 >= 400)
                            {
                                EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                                if(EXP1 > 600) EXP1 = 600;
                                M1 = M1 - 120;
                                if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    break;
                                }
                                else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                {
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                    M1 = 0;
                                    break;
                                }
                                else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                {
                                    // Third event in the second road
                                    if(EXP1 < 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 100;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                    else if(EXP1 >= 300)
                                    {
                                        EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                        if(EXP1 < 0) EXP1 = 0;
                                        M1 = M1 - 120;
                                        if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 > 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            break;
                                        }
                                        else if((M1_at_first - (double)M1 > (double)M1_at_first*50/100) && M1 <= 0)
                                        {
                                            HP1 = ceil(HP1 - (double)HP1*17/100);
                                            if(HP1 < 0) HP1 = 0;
                                            EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                            if(EXP1 > 600) EXP1 = 600;
                                            M1 = 0;
                                            break;
                                        }
                                        else if(M1_at_first - (double)M1 <= (double)M1_at_first*50/100)
                                        {
                                            goto repeat;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(E2 % 2 == 0)
            {
                // First event in the second road
                if(HP1 < 200)
                {
                    HP1 = ceil(HP1 + (double)HP1*30/100);
                    M1 = M1 - 150;
                    if(M1 <= 0)
                    {
                        HP1 = ceil(HP1 - (double)HP1*17/100);
                        if(HP1 < 0) HP1 = 0;
                        EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                        if(EXP1 > 600) EXP1 = 600;
                        M1 = 0;
                    }
                    else if(M1 > 0)
                    {
                        // Second event in the second road
                        if(EXP1 < 400)
                        {
                            EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                            M1 = M1 - 200;
                            if(M1 <= 0)
                            {
                                HP1 = ceil(HP1 - (double)HP1*17/100);
                                if(HP1 < 0) HP1 = 0;
                                EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                if(EXP1 > 600) EXP1 = 600;
                                M1 = 0;
                            }
                            else if(M1 > 0)
                            {
                                // Third event in the second road
                                if(EXP1 < 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 100;
                                    if(M1 < 0) M1 = 0;
                                    // With E2 is even when Sherlock walk to the end the HP and EXP change according to the description
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                                else if(EXP1 >= 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 120;
                                    if(M1 < 0) M1 = 0;
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                            }
                        }
                        // Second event in the second road
                        else if(EXP1 >= 400)
                        {
                            EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                            if(EXP1 > 600) EXP1 = 600;
                            M1 = M1 - 120;
                            if(M1 <= 0)
                            {
                                HP1 = ceil(HP1 - (double)HP1*17/100);
                                if(HP1 < 0) HP1 = 0;
                                EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                if(EXP1 > 600) EXP1 = 600;
                                M1 = 0;
                            }
                            else if(M1 > 0)
                            {
                                // Third event in the second road
                                if(EXP1 < 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 100;
                                    if(M1 < 0) M1 = 0;
                                    // With E2 is even when Sherlock walk to the end the HP and EXP change according to the description
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                                else if(EXP1 >= 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 120;
                                    if(M1 < 0) M1 = 0;
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                            }
                        }
                    }
                }
                else if(HP1 >= 200)
                {
                    HP1 = ceil(HP1 + (double)HP1*10/100);
                    if(HP1 > 666) HP1 = 666;
                    M1 = M1 - 70;
                    if(M1 <= 0)
                    {
                        HP1 = ceil(HP1 - (double)HP1*17/100);
                        if(HP1 < 0) HP1 = 0;
                        EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                        if(EXP1 > 600) EXP1 = 600;
                        M1 = 0;
                    }
                    else if(M1 > 0)
                    {
                        // Second event in the second road
                        if(EXP1 < 400)
                        {
                            EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                            M1 = M1 - 200;
                            if(M1 <= 0)
                            {
                                HP1 = ceil(HP1 - (double)HP1*17/100);
                                if(HP1 < 0) HP1 = 0;
                                EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                if(EXP1 > 600) EXP1 = 600;
                                M1 = 0;
                            }
                            else if(M1 > 0)
                            {
                                // Third event in the second road
                                if(EXP1 < 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 100;
                                    if(M1 < 0) M1 = 0;
                                    // With E2 is even when Sherlock walk to the end the HP and EXP change according to the description
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                                else if(EXP1 >= 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 120;
                                    if(M1 < 0) M1 = 0;
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                            }
                        }
                        // Second event in the second road
                        else if(EXP1 >= 400)
                        {
                            EXP1 = ceil(EXP1 + (double)EXP1*13/100);
                            if(EXP1 > 600) EXP1 = 600;
                            M1 = M1 - 120;
                            if(M1 <= 0)
                            {
                                HP1 = ceil(HP1 - (double)HP1*17/100);
                                if(HP1 < 0) HP1 = 0;
                                EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                if(EXP1 > 600) EXP1 = 600;
                                M1 = 0;
                            }
                            else if(M1 > 0)
                            {
                                // Third event in the second road
                                if(EXP1 < 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 100;
                                    if(M1 < 0) M1 = 0;
                                    // With E2 is even when Sherlock walk to the end the HP and EXP change according to the description
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                                else if(EXP1 >= 300)
                                {
                                    EXP1 = ceil(EXP1 - (double)EXP1*10/100);
                                    if(EXP1 < 0) EXP1 = 0;
                                    M1 = M1 - 120;
                                    if(M1 < 0) M1 = 0;
                                    HP1 = ceil(HP1 - (double)HP1*17/100);
                                    if(HP1 < 0) HP1 = 0;
                                    EXP1 = ceil(EXP1 + (double)EXP1*17/100);
                                    if(EXP1 > 600) EXP1 = 600;
                                }
                            }
                        }
                    }
                }
            }

            if(HP1 < 0) HP1 = 0;
            else if(HP1 > 666) HP1 = 666;

            if(EXP1 < 0) EXP1 = 0;
            else if(EXP1 > 600) EXP1 = 600;

            if(M1 < 0) M1 = 0;
            else if(M1 > 3000) M1 = 3000;

            int S2;
            S2 = nearestPerfectSquare(EXP1);
            if(EXP1 >= S2)
            {
                P2 = 1;
            }
            else P2 = (double)(EXP1/S2 + 80)/123;
        }

        // Third road
        int i;
        if(E2 >= 0 && E2 <= 9)
        {
            i = E2;
        }
        else if(E2 >= 10 && E2 <= 99)
        {
            i = valueForIndex(E2);
        }

        int arr[10] = {32, 47, 28, 79, 100, 50, 22, 83, 64, 11};
        double P3[10];

        for(i = 0; i < 10; i++)
        {
            P3[i] = (double)arr[i];
            P3[i] = P3[i]/100;
        }

        // Check all road together
        if(P1 == 1 && P2 == 1 && P3[i] == 1)
        {
            EXP1 = ceil(EXP1 - (double)EXP1*25/100);
            if(EXP1 < 0) EXP1 = 0;
        }
        else
        {
            double averageProbability;
            averageProbability = (P1 + P2 + P3[i])/3;
            if(averageProbability < 0.5)
            {
                HP1 = ceil(HP1 - (double)HP1*15/100);
                EXP1 = ceil(EXP1 + (double)EXP1*15/100);

                if(HP1 < 0) HP1 = 0;

                if(EXP1 > 600) EXP1 = 600;
            }
            else if(averageProbability >= 0.5)
            {
                HP1 = ceil(HP1 - (double)HP1*10/100);
                EXP1 = ceil(EXP1 + (double)EXP1*20/100);

                if(HP1 < 0) HP1 = 0;

                if(EXP1 > 600) EXP1 = 600;
            }
        }
    }

    return HP1 + EXP1 + M1;
}

// Task 3
int chaseTaxi(int & HP1, int & EXP1, int & HP2, int & EXP2, int E3)
{
    // TODO: Complete this function
    int finalValue;
    if(E3 < 0 || E3 > 99) return -99;

    else
    {
        int taxiMap[10][10] = {0};
        int i, j;
        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                taxiMap[i][j] = ((E3 * j) + (i * 2)) * (i - j);
            }
        }

        int i_meet = 0;
        int j_meet = 0;

        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                if(taxiMap[i][j] > E3 * 2)
                {
                    i_meet++;
                }
                if(taxiMap[i][j] < -E3)
                {
                    j_meet++;
                }
            }
        }

        while(i_meet >= 10 && i_meet <= 99) 
        {
            i_meet = i_meet % 10 + i_meet / 10;
        }

        while(j_meet >= 10 && j_meet <= 99) 
        {
            j_meet = j_meet % 10 + j_meet / 10;
        }

        i = i_meet;
        j = j_meet;

        int taxiScore;
        int SherlockWastonScore;

        taxiScore = taxiMap[i][j];

        int leftDiagonal[10][10] = {0};
        int rightDiagonal[10][10] = {0};
        int max1 = INT_MIN;
        int max2 = INT_MIN;

        for(i = 0; i < 10; i++)
        {
            for(j = 0; j < 10; j++)
            {
                if(i -j == i_meet - j_meet)
                {
                    leftDiagonal[i][j] = taxiMap[i][j];
                    if(leftDiagonal[i][j] > max1)
                    {
                        max1 = leftDiagonal[i][j];
                    }
                }
            }
        }

        for(i = 9; i >= 0; i--)
        {
            for(j = 0; j < 10; j++)
            {
                if(i + j == i_meet + j_meet)
                {
                    rightDiagonal[i][j] = taxiMap[i][j];
                    if(rightDiagonal[i][j] > max2)
                    {
                        max2 = rightDiagonal[i][j];
                    }
                }
            }
        }

        int maxScore;
        //int finalValue;

        maxScore = compareTwoValue(max1, max2);

        if(maxScore < 0)
        {
            SherlockWastonScore = abs(maxScore);
        }
        else if(maxScore >= 0)
        {
            SherlockWastonScore = maxScore;
        } 

        if(abs(taxiScore) > SherlockWastonScore) // Taxi not be caught
        {
            HP1 = ceil(HP1 - (double)HP1*10/100);
            if(HP1 < 0) HP1 = 0;
            EXP1 = ceil(EXP1 - (double)EXP1*12/100);
            if(EXP1 < 0) EXP1 = 0;
            HP2 = ceil(HP2 - (double)HP2*10/100);
            if(HP2 < 0) HP2 = 0;
            EXP2 = ceil(EXP2 - (double)EXP2*12/100);
            if(EXP2 < 0) EXP2 = 0;
            finalValue = taxiScore;
        }
        else if(abs(taxiScore) <= SherlockWastonScore) // Taxi be caught
        {
            HP1 = ceil(HP1 + (double)HP1*10/100);
            if(HP1 > 666) HP1 = 666;
            EXP1 = ceil(EXP1 + (double)EXP1*12/100);
            if(EXP1 > 600) EXP1 = 600;
            HP2 = ceil(HP2 + (double)HP2*10/100);
            if(HP2 > 666) HP2 = 666;
            EXP2 = ceil(EXP2 + (double)EXP2*12/100);
            if(EXP2 > 600) EXP2 = 600;
            finalValue = SherlockWastonScore;
        }
    }

    return finalValue;
}

// Task 4
bool stringContainString(const string &se, const string &password)
{
    if(password.find(se) != string::npos)
    {
        return true;
    }
    else return false;
}

bool checkConsecutiveDuplicate(const string &password)
{
    int count = 1;
    for(size_t i = 1; i < password.length(); i++)
    {
        if(password[i] == password[i - 1])
        {
            count++;
            if(count > 2)
            {
                return true;
            }
        }
        else count = 1;
    }
    return false;
}

int isOverTwoConsecutiveDuplicate(const string &password)
{
    int count = 1;
    for(size_t i = 1; i < password.length(); i++)
    {
        if(password[i] == password[i - 1])
        {
            count++;
            if(count > 2)
            {
                return i - count + 1;
            }
        }
        else count = 1;
    }
    return true;
}

int checkPassword(const char * s, const char * email)
{
    // TODO: Complete this function
    string my_email = email;
    string my_password = s;
    string se; // The string that before the character @
    int sei;
    int sci;

    int find_se = my_email.find('@');
    if(find_se != string::npos)
    {
        se = my_email.substr(0, find_se);
    }
    
    // Begin to test the conditions
    if(my_password.length() < 8) return -1;

    if(my_password.length() > 20) return -2;

    if(stringContainString(se, my_password) == true)
    {
        sei = my_password.find(se);
        return -(300 + sei);
    }

    if(checkConsecutiveDuplicate(my_password) == true)
    {
        sci = isOverTwoConsecutiveDuplicate(my_password);
        return -(400 + sci);
    }

    int specialCharacter = 0;
    bool remainingCharacter = false;
    int position;

    for(int i = 0; i < my_password.length(); i++)
    {
        if((my_password[i] >= 'a' && my_password[i] <= 'z') || (my_password[i] >= 'A' && my_password[i] <= 'Z') || (my_password[i] >= '0' && my_password[i] <= '9') || (!((my_password[i] >= 'a' && my_password[i] <= 'z') || (my_password[i] >= 'A' && my_password[i] <= 'Z') || (my_password[i] >= '0' && my_password[i] <= '9')) && !(my_password[i] == '@' || my_password[i] == '#' || my_password[i] == '%' || my_password[i] == '$' || my_password[i] == '!')))
        {
            continue;
        }
        else if(my_password[i] == '@' || my_password[i] == '#' || my_password[i] == '%' || my_password[i] == '$' || my_password[i] == '!')
        {
            specialCharacter++;
        }
    }

    if(specialCharacter == 0) return -5;

    else if(specialCharacter > 0)
    {
        for(int i = 0; i < my_password.length(); i++)
        {
            if((my_password[i] >= 'a' && my_password[i] <= 'z') || (my_password[i] >= 'A' && my_password[i] <= 'Z') || (my_password[i] >= '0' && my_password[i] <= '9') || my_password[i] == '@' || my_password[i] == '#' || my_password[i] == '%' || my_password[i] == '$' || my_password[i] == '!')
            {
                continue;
            }
            else if(!(my_password[i] >= 'a' && my_password[i] <= 'z') || (my_password[i] >= 'A' && my_password[i] <= 'Z') || (my_password[i] >= '0' && my_password[i] <= '9') && !(my_password[i] == '@' || my_password[i] == '#' || my_password[i] == '%' || my_password[i] == '$' || my_password[i] == '!'))
            {
                remainingCharacter = true;
                position = i;
                break;
            }
        }
    }

    if(remainingCharacter == true) return position;
    return -10;
}

// Task 5
int findCorrectPassword(const char * arr_pwds[], int num_pwds)
{
    // TODO: Complete this function
    string list_passwords[num_pwds];
    for(int i = 0; i < num_pwds; i++)
    {
        list_passwords[i] = arr_pwds[i];
    }

    int number_appearance[num_pwds] = {0};
    int length[num_pwds] = {0};
    int correct_position = 0;

    for(int i = 0; i < num_pwds; i++)
    {
        int string_length = list_passwords[i].length();
        length[i] = string_length;
        for(int j = 0; j < num_pwds; j++)
        {
            if(list_passwords[i].compare(list_passwords[j]) == 0)
            {
                number_appearance[i]++;
            }
        }
    }

    int max_number_appearance = 0;
    int max_length = 0;

    for(int i = 0; i < num_pwds; i++)
    {
        if(number_appearance[i] > max_number_appearance)
        {
            max_number_appearance = number_appearance[i];
            max_length = length[i];
            correct_position = i;
        }
        else if(number_appearance[i] == max_number_appearance && length[i] > max_length)
        {
            max_number_appearance = number_appearance[i];
            max_length = length[i];
            correct_position = i;
        }
    }
    
    return correct_position;
}
////////////////////////////////////////////////
/// END OF STUDENT'S ANSWER
////////////////////////////////////////////////