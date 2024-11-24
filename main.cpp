/**Proyecto: Restaurant
 * Nombre: Shaula Suhail Paz Garay
 * Matricula: A01712013
 * Fecha: 18 de septiembre de 2024
 */

//Archivos para manejar los alimentos
#include "sorts.h"
#include "alimentos.h"
#include "menu.h"
#include "bst.h"
#include "platillos.h"

//Variables
std::string nom, ext, nam;
bool continua = true, enc;
int opcion, op, ven;
float prec, busc;

//Sorts para enteros y floats
Sorts<int> sorts;
Sorts<float> fsorts;

/**Menu para elegir el orden
 * 
 * @param
 * @return seleccion del usuario
 */
int ordenapor(){
    int op;
    std::cout << "Seccion" << std::endl;
    std::cout << "1. Todas" << std::endl;
    std::cout << "2. Bebidas" << std::endl;
    std::cout << "3. Comidas" << std::endl;
    std::cout << "4. Postres" << std::endl;
    std::cout << "Seleccione una opcion: ";
    std::cin >> op;
    std::cout << std::endl;

    return op;
}

//Inicio del main
int main(){
    
    //Objeto menu para manejo del restaurant
    Menu menu;
    //BST para ventas y precios
    BST<int> vbst;
    BST<float> pbst;

    std::vector<Platillos> pl = readFromCSV("platillos.csv");
    for (const auto& pl : pl) {
        menu.agrega_alimento(pl);
    }

    //Vector ordenado de ventas
    std::vector <int> v = sorts.mergeSort(menu.ventas);
    //Vector ordenado de precios
    std::vector <float> p = fsorts.mergeSort(menu.precios);

    //While para continuar hasta que el usuario decida salir
    while (continua){
        std::cout << std::endl;
        //Menu principal
        std::cout << "Menu principal" << std::endl;
        std::cout << "1. Mostrar Menu" << std::endl;
        std::cout << "2. Agregar Alimento" << std::endl;
        std::cout << "3. Mostrar por ventas" << std::endl;
        std::cout << "4. Mostrar por precio" << std::endl;
        std::cout << "5. Buscar precio" << std::endl;
        std::cout << "6. Buscar ventas" << std::endl;
        std::cout << "7. Salir" << std::endl;
        //Seleccion de opcion del menu principal
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        std::cout << std::endl;

        //Switch para llevar al usuario a la opcion seleccionada
        switch(opcion){
            case 1:
                //Mostrar menu (alimentos disponibles)
                menu.imprime_();
            break;
            case 2:
                //Menu para elegir que agregar
                std::cout << "Seccion" << std::endl;
                std::cout << "1. Bebidas" << std::endl;
                std::cout << "2. Comidas" << std::endl;
                std::cout << "3. Postres" << std::endl;
                std::cout << "Seleccione una opcion: ";
                std::cin >> op;
                std::cout << std::endl;

                //Opcion invalida
                if (op < 1 || op > 3)
                    std::cout << "Opcion invalida";
                else{
                    std::cout << "Nombre del alimento: ";
                    std::cin >> nom;
                    std::cout << "Vendidos hasta el momento: ";
                    std::cin >> ven;
                    std::cout << "Precio: ";
                    std::cin >> prec;
                    if (op == 1){
                        //Opcion de bebida
                        std::cout << "Temperatura: ";
                        std::cin >> ext;
                        Alimentos * aux  = new Bebidas(nom, ven, prec, "Bebidas", ext);
                        //Agregar el bebida al menu, lista de venta y lista de compras
                        menu.agrega_alimento(aux);
                        vbst.add(nom, ven);
                        pbst.add(nom, prec);
                    } else if (op == 2){
                        //Opcion de comida
                        std::cout << "Tipos: ";
                        std::cin >> ext;
                        Alimentos * aux  = new Comidas(nom, ven, prec, "Comidas", ext);
                        //Agregar el comida al menu, lista de venta y lista de compras
                        menu.agrega_alimento(aux);
                        vbst.add(nom, ven);
                        pbst.add(nom, prec);
                    } else if (op == 3){
                        //Opcion de postre
                        std::cout << "Sabores: ";
                        std::cin >> ext;
                        Alimentos * aux  = new Postres(nom, ven, prec, "Postres", ext);
                        //Agregar el postre al menu, lista de venta y lista de compras
                        menu.agrega_alimento(aux);
                        vbst.add(nom, ven);
                        pbst.add(nom, prec);
                    }
                }
            break;
            case 3:
                //Elegir como mostrar las ventas
                op = ordenapor();
                    //Bucles para recorrer todo el vector
                for(int i = 0; i < v.size(); i++)
                    for(int j = 0; j < contador; j++)
                        //Condicionales para ver el objeto
                        //Todos
                        if(op == 1 && v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas())
                            menu.alim[j]->imprime();
                        //Bebidas
                        else if(op == 2 && v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Bebidas")
                            menu.alim[j]->imprime();
                        //Comidas
                        else if(op == 3 && v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Comidas")
                            menu.alim[j]->imprime();
                        //Postres
                        else if(op == 4 && v[i - 1] != v[i] && v[i] == menu.alim[j]->get_vendidas() && menu.alim[j]->get_tipo() == "Postres")
                            menu.alim[j]->imprime();
                        //Opción inválida
                        else if (op < 1 || op > 4)
                            std::cout << "Opcion no valida";
            break;
            case 4:
                //Elegir como mostrar los precios
                op = ordenapor();

                //Bucles para recorrer todo el vector
                for(int i = 0; i < p.size(); i++)
                    for(int j = 0; j < contador; j++)
                        //Condicionales para ver el objeto
                        //Todos
                        if(op == 1 && p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio())
                            menu.alim[j]->imprime();
                        //Bebidas
                        else if(op == 2 && p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Bebidas")
                            menu.alim[j]->imprime();
                        //Comidas
                        else if(op == 3 && p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Comidas")
                            menu.alim[j]->imprime();
                        //Postres
                        else if(op == 4 && p[i - 1] != p[i] && p[i] == menu.alim[j]->get_precio() && menu.alim[j]->get_tipo() == "Postres")
                            menu.alim[j]->imprime();
                        //Opción inválida
                        else if (op < 1 || op > 4)
                            std::cout << "Opcion no valida";
            break;
            //Opcion para buscar un alimento por su precio
            case 5:
                //Ingresar el precio para buscar el alimento
                std::cout << "Inserte el precio a buscar: ";
                std::cin >> busc;
                //Comprobar si el articulo existe
                if (!pbst.find(busc))
                    std::cout << "El articulo no existe" << std::endl;
            break;
            //Opcion para buscar un alimento por sus ventas
            case 6:
                //Ingresar las ventas para buscar el alimento
                std::cout << "Inserte las ventas a buscar: ";
                std::cin >> busc;
                //Comprobar si el articulo existe
                if (!vbst.find(busc))
                    std::cout << "El articulo no existe" << std::endl;
            break;
            //Opcion para salir
            case 7:
                continua = false;
            break;
            //Caso default para opcion invalida
            default:
                std::cout << "Opcion no valida";
        }
    }
}