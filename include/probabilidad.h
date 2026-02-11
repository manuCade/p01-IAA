#pragma once
#include <vector>
class Probabilidad {
  public:
    Probabilidad(std::vector<double> distribucion_conjunta, int num_variables, std::vector<bool> mascara_interes, std::vector<bool> mascara_condicional_indices, std::vector<bool> mascara_condicional_valores);
    std::vector<double> CalcularProbabilidadCondicional();
    void MostrarTablaPequeña(std::vector<double> tabla_pequeña);
    void MostrarDistribucionCondicional();
  private:
    std::vector<double> distribucion_conjunta_;
    int num_variables_;
    std::vector<bool> mascara_interes_;
    std::vector<bool> mascara_condicional_indices_;
    std::vector<bool> mascara_condicional_valores_;
};