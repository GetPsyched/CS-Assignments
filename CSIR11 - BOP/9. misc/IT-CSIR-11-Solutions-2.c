#include <stdio.h>
#include <stdlib.h>
// defining prototypes
void *malloc(size_t size);
void free(void *ptr);

// sum 100 sudents
void sumStudents()
{
    int n = 100;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int marks;
        scanf("%d", &marks);
        sum += marks;
    }
    printf("sum of %d students is %d", n, sum);
}
// Q.2 matrix multiplication
#define r1 3
#define r2 2
#define c1 2
#define c2 2

// vector multiply then sum
int vmul(int *a, int *b, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (a[i] * b[i]);
    }
    return sum;
}
int *getColVector(int *matrix, int colIndex, int nRows, int nCols)
{
    int *rVec = malloc(sizeof(int) * nRows);
    for (int i = 0; i < nRows; i++)
    {
        rVec[i] = matrix[i * nCols + colIndex];
    }
    return rVec;
}
void printMatrix(int *matrix, int nrow, int ncol)
{
    for (int i = 0; i < nrow; i++)
    {
        for (int j = 0; j < ncol; j++)
        {
            printf("| %d ", matrix[i * ncol + j]);
        }
        printf("|\n");
    }
}
void matmul()
{
    int m1[r1][c1] = {{2, 3}, {2, 3}, {2, 3}};
    int m2[r2][c2] = {{2, 3}, {2, 3}};
    int prodM[r1][c2];
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            int *rVec = getColVector((int *)m2, j, r2, c2);
            prodM[i][j] = vmul(m1[i], rVec, r2);
            free(rVec);
        }
    }
    printMatrix((int *)prodM, r1, c2);
}

// Q.4 Structure call by value and reference
struct Car
{
    float price;
    char *model;
};
int printCarbyValue(struct Car car)
{
    printf("price is %f and model is %s", car.price, car.model);
}
int printCarbyRef(struct Car *car)
{
    printf("price is %f and model is %s", car->price, car->model);
}

// Q.6 Copy file from A1 to A2
void cpFile(char *from, char *to)
{
    FILE *fromFp;
    FILE *toFp;
    fromFp = fopen(from, "r");
    toFp = fopen(to, "w");
    fseek(fromFp, 0, SEEK_END);
    int size = ftell(fromFp);
    char *fcontent = (char *)malloc(sizeof(char) * size);
    fseek(fromFp, 0, SEEK_SET);
    fread(fcontent, 1, size, fromFp);
    fwrite(fcontent, 1, size, toFp);
    fclose(fromFp);
    fclose(toFp);
    free(fcontent);
}

int testCpFile()
{
    cpFile("a1.txt", "a2.txt");
    return 0;
}

// search Array for a item
int getElementIndex(int *arr, int element, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}
// binary search for sorted array
int getBinIndex(int *arr, int element, int len)
{
    unsigned int low = 0;
    unsigned int high = len - 1;
    int mid;
    do
    {
        mid = (high + low) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] > element)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    } while (low <= high);

    return -1;
}
int testGetBinIndex(void)
{
    int arr[] = {1, 6, 8, 9, 12, 16, 19};
    printf("index at %d", getBinIndex(arr, 16, 7));
    return 0;
}

