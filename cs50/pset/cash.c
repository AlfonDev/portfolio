#include <cs50.h>
#include <stdio.h>

int get_cambio(void);
int calcular_quarters(int cambio_debido);
int calcular_dimes(int cambio_debido);
int calcular_nickles(int cambio_debido);
int calcular_pennies(int cambio_debido);

int main(void)
{
    int cambio_debido = get_cambio(); // Cuanto cambio
    int total_monedas = 0;

    // 1: Sumamos cuantos quarters al total de monedas y lo restamos del cambio
    int cuantos_quarters = calcular_quarters(cambio_debido); // Cuantos quarters

    total_monedas = total_monedas + cuantos_quarters; // Suma a total monedas los quarters que haya
    cambio_debido =
        cambio_debido - (25 * cuantos_quarters); // Resta a el cambio debido - los quarters

    // 2: Sumamos cuantos dimes al total de monedas y lo restamos del cambio
    int cuantos_dimes = calcular_dimes(cambio_debido); // Cuantos dimes

    total_monedas = total_monedas + cuantos_dimes;        // Suma a total monedas los dimes que haya
    cambio_debido = cambio_debido - (10 * cuantos_dimes); // Resta a el cambio debido - los dimes

    // 3: Sumamos cuantos dimes al total de monedas y lo restamos del cambio
    int cuantos_nickles = calcular_nickles(cambio_debido); // Cuantos dimes

    total_monedas = total_monedas + cuantos_nickles; // Suma a total monedas los nickles que haya
    cambio_debido = cambio_debido - (5 * cuantos_nickles); // Resta a el cambio debido - los nickles

    // 4: Sumamos cuantos pennies al total de monedas y lo restamos del cambio
    int cuantos_pennies = calcular_pennies(cambio_debido); // Cuantos pennies

    total_monedas = total_monedas + cuantos_pennies; // Suma a total monedas los pennies que haya
    cambio_debido = cambio_debido - (1 * cuantos_pennies); // Resta a el cambio debido - los pennies

    printf("%i\n", total_monedas);
}

int get_cambio(void) // Pide el cambio que debes
{
    int cambio_debido;
    do
    {
        cambio_debido = get_int("Cambio:");
    }
    while (cambio_debido < 0); // Si es negativo, vuelve a preguntar.
    return cambio_debido;
}

int calcular_quarters(int cambio_debido) // Calcula cuantos quarters caben y saca ese número
{
    int quarters = 0;
    while (cambio_debido >= 25)
    {
        quarters++;
        cambio_debido = cambio_debido - 25;
    }
    return quarters;
}

int calcular_dimes(int cambio_debido) // Calcula cuantos dimes caben y saca ese número
{
    intº dimes = 0;
    while (cambio_debido >= 10)
    {
        dimes++;
        cambio_debido = cambio_debido - 10;
    }
    return dimes;
}

int calcular_nickles(int cambio_debido) // Calcula cuantos nickles caben y saca ese número
{
    int nickles = 0;
    while (cambio_debido >= 5)
    {
        nickles++;
        cambio_debido = cambio_debido - 5;
    }
    return nickles;
}

int calcular_pennies(int cambio_debido) // Calcula cuantos nickles caben y saca ese número
{
    int pennies = 0;
    while (cambio_debido >= 1)
    {
        pennies++;
        cambio_debido = cambio_debido - 1;
    }
    return pennies;
}
