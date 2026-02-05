/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial Avanzada
 * Curso: 3º
 * Práctica 1: Inferencia Condicional en Distribuciones Discretas Binarias
 * Autores: Manuel Cadenas García alu0101636849@ull.edu.es
 *          Saúl Lorenzo Armas alu0101642468@ull.edu.es
 * Fecha: 05/02/2026
 */

#include <iostream>
#include <string>
#include "tabla.h"

int main() {
  std::cout << "Quiere generar la tabla a partir de un fichero csv? (s/n): ";
  char respuesta{};
  std::cin >> respuesta;

  Tabla tabla;
  if (respuesta == 's' || respuesta == 'S') {
    std::cout << "Introduzca el nombre del fichero csv: ";
    std::string nombre_csv{};
    std::cin >> nombre_csv;

    if (nombre_csv.empty() || nombre_csv.find(".csv") == std::string::npos) {
      std::cerr << "El nombre del fichero no puede estar vacío." << std::endl;
      return EXIT_FAILURE;
    }

    tabla = Tabla(nombre_csv);
  } else {
    std::cout << "Introduzca el número de variables binarias: ";
    int numero_variables{};
    std::cin >> numero_variables;

    if (numero_variables < 1) {
      std::cerr << "El número de variables debe ser al menos 1." << std::endl;
      return EXIT_FAILURE;
    }
    
    tabla = Tabla(numero_variables);
  }
  return EXIT_SUCCESS;
}