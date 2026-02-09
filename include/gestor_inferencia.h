#pragma once
#include <vector>
#include <iostream>
#include "distribucion_conjunta.h"

/**
 * @class Clase que gestiona la inferencia condicional en una distribución 
 * conjunta de variables binarias. Permite seleccionar variables como 
 * condicionadas o de interés, y mostrar la configuración actual.
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