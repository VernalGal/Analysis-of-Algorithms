#include<iostream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int InsertionMod(int A[], int n) // in reality the elements to be sorted are indexed from
{// index 1 to index n
    int i, j, temp, count = 0;
    A[0] = -32768; //smallest possible integer using 2 bytes integer representation
    for (i = 1; i <= n; i++) {
        j = i;
        while (A[j] < A[j - 1]) { // swap (1)
            temp = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temp;
            j--;
            count++;
        }
    }
    return count;
}

int Calculated_Real_Average(int n)
{
    double bound = 100000;
    double total_steps = 0;
    double Calculated_Average = ((n * n) / 4) + ((3 * n) / 4);
    double Real_Average;
    int sequence[n];
    int i;
    for (int i = 0; i < 100000; i++)
    {
        for (int k = 0; k < n; k++)
        {
            sequence[k] = rand() % -100000 + bound;
        }
        total_steps += InsertionMod(sequence, n);
    }

    Real_Average = total_steps / bound;
    cout << setw(10) << n << setw(18) << Calculated_Average << setw(20) << Real_Average << endl;
    return 0;
}

int main()
{
    cout << setw(10) << "Input Size\t" << setw(25) << "Calculated Average\t" << setw(8) << "Real Average" << endl;
    cout << setw(10) << "-------------------------------------------------------------" << endl;
    Calculated_Real_Average(100);
    Calculated_Real_Average(500);
    Calculated_Real_Average(1000);
    Calculated_Real_Average(2500);
    Calculated_Real_Average(3000);
    Calculated_Real_Average(3500);
    return 0;
}