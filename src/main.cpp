#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool checkCard(char card)
{
    return (card == 'A') || (card == 'J') || (card == 'Q') || (card == 'K') || ((card - '0') >= 2 && (card - '0') <= 10);
}

void translateCards(vector<float> *input, const vector<char> cards)
{
    // LOCAL DICTIONARY
    int num;
    // ALGORITHM
    for (auto &x : cards)
    {
        if (x == 'A')
        {
            input->push_back(1);
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
        else if ((x - '0') >= 2 && (x - '0') <= 10)
        {
            num = x - '0';
            input->push_back(num);
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

void printList(const vector<float> list)
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

// TODO : Generate random input

void getInput(vector<float> *input)
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
    cout << "Input from keyboard? (y/n)" << endl;
    cin >> ans;

    // from keyboard
    if (ans == 'y')
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
    else
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
}

float op(float num1, float num2, int opcode)
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
        if (num2 == 0)
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

string stringbuilder(float num1, float num2, int opcode)
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

string stringbuilderfromstring(string str1, float num2, int opcode)
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

string stringbuilderfromstring(float num1, string str2, int opcode)
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

// TODO : Time of execution

void solver(vector<float> list)
{
    // LOCAL DICTIONARY
    bool condition = true;

    int i, j, k, l, m, n, o, p, q, r, s, t, u;

    vector<string> solutions;

    vector<float> temp1, temp2, local;

    int num1, num2, num3, num4, hasil1, hasil2, hasil2alt, done;

    string solution;

    // ALGORITHM
    local = list;
    //
    for (i = 0; i < 4; i++)
    {
        cout << "i: " << i << endl;
        num1 = local.front();
        local.erase(local.begin());
        temp1 = local;
        for (j = 0; j < 3; j++)
        {
            // cout << "j: " << j << endl;
            num2 = temp1.front();
            temp1.erase(temp1.begin());
            temp2 = temp1;
            for (k = 0; k < 4; k++)
            {
                // cout << "k: " << k << endl;
                hasil1 = op(num1, num2, k);
                // cout << num1 << " " << k << " " << num2 << " = " << hasil1 << endl;
                for (l = 0; l < 2; l++)
                {
                    // cout << "l: " << l << endl;
                    num3 = temp2.front();
                    temp2.erase(temp2.begin());
                    for (m = 0; m < 4; m++)
                    {
                        // cout << "m: " << m << endl;
                        hasil2 = op(hasil1, num3, m);
                        num4 = temp2.front();
                        for (n = 0; n < 4; n++)
                        {
                            // cout << "n: " << n << endl;
                            done = op(hasil2, num4, n);
                            if (done == 24)
                            {
                                solution = stringbuilder(num1, num2, k);
                                solution = stringbuilderfromstring(solution, num3, m);
                                solution = stringbuilderfromstring(solution, num4, n);
                                solutions.push_back(solution);
                                // ((num1 .. num2) .. num3) .. num4
                            }
                        }
                    }
                    num4 = temp2.front();
                    for (o = 0; o < 4; o++)
                    {
                        // cout << "m: " << m << endl;
                        hasil2 = op(num3, num4, o);
                        // cout << hasil1 << " <- 1 2 -> " << hasil2 << endl;
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
                                solutions.push_back(solution);
                                // (num1 .. num2) .. (num3 .. num4)
                            }
                        }
                    }
                    temp2.push_back(num3);
                }
            }

            for (q = 0; q < 2; q++)
            {
                num3 = temp2.front();
                temp2.erase(temp2.begin());
                num4 = temp2.front();
                for (r = 0; r < 4; r++)
                {
                    hasil1 = op(num2, num3, r);
                    for (s = 0; s < 4; s++)
                    {
                        hasil2 = op(num1, hasil1, s);
                        for (t = 0; t < 4; t++)
                        {
                            done = op(hasil2, num4, t);
                            if (done == -1)
                            {
                                continue;
                            }
                            if (done == 24)
                            {
                                solution = stringbuilder(num2, num3, r);
                                // cout << "solution temp: " << solution << endl;
                                solution = stringbuilderfromstring(num1, solution, s);
                                solution = stringbuilderfromstring(solution, num4, t);
                                solutions.push_back(solution);
                                // (num1 .. num2) .. (num3 .. num4)
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
    for (auto &x : solutions)
    {
        cout << x << endl;
    }
    cout << solutions.size();
}

int main()
{
    vector<float> ans;
    getInput(&ans);
    printList(ans);

    solver(ans);

    return 0;
}