#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"
/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{

    int opcion = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
   // LinkedList* listaFiltradaPorSueldo = ll_newLinkedList();
   // LinkedList* listafiltradaPorSueldoYhoras = ll_newLinkedList();
    do{
    opcion=menu();
        switch(opcion)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;

            case 2:
            	controller_loadFromBinary("data.bin",listaEmpleados);
            	break;

            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;

            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;

            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;

            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;

            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;

            case 8:
            	controller_saveAsText("data.csv",listaEmpleados);
            	break;

            case 9:
            	controller_saveAsBinary("data.bin",listaEmpleados);
            	break;
            case 10:
            	break;
/*
            	calculaMinimo(listaEmpleados);
            	ll_map(listaEmpleados,em_calcularSueldo);
            	contadorConCondicion(listaEmpleados,13500);
            	acumuladorConCondicion(listaEmpleados,13500);
            	calculaSalario(listaEmpleados);
            	controller_saveAsText3("horas.txt",listaEmpleados);
            	break;
            case 11:
            	listaFiltradaPorSueldo=ll_filter(listaEmpleados,filtrarPorSueldo,14000,35000);
            	controller_saveAsText("data-filfrada.csv",listaFiltradaPorSueldo);
            	listafiltradaPorSueldoYhoras = ll_filter(listaFiltradaPorSueldo,filtrarPorHoras,100,140);
            	controller_saveAsText("data-filtrada2.csv",listafiltradaPorSueldoYhoras);


            	//controller_ListEmployee(listaFiltradaPorSueldo);

            	break;
*/

        }
    }while(opcion != 10);
    return 0;
}
