#pragma once
#include <vector>
#include <iostream>
#include "distribucion_conjunta.h"

/**
 * @class GestorInferencia
 * @brief Clase que gestiona la configuración de la inferencia condicional, 
 *        incluyendo las variables de interés y las variables condicionadas, así como sus valores.
 */
class GestorInferencia {
 public:
  GestorInferencia(const DistribucionConjunta& tabla);
  void SeleccionarCondicionada(int indice_variable, bool valor);
  void IndicesCondicionada(int indice_variable);
  void SeleccionarInteres(int indice_variable);
  void MostrarConfiguracion();
  std::vector<bool> getIndicesCondicionados() const { return indices_condicionados_; }
  std::vector<bool> getValoresCondicionados() const { return valores_condicionados_; }
  std::vector<bool> getEsInteres() const { return es_interes_; }

 private:
  int num_variables_{0};
  std::vector<bool> indices_condicionados_;
  std::vector<bool> valores_condicionados_;
  std::vector<bool> es_interes_;
};