#include <stdio.h>
#include <assert.h>

int Atoi_K (const char* const Str);
int Puts_K (const char* const Str);
char* Strdup_K (const char* const Str);
size_t Strlen_K (const char* const Str);
size_t Min_size_t (const size_t First, const size_t Second);
const char* Strchr_K (const char* const Str, const char Symbol);
int Strcmp_K (const char* const Str_1, const char* const Str_2);
char* Strcpy_K (char* const Changeable_Str, const char* const Str);
char* Strcat_K (char* const Changeable_Str, const char* const Str);
ssize_t Getline_K (char** Buffer_Str, size_t* Len_Buffer, FILE* const Str);
char* Fgets_K (char* const Changeable_Str, const size_t Max_Quantity, FILE* const Str);
char* Strncpy_K (char* const Changeable_Str, const char* const Str, const size_t Max_Quantity);
char* Strncat_K (char* const Changeable_Str, const char* const Str, const size_t Max_Quantity);

int main ()
{
    char Str[7] = "sqvRT";
    char Empty_Str_1[20] = "123456789";
    char Empty_Str_2[10] = "123456789";
    char* Empty_Str_3 = (char*) calloc (100, sizeof (char));
    Empty_Str_3[0] = '5'; // просто для примера
    char* Empty_Str_4 = (char*) calloc (100, sizeof (char));
    char Empty_Str_5[100] = "01234";
    char Str_Numeric[100] = "291474836411abs";
    char Original_Str[40] = "abs rty 123";

    Puts_K (Str);

    printf ("strchr: %p\n", Strchr_K (Str, 'v'));

    printf ("strlen: %zu\n", Strlen_K (Str));

    printf ("strcpy: %s\n", Strcpy_K (Empty_Str_1, Str));

    printf ("strncpy: %s\n", Strncpy_K (Empty_Str_2, Str, 5));

    printf ("strcat: %s\n",Strcat_K (Empty_Str_3, Str));

    printf ("strncat: %s\n", Strncat_K (Empty_Str_4, Str, 2));

    FILE* Fgets_K_Test = fopen ("Fgets_K_Test.txt", "r");
    printf ("fgets: %s\n", Fgets_K (Empty_Str_5, 5, Fgets_K_Test));
    fclose (Fgets_K_Test);

    printf ("atoi: %d\n", Atoi_K (Str_Numeric));

    char* Copied_Str = Strdup_K (Original_Str);
    printf ("strdup: %s\n", Copied_Str);

    size_t Len_Buffer = 10;
    FILE* Getline_K_Test = fopen ("Getline_K_Test.txt", "r");
    char* Str_For_Getline = (char*) calloc (Len_Buffer, sizeof (char));
    ssize_t k = Getline_K (&Str_For_Getline, &Len_Buffer, Getline_K_Test);
    printf ("getline: %s\n", Str_For_Getline);
    fclose (Getline_K_Test);

    printf ("strcmp: %d\n", Strcmp_K ("abs11", "abs111"));

    free (Empty_Str_3);
    free (Empty_Str_4);
    free (Copied_Str);
    free (Str_For_Getline);
    return 0;
}

size_t Min_size_t (const size_t First, const size_t Second)
{
    if (First > Second)
    {
        return Second;
    }

    else
    {
        return First;
    }
}

int Strcmp_K (const char* const Str_1, const char* const Str_2)
{
    assert (Str_1 != NULL);
    assert (Str_2 != NULL);

    const size_t Len_Str_1 = Strlen_K (Str_1);

    for (size_t i = 0; i < Len_Str_1 + 1; i++)
    {
        int Difference = (Str_1[i] - Str_2[i]);

        if (Difference != 0)
        {
            return Difference;
        }
    }

    return 0;
}

ssize_t Getline_K (char** const Buffer_Str, size_t* const Len_Buffer, FILE* const Str)
{
    assert (Str != NULL);
    assert (Buffer_Str != NULL);
    assert (Len_Buffer != NULL);

    const size_t Len_New_Empty_Buffer = 100;

    if (*Buffer_Str == NULL || Len_Buffer == 0)
    {
        *Buffer_Str = (char*) calloc (Len_New_Empty_Buffer, sizeof (char));

        if (*Buffer_Str == NULL)
        {
            return -1;
        }

        *Len_Buffer = Len_New_Empty_Buffer;
    }

    size_t i = 0;

    while (1)
    {
        const int Symbol = fgetc(Str);

        if (Symbol == '\n')
        {
            (*Buffer_Str)[i] = Symbol;
            (*Buffer_Str)[i+1] = '\0';

            return i;
        }

        if (Symbol == EOF)
        {
            if (i != 0)
            {
                return i;
            }

            else
            {
                return -1;
            }
        }

        (*Buffer_Str)[i] = Symbol;

        i++;

        if (i == (*Len_Buffer) - 1)
        {
            *Buffer_Str = (char*) realloc (*Buffer_Str, (*Len_Buffer) * 2);

            if (*Buffer_Str == NULL)
            {
                return -1;
            }

            *Len_Buffer = (*Len_Buffer) * 2;
        }
    }
}

char* Strdup_K (const char* const Str)
{
    assert (Str != NULL);

    return Strcpy_K ((char*) malloc (Strlen_K (Str)), Str);
}

int Atoi_K (const char* const Str)
{
    assert (Str != NULL);

    size_t i = 0;
    int Sign = 1;
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
        Sum = (Sum * 10) + int ((Str[i]) - '0');

        i++;
    }

    return Sum * Sign;
}

char* Fgets_K (char* const Changeable_Str, const size_t Max_Quantity, FILE* const Str)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    size_t i = 0;

    if (Max_Quantity < 1)
    {
        return NULL;
    }

    while (i < Max_Quantity - 1)
    {
        int Symbol = fgetc(Str);

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

char* Strncat_K (char* const Changeable_Str, const char* const Str, const size_t Max_Quantity)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    const size_t Len_Changeable_Str = Strlen_K (Changeable_Str);
    const size_t Smaller = Min_size_t (Max_Quantity, Strlen_K (Str));

    for (size_t i = 0; i < Smaller; i++)
    {
        Changeable_Str[Len_Changeable_Str + i] = Str[i];
    }

    Changeable_Str[Len_Changeable_Str + Smaller + 1] = '\0';

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

char* Strncpy_K (char* const Changeable_Str, const char* const Str, const size_t Max_Quantity)
{
    assert (Changeable_Str != NULL);
    assert (Str != NULL);

    const size_t Len_Str = (Strlen_K (Str));
    const size_t Smaller = Min_size_t (Max_Quantity, Len_Str);

    for (size_t i = 0; i < Smaller; i++)
    {
        Changeable_Str[i] = Str[i];
    }

    if (Len_Str < Max_Quantity)
    {
        for (size_t i = 0; i < Max_Quantity - Len_Str; i++)
        {
            Changeable_Str[i] = '\0';
        }
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

int Puts_K (const char* const Str)
{
    assert (Str != NULL);

    const size_t Len_Str = (Strlen_K (Str));

    for (size_t i = 0; i < Len_Str; i++)
    {
        int Symbol = putchar (Str[i]);

        if (Symbol == EOF)
        {
            return EOF;
        }
    }

    putchar('\n');

    return 1;
}