// inplace sorting
// helper function to swap the element in array
void swap(int *arr, int fi, int si)
{
    int temp = arr[fi];
    arr[fi] = arr[si];
    arr[si] = temp;
}
// bubble sort
void bubbleSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len - i; j++)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr, j - 1, j);
            }
        }
    }
}
// insertion sort
void insertionSort(int *arr, int len)
{
    for (int i = 1; i < len; i++)
    {
        int j = i - 1;
        int cur = arr[i];
        while (cur < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
}
// merge sort
int *merge(int *left, int ll, int *right, int lr)
{
    int *mergedArr = (int *)malloc(sizeof(int) * (ll + lr));
    int l = 0;
    int r = 0;
    while (l < ll && r < lr)
    {
        if (left[l] < right[r])
        {
            mergedArr[l + r] = left[l];
            l++;
        }
        else
        {
            mergedArr[l + r] = right[r];
            r++;
        }
    }
    while (l < ll)
    {
        mergedArr[l + r] = left[l];
        l++;
    }
    while (r < lr)
    {
        mergedArr[l + r] = right[r];
        r++;
    }
    return mergedArr;
}
int *mergeSort(int *arr, int low, int high)
{
    if (low == high)
    {
        return &arr[low];
    }
    int mid = (high + low) / 2;
    int *left = mergeSort(arr, low, mid);
    int *right = mergeSort(arr, mid + 1, high);
    return merge(left, mid - low + 1, right, high - mid);
}

int testSort()
{
    int n = 7;
    int arr[] = {3, 1, 5, 4, 2, 1, 9};
    // bubbleSort(arr,6);
    // printf("Resultant array after bubble sort :");
    // insertionSort(arr, n);
    // printf("Resultant array after insertion sort :");
    int *arrr = mergeSort(arr, 0, n - 1);
    printf("Resultant array after merge sort :");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arrr[i]);
    }

    return 0;
}

// Q23 1 to 100
void foo()
{
    for (int i = 1; i < 101; i++)
    {
        printf("%d", i);
    }
}
// Q 24
void printTable()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 11; i++)
    {
        printf("%d x %d = %d \n", n, i, n * i);
    }
}
// Q25
void printSeries()
{
    int a, d, n;
    scanf("%d%d%d", &a, &d, &n);
    for (int i = 1; i <= n; i++)
    {
        printf("%d", a + (i - 1) * d);
    }
}
// 26 a^b
void powpow()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int prod = 1;
    for (int i = 0; i < b; i++)
    {
        prod *= a;
    }
    printf("%d^%d is %d", a, b, prod);
}
// 27 factorial
void fact()
{
    int a = 0, b = 1;
    int n;
    int fact;
    scanf("%d", &n);
    if (n == 1)
    {
        fact = a;
    }
    else if (n == 2)
    {
        fact = b;
    }
    else
    {

        for (int i = 0; i < n - 2; i++)
        {
            fact = a + b;
            a = b;
            b = fact;
        }
    }
    printf("%d", fact);
}
// Q28 is prime?
int isPrime(int n)
{
    // looping to sqrt(n) would be enough
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 1;
        }
    }
    return 0;
}
// Q29 palidrome check
int isPalidrome(int a)
{
    if (getReverseNumber(a) == a)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// Q19 sort 3 nmber
void threeSort()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int *arr[] = {a, b, c};
    bubbleSort(arr, 3);
    for (int i = 0; i < 3; i++)
    {
        printf("%d", arr[i]);
    }
}
// Q20 quadrant of 2d coor
int getQuad(int x, int y)
{
    if (x < 0 && y < 0)
    {
        return 4;
    }
    else if (x < 0 && y > 0)
    {
        return 2;
    }
    else if (x > 0 && y > 0)
    {
        return 1;
    }
    else
    {
        return 3;
    }
}
// Q 21 reverse a number
int getReverseNumber(int n)
{
    int reverse = 0;
    // scanf("%d", &n);
    while (n > 0)
    {
        int lastDigit = (n % 10);
        reverse = reverse * 10 + lastDigit;
        n = n / 10;
    }
    return reverse;
}

// Q22 ranking student
void rankStudent(int marks)
{
    if (marks > 75)
    {
        printf("with honour");
    }
    else if (marks > 60)
    {
        printf("with 2nd div");
    }
    else if (marks > 45)
    {
        printf("with 3rd div");
    }
    else if (marks > 30)
    {
        printf("with 4th div");
    }

    else
    {
        printf("fail!");
    }
}

