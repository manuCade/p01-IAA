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
#include <vector>

/**
 * @class Probabilidad
 * @brief Clase que calcula la distribución condicional a partir de una distribución 
 *        conjunta y las máscaras *de interés y condicionales.
 */
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