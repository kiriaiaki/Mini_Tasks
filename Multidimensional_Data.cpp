#include <stdio.h>

void Print_Triangular_Array (const int* const Triangular_Array, size_t Height);
int Max_Rectangular_Array (const int Rectangular_Array[][3], size_t Size_Y, size_t Size_X);
void Print_Rectangular_Array (const int Rectangular_Array[][3], size_t Size_Y, size_t Size_X);
void Print_Symbol_Rectangular_Array (const int Rectangular_Array[][3], size_t Size_Y, size_t Size_X);

int main()
{
    int Rectangular_Array[][3] = {{11, 12, 13},
                                {21, 22, 23},
                                {31, 23, 33},
                                {41, 42, 43}};

    // int Triangular_Array[][5] = {{1},
    //                             {1, 2},
    //                             {1, 2, 3},
    //                             {1, 2, 3, 4},
    //                             {1, 2, 3, 4, 5}};
    //??????
    int Triangular_Array[] = {1, 1, 2, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 4, 5};

    Print_Symbol_Rectangular_Array (Rectangular_Array, 4, 3);
    //const int const and const int* Rectangular_Array[3]
    // why not work with i ![][]?

    Print_Rectangular_Array (Rectangular_Array, 4, 3);

    printf ("%d\n", Max_Rectangular_Array (Rectangular_Array, 4, 3));

    return 0;
}

void Print_Triangular_Array (const int* const Triangular_Array, size_t Height)
{
    for (size_t i = 0; i < (Height * (Height+1)) / 2; i++)
    {
        int Element = *(int*)(size_t (Triangular_Array) + (i * sizeof (int)));

        printf ("%d", Element);
    }
}

int Max_Rectangular_Array (const int Rectangular_Array[][3], size_t Size_Y, size_t Size_X)
{
    int Now_Max = -2147483648; //how inia...

    for (size_t y = 0; y < Size_Y; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            size_t Offset = ((y * Size_X) + x) * sizeof (int);
            int Element = *((int*)(size_t (Rectangular_Array) + Offset));

            if (Element > Now_Max)
            {
                Now_Max = Element;
            }
        }
    }

    return Now_Max;
}

void Print_Symbol_Rectangular_Array (const int Rectangular_Array[][3], size_t Size_Y, size_t Size_X)
{

    for (size_t y = 0; y < Size_Y; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            size_t Offset = ((y * Size_X) + x) * sizeof (int);
            int Element = *((int*)(size_t (Rectangular_Array) + Offset));

            printf ("[%zu][%zu] = %d\n", y, x, Element);
        }
    }

//     for (size_t i = 0; i < (Size_Y * Size_X); i++)
//     {
//         int Element = *(int*)(size_t (Rectangular_Array) + (i * sizeof (int)));
//
//         printf ("[%zu][%zu] = %d\n", i / Size_Y, i % Size_X, Element);
//     }
}

void Print_Rectangular_Array (const int Rectangular_Array[][3], size_t Size_Y, size_t Size_X)
{
    for (size_t y = 0; y < Size_Y; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            size_t Offset = ((y * Size_X) + x) * sizeof (int);
            int Element = *((int*)(size_t (Rectangular_Array) + Offset));

            printf ("%d ", Element);
        }

        printf ("\n");
    }
}
