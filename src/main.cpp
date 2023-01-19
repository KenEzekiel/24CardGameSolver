#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

// TODO : check / karna belum bener
// TODO : kenapa 10 masukan invalid

bool checkCard(char card)
{
    string str(1, card);
    int num = atoi(str.c_str());
    return (card == 'A') || (card == 'J') || (card == 'Q') || (card == 'K') || (num <= 10 && num >= 2);
}

void translateCards(vector<double> *input, const vector<char> cards)
{
    // LOCAL DICTIONARY

    // ALGORITHM
    for (auto &x : cards)
    {
        string str(1, x);
        int num = atoi(str.c_str());
        if (num >= 2 && num <= 10)
        {
            input->push_back(num);
        }
        else if (x == 'J')
        {
            input->push_back(11);
        }
        else if (x == 'Q')
        {
            input->push_back(12);
        }
        else if (x == 'K')
        {
            input->push_back(13);
        }
        else if (x == 'A')
        {
            input->push_back(1);
        }
    }
}

void printCards(const vector<char> cards)
{
    // LOCAL DICTIONARY
    int i;
    // ALGORITHM
    for (i = 0; i < cards.size(); i++)
    {
        cout << cards.at(i) << " ";
    }
    cout << endl;
}

void printList(const vector<double> list)
{
    // LOCAL DICTIONARY
    int i;
    // ALGORITHM
    for (i = 0; i < list.size(); i++)
    {
        cout << list.at(i) << " ";
    }
    cout << endl;
}

vector<double> generateRandom()
{
    // LOCAL DICTIONARY
    vector<double> output;
    double d;
    srand(time(NULL));
    // ALGORITHM

    for (int i = 0; i < 4; i++)
    {
        d = (rand() % 13) + 1;
        output.push_back(d);
    }
    return output;
}

void getInput(vector<double> *input)
{
    // LOCAL DICTIONARY
    char ans;
    char c1, c2, c3, c4;
    vector<char> cards;

    ifstream fin;

    string line;
    char temp;

    bool condition = true;

    int count;

    // ALGORITHM
    // input selection
    cout << "k : keyboard f : file r : random" << endl;
    cout << "Input? (k/f/r) (default: r) " << endl;
    cin >> ans;

    // from keyboard
    if (ans == 'k')
    {
        // loop until valid
        while (condition)
        {
            cout << "Enter 4 cards: ";
            cin >> c1;
            cin >> c2;
            cin >> c3;
            cin >> c4;
            if (checkCard(c1) && checkCard(c2) && checkCard(c3) && checkCard(c4))
            {
                condition = false;
            }
            else
            {
                cout << "Masukan tidak valid, harap diulangi!" << endl;
            }
        }

        // cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
        // input is put to a vector
        cards.push_back(c1);
        cards.push_back(c2);
        cards.push_back(c3);
        cards.push_back(c4);
        printCards(cards);
        // translate cards to integer
        translateCards(input, cards);
    }
    // from file
    else if (ans == 'f')
    {
        // open file
        fin.open("src/input.txt");
        // get line
        getline(fin, line);
        // cout << "here's the line: " << line << endl;
        fin.close();

        stringstream ss(line);
        count = 0;
        // check if the input is valid, if valid continue to put the input inside a vector, if not, exit, and only takes 4 input
        while (ss >> temp && condition && count <= 3)
        {
            if (!checkCard(temp))
            {
                cout << "Masukan tidak valid, ganti isi file!" << endl;
                condition = false;
            }
            cards.push_back(temp);
            count++;
        }
        if (condition)
        {
            printCards(cards);
            // translates card
            translateCards(input, cards);
        }
    }
    else
    {
        *input = generateRandom();
        printList(*input);
    }
}

double op(double num1, double num2, int opcode)
{
    if (opcode == 0)
    {
        return num1 + num2;
    }
    else if (opcode == 1)
    {
        return num1 - num2;
    }
    else if (opcode == 2)
    {
        return num1 * num2;
    }
    else if (opcode == 3)
    {
        if (num2 != 0)
        {
            return num1 / num2;
        }
        else
        {
            return -999;
        }
    }
    else
    {
        return 0;
    }
}

string stringbuilder(double num1, double num2, int opcode)
{
    // LOCAL DICTIONARY
    string solution = "(";
    int numtemp1 = num1;
    int numtemp2 = num2;
    // ALGORITHM
    solution += to_string(numtemp1);
    switch (opcode)
    {
    case 0:
        solution += " + ";
        break;
    case 1:
        solution += " - ";
        break;
    case 2:
        solution += " * ";
        break;
    case 3:
        solution += " / ";
        break;
    }
    solution += to_string(numtemp2);
    solution += ")";
    return solution;
}

