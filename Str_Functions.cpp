#include <stdio.h>
#include <assert.h>
#include <math.h>

int Atoi_K (const char* const Str);
void Puts_K (const char* const Str);
size_t Strlen_K (const char* const Str);
const char* Strchr_K (const char* const Str, const char Symbol);
char* Strcpy_K (char* const Changeable_Str, const char* const Str);
char* Strcat_K (char* const Changeable_Str, const char* const Str);
char* Fgets_K (char* const Changeable_Str, const int Quantity, FILE* Str);
char* Strncpy_K (char* const Changeable_Str, const char* const Str, const int Quantity);
char* Strncat_K (char* const Changeable_Str, const char* const Str, const int Quantity);

int main ()
{
    char Str[7] = "sqvRT";
    char Empty_Str_1[20] = "123456789";
    char Empty_Str_2[10] = "123456789";
    char* Empty_Str_3 = (char*) calloc (100, sizeof(char));
    Empty_Str_3[0] = '5';
    char* Empty_Str_4 = (char*) calloc (100, sizeof(char));
    char Empty_Str_5[100] = "01234";
    char Str_Numeric[10] = "-123weg";

    Puts_K (Str);

    printf ("%p\n", Strchr_K (Str, 'v'));

    printf ("%zu\n", Strlen_K (Str));

    printf ("%s\n", Strcpy_K (Empty_Str_1, Str));

    printf ("%s\n", Strncpy_K (Empty_Str_2, Str, 5));

    printf ("%s\n",Strcat_K (Empty_Str_3, Str));

    printf ("%s\n", Strncat_K (Empty_Str_4, Str, 2));

    FILE* fl = fopen ("Fgets_K.txt", "r");
    printf ("%s\n", Fgets_K (Empty_Str_5, 5, fl));
    fclose (fl);

    printf ("%d\n", Atoi_K (Str_Numeric));



    free (Empty_Str_3);
    free (Empty_Str_4);
    return 0;
}



int Atoi_K (const char* const Str)
{
    assert (Str != NULL);

    size_t Len_Str = Strlen_K (Str);

    int M_Only_Numeric[50];
    int i = 0;
    int Sign = 1;
    int Degree = 0;
    int Sum = 0;

    while (Str[i] == ' ')
    {
        i++;
    }

    if (Str[i] == '-')
    {
        Sign = -1;
        i++;
    }

    else if (Str[i] == '+')
    {
        i++;
    }

    while (Str[i] >= '0' && Str[i] <= '9')
    {
        M_Only_Numeric[Degree] = int (Str[i]) - 48;

        Degree ++;
        i++;
    }

    for (int j = 0; j < Degree; j++)
    {
        Sum += M_Only_Numeric[j] * pow (10, (Degree - j - 1));
    }

    return Sum*Sign;
}

char* Fgets_K (char* const Changeable_Str, const int Quantity, FILE* const Str)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    int i = 0;

    if (Quantity < 1)
    {
        return NULL;
    }

    while (i < Quantity - 1)
    {
        char Symbol = fgetc(Str);

        if (Symbol == '\n')
        {
            Changeable_Str[i] = Symbol;
            Changeable_Str[i+1] = '\0';
            return Changeable_Str;
        }

        if (Symbol == EOF)
        {
            if (i != 0)
            {
                return Changeable_Str;
            }

            else
            {
                return NULL;
            }
        }

        Changeable_Str[i] = Symbol;

        i++;
    }

    Changeable_Str[i] = '\0';

    return Changeable_Str;

}

char* Strncat_K (char* const Changeable_Str, const char* const Str, const int Quantity)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    const size_t Len_Changeable_Str = Strlen_K (Changeable_Str);
    const size_t Len_Str = Strlen_K (Str);
    size_t a = 0;

    if (Quantity <= Len_Str)
    {
        a = Quantity;
    }

    else
    {
        a = Len_Str;
    }

    for (size_t i = 0; i < a; i++)
    {
        Changeable_Str[Len_Changeable_Str + i] = Str[i];
    }

    Changeable_Str[Len_Changeable_Str + a + 1] = '\0';

    return Changeable_Str;
}

char* Strcat_K (char* const Changeable_Str, const char* const Str)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    const size_t Len_Changeable_Str = Strlen_K (Changeable_Str);
    const size_t Len_Str = Strlen_K (Str);

    for (size_t i = 0; i < Len_Str + 1; i++)
    {
        Changeable_Str[Len_Changeable_Str + i] = Str[i];
    }

    return Changeable_Str;
}

char* Strncpy_K (char* const Changeable_Str, const char* const Str, const int Quantity)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    const size_t Len_Str = Strlen_K (Str);
    const size_t Len_Changeable_Str = Strlen_K (Changeable_Str);
    size_t a = 0;

    if (Quantity >= Len_Changeable_Str)
    {
        a = Len_Changeable_Str;
    }

    else if (Quantity <= Len_Str)
    {
        a = Quantity;
    }

    else
    {
        a = Len_Str + 1;
    }

    for (size_t i = 0; i < a; i++)
    {
        Changeable_Str[i] = Str[i];
    }

    return Changeable_Str;
}

char* Strcpy_K (char* const Changeable_Str, const char* const Str)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    const size_t Len_Str = Strlen_K (Str);

    for (size_t i = 0; i < Len_Str + 1; i++)
    {
        Changeable_Str[i] = Str[i];
    }

    return Changeable_Str;
}

size_t Strlen_K (const char* const Str)
{
    assert (Str != NULL);

    size_t i = 0;

    while (Str[i] != '\0')
    {
        i++;
    }

    return i;
}

const char* Strchr_K (const char* const Str, const char Symbol)
{
    assert (Str != NULL);

    const size_t Len_Str = Strlen_K (Str);

    for (size_t i = 0; i < Len_Str + 1; i++)
    {
        if (Str[i] == Symbol)
        {
            return &Str[i];
        }
    }

    return NULL;
}

void Puts_K (const char* const Str)
{
    assert (Str != NULL);

    const size_t Len_Str (Strlen_K (Str));

    for (size_t i = 0; i < Len_Str; i++)
    {
        putchar (Str[i]);
    }

    putchar('\n');
}
