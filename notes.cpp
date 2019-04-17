#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <regex>
#include <cmath>
#include <fstream>
#include <algorithm>

using namespace std;

#define PI 3.141592653589793

const short LEFTMARGIN = 10;

int findHighest(int array[], int n)
{
    int hight = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > hight)
            hight = array[i];
    }
    return hight;
}

int findlowest(int array[], int n)
{
    int low = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] < low)
            low = array[i];
    }
    return low;
}

void printArr(int array[], int n)
{
    cout << endl
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << array[i] << " ";
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    return;
}

void loadArray(int array[], int n, int lower_bound, int upper_bound)
{
    for (int i = 0; i < n; i++)
        array[i] = (rand() % (upper_bound + 1 - lower_bound)) + lower_bound;

    return;
}

void displayArray(int array[], int n)
{
    cout << "\n";

    for (int i = 0; i < n; i++)
    {
        cout << setw(5) << right << array[i];
        if ((i + 1) % 10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
    return;
}

/*   ----  Temperature Conversion ---- */
double celsiusToFahrenheit(double c)
{
    return (c * 1.8) + 32;
}

double fahrenheitToCelsius(double f)
{
    return (f - 32) * (5.0 / 9.0);
}

/*   ----  Sortting ---- */

void doSwap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

void SelectionSort(int array[], int n)
{
    int minIndex;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i; j < n; j++)
        {
            if (array[j] < array[minIndex])
                doSwap(array[j], array[minIndex]);
        }
    }
    return;
}
void BubbleSort(int array[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1; j++)
            if (array[j] > array[j + 1])
                doSwap(array[j], array[j + 1]);
    return;
}

void BetterBubbleSort(int array[], int n)
{
    bool didSwap;
    int tmp;

    do
    {
        didSwap = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
                didSwap = true;
            }
        }

    } while (didSwap);
    return;
}
// ----------    trangles math stuff------
double DegreeseToRadians(double degree)
{
    return (degree * PI) / 180;
}
double RadiansToDegreese(double radians)
{
    return (radians * 180) / PI;
}

double LawOfSine(double &a, double &A, double &B)
{
    //returns side b
    return (a * sin((B * PI) / 180)) / (sin((A * PI) / 180));
}

double lawOfCosine(double &a, double &b, double &C)
{
    //return side C
    return sqrt((pow(a, 2) + pow(b, 2)) - (2 * a * b * cos((C * PI) / 180)));
}

double inverseLawOfSine(double &a, double &A, double &b)
{
    // return angle B;
    return (asin((b * sin((A * PI) / 180)) / a) * 180) / PI;
}
double inverseLawOfCosine(double &a, double &b, double &c)
{
    //return angles c;
   return acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c)) * 180 / PI;
}

void PrintTrangle(double &a, double &b, double &c, double &A, double &B, double &C)
{
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    cout << "c=" << c << endl
         << endl;

    cout << "A=" << A << endl;
    cout << "B=" << B << endl;
    cout << "C=" << C << endl;

    return;
}

