#include <stdio.h>

const size_t X_1 = 7;

void Print_Triangular_Array (const int Triangular_Array[][X_1], size_t Height, size_t Size_X);
void Print_Rhombus_Array (const int Print_Rhombus_Array[][X_1], size_t Height, size_t Size_X);
int Max_Rectangular_Array (const int Rectangular_Array[][X_1], size_t Size_Y, size_t Size_X);
void Print_Rectangular_Array (const int Rectangular_Array[][X_1], size_t Size_Y, size_t Size_X);
void Print_Symbol_Rectangular_Array (const int Rectangular_Array[][X_1], size_t Size_Y, size_t Size_X);

int main()
{
    int Rectangular_Array[][X_1] = {
                                   {11, 12, 13},
                                   {21, 22, 23},
                                   {31, 23, 33},
                                   {41, 42, 43}};
    int Triangular_Array[][X_1] = {
                                 {1},
                                 {1, 2},
                                 {1, 2, 3},
                                 {1, 2, 3, 4},
                                 {1, 2, 3, 4, 5}};
    int Rhombus_Array[][X_1] = {
                                {0, 0, 0, 1},
                                {0, 0, 1, 2, 1},
                                {0, 1, 2, 3, 2, 1},
                                {1, 2, 3, 4, 3, 2, 1},
                                {0, 1, 2, 3, 2, 1,},
                                {0, 0, 1, 2, 1},
                                {0, 0, 0, 1}};
    int Round_Array[][5] = {
                         {0, 1, 2, 1},
                         {1, 2, 3, 2, 1},
                         {1, 2, 3, 2, 1},
                         {1, 2, 3, 2, 1,},
                         {0, 1, 2, 1}};

    printf ("\nWork with Rectangular_Array:\n\n");
    Print_Symbol_Rectangular_Array (Rectangular_Array, 4, X_1);
    //const int const and const int* Rectangular_Array[3]
    Print_Rectangular_Array (Rectangular_Array, 4, X_1);
    printf ("max: %d\n", Max_Rectangular_Array (Rectangular_Array, 4, X_1));

    printf ("\nWork with Triangular_Array:\n\n");
    Print_Triangular_Array (Triangular_Array, 5, X_1);

    printf ("\nWork with Rhombus_Array:\n\n");
    Print_Rhombus_Array (Rhombus_Array, 7, X_1);

    printf ("\nWork with Round_Array:\n\n");


    return 0;
}

void Print_Rhombus_Array (const int Print_Rhombus_Array[][X_1], size_t Height, size_t Size_X)
{
    size_t Center = Size_X / 2;
    size_t Counter = 0;
    int Flag = 0;

    for (size_t y = 0; y < Height; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            const size_t Offset = ((y * Size_X) + x) * sizeof (int);
            const int Element = *((int*)(size_t (Print_Rhombus_Array) + Offset));

            if (x >= Center - Counter && x <= Center + Counter)
            {
                printf ("%d ", Element);

                if (x == Center + Counter)
                {
                    printf ("\n");

                    if (Center + Counter == Size_X - 1)
                    {
                        Flag = 1;
                        Counter--;
                    }

                    else if (Center + Counter < Size_X - 1 && Flag == 0)
                    {
                        Counter++;
                    }

                    else
                    {
                        Counter--;
                    }

                    break;
                }
            }

            else
            {
                printf ("  ");
            }
        }
    }
}

void Print_Triangular_Array (const int Triangular_Array[][X_1], size_t Height, size_t Size_X)
{
    size_t Counter = 1;

    for (size_t y = 0; y < Height; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            const size_t Offset = ((y * Size_X) + x) * sizeof (int);
            const int Element = *((int*)(size_t (Triangular_Array) + Offset));

            printf ("%d ", Element);

            if (x + 1 == Counter)
            {

                printf ("\n");

                Counter++;
                break;
            }
        }
    }
}

int Max_Rectangular_Array (const int Rectangular_Array[][X_1], size_t Size_Y, size_t Size_X)
{
    int Now_Max = -2147483648;

    for (size_t y = 0; y < Size_Y; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            const size_t Offset = ((y * Size_X) + x) * sizeof (int);
            const int Element = *((int*)(size_t (Rectangular_Array) + Offset));

            if (Element > Now_Max)
            {
                Now_Max = Element;
            }
        }
    }

    return Now_Max;
}

void Print_Symbol_Rectangular_Array (const int Rectangular_Array[][X_1], size_t Size_Y, size_t Size_X)
{

    for (size_t y = 0; y < Size_Y; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            const size_t Offset = ((y * Size_X) + x) * sizeof (int);
            const int Element = *((int*)(size_t (Rectangular_Array) + Offset));

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

void Print_Rectangular_Array (const int Rectangular_Array[][X_1], size_t Size_Y, size_t Size_X)
{
    for (size_t y = 0; y < Size_Y; y++)
    {
        for (size_t x = 0; x < Size_X; x++)
        {
            const size_t Offset = ((y * Size_X) + x) * sizeof (int);
            const int Element = *((int*)(size_t (Rectangular_Array) + Offset));

            printf ("%d ", Element);
        }

        printf ("\n");
    }
}
