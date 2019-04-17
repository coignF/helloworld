#include "./notes.cpp"

using namespace std;


int main(int argc, char **argv)
{
      double a = 100, b = 100, c = 100, A = 0, B = 0, C = 0;

      solveTrangle(a, b, c, A, B, C);
      PrintTrangle(a, b, c, A, B, C);

      return 0;
}
