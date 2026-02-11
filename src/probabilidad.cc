#include "probabilidad.h"
#include <cmath>
#include <iostream>
#include <iomanip>

Probabilidad::Probabilidad(std::vector<double> distribucion_conjunta, int num_variables, std::vector<bool> mascara_interes, std::vector<bool> mascara_condicional_indices, std::vector<bool> mascara_condicional_valores) {
  distribucion_conjunta_ = distribucion_conjunta;
  num_variables_ = num_variables;
  mascara_interes_ = mascara_interes;
  mascara_condicional_indices_ = mascara_condicional_indices;
  mascara_condicional_valores_ = mascara_condicional_valores;
}


std::vector<bool> indexToBinary(int index, int num_bits) {
  std::vector<bool> binary(num_bits, 0);
  for (int i = 0; i < num_bits; ++i) {
    binary[i] = index % 2;
    index /= 2;
  }
  return binary;
}

std::vector<double> Probabilidad::CalcularProbabilidadCondicional() {
  //Contar cuántas variables de interés hay 
  int count = 0;
  for (bool es_de_interes : mascara_interes_) {
    if (es_de_interes) ++count;
  }
  // Creeamos y damos tamaño a la tabla pequeña de probabilidades condicionales
  std::vector<double> resultado(pow(2, count), 0.0); 
  double suma_normalizacion = 0.0; 

  // Recorrer toda la tabla de distribucion.
  for (size_t i = 0; i < distribucion_conjunta_.size(); ++i) { 
    std::vector<bool> linea = indexToBinary(i, num_variables_); 
    // Debe pasar 2 filtros para llegar a la tabla pequeña:
    bool cumple_condicion = true;
    // Primero, debe ser que en esa liena haya una variable condicionada (la parte de debajo de la barra) y el vaor sea el esperado (0 o 1)
    for (int v = 0; v < num_variables_; ++v) {
      if (mascara_condicional_indices_[v]) { 
        // Desde que no se cumpla una condición, no hace falta seguir comprobando esa linea pq no perteneceria a la tabla mediana.
        if (linea[v] != mascara_condicional_valores_[v]) { 
          cumple_condicion = false;
          break;
        }
      }
    }
    // Si se cumplen la  primera condicion, entonces esa linea pertenece a la tabla mediana. 
    if (cumple_condicion) {
      int index_resultado = 0;
      int potencia = 0;
      for (int v = 0; v < num_variables_; ++v) {
        // Desde que en esa linea haya una variable de interés, entonces esa variable no se marginaliza y se suma a la tabla pequeña.
        if (mascara_interes_[v]) { 
          if (linea[v]) {
            // Aqui miramos en que posición de la tabla pequeña se suma esa probabilidad. Para eso, vamos sumando potencias de 2 dependiendo de si esa variable de interés es 0 o 1.
            // Si es 0 pero es de interes, se tiene en cineta su possicion y incrementa la potencia, pero no se suma nada al index_resultado. 
            // Si es 1 y es de interes, entonces se suma la potencia de 2 correspondiente a esa variable de interés.
            index_resultado += pow(2, potencia);
          }
          potencia++;
        }
      }
      // Ponemos el valor en el hueco correspondiente de la tabla pequeña, que es el resultado de sumar esa probabilidad a lo que ya hubiera en ese hueco.
      resultado[index_resultado] += distribucion_conjunta_[i]; 
      // Y vamos sumando a la variable de normalización el valor de esa probabilidad, para luego dividir entre esa suma cada valor de la tabla pequeña y así normalizarla.
      suma_normalizacion += distribucion_conjunta_[i]; 
    }
  }
  // Finalmente, normalizamos la tabla pequeña dividiendo cada valor entre la suma de normalización, y la devolvemos.
  for (double& prob : resultado) {
    if (suma_normalizacion > 0) prob /= suma_normalizacion; 
  }
  return resultado;
}

void Probabilidad::MostrarTablaPequeña(std::vector<double> tabla_pequeña) {
for (size_t i = 0; i < tabla_pequeña.size(); ++i) {
    std::cout << tabla_pequeña[i] << "\n";
  }
}

/**
 * @brief Muestra la distribución condicional formateada alineando
 * las variables de interés con sus bits correspondientes.
 * * @param tabla_pequeña El vector con las probabilidades ya calculadas y normalizadas.
 */
void Probabilidad::MostrarDistribucionCondicional() {
  const std::vector<double> tabla_pequeña = CalcularProbabilidadCondicional();
  const int ancho = static_cast<int>(std::log10(num_variables_)) + 3;
  for (int j = num_variables_ - 1; j >= 0; --j) {
    if (mascara_interes_[j]) {
      std::cout << std::setw(ancho) << ("X" + std::to_string(j + 1));
    }
  }
  std::cout << " : Probabilidad\n";

  int num_vars_interes = 0;
  for(bool v : mascara_interes_) if(v) num_vars_interes++;
  
  for (size_t i = 0; i < tabla_pequeña.size(); ++i) {
    for (int bit = num_vars_interes - 1; bit >= 0; --bit) {
      std::cout << std::setw(ancho) << ((i & (1 << bit)) ? "1" : "0");
    std::cout << " : " << std::fixed << std::setprecision(4) << tabla_pequeña[i] << "\n";
    }
  }
}