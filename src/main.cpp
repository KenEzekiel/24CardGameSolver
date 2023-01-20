#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

bool checkCard(string card)
{
    vector<string> listofcard = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    for (auto &x : listofcard)
    {
        if (card == x)
        {
            return true;
        }
    }
    return false;
}

void translateCards(vector<double> *input, const vector<string> cards)
{
    // LOCAL DICTIONARY

    // ALGORITHM
    for (auto &x : cards)
    {
        if (x == "2")
        {
            input->push_back(2);
        }
        else if (x == "3")
        {
            input->push_back(3);
        }
        else if (x == "4")
        {
            input->push_back(4);
        }
        else if (x == "5")
        {
            input->push_back(5);
        }
        else if (x == "6")
        {
            input->push_back(6);
        }
        else if (x == "7")
        {
            input->push_back(7);
        }
        else if (x == "8")
        {
            input->push_back(8);
        }
        else if (x == "9")
        {
            input->push_back(9);
        }
        else if (x == "10")
        {
            input->push_back(10);
        }
        else if (x == "J")
        {
            input->push_back(11);
        }
        else if (x == "Q")
        {
            input->push_back(12);
        }
        else if (x == "K")
        {
            input->push_back(13);
        }
        else if (x == "A")
        {
            input->push_back(1);
        }
    }
}

void printCards(const vector<string> cards)
{
    // LOCAL DICTIONARY
    int i;
    // ALGORITHM
    for (auto &x : cards)
    {
        std::cout << x << " ";
    }
    std::cout << endl;
}

