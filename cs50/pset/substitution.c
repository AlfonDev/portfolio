#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int comprobaciones_iniciales(int argc, string argv[]);
void cifrar_texto(string clave, string plaintext);

int main(int argc, string argv[]) // Comand line argument
{
    int error = comprobaciones_iniciales(argc, argv);

    if (error == 1)
    {
        return 1;
    }

    string clave = argv[1];
    string plaintext = get_string("Plaintext:");

    printf("ciphertext: ");
    cifrar_texto(clave, plaintext);
}

int comprobaciones_iniciales(int argc, string argv[])
{
    if (argc != 2) // si no hay al menos 2 cosas
    {
        printf("Usage:  ./substitution KEY\n");
        return 1;
    }

    if (strlen(argv[1]) != 26) // Si el segundo no es igual a 26
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int casillero[26] = {0}; // el casillero donde se va a guardar, empieza con 0

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        char letra_actual = argv[1][i]; // argv el command line argument, la letra i

        if (!isalpha(letra_actual))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        int casilla; // la casilla en la uqe estará

        if (islower(letra_actual))
        {
            casilla = letra_actual - 'a';
        }
        else
        {
            casilla = letra_actual - 'A';
        }

        if (casillero[casilla] == 1)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        casillero[casilla] = 1;
    }

    return 0; // si llega hasta aquí pasa a lo siguiente
}

void cifrar_texto(string clave, string plaintext)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char letra_actual = plaintext[i];

        if (isupper(letra_actual))
        {
            int posicion_letra_actual = letra_actual - 'A';
            char letra_cambiada = toupper(clave[posicion_letra_actual]);
            printf("%c", letra_cambiada);
        }
        else if (islower(letra_actual))
        {
            int posicion_letra_actual = letra_actual - 'a';
            char letra_cambiada = tolower(clave[posicion_letra_actual]);
            printf("%c", letra_cambiada);
        }
        else
        printf("%c", letra_actual);
    }
    printf("\n");
}