// Pattern printing
// Q 9
int drawTriangle(int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < (n - k) || i == 0)
            {

                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (i >= (k - 1) || k == 0 || k == 1)
            {

                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
// Q 10
int drawABCTriangle()
{
    char ABC[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < (n - k) || i == 0)
            {

                printf("%c", ABC[i]);
            }
            else
            {
                printf(" ");
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (i >= (k - 1) || k == 0 || k == 1)
            {

                printf("%c", ABC[n + i]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
// Q 11
int drawCBATriangle()
{
    char ABC[] = {'A', 'B', 'C', 'D', 'E'};
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < (n - k) || i == 0)
            {

                printf("%c", ABC[i]);
            }
            else
            {
                printf(" ");
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (i >= (k - 1) || k == 0 || k == 1)
            {

                printf("%c", ABC[n - 2 - i]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
// Q 12
int pat12()
{
    char ABC[] = {'A', 'B', 'C', 'D', 'E'};
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i >= (n - k - 1))
            {

                printf("%c", ABC[n - 1 - i]);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
// Q 13
int pat13()
{
    char ABC[] = {'A', 'B', 'C', 'D', 'E'};
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (i >= (n - k - 1))
            {

                printf("%c", ABC[j]);
                j++;
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
// more patterns
// Q 1
int pat1()
{
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <= k; i++)
        {

            printf("*");
        }
        printf("\n");
    }

    return 0;
}
// Q 2
// Q 3
int pat3()
{
    int n = 5;
    int j = 1;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <= k; i++)
        {
            if (j >= 10)
            {
                j = 0;
            }

            printf("%d", j);
            j++;
        }
        printf("\n");
    }

    return 0;
}
// Q 4
int pat4()
{
    char ABC[] = {'A', 'B', 'C', 'D', 'E'};
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <= k; i++)
        {

            printf("%c", ABC[i]);
        }
        printf("\n");
    }

    return 0;
}
// Q 5
int pat5()
{
    char ABC[] = {1, 2, 3, 4, 5};
    int n = 5;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <= k; i++)
        {

            printf("%c", ABC[i]);
        }
        printf("\n");
    }

    return 0;
}
// Q6
// Q7
int pat7()
{
    int n = 6;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i < (n - k) || i == 0)
            {

                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (i >= (k - 1) || k == 0 || k == 1)
            {

                printf(" ");
            }
            else
            {
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}
// Q 6
int pat6()
{
    int offset = 'A';
    int n = 5;
    int j = 0;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i <= k; i++)
        {

            printf("%c", offset + j);
            j++;
        }
        printf("\n");
    }

    return 0;
}

//------
// Q8
void max()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf(a > b && a > c ? "a" : b > c ? "b"
                                        : "c");
}

// Q9 ??
// Q 10
void isLeapYear()
{
    int a;
    scanf("%d", &a);
    printf(((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)) ? "prime" : "not prime");
}
// Q 11
void licenseFee()
{
    int a;
    char gender;
    scanf("%d%c", &a, &gender);
    if (a >= 18 && a < 60)
    {
        if (gender == 'M')
        {
            printf("1500");
        }
        else
        {
            printf("1000");
        }
    }
}

// Q 12
void helloWorld()
{
    printf("Hello world :0");
}
// Q 13
int getTax(int salary)
{
    if (salary > 100000)
    {
        return 0.1 * salary;
    }
    else
    {
        return 0;
    }
}
//  Q 14
int maxTwo(int a, int b)
{
    return a > b ? a : b;
}
// Q 15
// for temp swap refer above
int swapByAdd()
{
    int a = 10;
    int b = 20;
    a = a + b;
    b = a - b;
    a = a - b;
    printf("%d %d", a, b);
}
// Q 16
int checkColinearity()
{
    int x1, y1, x2, y2, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    float slope1 = (y2 - y1) / (x2 - x1);
    float slope2 = (y3 - y2) / (x3 - x2);
    printf((slope1 == slope2) ? "yes colinear" : "Not colinear");
}