string stringbuilderfromstring(string str1, double num2, int opcode)
{
    // LOCAL DICTIONARY
    string solution = "(";
    // int numtemp1 = num1;
    int numtemp2 = num2;
    // ALGORITHM
    solution += str1;
    switch (opcode)
    {
    case 0:
        solution += " + ";
        break;
    case 1:
        solution += " - ";
        break;
    case 2:
        solution += " * ";
        break;
    case 3:
        solution += " / ";
        break;
    }
    solution += to_string(numtemp2);
    solution += ")";
    return solution;
}

string stringbuilderfromstring(double num1, string str2, int opcode)
{
    // LOCAL DICTIONARY
    string solution = "(";
    int numtemp1 = num1;
    // int numtemp2 = num2;
    // ALGORITHM
    solution += to_string(numtemp1);
    switch (opcode)
    {
    case 0:
        solution += " + ";
        break;
    case 1:
        solution += " - ";
        break;
    case 2:
        solution += " * ";
        break;
    case 3:
        solution += " / ";
        break;
    }
    solution += str2;
    solution += ")";
    return solution;
}

string stringbuilderfromtwostring(string str1, string str2, int opcode)
{
    // LOCAL DICTIONARY
    string solution = "(";
    // ALGORITHM
    solution += str1;
    switch (opcode)
    {
    case 0:
        solution += " + ";
        break;
    case 1:
        solution += " - ";
        break;
    case 2:
        solution += " * ";
        break;
    case 3:
        solution += " / ";
        break;
    }
    solution += str2;
    solution += ")";
    return solution;
}

bool stringChecker(vector<string> list, string str)
{
    // LOCAL DICTIONARY

    // ALGORITHM
    // if (find(list.begin(), list.end(), str) != list.end()) {

    // }
    for (auto &x : list)
    {
        if (x == str)
        {
            return false;
        }
    }
    return true;
}

