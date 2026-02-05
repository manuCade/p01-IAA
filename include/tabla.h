#pragma once

#include <vector>
#include <cmath>
#include <string>

class Tabla {
 public:
  Tabla(int numero_variables);
  Tabla(const std::string& nombre_archivo_csv);
 private:
  std::vector<double> distribucion_conjunta_;
 private:
  size_t ConvertirAIndice(const std::string& input);
};