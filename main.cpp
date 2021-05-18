/*
* Proyecto Nómina main
* Samuel Octavio González Azpeitia
* A01704696
* 16/10/2019
*
* Este es un proyecto demo para la clase TC1030 Programación Orientado a
* Objetos. Es un programa que captura diferentes tipos de empleados con sus
* respectivos sueldos, y nos permite calcular la nómina para cada tipo de
* empleado diferente.
*/

#include <iostream>   // para imprimir.
#include "empleado.h" // bibliotecas con objetos de mi proyecto.
#include "empresa.h"

using namespace std;

int main(int argc, char* argv[]){

  double t = 0;
  string temp_nombre;
  double temp_salario;
  int temp_horas;

  Empresa empresa;
  empresa.crea_ejemplos();
  empresa.muestra_empleados();

  cout<< "test \n\n";
  empresa.muestra_empleados("asalariado");
  t = empresa.calc_paga_empleados();
  cout << "pago empleados " << t << endl;
  t = empresa.calc_paga_hacienda();
  cout << "pago hacienda " << t << endl;
  empresa.agrega_asalariado("Johnny", 20032);
  empresa.muestra_empleados("asalariado");
  empresa.agrega_por_hora("Veronica", 170, 100000);
  empresa.muestra_empleados("por hora");
  empresa.agrega_practicante("Benjamin", 40, 3000);
  empresa.muestra_empleados("practicante");
  cout<< "test \n\n";
}