void solver(vector<double> list)
{
    // LOCAL DICTIONARY
    bool condition = true;

    int i, j, k, l, m, n, o, p, q, r, s, t, u;

    vector<string> solutions;

    vector<double> temp1, temp2, local;

    double num1, num2, num3, num4;
    double hasil1, hasil2, done;

    string solution;

    // const clock_t begintime = clock();

    // ALGORITHM
    local = list;
    auto t_start = chrono::high_resolution_clock::now();
    // pick card 1 from the list
    for (i = 0; i < 4; i++)
    {
        // cout << "i: " << i << endl;
        num1 = local.front();
        local.erase(local.begin());
        temp1 = local;
        // pick card 2 from the list
        for (j = 0; j < 3; j++)
        {
            // cout << "j: " << j << endl;
            num2 = temp1.front();
            temp1.erase(temp1.begin());
            temp2 = temp1;
            // operation on card 1 and card 2
            for (k = 0; k < 4; k++)
            {
                // cout << "k: " << k << endl;
                hasil1 = op(num1, num2, k);
                // cout << num1 << " " << k << " " << num2 << " = " << hasil1 << endl;
                // pick card 3 from the list
                for (l = 0; l < 2; l++)
                {
                    // cout << "l: " << l << endl;
                    num3 = temp2.front();
                    temp2.erase(temp2.begin());
                    // operation on (card 1 card 2) and card 3
                    for (m = 0; m < 4; m++)
                    {
                        // cout << "m: " << m << endl;
                        hasil2 = op(hasil1, num3, m);
                        // pick card 4 (last card on list)
                        num4 = temp2.front();
                        // operation on ((card 1 card 2) card 3) and card 4
                        for (n = 0; n < 4; n++)
                        {
                            // cout << "n: " << n << endl;
                            done = op(hasil2, num4, n);
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                solution = stringbuilderfromstring(solution, num3, m);
                                solution = stringbuilderfromstring(solution, num4, n);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
                            }
                        }
                        // can be commented out
                        // operation on card 4 and ((card 1 card 2) card 3)
                        for (n = 0; n < 4; n++)
                        {
                            // cout << "n: " << n << endl;
                            done = op(num4, hasil2, n);
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                solution = stringbuilderfromstring(solution, num3, m);
                                solution = stringbuilderfromstring(num4, solution, n);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
                            }
                        }
                    }
                    // operation on card 3 and (card 1 card 2)
                    for (m = 0; m < 4; m++)
                    {
                        // cout << "m: " << m << endl;
                        hasil2 = op(num3, hasil1, m);
                        // pick card 4 (last card on list)
                        num4 = temp2.front();
                        // operation on ((card 1 card 2) card 3) and card 4
                        for (n = 0; n < 4; n++)
                        {
                            // cout << "n: " << n << endl;
                            done = op(hasil2, num4, n);
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                solution = stringbuilderfromstring(num3, solution, m);
                                solution = stringbuilderfromstring(solution, num4, n);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
                            }
                        }
                        // can be commented out
                        // operation on card 4 and ((card 1 card 2) card 3)
                        for (n = 0; n < 4; n++)
                        {
                            // cout << "n: " << n << endl;
                            done = op(num4, hasil2, n);
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                solution = stringbuilderfromstring(solution, num3, m);
                                solution = stringbuilderfromstring(num4, solution, n);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
                            }
                        }
                    }
                    // pick card 4 (last card in list)
                    num4 = temp2.front();
                    // operation on card 3 and card 4 first
                    for (o = 0; o < 4; o++)
                    {
                        // cout << "m: " << m << endl;
                        hasil2 = op(num3, num4, o);
                        // operation on (card 1 card 2) and (card 3 card 4)
                        for (p = 0; p < 4; p++)
                        {
                            // cout << "n: " << n << endl;

                            done = op(hasil1, hasil2, p);
                            if (done == -999)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                // cout << "solution temp: " << solution << endl;
                                string solutiontemp = stringbuilder(num3, num4, o);
                                solution = stringbuilderfromtwostring(solution, solutiontemp, p);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
                            }
                        }
                    }
                    temp2.push_back(num3);
                }
            }

            // pick card 3 first before operation
            for (q = 0; q < 2; q++)
            {
                num3 = temp2.front();
                temp2.erase(temp2.begin());
                // card 4 is the last card on the list
                num4 = temp2.front();
                // operation on card 2 and card 3
                for (r = 0; r < 4; r++)
                {
                    hasil1 = op(num2, num3, r);
                    // operation on card 1 and (card 2 card 3)
                    for (s = 0; s < 4; s++)
                    {
                        hasil2 = op(num1, hasil1, s);
                        // operation on (card 1 (card 2 card 3)) and card 4
                        for (t = 0; t < 4; t++)
                        {
                            done = op(hasil2, num4, t);
                            if (done == -999)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num2, num3, r);
                                // cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(num1, solution, s);
                                solution = stringbuilderfromstring(solution, num4, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                } // (num1 .. num2) .. (num3 .. num4)
                            }
                        }
                        // can be commented out
                        // operation on card 4 and (card 1 (card 2 card 3))
                        for (t = 0; t < 4; t++)
                        {
                            done = op(num4, hasil2, t);
                            if (done == -999)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num2, num3, r);
                                // cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(num1, solution, s);
                                solution = stringbuilderfromstring(num4, solution, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                } // (num1 .. num2) .. (num3 .. num4)
                            }
                        }
                    }

                    // operation on (card 2 card 3) and card 4
                    for (s = 0; s < 4; s++)
                    {
                        hasil2 = op(hasil1, num4, s);
                        // operation on card 1 and ((card 2 card 3) card 4)
                        for (t = 0; t < 4; t++)
                        {
                            done = op(num1, hasil2, t);
                            if (done == -999)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num2, num3, r);
                                // cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(solution, num4, s);
                                solution = stringbuilderfromstring(num1, solution, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                } // (num1 .. num2) .. (num3 .. num4)
                            }
                        }
                        // can be commented out
                        // operation on ((card 2 card 3) card 4) and card 1
                        for (t = 0; t < 4; t++)
                        {
                            done = op(hasil2, num1, t);
                            if (done == -999)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num2, num3, r);
                                // cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(solution, num4, s);
                                solution = stringbuilderfromstring(solution, num1, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                } // (num1 .. num2) .. (num3 .. num4)
                            }
                        }
                    }
                }

                temp2.push_back(num3);
            }

            temp1.push_back(num2);
        }

        local.push_back(num1);
    }
    // cout << "executed in " << float(clock() - begintime) << endl;
    auto t_end = chrono::high_resolution_clock::now();
    double elapsed_time_ms = chrono::duration<double, std::milli>(t_end - t_start).count();
    cout << "executed in " << elapsed_time_ms << " ms" << endl;
    for (auto &x : solutions)
    {
        cout << x << endl;
    }
    cout << solutions.size();
}

int main()
{
    vector<double> ans;
    getInput(&ans);
    printList(ans);

    solver(ans);

    // TODO : fix kenapa -24 jadi 24 di kode
    // double a = op(2, 4, 1);
    // double b = op(a, 6, 1);
    // double c = op(3, b, 2);

    // cout << a << endl
    //      << b << endl
    //      << c << endl;

    // if (c == 24)
    // {
    //     cout << c << endl;
    // }

    return 0;
}