#include <cs50.h>
#include <stdio.h>

void print_row_derecha(int ladrillos);
void print_row_espaces(int espaces);

int main(void)
{
    // Pregunto por altura int
    int altura;
    do
    {
        altura = get_int("Altura:");
    }
    while (altura > 8 || altura < 1);

    // Hace los espacios para que se quede con ese formato, luego los hastags,
    // luego deja 2 espacios y vuelve a poner los hastags, no hace falta espacios
    for (int i = 1; i < altura + 1; i++)
    {
        print_row_espaces(altura - i);
        print_row_derecha(i);
        printf("  ");
        print_row_derecha(i);
        printf("\n");
    }
}

void print_row_derecha(int hastags)
{
    for (int i = 0; i < hastags; i++)
    {
        printf("#");
    }
}

// va sumando un 0 hasta dar i del main y para, siempre van siendo menos
// porque la i del main va bajando
void print_row_espaces(int espaces)
{
    for (int i = 0; i < espaces; i++)
    {
        printf(" ");
    }
}