//Needs some work.
//solves triangle from the info in a,b,c,A,B,C or returns false
bool solveTrangle(double &a, double &b, double &c, double &A, double &B, double &C)
{
    /*
       A
       |\
       | \
      c|  \ b
       |   \
       |____\
      B   a   C
 */
    //Law of sine
    if (a > 0 && A > 0 && B > 0)
    {
        C = (180 - (A + B));
        b = LawOfSine(a, A, B);
        c = LawOfSine(a, A, C);
        return true;
    }
    else if (a > 0 && A > 0 && C > 0)
    {
        B = (180 - (A + C));
        b = LawOfSine(a, A, B);
        c = LawOfSine(a, A, C);
        return true;
    }
    else if (b > 0 && B > 0 && A > 0)
    {
        C = (180 - (A + B));
        a = LawOfSine(b, B, A);
        c = LawOfSine(b, B, C);
        return true;
    }
    else if (b > 0 && B > 0 && C > 0)
    {
        A = (180 - (B + C));
        a = LawOfSine(b, B, A);
        c = LawOfSine(b, B, C);
        return true;
    }
    else if (c > 0 && C > 0 && A > 0)
    {
        B = (180 - (A + C));
        b = LawOfSine(c, C, B);
        a = LawOfSine(c, C, A);
        return true;
    }
    else if (c > 0 && C > 0 && B > 0)
    {
        A = (180 - (C + B));
        b = LawOfSine(c, C, B);
        a = LawOfSine(c, C, A);
        return true;
    }

    //inverseLaw of sine
    else if (a > 0 && A > 0 && b > 0)
    {
        B = inverseLawOfSine(a, A, b);
        C = (180 - (A + B));
        c = LawOfSine(a, A, C);
        return true;
    }
    else if (a > 0 && A > 0 && c > 0)
    {
        C = inverseLawOfSine(a, A, c);
        B = (180 - (A + C));
        b = LawOfSine(a, A, B);
        return true;
    }

    else if (b > 0 && B > 0 && a > 0)
    {
        A = inverseLawOfSine(b, B, a);
        C = (180 - (A + B));
        c = LawOfSine(b, B, C);
        return true;
    }
    else if (b > 0 && B > 0 && c > 0)
    {
        C = inverseLawOfSine(b, B, c);
        A = (180 - (C + B));
        a = LawOfSine(b, B, A);
        return true;
    }

    else if (c > 0 && C > 0 && a > 0)
    {
        A = inverseLawOfSine(c, C, a);
        B = (180 - (A + C));
        b = LawOfSine(c, C, B);
        return true;
    }
    else if (c > 0 && C > 0 && b > 0)
    {
        B = inverseLawOfSine(c, C, b);
        A = (180 - (C + B));
        a = LawOfSine(c, C, a);
        return true;
    }

    //Law Of Cosine
    else if (a > 0 && c > 0 && B > 0)
    {
        b = lawOfCosine(a, c, B);
        A = inverseLawOfCosine(b, c, a);
        B = inverseLawOfCosine(a, c, b);
        return true;
    }
    else if (b > 0 && c > 0 && A > 0)
    {
        b = lawOfCosine(b, c, A);
        B = inverseLawOfCosine(a, c, b);
        C = inverseLawOfCosine(a, b, c);
        return true;
    }
    else if (a > 0 && b > 0 && C > 0)
    {
        c = lawOfCosine(a, b, C);
        A = inverseLawOfCosine(b, c, a);
        B = inverseLawOfCosine(a, c, b);
        return true;
    }
    //know all sides inverseLawOfCosine
    else if (a > 0 && b > 0 && c > 0)
    {
        A = inverseLawOfCosine(b, c, a);
        B = inverseLawOfCosine(a, c, b);
        C = inverseLawOfCosine(a, b, c);
        return true;
    }

    return false;
}

// ------    misc functions ---------
int ThousandSeparator()
{
    int num = 0;
    const int MAX = 999999;
    const short LEFTMARGIN = 10;
    string str;

    // part 1
    cout << "\n\n\n";
    cout << setw(LEFTMARGIN) << "";
    cout << "Program Part 1 starts here\n";

    cout << setw(LEFTMARGIN) << "";
    cout << "Enter a nuber between 1 - 999999: ";
    cin >> num;

    if (num > MAX)
    {
        cout << endl;

        cout << setw(LEFTMARGIN) << "";
        cout << "You didn't enter a number between 1 and " << MAX << "." << endl;

        cout << setw(LEFTMARGIN) << "";
        cout << "Please try again." << endl;
        exit(0);
    }

    cout << setw(LEFTMARGIN) << "";
    cout << "The number is: ";
    if (1000 > num)
        cout << num << endl;
    else
    {
        cout << num / 1000 << ",";
        num = num - (1000 * (num / 1000));

        cout << num / 100;
        num = num - (100 * (num / 100));

        cout << num / 10;
        num = num - (10 * (num / 10));

        cout << num;
    }

    // Part 2
    cout << "\n\n\n";
    cout << setw(LEFTMARGIN) << "";
    cout << "Program Part 2 starts here\n";

    cout << setw(LEFTMARGIN) << "";
    cout << "Enter a nuber between 1 - 999999: ";
    cin >> str;

    if (str.length() > 6)
    {
        cout << endl;
        cout << setw(LEFTMARGIN) << "";
        cout << "You didn't enter a number between 1 and " << MAX << "." << endl;

        cout << setw(LEFTMARGIN) << "";
        cout << "Please try again." << endl;
        exit(0);
    }

    cout << setw(LEFTMARGIN) << "";
    cout << "The number is: ";
    if (str.length() > 3)
        str.insert(str.length() - 3, 1, ',');

    cout << str << endl;

    return 0;
}

