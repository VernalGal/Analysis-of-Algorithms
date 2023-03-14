#include <iostream>
#include <iomanip>

using namespace std;

const long max_value = 250000;
int x[max_value];
int y[max_value];
int z[max_value];
int b[max_value];
int c[max_value];



void Fixheap(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])

        largest = left;

    if (right < n && arr[right] > arr[largest])

        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        Fixheap(arr, n, largest);
    }
}



void HeapSort(int A[], int n) {
    int c[max_value];
    int temp;
    for (int i = (n / 2) - 1; i >= 0; i--)
        Fixheap(A, n, i);
    for (int i = n - 1; i >= 0; i--) {
        swap(A[0], A[i]);
        Fixheap(A, i, 0);
    }
}




void InsertionSort(int A[], int n)
{
    int temporary;
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while (A[j] < A[j - 1])
        {
            temporary = A[j];
            A[j] = A[j - 1];
            A[j - 1] = temporary;
            j--;
        }
    }
}


void Merge(int A[], int first, int mid, int last)
{
    int i = first, j = mid + 1, p;
    int    k = first;

    while ((i <= mid) && (j <= last))
    {
        if (A[i] <= A[j])
        {
            b[k] = A[i];
            i++;
        }

        else
        {
            b[k] = A[j];
            j++;
        }
        k++;
    }

    if (i > mid)
    {
        for (p = j; p <= last; p++)
        {
            b[k] = A[p];
            k++;
        }
    }
    else
    {
        for (p = i; p <= mid; p++)
        {
            b[k] = A[p];
            k++;
        }
    }
    for (i = first; i <= last; i++)
    {
        A[i] = b[i];
    }
}



void MergeSort(int A[], int first, int last)
{

    int mid;
    if (first < last)
    {
        mid = (first + last) / 2;
        MergeSort(A, first, mid);
        MergeSort(A, mid + 1, last);
        Merge(A, first, mid, last);
    }
}

void timeTook(int num)
{
    int bound = 5000000, ramdom;
    int Sequence[max_value];

    for (int i = 0; i < num; i++)
    {
        ramdom = rand() % bound;
        Sequence[i] = ramdom;
    }

    cout << setw(10) << num << fixed;
    double t1, t2, t3, t4, t5, t6;

    for (int i = 0; i < num; i++)
    {
        x[i] = Sequence[i];
        y[i] = Sequence[i];
        z[i] = Sequence[i];
    }

    t1 = clock();
    HeapSort(x, num);
    t2 = clock();
    cout << setw(14) << setprecision(3) << (t2 - t1) / CLOCKS_PER_SEC;
    t3 = clock();
    InsertionSort(y, num);
    t4 = clock();
    cout << setw(19) << setprecision(3) << (t4 - t3) / CLOCKS_PER_SEC;
    t5 = clock();//
    MergeSort(z, 0, num - 1);
    t6 = clock();
    cout << setw(19) << setprecision(3) << (t6 - t5) / CLOCKS_PER_SEC;

    if ((t2 - t1) < (t4 - t3) && (t2 - t1) < (t6 - t5))
    {
        cout << setw(20) << "HEAP" << endl;
    }
    else if ((t4 - t3) < (t2 - t1) && (t4 - t3) < (t6 - t5))
    {
        cout << setw(20) << "INSERTION" << endl;
    }
    else if ((t6 - t5) < (t2 - t1) && (t6 - t5) < (t4 - t3))
    {
        cout << setw(20) << "MERGE" << endl;
    }
    else if ((t2 - t1) == (t6 - t5) && (t2 - t1) < (t4 - t3))
    {
        cout << setw(27) << "HEAP & MERGE" << endl;
    }
    else
    {
        cout << setw(20) << "ERROR" << endl;
    }
}



int main()
{
    cout << setw(6) << "Input Length\t" << setw(8) << "Heap Sort(sec.)\t" << setw(20) << "Insertion Sort(sec.)";
    cout << setw(20) << "Merge Sort(sec.)\t" << setw(14) << "Best Time\t" << endl;

    int dataNeed[] = { 1000, 10000, 25000, 50000, 150000, 250000 };
    int value = *(&dataNeed + 1) - dataNeed;
    long length;

    for (int i = 0; i < value; i++) {

        length = dataNeed[i];

        timeTook(length);

    }
    return 0;
}
