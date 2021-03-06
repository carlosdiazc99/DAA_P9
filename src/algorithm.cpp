#include "../include/algorithm.hpp"

/**
 * @brief Devuelve el valor del centro de gravedad del vector actual
 * 
 * @param currentElement Representa el vector del que se va a calcular el centro
 * de gravedad (este también es un vector)
 * @return std::vector <float> Valor del centro de gravedad calculado
 */
std::vector <float> Algorithm::getGravityCenter(std::vector <int> currentElement) {
  std::vector <float> center;
  for (int index = 0; index < currentVectors.getDimension(); index++) {
    float currentSum = 0;
    for (int i = 0; i < currentElement.size(); i++) {
      currentSum += currentVectors.getDataValue(currentElement[i], index);
    }
    center.push_back(currentSum / currentElement.size());
  }
  return center;
}

/**
 * @brief Se encarga de inicializar la información recogida del fichero,
 * es decir, los vectores y asignarlos al atributo de la clase que lo va
 * a almacenar.
 * 
 * @param newVector El elemento que se va a asignar
 */
void Algorithm::setInfo(Vectors newVector) {
  currentVectors = newVector;
}

/**
 * @brief Este método se encarga de hacer un sumatorio de todas las
 * distancias de los nodos que se encuentran en el vector que se pasa
 * como argumento.
 * 
 * @param solution Vector que contiene los distintos nodos
 * @return float Valor de la distancia entre los nodos
 */
float Algorithm::getTotalDistance(std::vector<int> solution) {
  float distance = 0;
  for(int i = 0; i < solution.size(); i++) {
    for(int j = i + 1; j < solution.size(); j++) {
      distance += currentVectors.getEuclideanDistance(solution[i], solution[j]);
    }
  }
  return distance;
}

/**
 * @brief Se encarga de determinar los candidatos a partir de un vector.
 * Es decir, devuelve los elementos que no se encuentran en el vector que
 * se pasa como parámetro.
 * 
 * @param checkSelected Representa el vector sobre el que se quieren determinar
 * los elementos que no pertenecen al mismo.
 * @return std::vector<int> Vector con los elementos que no pertenecen al
 * vector checkSelected.
 */
std::vector<int> Algorithm::getCandidates(std::vector<int> checkSelected) {
  std::vector<int> candidates;
  for (int currentElement = 0; currentElement < currentVectors.getSize(); currentElement++) {
    if (std::find(checkSelected.begin(), checkSelected.end(), currentElement) == checkSelected.end()) {
      candidates.push_back(currentElement);
    }
  }
  return candidates;
}