void printList(const vector<double> list)
{
    // LOCAL DICTIONARY
    int i;
    // ALGORITHM
    for (i = 0; i < list.size(); i++)
    {
        std::cout << list.at(i) << " ";
    }
    std::cout << endl;
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
    string c1, c2, c3, c4;
    vector<string> cards;

    ifstream fin;

    string line;
    string temp;

    bool condition = true;

    int count;

    // ALGORITHM
    // input selection
    std::cout << "k : keyboard f : file r : random" << endl;
    std::cout << "Input? (k/f/r) (default: r) " << endl;
    cin >> ans;

    // from keyboard
    if (ans == 'k')
    {
        // loop until valid
        while (condition)
        {
            std::cout << "Enter 4 cards: ";
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
                std::cout << "Masukan tidak valid, harap diulangi!" << endl;
            }
        }

        // std::cout << c1 << " " << c2 << " " << c3 << " " << c4 << endl;
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
        // std::cout << "here's the line: " << line << endl;
        fin.close();

        stringstream ss(line);
        count = 0;
        // check if the input is valid, if valid continue to put the input inside a vector, if not, exit, and only takes 4 input
        while (ss >> temp && condition && count <= 3)
        {
            if (!checkCard(temp))
            {
                std::cout << "Masukan tidak valid, ganti isi file!" << endl;
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
        return -999;
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

    char save;

    string filename;

    // const clock_t begintime = clock();

    // ALGORITHM
    local = list;
    auto t_start = chrono::high_resolution_clock::now();
    // pick card 1 from the list
    for (i = 0; i < 4; i++)
    {
        // std::cout << "i: " << i << endl;
        num1 = local.front();
        local.erase(local.begin());
        temp1 = local;
        // pick card 2 from the list
        for (j = 0; j < 3; j++)
        {
            // std::cout << "j: " << j << endl;
            num2 = temp1.front();
            temp1.erase(temp1.begin());
            temp2 = temp1;
            // operation on card 1 and card 2
            for (k = 0; k < 4; k++)
            {
                // std::cout << "k: " << k << endl;
                hasil1 = op(num1, num2, k);
                // std::cout << num1 << " " << k << " " << num2 << " = " << hasil1 << endl;
                // pick card 3 from the list
                for (l = 0; l < 2; l++)
                {
                    // std::cout << "l: " << l << endl;
                    num3 = temp2.front();
                    temp2.erase(temp2.begin());
                    // operation on (card 1 card 2) and card 3
                    for (m = 0; m < 4; m++)
                    {
                        // std::cout << "m: " << m << endl;
                        hasil2 = op(hasil1, num3, m);
                        // pick card 4 (last card on list)
                        num4 = temp2.front();
                        // operation on ((card 1 card 2) card 3) and card 4
                        for (n = 0; n < 4; n++)
                        {
                            // std::cout << "n: " << n << endl;
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
                            // std::cout << "n: " << n << endl;
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
                        // std::cout << "m: " << m << endl;
                        hasil2 = op(num3, hasil1, m);
                        // pick card 4 (last card on list)
                        num4 = temp2.front();
                        // operation on (card 3 (card 1 card 2)) and card 4
                        for (n = 0; n < 4; n++)
                        {
                            // std::cout << "n: " << n << endl;
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
                        // operation on card 4 and (card 3 (card 1 card 2))
                        for (n = 0; n < 4; n++)
                        {
                            // std::cout << "n: " << n << endl;
                            done = op(num4, hasil2, n);
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                solution = stringbuilderfromstring(num3, solution, m);
                                solution = stringbuilderfromstring(num4, solution, n);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    // std::cout << num4 << " " << n << " " << hasil2 << " " << num1 << k << num2 << m << num3 << endl;
                                    // std::cout << solution << endl;
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
                        // std::cout << "m: " << m << endl;
                        hasil2 = op(num3, num4, o);
                        // operation on (card 1 card 2) and (card 3 card 4)
                        for (p = 0; p < 4; p++)
                        {
                            // std::cout << "n: " << n << endl;

                            done = op(hasil1, hasil2, p);
                            if (done == -999)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                // std::cout << "solution temp: " << solution << endl;
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
                                // std::cout << "solution temp: " << solution << endl;
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
                                // std::cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(num1, solution, s);
                                solution = stringbuilderfromstring(num4, solution, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
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
                                // std::cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(solution, num4, s);
                                solution = stringbuilderfromstring(num1, solution, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
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
                                // std::cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(solution, num4, s);
                                solution = stringbuilderfromstring(solution, num1, t);
                                if (stringChecker(solutions, solution))
                                {
                                    // solution += " = ";
                                    // solution += to_string(done);
                                    solutions.push_back(solution);
                                }
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
    // std::cout << "executed in " << float(clock() - begintime) << endl;
    auto t_end = chrono::high_resolution_clock::now();
    double elapsed_time_ms = chrono::duration<double, milli>(t_end - t_start).count();
    std::cout << "executed in " << elapsed_time_ms << " ms" << endl;

    std::cout << solutions.size() << " solutions found" << endl;

    for (auto &x : solutions)
    {
        std::cout << x << endl;
    }

    std::cout << "save it to a file? (y/n) " << endl;

    cin >> save;

    if (save == 'y')
    {
        filename += "test/";
        for (auto &x : list)
        {
            if (x == 1)
            {
                filename += "A ";
            }
            else if (x == 11)
            {
                filename += "J ";
            }
            else if (x == 12)
            {
                filename += "Q ";
            }
            else if (x == 13)
            {
                filename += "K ";
            }
            else
            {
                int num = x;
                filename += to_string(num);
                filename += " ";
            }
        }
        filename += ".txt";
        ofstream fileout(filename);

        for (auto &x : solutions)
        {
            fileout << x;
            fileout << "\n";
        }

        fileout << solutions.size();

        fileout << " solutions";

        fileout.close();
    }
}

int main()
{
    vector<double> ans;
    getInput(&ans);
    printList(ans);

    solver(ans);

    // double a = op(3, 2, 1);
    // double b = op(a, 6, 3);
    // double c = op(4, b, 2);

    // std::cout << a << endl
    //      << b << endl
    //      << c << endl;

    // if (c == 24)
    // {
    //     std::cout << c << endl;
    // }

    return 0;
}

// TODO : run.bat, laporan etc + sesuain lg sm spek + output ke file