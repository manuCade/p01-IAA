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
#include "distribucion_conjunta.h"
#include "gestor_inferencia.h"
#include "probabilidad.h"

#include "benchmark.h"

int main() {
  std::cout << "¿Quiere ejecutar el benchmark o la aplicación interactiva? (b/a): ";
  char modo{};
  std::cin >> modo;

  if (modo == 'b' || modo == 'B') {
    for (int n = 1; n <= 10; n++) {
      Benchmark benchmark(n);
      std::string nombre_archivo = "csv/results_" + std::to_string(n) + "_variables.csv";
      benchmark.EjecutarYGuardar(nombre_archivo);
    }
    return EXIT_SUCCESS;
  }


  std::cout << "Quiere generar la tabla a partir de un fichero csv? (s/n): ";
  char respuesta{};
  std::cin >> respuesta;

  DistribucionConjunta tabla;
  if (respuesta == 's' || respuesta == 'S') {
    std::cout << "Introduzca el nombre del fichero csv: ";
    std::string nombre_csv{};
    std::cin >> nombre_csv;

    if (nombre_csv.empty() || nombre_csv.find(".csv") == std::string::npos) {
      std::cerr << "El nombre del fichero no puede estar vacío." << std::endl;
      return EXIT_FAILURE;
    }

    tabla = DistribucionConjunta(nombre_csv);
  } else {
    std::cout << "Introduzca el número de variables binarias: ";
    int numero_variables{};
    std::cin >> numero_variables;

    if (numero_variables < 1) {
      std::cerr << "El número de variables debe ser al menos 1." << std::endl;
      return EXIT_FAILURE;
    }
    
    tabla = DistribucionConjunta(numero_variables);
  }
  tabla.Mostrar();

  GestorInferencia gestor(tabla);
  int n_vars = tabla.GetNumeroVariables();

  int cantidad_cond;
  std::cout << "\nCuántas variables quieres condicionar? ";
  std::cin >> cantidad_cond;

  for(int i = 0; i < cantidad_cond; ++i) {
    int indice, valor;
    std::cout << "Índice variable (1-" << n_vars << "): ";
    std::cin >> indice;
    gestor.IndicesCondicionada(indice);
    std::cout << "Valor (0 o 1): ";
    std::cin >> valor;
    gestor.SeleccionarCondicionada(indice, valor);
  }

  int cantidad_int;
  std::cout << "\nCuántas variables de interés? ";
  std::cin >> cantidad_int;

  for(int i = 0; i < cantidad_int; ++i) {
    int indice;
    std::cout << "Índice variable (1-" << n_vars << "): ";
    std::cin >> indice;
    gestor.SeleccionarInteres(indice);
  }

  std::cout << "\nConfiguración actual:\n";
  gestor.MostrarConfiguracion();
  Probabilidad prob(tabla.GetDistribucionConjunta(), tabla.GetNumeroVariables(), 
                    gestor.getEsInteres(), gestor.getIndicesCondicionados(), 
                    gestor.getValoresCondicionados());
  std::vector<double> resultado = prob.CalcularProbabilidadCondicional();

  std::cout << "\nDistribución condicional formateada:\n";
  prob.MostrarDistribucionCondicional();

  return EXIT_SUCCESS;
}