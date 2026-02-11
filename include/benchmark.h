#pragma once
#include <string>
#include <vector>
#include "distribucion_conjunta.h"

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