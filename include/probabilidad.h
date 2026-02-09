#pragma once
#include <vector>
class Probabilidad {
  public:
    Probabilidad(std::vector<double> distribucion_conjunta, int num_variables, int mascara_interes, int mascara_condicional_indices, int mascara_condicional_valores);
    std::vector<double> CalcularProbabilidadCondicional();
  private:
    std::vector<double> distribucion_conjunta_;
    int num_variables_;
    int mascara_interes_;
    int mascara_condicional_indices_;
    int mascara_condicional_valores_;
};