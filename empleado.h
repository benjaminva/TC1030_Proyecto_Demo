/*
*
* Proyecto Nómina clase Empresa
* Samuel Octavio González Azpeitia
* A01704696
* 16/10/2019
* versio : 2
* Esta clase defina objeto de tipo Empleado que contiene las clases heredadas
* Asalariado, PorHora y Practicante.
*/

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include <string>
#include <sstream>

using namespace std;

//Declaracion de clase empleado que es abstracta
class Empleado {

    //Declaro variables de instancia
    protected:
        int id;
        string nombre;
        string tipo;

    //Declaro los métodos que va a tener el objeto
    public:
        Empleado(): id(0),nombre(""),tipo(""){}; //constructor por defualt
        Empleado(int id_num, string nom, string tip):
          id(id_num), nombre(nom), tipo(tip){};

        int get_id() { return id; }
        string get_nombre() { return nombre; }
        string get_tipo() { return tipo; }
        virtual double pago_mensual() = 0;  //método abstracto será sobreescrito
        virtual string to_string() = 0;
};

//Declaro objeto asalariado que hereda de Empleado
class Asalariado: public Empleado{

    //Variables de instancia del objeto
    private:
        double salario_mensual;

    //Metodos del objeto
    public:

        Asalariado():Empleado(0,"","asalariado"){};
        Asalariado (int id, string nombre, double salar):
          Empleado(id,nombre,"asalariado"), salario_mensual(salar){};

        int get_id(){ return id; }
        string get_nombre(){ return nombre; }
        double pago_mensual(){ return salario_mensual; }
        string to_string();
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Asalariado::to_string(){

    stringstream aux;
    aux << "Id es " << id << " puesto " << tipo << "su nombre es "<< nombre
        << " su salario es " << salario_mensual << "\n";
    return aux.str();
}



//Declaro objeto PorHora que hereda de Empleado
class PorHora: public Empleado{

    //Declaro las variables de instancia privadas
    private:

        double horas_t, pago_por_h;

    //Declaro metodos públicos
    public:

        PorHora():Empleado(0,"","por hora"){};
        PorHora (int id, string nombre, double horas, double pago):
          Empleado(id,nombre,"por hora"), horas_t(horas), pago_por_h(pago){};

        double pago_mensual() { return horas_t * pago_por_h; }
        string to_string();

};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string PorHora::to_string(){

    stringstream aux;
    aux << "Id es " << id << " puesto " << tipo <<  " su nombre es " << nombre
        << " su pago mensual es " << pago_mensual() <<"\n";
    return aux.str();
}



//Declaro el objet Practicante que hereda de Empleado
class Practicante: public Empleado{

    //Variables de instancia privadas del objeto
    private:

        double horas_t, pago_p;

    //Metodos públicos del objeto
    public:

        Practicante():Empleado(0,"", "practicante"){};

        Practicante (int id, string nombre, double horas, double pago):
          Empleado(id, nombre,"practicante"), horas_t(horas), pago_p(pago){};

        double pago_mensual(){ return horas_t * pago_p; }
        string to_string();
};

/**
 * to_string convierte a atributos a string.
 *
 * concatena todos los valores de los atributos en un string para ser impreso
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
string Practicante::to_string(){

    stringstream aux;
    aux << "Id es " << id << " puesto " << tipo <<  " su nombre es "<< nombre
        << " su por practicas es " << pago_mensual() << "\n";
    return aux.str();
}


#endif // EMPLEADO_H_
