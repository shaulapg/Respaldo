/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

#ifndef MENU_H
#define MENU_H

//Librerias
#include <string>
#include <iostream>
#include <vector>

//Archivo para que el menu pueda manejar los alimentos
#include "alimentos.h"
#include "platillos.h"

//Contador para el numero de alimentos
int contador = 0;
//Clase Menu
class Menu{
    //Atributos publicos
    public:
    //Lista de apuntadores de los alimentos
    Alimentos * alim[50];
    Platillos * plat[50];
    //Vectores para precios y ventas
    std::vector <float> precios;
    std::vector <int> ventas;

    //Constructor para menu (sin parametros)
    Menu(){};

    //funciones
    void agrega_alimento(Alimentos *);
    void agrega_platillo(Platillos *);
    void imprime_();
};

/**funcion para agregar un alimento
 * 
 * @param Apuntador de alimentos
 * @return
 */
void Menu::agrega_alimento(Alimentos * objeto){
    if(contador < 50){
        alim[contador] = objeto;
        precios.push_back(objeto->get_precio());
        ventas.push_back(objeto->get_vendidas());
        contador++;
    }
}

void Menu::agrega_platillo(Platillos * objeto){
    if(contador < 50){
        plat[contador] = objeto;
        precios.push_back(objeto->get_precio());
        ventas.push_back(objeto->get_vendidas());
        contador++;
    }
}

/**funcion para imprimir
 * 
 * @param
 * @return
 */
void Menu::imprime_(){
    for (int i = 0; i < contador; i++)
        alim[i] -> imprime();
}

#endif