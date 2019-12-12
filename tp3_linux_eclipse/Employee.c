#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#define CHAR_SIZE 128


/** \brief Imprime el menu de opciones y solicita que es escoja uno.
 *
 * \return int el numero de opcion escogida.
 *
 */
int menu(){
    int opcion=0;
    __fpurge(stdin);
        utn_getUnsignedInt(
     "Menu:\n"
     "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
     "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
     "3. Alta de empleado\n"
     "4. Modificar datos de empleado\n"
     "5. Baja de empleado\n"
     "6. Listar empleados\n"
     "7. Ordenar empleados\n"
     "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
     "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
     "10. Salir\n","Error intentelo nuevamente\n"
	 "11 Filtrar la lista",1,sizeof(int),1,10,2,&opcion);

    return opcion;
}



/** \brief reserva espacio en memoria para un nuevo elemento.
 *

 * \return Employee * retorna un puntero a Employee con la direccion de memoria asignada
 *
 */
Employee* employee_new()
{
    Employee * new_Employee;
    new_Employee=malloc(sizeof(Employee));
    if(new_Employee!=NULL)
    {
        return new_Employee;
    }

    return NULL;
}


/** \brief Crea un nuevo elemento agregandole los argumentos pasados por parametro.
 *
 * \param idString char* string con el id
 * \param nameString char* string con el nombre
 * \param hoursString char* string con las horas trabajadas
 * \param SalaryString char* string con el salario
 * \return Employee * Retorna un puntero a la persona si se creo con exito y de lo contrario puntero a NULL
 *
 */

Employee* employee_newParametros(char* idString,char* nameString,char* hoursString,char* SalaryString)
{
    Employee* persona=employee_new();
    int valida=0;
    if(employee_setId(persona,atoi(idString))==1)
    {
        if(employee_setNombre(persona,nameString)==1)
        {
            if(employee_setHorasTrabajadas(persona,atoi(hoursString))==1)
            {
                if(employee_setSueldo(persona,atoi(SalaryString))==1)
                    valida=1;
            }
        }
    }
    if(valida==0)
    {
        persona = NULL;
    }
    return persona;
}
/*
 * 		SETTERS Y GETTERS
 */

/** \brief Establece el atributo  en Employee-.
 *
 * \param int id . Se pasa por parametro el id a establecer.
 * \param pArrayListEmployee LinkedList*
 * \return int si el retorno es exitoso, retorna 0. Si falla retorna -1
 *
 */


int employee_setId(Employee* this,int id){
    int ret=0;
    if(this!=NULL&&id>0){
        this->id=id;
        ret=1;
    }
    return ret;
}
int employee_getId(Employee* this,int* id)
{
    int ret=0;
    if(this!=NULL&&id!=NULL){
        *id=this->id;
        ret=1;
    }
    return ret;
}
int employee_setNombre(Employee* this,char* nombre)
{
    int ret=0;
    if(this!=NULL&&nombre!=NULL){
        strcpy(this->nombre,nombre);
        ret=1;
    }
    return ret;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int ret=0;
    if(this!=NULL&&nombre!=NULL){
        strcpy(nombre,this->nombre);
        ret=1;
    }
    return ret;
}
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int ret=0;
    if(this!=NULL&&horasTrabajadas>0){
        this->horasTrabajadas=horasTrabajadas;
        ret=1;
    }
    return ret;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int ret=0;
    if(this!=NULL&&horasTrabajadas!=NULL){
        *horasTrabajadas=this->horasTrabajadas;
        ret=1;
    }
    return ret;
}
int employee_setSueldo(Employee* this,int sueldo){
    int ret=0;
    if(this!=NULL&&sueldo>0){
        this->sueldo=sueldo;
        ret=1;
    }
    return ret;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int ret=0;
    if(this!=NULL&&sueldo!=NULL){
        *sueldo=this->sueldo;
        ret=1;
    }
    return ret;
}




