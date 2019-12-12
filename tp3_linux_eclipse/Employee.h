#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void mostrarEmployee(Employee* emp);
void mostrarEmployees(LinkedList* lista);
int menu();
int menuOrdenar();
int employee_id(void* employeeA, void* employeeB);
int employee_nombre(void* employeeA, void* employeeB);
int employee_horasTrabajadas(void* employeeA, void* employeeB);
int employee_sueldo(void* employeeA,void* employeeB);
int employeeSortCondition(void* Employee1, void* Employee2);
int employee_lastID(LinkedList *pArrayListEmployee);
void em_calcularSueldo2(void* p);
void em_calcularSueldo(void* p);
int acumuladorConCondicion(LinkedList *lista,int condicion);
int contadorConCondicion(LinkedList *lista,int condicion);


#endif // employee_H_INCLUDEDS
