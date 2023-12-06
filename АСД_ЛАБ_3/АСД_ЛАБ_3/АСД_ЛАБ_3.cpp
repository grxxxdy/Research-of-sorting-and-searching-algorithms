#include <iostream>

using namespace std;

int bubbleSort(int* array, const int size)                  // 1.2
{
    int k;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                k = array[j];
                array[j] = array[j + 1];
                array[j + 1] = k;
            }
        }
    }
    return array[size];
}

int linSearch(int* array, const int size, int n)            // 1.3
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == n)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int* array, const int size, int n)         // 1.4
{
    int min = 0, max = size - 1, middle;

    while (min <= max)
    {
        middle = (min + max) / 2;

        if (n > array[middle])
        {
            min = middle + 1;
            middle = (min + max) / 2;
        }
        else if (n < array[middle])
        {
            max = middle - 1;
            middle = (min + max) / 2;
        }
        else
        {
            return middle;
        }
    }

    return -1;
}

bool test(int* array, const int size, int number, int number1)      //1.5
{
    for (int i = 0; i < 10; i++)
    {
        if (linSearch(array, size, number) != binarySearch(array, size, number1))
        {
            return false;
        }
    }

    return true;
}

void task1()
{
    const int size = 1000;                                      // 1.1
    int array[size];

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 2001 - rand() % 2001;
        cout << "a(" << i + 1 << ") = " << array[i] << "\t";

        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;


    cout << "Array sorted by size: " << endl;       //1.2

    bubbleSort(array, size);

    for (int i = 0; i < size; i++)
    {
        cout << "a(" << i + 1 << ") = " << array[i] << "\t";

        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }

    cout << endl;

    int number, result;                                         // 1.3 (лінійний)

    cout << "Enter a number whose index needs to be found: ";
    cin >> number;

    clock_t startTime = clock();

    for (int i = 0; i < 100000; i++)
    {
        result = linSearch(array, size, number);
    }

    clock_t endTime = clock();

    double seconds = (double(endTime - startTime)) / CLOCKS_PER_SEC;


    if (result == -1)
    {
        cout << "The number " << number << " is not in the array." << endl;
    }
    else
    {
        cout << "The number " << number << " is in the array by index " << result + 1 << endl;
    }

    cout << "Runtime of the linear search: " << seconds << " seconds" << endl;



    int number1, result1;                                       // 1.4 (бінарний)

    cout << "Enter a number whose index needs to be found: ";
    cin >> number1;

    clock_t startTime1 = clock();

    for (int i = 0; i < 100000; i++)
    {
        result1 = binarySearch(array, size, number1);
    }

    clock_t endTime1 = clock();

    double seconds1 = (double(endTime1 - startTime1)) / CLOCKS_PER_SEC;

    if (result1 == -1)
    {
        cout << "The number " << number1 << " is not in the array." << endl;
    }
    else
    {
        cout << "The number " << number1 << " is in the array by index " << result1 + 1 << endl;
    }

    cout << "Runtime of the binary search: " << seconds1 << " seconds" << endl;



    if (!test(array, size, number, number1))        // 1.5
    {
        cout << "Error!" << endl;
    }
}

int shuffle(int* arr, const int size)				// 2.2
{
    int randIndex, k;

    for (int i = size - 1; i > 0; i--)
    {
        randIndex = rand() % (i + 1);

        k = arr[i];
        arr[i] = arr[randIndex];
        arr[randIndex] = k;
    }

    return arr[size];
}

int sort(int* arr, const int size)					// 2.3
{
    int i, k;

    for (int border = 1; border < size; border++)
    {
        i = border - 1;

        while (i >= 0 && ((arr[i] % 10) >= ((arr[i + 1]) % 10)))
        {
            k = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = k;

            if ((arr[i] % 10) == ((arr[i + 1]) % 10) && arr[i] > arr[i + 1])
            {
                k = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = k;
            }

            i--;
        }
    }

    return arr[size];
}

void task2()
{
    const int N = 200;								// 2.1
    int array[N];

    for (int i = 0; i < N; i++)
    {
        array[i] = i + 1;
        cout << "a(" << i + 1 << ") = " << array[i] << "\t";

        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }

    }

    cout << "\nShuffled array: " << endl;		// 2.2

    shuffle(array, N);

    for (int i = 0; i < N; i++)
    {
        cout << "a(" << i + 1 << ") = " << array[i] << "\t";

        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }


    cout << "\nSorted by last digit in ascending order array: " << endl;	//2.3

    sort(array, N);

    for (int i = 0; i < N; i++)
    {
        cout << "a(" << i + 1 << ") = " << array[i] << "\t";

        if ((i + 1) % 5 == 0)
        {
            cout << endl;
        }
    }
}

double searchMin(double lBorder, double rBorder, double iter, double a, double b)
{
    double mid1, mid2, f1, f2;

    for (int i = 0; i < iter; i++)
    {
        mid1 = (2 * lBorder + rBorder) / 3.0;
        mid2 = (lBorder + 2 * rBorder) / 3.0;

        f1 = mid1 * mid1 + a * mid1 + b;
        f2 = mid2 * mid2 + a * mid2 + b;

        if (f1 < f2)
        {
            rBorder = mid2;
        }
        else
        {
            lBorder = mid1;
        }
    }

    return (lBorder + rBorder) / 2.0;
}

void task3()
{
    double iterations, a, b, leftBorder, rightBorder;

    cout << "f(x) = x^2 + ax + b" << endl;

    cout << "Enter the `a` value: ";
    cin >> a;

    cout << "Enter the `b` value: ";
    cin >> b;

    cout << "Enter the number of iterations to perforn to archieve the necessary accuracy : ";
    cin >> iterations;

    cout << "Enter the left border: ";			// -100
    cin >> leftBorder;

    cout << "Enter the right border: ";			// 100
    cin >> rightBorder;

    cout << "Minimum of the function = " << searchMin(leftBorder, rightBorder, iterations, a, b) << endl;
}


int main()
{
    srand(time(NULL));

    int choice;
    
    while (true)
    {
        cout << "Enter task number (1-3) or 0 to exit the program" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            return 0;
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        default:
            cout << "Enter the correct number (1-3)" << endl;
            break;
        }
    }
    

}

