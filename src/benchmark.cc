#include "benchmark.h"
#include "probabilidad.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <iomanip>
#include <cmath>

Benchmark::Benchmark(int num_variables) : n_variables_(num_variables), distribucion_(num_variables) {
  std::cout << "[Benchmark] Inicializando distribucion con N=" 
            << n_variables_ << "...\n";
}

void Benchmark::EjecutarYGuardar(const std::string& nombre_archivo) {
  std::ofstream archivo(nombre_archivo);
  std::cout << "[Benchmark] Guardando resultados exhaustivos en: " << nombre_archivo 
            << "...\n";
  archivo << "n_variables,k_interes,k_condicionales,tiempo_ms\n";
  archivo.close();
  
  for (int k_int = 1; k_int <= n_variables_; ++k_int) {
    int max_condicionales = n_variables_ - k_int; 
    for (int k_cond = 1; k_cond <= max_condicionales; ++k_cond) {
      archivo.open(nombre_archivo, std::ios::app);
      std::vector<bool> mascara_interes(n_variables_, false);
      std::vector<bool> mascara_condicionales(n_variables_, false);
      std::vector<bool> mascara_valores_condicionales(n_variables_, false);

      for (int i = 0; i < k_int; ++i) mascara_interes[i] = true;

      for (int i = 0; i < k_cond; ++i) {
        int index = n_variables_ - 1 - i;
        mascara_condicionales[index] = true;
        mascara_valores_condicionales[index] = true;
      }

      double tiempo = MedirUnaEjecucion(mascara_interes, mascara_condicionales, mascara_valores_condicionales);

      archivo << n_variables_ << "," << k_int << "," << k_cond << "," << tiempo << "\n";
      archivo.close();
    }
  }
  
  std::cout << "[Benchmark] Finalizado.\n";
}

double Benchmark::MedirUnaEjecucion(const std::vector<bool>& mascara_interes, 
                                    const std::vector<bool>& mascara_condicionales, 
                                    const std::vector<bool>& mascara_valores_condicionales) {
  Probabilidad prob(distribucion_.GetDistribucionConjunta(), n_variables_, 
                    mascara_interes, mascara_condicionales, mascara_valores_condicionales);

  auto start = std::chrono::high_resolution_clock::now();
  prob.CalcularProbabilidadCondicional();
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double, std::milli> duration = end - start;
  std::cout << "Medición realizada en " << duration.count() << " ms\n";
  return duration.count();
}