int ReadingFromFile()
{
    const short LEFTMARGIN = 10;
    const string filename = "soccer.txt";
    string line = "";
    char c;

    ifstream infile;

    infile.open(filename);
    if (infile)
    {
        cout << "\n\n\n";
        while (infile >> c || !infile.eof())
            cout << c;

        cout << endl
             << endl;

        infile.close();
        infile.open(filename);

        while (getline(infile, line) || !infile.eof())
            cout << line;

        cout << endl
             << endl;

        infile.close();
        infile.open(filename);

        while (infile.get(c) || !infile.eof())
            cout << c;

        cout << endl
             << endl;

        infile.close();
    }
    else
    {
        cout << setw(LEFTMARGIN) << "";
        cout << "Can't open file " << filename << "quiting." << endl;
    }

    return 0;
}

// find the space  we need to print a number with no extra space
int spaceOfNumber(int i)
{
    int space = 0;

    while (i > 0)
    {
        i = i / 10;
        space++;
    }
    return space;
}

int Lab_3_03ColorMixer()
{
    string color1, color2, color3;
    const short LEFTMARGIN = 10;

    cout << "\n\n\n";

    cout << setw(LEFTMARGIN) << "";
    cout << "Primary colors are RED, BLUE, YELLOW" << endl;
    cout << setw(LEFTMARGIN) << "";
    cout << "_____________________________________" << endl
         << endl;

    cout << setw(LEFTMARGIN) << "";
    cout << "Enter two primary colors: ";
    cin >> color1 >> color2;

    //force all uppercase
    transform(color1.begin(), color1.end(), color1.begin(), ::toupper);
    transform(color2.begin(), color2.end(), color2.begin(), ::toupper);

    //check color1 and color2 for bad input
    if ((("RED" == color1) || ("BLUE" == color1) || ("YELLOW" == color1)) &&
        (("RED" == color2) || ("BLUE" == color2) || ("YELLOW" == color2)))
    {
        // the reds
        if ("RED" == color1)
        {
            if ("BLUE" == color2)
                color3 = "PURPLE";
            else if ("YELLOW" == color2)
                color3 = "ORANGE";
            else
                color3 = "RED";
        }
        // the blues
        else if ("BLUE" == color1)
        {
            if ("BLUE" == color2)
                color3 = "BLUE";
            else if ("YELLOW" == color2)
                color3 = "GREEN";
            else
                color3 = "PURPLE";
        }
        // the yellows
        else if ("YELLOW" == color1)
        {
            if ("BLUE" == color2)
                color3 = "GREEN";
            else if ("YELLOW" == color2)
                color3 = "YELLOW";
            else
                color3 = "ORANGE";
        }
        cout << setw(LEFTMARGIN) << "";
        cout << "Mixing " << color1 << " and " << color2 << " makes " << color3 << endl
             << endl;
    }
    else
    // bad input
    {
        cout << endl;
        cout << setw(LEFTMARGIN) << "";
        cout << "you didn't enter RED, BLUE, YELLOW for at least one color.\n";
        cout << setw(LEFTMARGIN) << "";
        cout << "Please try again.\n\n";
        exit(0);
    }

    return 0;
}
