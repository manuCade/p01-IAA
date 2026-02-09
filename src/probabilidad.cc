#include "probabilidad.h"

Probabilidad::Probabilidad(std::vector<double> distribucion_conjunta, int num_variables, int mascara_interes, int mascara_condicional_indices, int mascara_condicional_valores) {
  distribucion_conjunta_ = distribucion_conjunta;
  num_variables_ = num_variables;
  mascara_interes_ = mascara_interes;
  mascara_condicional_indices_ = mascara_condicional_indices;
  mascara_condicional_valores_ = mascara_condicional_valores;
}

std::vector<double> Probabilidad::CalcularProbabilidadCondicional() {
  
}