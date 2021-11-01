#include <stdio.h>
#include <string.h>
#include <conio.h>

#define N 3

typedef struct
{
    int clave;
    char nombre[20];
    float estatura;
    float sueldo;

}Datos;

void pideDatos(Datos d[N]);
int empleadoMasAlto(Datos d[N]);
void ordenaSueldo(Datos d[N]);
void imprimeDatos(Datos d[N]);

int main()
{
    Datos empleados[N];

    int empleadoAlto;

    pideDatos(empleados);
    empleadoMasAlto(empleados);

    empleadoAlto = empleadoMasAlto(empleados);

    printf("\n El empleado más alto es: %s", empleados[empleadoAlto].nombre, 
    "\n Su estatura es: %f \n", empleados[empleadoAlto].estatura);

    ordenaSueldo(empleados);
    imprimeDatos(empleados);
    
    getch();
    return 0;
}

void pideDatos(Datos d[N])
{
    for( int i = 0; i < N; i++)
    {
        printf("Empleado[%d]\n", i);

        printf("\tClave: ");
        scanf("%d", &d[i].clave);

        printf("\tNombre: ");
        scanf("%s", d[i].nombre);

        printf("\tEstatura: ");
        scanf("%f", &d[i].estatura);

        printf("\tSueldo: ");
        scanf("%f", &d[i].sueldo);
    }
}

int empleadoMasAlto(Datos d[N])
{
    int empleado;
    float mayor = d[0].estatura;
    int pos = 0;

    for(empleado = 0; empleado < N; empleado++)
    {
        if(d[empleado].estatura > mayor)
        {
            mayor = d[empleado].estatura;
            pos = empleado;
        }
    }
    return pos;
}

void ordenaSueldo(Datos d[N])
{
    int auxClave;
    float auxEstatura, auxSueldo;
    char auxNombre[20];

    for(int i = 0 ; i < (N-1); i++)
    {
        for(int j = 0; j < (N-1); i++)
        {
            if(d[j].sueldo < d[j+1].sueldo)
            {
                auxSueldo = d[j].sueldo;
                d[j].sueldo = d[j + 1].sueldo;
                d[j + 1].sueldo = auxSueldo;
                
                auxEstatura = d[j].estatura;
                d[j].estatura = d[j+1].estatura;
                d[j+1].estatura = auxEstatura;

                auxClave = d[j].clave;
                d[j].clave = d[j + 1].clave;
                d[j + 1].clave = auxClave;

                strcpy(auxNombre, d[j].nombre);
                strcpy(d[j].nombre, d[j+1].nombre);
                strcpy(d[j+1].nombre, auxNombre);

            }
        }
    }
}

void imprimeDatos(Datos d[N])
{
    printf("\nClave \tNombre \tEstatura \tSueldo \n");

    for(int i = 0; i < N; i++)
    {
        printf("\n%i \t%s \t%f \t%f", d[i].clave, d[i].nombre, d[i].estatura, d[i].sueldo);
    }
}
