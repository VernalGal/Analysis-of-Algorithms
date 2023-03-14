#include <iostream> 
#include <ctime> 
#include <iomanip> 
#define max 60 
using namespace std;


//Recursive Algorithm 
int FiboR(int n)
{
    if (n == 0 || n == 1)
        return (n);
    else
        return (FiboR(n - 1) + FiboR(n - 2));
}

//Non-Recursive Algorithm 
int FiboNR(int n)
{
    int F[max];
    F[0] = 0; F[1] = 1;
    for (int i = 2; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
    }
    return (F[n]);
}

//Modified Recursive Algorithm 
int MODFibR(int n, int F[max])
{
    if (n == 0 || n == 1)
    {
        return(n);
    }
    else if (F[n - 1] > -1 && F[n - 2] > -1)
    {
        
        {
            F[n] = F[n - 1] + F[n - 2];
            return F[n];
        }
    }
    else
        return (MODFibR(n - 1, F)) + MODFibR(n - 2, F);
}

int main() {
    clock_t start_time, end_time;
    double time1, time2, time3;
    int fiboValue{};

    cout << "\tFibonacci Time Analysis (Recursive vs. Modified Recursive vs. Non-Recursive)" << endl;
    cout << "Integer" << setw(20) << "FiboR (seconds)" << setw(20) << "MODFibR (seconds)" << setw(20) << "FibNR (seconds)" << setw(20) << "Fibo-value" << endl;

    for (int i = 0; i <= 60; i += 5)
    {
        int F[max];
        int fiboValue = 0;
        for (int j = 0; j <= 60; j++)
        {
            F[j] = -1;
        }
        fiboValue = MODFibR(i, F);
        cout << setw(4) << i;

        start_time = clock();
        FiboR(i);
        end_time = clock();
        clock_t time1 = end_time - start_time;


        start_time = clock();
        MODFibR(i, F);
        end_time = clock();
        clock_t time2 = end_time - start_time;

        start_time = clock();
        FiboNR(i);
        end_time = clock();
        clock_t time3 = end_time - start_time;

        cout << setw(18) << setprecision(3) << fixed << ((double)time1) << setw(18) << setprecision(3) << fixed << ((double)time2) << setw(20) << setprecision(3) << fixed << ((double)time3) << setw(25) << fiboValue << endl;;

    }

    return 0;
}