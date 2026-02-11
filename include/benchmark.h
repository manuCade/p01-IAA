/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Asignatura: Inteligencia Artificial Avanzada
 * Curso: 3º
 * Práctica 1: Inferencia Condicional en Distribuciones Discretas Binarias
 * Autores: Manuel Cadenas García alu0101636849@ull.edu.es
 *          Saúl Lorenzo Armas alu0101642468@ull.edu.es
 * Fecha: 09/02/2026
 */

#pragma once
#include <string>
#include <vector>
#include "distribucion_conjunta.h"

/**
 * @class Benchmark
 * @brief Clase para realizar benchmarks de la función de cálculo de probabilidades condicionales.
 */
class Benchmark {
public:
  Benchmark(int n_variables = 20);
  void EjecutarYGuardar(const std::string& nombre_archivo = "csv/results.csv");

private:
  int n_variables_;
  DistribucionConjunta distribucion_;
  double MedirUnaEjecucion(const std::vector<bool>& m_interes, 
                           const std::vector<bool>& m_cond_idx, 
                           const std::vector<bool>& m_cond_val);
};