/** \brief Imprime empleado, recibe como parametro un puntero a Employee y lo imprime.
 *
 * \param emp Employee*
 * \return void
 *
 */


int menuOrdenar(){
    int opcion;
    utn_getUnsignedInt("\n\nDe que manera lo quiere ordenar: "
    		"\n		Coloque 0 para que sea Ascendente"
    		"\n		Coloque 1 para que sea Descendente","Debe ser 0 o 1: ",1,sizeof(int),0,1,1,&opcion);

    return opcion;
}



/** \brief compara los sueldos de dos empleados y si son iguales compara los nombre... ordena por sueldo y nombre.
 * \param void* Employee1 puntero al empleado 1
 * \param void* Employee2 puntero al empleado 2
 * \return int Retorna  (1) si el sueldo del empleado 1> sueldo del empleado 2
 	 	 	 	 	 	 Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */

int employeeSortCondition(void* Employee1, void* Employee2)
{
	int sueldo1;
	int sueldo2;
	char nombre1[50];
	char nombre2[50];
	Employee* empleado1 = (Employee*) Employee1;
	Employee* empleado2 = (Employee*) Employee2;
	employee_getSueldo(empleado1,&sueldo1);
	employee_getSueldo(empleado2,&sueldo2);
    employee_getNombre(empleado1,nombre1);
    employee_getNombre(empleado2,nombre2);


			if(sueldo1>sueldo2)
			{
				return 1;
			}
			else if(sueldo1<sueldo2)
			{
				return -1;
			}
			else if(strcmp(nombre1,nombre2)<0)
			{

				return 1;
			}
			else if(strcmp(nombre1,nombre2)>0)
			{
				return -1;
			}
			else
				return 0;

}

int employee_lastID(LinkedList *pArrayListEmployee)
{
	int flag = 0;
	int maxId;
	int idAux;
	int i;
	Employee *auxEmpleado;
	int size = ll_len(pArrayListEmployee);
	for (i = 1; i < size; i++)
	{
		auxEmpleado = ll_get(pArrayListEmployee, i);
		employee_getId(auxEmpleado,&idAux);

		if (idAux> maxId || flag == 0)
		{
			flag = 1;
			maxId = idAux;
		}
	}

	return maxId;
}

void em_calcularSueldo2(void* p)
{
	if(p != NULL)
	{
			((Employee*)p)->sueldo =((Employee*)p)->horasTrabajadas*135;
	}
}
void em_calcularSueldo(void* p)
{
	if(p != NULL)
	{
		if(((Employee*)p)->horasTrabajadas > 0 && ((Employee*)p)->horasTrabajadas <= 120)
		{
			((Employee*)p)->sueldo = 180 * ((Employee*)p)->horasTrabajadas;
		}
		if(((Employee*)p)->horasTrabajadas > 120 && ((Employee*)p)->horasTrabajadas <= 160)
		{
			((Employee*)p)->sueldo = 240 * ((Employee*)p)->horasTrabajadas;
		}
		if(((Employee*)p)->horasTrabajadas > 160 && ((Employee*)p)->horasTrabajadas <= 240)
		{
			((Employee*)p)->sueldo = 350 * ((Employee*)p)->horasTrabajadas;
		}
	}
}


int contadorConCondicion(LinkedList *lista,int condicion)
{
	int contador=0;
	Employee * aux;

	for(int i=0;i<ll_len(lista);i++)
	{
		aux=ll_get(lista,i);
		if(aux->sueldo>condicion)
			contador++;
	}
	printf("\n\nLa cantidad de sueldo mayoras a %d son %d",condicion,contador);
	return contador;
}

int acumuladorConCondicion(LinkedList *lista,int condicion)
{
	int acumulador=0;
	Employee * aux;

	for(int i=0;i<ll_len(lista);i++)
	{
		aux=ll_get(lista,i);
		if(aux->sueldo>condicion)
			acumulador=acumulador+aux->horasTrabajadas;
	}
	printf("\n\nLa cantidad de horas trabajadas son %d",acumulador);
	return acumulador;
}
