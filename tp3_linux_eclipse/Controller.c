#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#define CHAR_SIZE 50

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int si el retorno es exitoso, retorna 0. Si falla retorna -1
 *
 */

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)// archivo y lista
{
    int ret=-1;
	FILE* punteroFile;
	punteroFile = fopen(path,"r");

	printf("1.Entro al load\n");
		if(punteroFile != NULL && path != NULL)
		{
			printf("2.Entro al load al if\n");
            parser_EmployeeFromText(punteroFile, pArrayListEmployee);
			ret =0;
        }
		else
		{
		    printf("El archivo no existe");

		}
		fclose(punteroFile);
    return ret;
}

int controller_loadFromText2(char* path , LinkedList* pArrayListEmployee)
{
    int ret=0;
	FILE* pFile;
	pFile = fopen(path,"r");
		if(pFile == NULL)
		{
				printf("El archivo no ha sido encontrado.");
        }
		else
		{
			parser_EmployeeFromText2(pFile, pArrayListEmployee);
			ret =1;
		}
		fclose(pFile);
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int si el retorno es exitoso, retorna 0. Si falla retorna -1
 *
 */


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* punteroFile;
	int ret=-1;
		punteroFile = fopen(path,"rb");
			if(punteroFile == NULL)
			{
					printf("El archivo no ha sido encontrado.");

			}
			else
			{
				parser_EmployeeFromBinary(punteroFile, pArrayListEmployee);
				ret=0;
			}
			fclose(punteroFile);

	return ret;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int si el retorno es exitoso, retorna 0. Si falla retorna -1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int ret= -1;
    int max =employee_lastID(pArrayListEmployee);
    Employee* this=employee_new();
    char nombreAux[CHAR_SIZE];
    int horasAux;
    int sueldoAux;
	if(this!=NULL)

	{
		this->id = max+1;
        utn_getName("Ingrese nombre","Error, intentelo nuevamente por favor",1,30,2,nombreAux);
        employee_setNombre(this,nombreAux);
        utn_getUnsignedInt("ingrese las horas trabajadas","Error, intentelo nuevamente por favor",1,sizeof(int),1,10000,2,&horasAux);
        employee_setHorasTrabajadas(this,horasAux);
        utn_getUnsignedInt("ingrese el sueldo","Error, intentelo nuevamente por favor",1,sizeof(double),1,150000,2,&sueldoAux);
        employee_setSueldo(this,sueldoAux);

		if(ll_add(pArrayListEmployee, this)==1)//si se cargo en la LL->retorno exitodos
                ret=0;
	}
    return ret;
}

int controller_addEmployee2(LinkedList* pArrayListEmployee)
{
	int max =employee_lastID(pArrayListEmployee);
	printf("\nEl maximo es: %d",max);
	Employee* this=NULL;
	this = employee_new();
	int id=0;
	char nombreStr[50];
	int horasTrabajadas=0;
	int sueldo=0;

	if(this!=NULL)
	{

		this->id = max+1;
		//Ejemplo de como cambiar set_nombre(this, auxnombre);
		printf("Ingrese Nombre: \n");
		scanf("%s",this->nombre);
		printf("Ingrese Horas Trabajadas: \n");
		scanf("%d",&this->horasTrabajadas);
		printf("Ingrese Sueldo: \n");
		scanf("%d",&this->sueldo);

		ll_add(pArrayListEmployee, this);
	}
    return -1;
	//return this;
}


/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int index=0;
	Employee* this;
	printf("Introducir ID de empleado \n");
	__fpurge(stdin);
	scanf("%d",&index);
	__fpurge(stdin);

	for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
	{
		this=ll_get(pArrayListEmployee, i);
		if(index == this->id)
		{
			printf("Ingrese Nombre: \n");
			scanf("%s",this->nombre);
			//Ejemplo de como cambiar set_nombre(this, auxnombre);
			printf("Ingrese Horas Trabajadas: \n");
			scanf("%d",&this->horasTrabajadas);
			//Ejemplo de como cambiar set_nombre(this, auxtrabajadas);
			printf("Ingrese Sueldo: \n");
			scanf("%d",&this->sueldo);
			break;
		}
	}
    return 1;
}

