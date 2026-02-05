#include "tabla.h"

#include <random>
#include <fstream>
#include <sstream>
#include <iostream>

Tabla::Tabla(int numero_variables) {
  std::vector<double> tabla{};
  tabla.resize(std::pow(2, numero_variables));

  // Genera numero aleatorio
  std::mt19937 generador{};
  std::uniform_int_distribution<> distribucion(0, 1000);
  int suma_numeros_aleatorios = 0;

  for (size_t i = 0; i < tabla.size(); ++i) {
    int numero_aleatorio = distribucion(generador);
    tabla[i] = numero_aleatorio;
    suma_numeros_aleatorios += numero_aleatorio;
  }

  for (size_t i = 0; i < tabla.size(); ++i) {
    tabla[i] /= double(suma_numeros_aleatorios);
  }
}

size_t Tabla::ConvertirAIndice(const std::string& input) {
  size_t indice{0};
  for (size_t i = 0; i < input.length(); ++i) {
    indice += (input[i] == '1') ? std::pow(2, input.length() - 1 - i) : 0;
  }
  return indice;
}

Tabla::Tabla(const std::string& nombre_archivo_csv) {
  std::ifstream archivo_csv(nombre_archivo_csv);
  std::string linea{};
  std::string separador = ",";
  size_t contador_de_linea = 1;
  while (std::getline(archivo_csv, linea)) {
    std::stringstream stream(linea);
    std::string numero_binario = linea.substr(0, linea.find(separador));
    std::string valor_str = linea.substr(linea.find(separador) + 1, linea.length());

    if (contador_de_linea == 1) {
      distribucion_conjunta_.resize(std::pow(2, numero_binario.length()));
    }

    size_t indice = ConvertirAIndice(numero_binario);
    double valor = std::stod(valor_str);

    distribucion_conjunta_[indice] = valor;
    ++contador_de_linea;
  }
}