#include <iostream> 
#include <iomanip> 
#include <limits> 
using namespace std;

int Find(int x, int A[], int n)
{
    int  j;
    for (j = 0; j < n; j++)
    {

        if (x == A[j])
        {
            return (j + 1);
        }
    }
    return 0;

}

void Calculated_Real_Average(int bound)
{
    int n = 50;
    double hits = 0;
    int Sequence[50];
    int steps;
    double total_steps = 0;
    double q = hits / 10000;
    double Calculated_Average;
    double Real_Average;
    double half_q = (q / 2);
    int bounds[] = { 30, 50, 80, 100, 1000, 10000, numeric_limits<int>::max() };

    for (int i = 0; i < 10000; i++)
    {
        for (int k = 0; k < n; k++)
            Sequence[k] = rand() % bound;
        if (Find(25, Sequence, n))
        {
            steps = (Find(25, Sequence, n));
            total_steps += steps;
            hits++;
        }

        else

            total_steps += n;

    }

    q = hits / 10000;
    half_q = (q / 2);
    Calculated_Average = n + (half_q)-(50 * (half_q));
    Real_Average = total_steps / 10000;

    if (bound == numeric_limits<int>::max())
        cout << setw(10) << "Infinite" << setw(18) << Calculated_Average << setw(20) << Real_Average << endl;
    else
        cout << setw(10) << bound << setw(18) << Calculated_Average << setw(20) << Real_Average << endl;
}


int main()
{
    cout << setw(10) << "Bound" << setw(25) << "Calculated Average\t" << setw(8) << "Real Average" << endl;
    cout << setw(10) << "-------------------------------------------------------------" << endl;

    Calculated_Real_Average(30);
    Calculated_Real_Average(50);
    Calculated_Real_Average(80);
    Calculated_Real_Average(100);
    Calculated_Real_Average(1000);
    Calculated_Real_Average(10000);
    Calculated_Real_Average(numeric_limits<int>::max());

    return 0;
}