int controller_editEmployee2(LinkedList* pArrayListEmployee)
{
	int index=0;
	Employee* this;
	printf("Introducir ID de empleado \n");
	__fpurge(stdin);
	scanf("%d",&index);
	__fpurge(stdin);

	for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
	{
		this=ll_get(pArrayListEmployee, i);
		if(index == this->id)
		{
			printf("Ingrese Nombre: \n");
			scanf("%s",this->nombre);
			//Ejemplo de como cambiar set_nombre(this, auxnombre);
			printf("Ingrese Horas Trabajadas: \n");
			scanf("%d",&this->horasTrabajadas);
			//Ejemplo de como cambiar set_nombre(this, auxtrabajadas);
			printf("Ingrese Sueldo: \n");
			scanf("%d",&this->sueldo);
			break;
		}
	}
    return 1;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int index=0;
		Employee* this;
		printf("Introducir ID de empleado \n");
		__fpurge(stdin);
		scanf("%d",&index);
		__fpurge(stdin);

		for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
		{
			this=ll_get(pArrayListEmployee, i);
			if(index == this->id)
			{
				ll_remove(pArrayListEmployee,i);
				break;
			}
		}
	    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */



 /*

 recorro todos los elementos del linkedlist y en cada uno creo un puntero a Employee
 En el puntero guardo la direccion de memoria del elemento segun el indice que se especifica.
 imprimo el elemento.

 */



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	for(int i =0 ; i <ll_len(pArrayListEmployee); i++)
	{
	Employee* empleado;
	empleado=ll_get(pArrayListEmployee, i); // equivalente empleado = array[i]
	printf("\nID Empleado %d\nNombre Empleado  %s\nHoras Trabajadas %d\nSueldo %d\n", empleado->id , empleado->nombre , empleado->horasTrabajadas , empleado->sueldo);
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ordenamiento=menuOrdenar();
	ll_sort(pArrayListEmployee,employeeSortCondition,ordenamiento);

    return 1;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* empleado;
	int length = ll_len(pArrayListEmployee);
	pFile=fopen(/*"data.csv"*/path,"w");
	if(pFile==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
	exit (1);
	}
	for(int i=0 ; i <length; i++)
	{
		//empleado=ll_get(pArrayListEmployee, i);
		empleado=ll_get(pArrayListEmployee, i); // equivalente empleado = array[i]
		fprintf(pFile,"%d , %s , %d , %d \n", empleado->id , empleado->nombre , empleado->horasTrabajadas , empleado->sueldo);
	}//get_blabla(empleado/this, id)

	fclose(pFile);
    return 1;
}

int controller_saveAsText3(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* empleado;
	int length = ll_len(pArrayListEmployee);
	int horas=contadorConCondicion(pArrayListEmployee,13500);
	pFile=fopen(path,"w");
	if(pFile==NULL)
	{
	printf("\nEl archivo no puede ser abierto");
	exit (1);
	}
	fprintf(pFile,"***********************************************\nla cantidad de horas trabajadas son %d\n***********************************************",horas);
	fclose(pFile);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pFile;
	Employee* empleado;
	int length = ll_len(pArrayListEmployee);
	pFile=fopen(path,"wb");
	if(pFile==NULL)
	{
		printf("\nEl archivo no puede ser abierto");
		exit (1);
	}
	for(int i=0 ; i <length; i++)
	{
		empleado=ll_get(pArrayListEmployee, i);
		fwrite(empleado,sizeof(Employee),1,pFile);
	}
		fclose(pFile);
	    return 1;
}



int filtrarPorSueldo(Employee* p, int min, int max)
{
	int ret=-1;
	if(p!=NULL && min >0 && min<max)
	{
		if(p->sueldo>min && p->sueldo<max)
			ret=1;
	}
	else
		ret=0;

	return ret;
}

int filtrarPorChar(Employee* p, char* texto)
{
	int ret=-1;
	if(p!=NULL && texto!=NULL)
	{
		if(strcmp(p->nombre,texto)==1)
			ret=1;
	}
	else
		ret=0;

	return ret;
}

int filtrarPorHoras(Employee * p, int min, int max)
{
	int ret=-1;

	if(p!=NULL && min >0 && min<max)
	{
		if(p->horasTrabajadas>min && p->horasTrabajadas<max)
			ret=1;
	}
	else
		ret=0;

	return ret;
}


LinkedList* usarFuncionFiltrar(LinkedList *listaEmpleados) // no funciona
{
	printf("\n\nAca");
	LinkedList* listaAuxiliar=ll_newLinkedList();
	printf("\n\nAca 2");
	listaAuxiliar=ll_filter(listaEmpleados,filtrarPorSueldo,14000,35000);
	printf("\n\n%d",ll_len(listaAuxiliar));
	return listaAuxiliar;

}

void calculaMinimo(LinkedList* lista)
{
	int min;
	int i=0;
	int flag=1;
	Employee *empAux=NULL;
	Employee *menor=NULL;

	for (i=0;i<ll_len(lista);i++)
	{
		empAux = ll_get(lista,i);
		if(flag==1)
		{
			min=empAux->sueldo;
			menor=empAux;
			flag=0;

		}else if(min>empAux->sueldo)
		{
			min=empAux->sueldo;
			menor=empAux;
		}
	}
	printf("\nID Empleado %d\nNombre Empleado  %s\nHoras Trabajadas %d\nSueldo %d\n", menor->id , menor->nombre , menor->horasTrabajadas , menor->sueldo);
	//return empAux;
}

void calculaSalario (LinkedList * lista)
{
	printf("Entro a la funcion salario");
	Employee * aux=employee_new();
	printf("\n\nCreo el empleado aux");
	for(int i=0;ll_len(lista);i++)
	{
		aux=ll_get(lista,i);
		aux->sueldo=10;
	}

}

