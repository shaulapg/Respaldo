#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class Platillos {
public:
    std::string alimento, tipo, extra;
    int vendidas, compradas;
    float precio;
    Platillos(){};
    Platillos(const std::string& alim, int prec) : alimento(alim), precio(prec) {};

    static Platillos fromCSV(const std::string& csv) {
        std::istringstream ss(csv);
        std::string alimento;
        std::string cantStr;
        
        std::getline(ss, alimento, ',');
        std::getline(ss, cantStr);
        int precio = std::stoi(cantStr);
        
        return Platillos(alimento, precio);
    }

    std::string get_nombre();
    int get_vendidas();
    float get_precio();
    std::string get_tipo();
    
    std::string toCSV() const;
    std::string toString() const;
};

std::string Alimentos::get_nombre(){
    return nombre;
}

int Alimentos::get_vendidas(){
    return vendidas;
}

float Alimentos::get_precio(){
    return precio;
}

std::string Alimentos::get_tipo(){
    return tipo;
}

std::string Platillos::toCSV() const {
        return alimento + "," + std::to_string(precio);
}

std::string Platillos::toString() const {
        std::stringstream ss;
        ss << "Alimento: " << alimento << ", Precio: " << precio;
        return ss.str();
}

std::vector<Platillos> readFromCSV(const std::string& csv) {
    std::vector<Platillos> Platillos;
    std::ifstream file(csv);
    std::string line;

    if (file.is_open()) {        
        while (std::getline(file, line))
            if (!line.empty())
                Platillos.push_back(Platillos::fromCSV(line));
        file.close();
    } else
        std::cerr << "Error al abrir el archivo" << std::endl;

    return Platillos;
}


void writeToCSV(const std::string& csv, const std::vector<Platillos>& Platilloss) {
    std::ofstream file(csv, std::ios::app);
    if (file.is_open()) {
        for (const auto& Platillos : Platilloss)
            file << Platillos.toCSV() << std::endl;
        file.close();
    } else
        std::cerr << "Error al abrir el archivo" << std::endl;
}