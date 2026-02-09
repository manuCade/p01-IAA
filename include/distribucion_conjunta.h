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

#pragma once

#include <vector>
#include <string>

/**
 * @class Clase que representa una tabla de probabilidades para una distribución
 * conjunta de variables binarias. La tabla se puede inicializar de dos formas: 
 * generando números aleatorios o leyendo los valores desde un archivo CSV.
 */
class DistribucionConjunta {
 public:
  DistribucionConjunta() = default;
  DistribucionConjunta(int numero_variables);
  DistribucionConjunta(const std::string& nombre_archivo_csv);
  size_t GetNumeroVariables() const { return num_variables_; }
  void Mostrar() const;
  std::vector<double> GetDistribucionConjunta() const { return distribucion_conjunta_; }
 private:
  std::vector<double> distribucion_conjunta_;
  int num_variables_{0};
 private:
  size_t ConvertirAIndice(const std::string& input);
};