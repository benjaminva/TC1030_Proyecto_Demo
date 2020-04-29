#ifndef EMPRESA_H_
#define EMPRESA_H_
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

#include "Empleado.h"
const int MAX = 1000; //constante de tamaño de arreglos

class Empresa {

/*
Declara las variables de instancia
Arreglo de Empleados
Identificador de Nomina
*/
    private:

        Empleado *emp[MAX];  //se define como apuntador para usar polimorfismo
        int nomina;

/*
Métodos:
Costructor por default y los diferentes metodos que empleara.
*/
    public:

        Empresa(): nomina(0){}; //constructor por defualt

        void crea_ejemplos();
        void muestra_empleados();
        void muestra_empleados(string tipo);
        double calc_paga_empleados();
        double calc_paga_empleados(string tipo);
        double calc_paga_hacienda();
        double calc_pago_total();
        void agrega_asalariado(string nombre, double salario);
        void agrega_por_hora(string nombre, double horas, double salario);
        void agrega_practicante(string nombre, double horas, double salario);

};

/*
 Utiliza el arreglo de tipo Empleados.
 Llena el arreglo con ejemplos de cada tipo de empleado
*/
void Empresa::crea_ejemplos(){

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new Asalariado(nomina, "Fernando", 2000);
  nomina++;
  emp[nomina] = new Asalariado(nomina, "Alejandro", 1800);
  nomina++;
  emp[nomina] = new Asalariado(nomina, "Ivett", 1200);
  nomina++;
  emp[nomina] = new PorHora(nomina, "Claudia", 24, 400);
  nomina++;
  emp[nomina] = new PorHora(nomina, "Felipe", 20, 650);
  nomina++;
	emp[nomina] = new Practicante(nomina, "María", 10, 200);
  nomina++;
  emp[nomina] = new Practicante(nomina, "Ramon", 15, 200);
  nomina++;
  emp[nomina] = new Practicante(nomina, "Luisa", 20, 150);
  nomina++;
}

/*
Utiliza el arreglo emp y el número de nómina.
Recorre todo el arreglo imprimiendo cada uno de los objetos.
*/

void Empresa::muestra_empleados(){

  //Ciclo que recorre el arreglo e imprime cada objeto.
	for(int i=0; i<nomina ;i++)
		  cout << emp[i]->to_string();
}

/*
Recibe: string tipo
Utiliza el arreglo emp y el número de nómina.
Recorre todo el arreglo imprimiendo cada uno de los objetos  que coinciden
con el string tipo ("asalariado, por hora o practicante").
*/

void Empresa::muestra_empleados(string tipo){

  //Ciclo que recorre el arreglo e imprime cada objeto.
	for(int i=0; i<nomina ;i++){
    if(emp[i]->get_tipo() == tipo)
		  cout << emp[i]->to_string();
  }
}

/*
Utiliza el arreglo emp y el número de nómina.
Acumula todo los pagos mensaules de loe empleados
devuelve: double total.
*/
double Empresa::calc_paga_empleados(){

    double total=0;
    for(int i=0; i<nomina; i++)
        total = total + emp[i]->pago_mensual();
    return total;
}

/*
Recibe: string tipo
Utiliza el arreglo emp y el número de nómina.
Acumula todo los pagos mensaules de los empleados cuyo atributo ->tipo
coincide con el string recibido "tipo"
devuelve: double total.
*/
double Empresa::calc_paga_empleados(string tipo){

    int total=0;
    for(int i=0; i<nomina ;i++){
      if(emp[i]->get_tipo() == tipo)
  	      total = total + emp[i]->pago_mensual();
    }
	  return total;
}

/*
Suma el pago a empleados y asalaridos para hacienda
devuelve: duble total
*/
double Empresa::calc_paga_hacienda(){

		return calc_paga_empleados("asalariado") + calc_paga_empleados("por hora");
}

/*
manda a llamar calc_paga_empleados
devuelve: double total
*/
double Empresa::cal_pago_total(){

    return calc_paga_empleados();

}

/*
Recibe string nombre y double salario.
Crea un nuevo objeto tipo Asalariado y lo agrega a emp
*/
void Empresa::agrega_asalariado(string nombre, double salario){

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
	emp[nomina] = new Asalariado(nomina, nombre, salario);
  nomina++;

}

/*
Recibe string nombre, int horas y double salario.
Crea un nuevo objeto tipo PorHora y lo agrega a emp
*/
void Empresa::agrega_por_hora(string nombre, int horas, double salario){

  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new PorHora(nomina, nombre, horas, salario);
  nomina++;
}

/*
Recibe string nombre, int horas y double salario.
Crea un nuevo objeto tipo Practicante y lo agrega a emp
*/
void Empresa::agrega_practicante(string nombre, int horas, double salario){
  //new crea el objeto en tiempo de ejecución para usar polimorfismo
  emp[nomina] = new Practicante(nomina, nombre, horas, salario);
  nomina++;
}

#endif // EMPRESA_H_
