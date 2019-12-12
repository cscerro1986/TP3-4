#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret =1;
	int cuentaCopia;
	char buffer[4][60];
	Employee* nuevoEmpleado;
	do
	{

			cuentaCopia = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);


			if(cuentaCopia==4)
			{
			 	 nuevoEmpleado = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
				 if(nuevoEmpleado!=NULL)
				 {
					 ll_add(pArrayListEmployee,nuevoEmpleado);
                    ret=0;
				 }

			}
			else
                break;

	}while(!feof(pFile));

    return ret;
}
int parser_EmployeeFromText2(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int ret =1;
	int cuentaCopia;

	char idChar[50],nombreChar[50],horastrabajadasChar[50];
	Employee* nuevoEmpleado;
	do
	{

			cuentaCopia = fscanf(pFile,"%[^,],%[^,],%[^\n]\n",idChar,nombreChar,horastrabajadasChar);
			if(cuentaCopia==3)
			{
			 	 nuevoEmpleado = employee_new();
			 	 employee_setId(nuevoEmpleado,atoi(idChar));
			 	 employee_setNombre(nuevoEmpleado,nombreChar);
			 	 employee_setHorasTrabajadas(nuevoEmpleado, atoi(horastrabajadasChar));
				 if(nuevoEmpleado!=NULL)
				 {
					 ll_add(pArrayListEmployee,nuevoEmpleado);
                    ret=0;
				 }

			}
			else
                break;

	}while(!feof(pFile));

    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee* employeeAux;
    int ret=1;
    int cantidadLeida;
    do{
        employeeAux= employee_new();
        if(employeeAux!=NULL){
            cantidadLeida = fread(employeeAux, sizeof(Employee), 1, pFile);
            printf("\nLa cantidad leida es: %d ",cantidadLeida);
            if(cantidadLeida<1)
            {
                if(!feof(pFile))
                    ret=0;
                break;
            }
            if(ll_add(pArrayListEmployee,employeeAux))
            {
                ret=0;
                break;
            }
        }
    }while(!feof(pFile));
    return ret;
}

