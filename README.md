# Actividad 3.4 – Árbol Binario de Búsqueda (BST) para IPs más frecuentes

**Autor:** Paul Aureliano Sarmiento Baldenebro  
**Equipo 2**  
**Materia:** Estructura de Datos  
**Institución:** Tecnológico de Monterrey  

---

## 🧠 Descripción General

Este programa extiende la actividad integradora anterior, en la cual se ordenaba una bitácora por dirección IP.  
En esta versión, además de ordenar el archivo, se agregan los accesos por IP (sin tomar en cuenta el puerto) y se almacenan en un **árbol binario de búsqueda (BST)**.  

El objetivo principal es **encontrar las IPs con más accesos** y mostrar en pantalla las más frecuentes junto con su cantidad de intentos.

---

## ⚙️ Funcionamiento del Programa

1. **Lectura del archivo de entrada (`bitacora2.txt`)**  
   - Se leen todas las líneas y se extrae la dirección IP y su puerto.  
   - Se calcula una *IP ponderada* para poder ordenar los registros numéricamente.  

2. **Ordenamiento con Merge Sort**  
   - Se reutiliza el algoritmo Merge Sort implementado en la actividad anterior, aplicado sobre una lista enlazada.  
   - Complejidad: **O(n log n)**.

3. **Generación del archivo ordenado (`bitacoraOrdenadaIP-Eq2-BST.txt`)**  
   - Se escriben las líneas ordenadas por dirección IP.

4. **Limpieza de IPs (sin puerto)**  
   - Se lee el archivo ordenado y se elimina la parte del puerto (`:` y lo que le sigue).  
   - Las IPs limpias se almacenan en un vector.

5. **Construcción del BST (`makeTree`)**  
   - Se cuentan las repeticiones consecutivas de cada IP.  
   - Por cada grupo de repeticiones, se inserta en el árbol binario de búsqueda con:
     - **Llave:** número de accesos.  
     - **Valor:** dirección IP o lista de IPs con esa frecuencia.  
   - Complejidad de inserción: **O(h)**, promedio **O(log n)**, peor caso **O(n)**.

6. **Recorrido e impresión (`inorder`)**  
   - Se usa un recorrido **inorder inverso (right → root → left)** para obtener los accesos de mayor a menor.  
   - Se imprime solo una cantidad limitada de IPs (por ejemplo, las 5 más frecuentes).  
   - Complejidad: **O(n)**, con límite de impresión para mayor eficiencia.

---

## 🧩 Estructuras y métodos principales

### `MyBST`
- `insert(int data, std::string ip)`: Inserta un nuevo nodo con la frecuencia de accesos y la IP.  
  Si la frecuencia ya existe, se agrega la IP al vector del nodo correspondiente.
- `inorder(MyNodeBST* current, std::vector<std::pair<std::vector<std::string>, int>>& result)`:  
  Recorre el árbol en orden descendente y llena un vector con las IPs y sus frecuencias.
- `inorder(int num)`: Imprime las IPs con más accesos, limitando el total mostrado a `num`.

### `AlgoritmosLinked`
- `makeTree(const std::vector<std::string>& v, int elements)`:  
  Cuenta repeticiones consecutivas de IPs y construye el BST a partir de ellas.

---

## 🧮 Complejidad de los algoritmos

| Etapa | Algoritmo | Complejidad |
|--------|------------|-------------|
| Ordenamiento | Merge Sort sobre lista enlazada | **O(n log n)** |
| Conteo de repeticiones | Recorrido lineal sobre vector ordenado | **O(n)** |
| Inserción en BST | Por nodo: **O(h)** → promedio **O(log n)**, peor caso **O(n)** |
| Recorrido e impresión | Inorder inverso limitado | **O(n)** |

---

## 💡 Resultados esperados

El programa muestra en consola las IPs con más accesos en el siguiente formato:

