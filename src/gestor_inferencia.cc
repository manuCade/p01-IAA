#include "gestor_inferencia.h"


/**
 * @brief Constructor que inicializa el gestor de inferencia a partir de la 
 *        distribución conjunta
 * 
 * @param tabla La tabla de probabilidades que se va a gestionar
 */
GestorInferencia::GestorInferencia(const DistribucionConjunta& tabla) {
  num_variables_ = tabla.GetNumeroVariables();
  // Indicamos con -1 que no hay condicionamiento
  valores_condicionados_.assign(num_variables_, -1);
  es_interes_.assign(num_variables_, false);
}

/**
 * @brief Método para seleccionar una variable como condicionada 
 *        con un valor específico (0 o 1)
 * 
 * @param indice_variable El índice de la variable a condicionar
 * @param valor El valor (0 o 1) al que se condiciona la variable
 */
void GestorInferencia::SeleccionarCondicionada(int indice_variable, bool valor) {
  int indice_real = indice_variable - 1;

  if (indice_real >= 0 && indice_real < num_variables_) {
    valores_condicionados_[indice_real] = valor;
  } else {
    std::cerr << "Error: Índice o valor incorrecto." << "\n";
  }
}

/**
 * @brief Método para seleccionar una variable como de interés
 * 
 * @param indice_variable El índice de la variable de interés
 */
void GestorInferencia::SeleccionarInteres(int indice_variable) {
  int indice_real = indice_variable - 1;
  
  if (indice_real >= 0 && indice_real < num_variables_) {
    es_interes_[indice_real] = true;
  } else {
    std::cerr << "Error: Índice incorrecto." << "\n";
  }
}

/**
 * @brief Método para imprimir la configuración actual de variables 
 *        condicionadas e interés
 * 
 * @return true Si la configuración es válida, false si hay conflictos
 */
void GestorInferencia::MostrarConfiguracion() {
  std::cout << "Variables Condicionadas:\n";
  for(int i = 0; i < num_variables_; ++i) {
    if(valores_condicionados_[i] != -1) {
      std::cout << "  Variable X" << (i+1) << " = " 
                << valores_condicionados_[i] << "\n";
    }
  }
  std::cout << "Variables de Interes\n";
  for(int i = 0; i < num_variables_; ++i) {
    if(es_interes_[i]) {
      std::cout << "  Variable X" << (i+1) << "\n";
    }
  }
}