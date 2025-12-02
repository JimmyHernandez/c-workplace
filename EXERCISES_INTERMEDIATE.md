# Ejercicios de C - Nivel Intermedio

Estos ejercicios cubren conceptos más avanzados: arrays, strings, estructuras, y manejo de memoria.

---

## Ejercicio 1: Arrays y Bucles

**Objetivo:** Crear una función que sume todos los elementos de un array.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int sum_array(int* arr, int size);  /* Suma todos los elementos */
```

2. Implementa en `src/math_utils.c`:
```c
int sum_array(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_sum_array(void) {
    printf("Running: test_sum_array\n");
    int arr1[] = {1, 2, 3, 4, 5};
    ASSERT_EQ(sum_array(arr1, 5), 15);
    
    int arr2[] = {0, 0, 0};
    ASSERT_EQ(sum_array(arr2, 3), 0);
    
    int arr3[] = {-1, 1, -1, 1};
    ASSERT_EQ(sum_array(arr3, 4), 0);
}
```

4. Compila y prueba: `make test`

**Concepto aprendido:** Punteros, arrays, iteración sobre arrays.

---

## Ejercicio 2: Encontrar el Máximo en un Array

**Objetivo:** Crear una función que encuentre el valor máximo en un array.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int max_array(int* arr, int size);  /* Retorna el elemento máximo */
```

2. Implementa en `src/math_utils.c`:
```c
int max_array(int* arr, int size) {
    if (size <= 0) return 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_max_array(void) {
    printf("Running: test_max_array\n");
    int arr1[] = {3, 7, 2, 9, 1};
    ASSERT_EQ(max_array(arr1, 5), 9);
    
    int arr2[] = {-5, -1, -10};
    ASSERT_EQ(max_array(arr2, 3), -1);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Búsqueda en arrays, condicionales.

---

## Ejercicio 3: Invertir un Array

**Objetivo:** Crear una función que invierta el orden de los elementos.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
void reverse_array(int* arr, int size);  /* Invierte arr in-place */
```

2. Implementa en `src/math_utils.c`:
```c
void reverse_array(int* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_reverse_array(void) {
    printf("Running: test_reverse_array\n");
    int arr1[] = {1, 2, 3, 4, 5};
    reverse_array(arr1, 5);
    ASSERT_EQ(arr1[0], 5);
    ASSERT_EQ(arr1[4], 1);
    
    int arr2[] = {10, 20};
    reverse_array(arr2, 2);
    ASSERT_EQ(arr2[0], 20);
    ASSERT_EQ(arr2[1], 10);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Modificación in-place, swapping, pointers.

---

## Ejercicio 4: Contar Ocurrencias

**Objetivo:** Crear una función que cuente cuántas veces aparece un número en un array.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int count_occurrences(int* arr, int size, int target);
```

2. Implementa en `src/math_utils.c`:
```c
int count_occurrences(int* arr, int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_count_occurrences(void) {
    printf("Running: test_count_occurrences\n");
    int arr[] = {1, 2, 2, 3, 2, 4, 2};
    ASSERT_EQ(count_occurrences(arr, 7, 2), 4);
    ASSERT_EQ(count_occurrences(arr, 7, 1), 1);
    ASSERT_EQ(count_occurrences(arr, 7, 5), 0);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Búsqueda y conteo en arrays.

---

## Ejercicio 5: Función con Struct

**Objetivo:** Crear una estructura para representar un punto 2D y una función que calcule distancia.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
typedef struct {
    double x;
    double y;
} Point;

double distance(Point p1, Point p2);  /* Distancia Euclidiana */
```

2. Implementa en `src/math_utils.c`:
```c
#include <math.h>

double distance(Point p1, Point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    return sqrt(dx * dx + dy * dy);
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_distance(void) {
    printf("Running: test_distance\n");
    Point p1 = {0.0, 0.0};
    Point p2 = {3.0, 4.0};
    double dist = distance(p1, p2);
    ASSERT_EQ((int)dist, 5);  /* 3-4-5 triangle */
}
```

4. Actualiza el `Makefile` para compilar con `-lm` (math library):
```makefile
CFLAGS ?= -Wall -Wextra -O2 -Iinclude -g -lm
```

5. Prueba: `make test`

**Concepto aprendido:** Structs, typedef, librerías matemáticas.

---

## Ejercicio 6: Duplicar Array

**Objetivo:** Crear una función que aloque memoria y retorne una copia de un array.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int* duplicate_array(int* arr, int size);  /* Retorna una copia */
```

2. Implementa en `src/math_utils.c`:
```c
#include <stdlib.h>

int* duplicate_array(int* arr, int size) {
    int* copy = (int*)malloc(size * sizeof(int));
    if (copy == NULL) return NULL;  /* Error: memoria insuficiente */
    
    for (int i = 0; i < size; i++) {
        copy[i] = arr[i];
    }
    return copy;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_duplicate_array(void) {
    printf("Running: test_duplicate_array\n");
    int original[] = {1, 2, 3};
    int* copy = duplicate_array(original, 3);
    
    ASSERT_EQ(copy[0], 1);
    ASSERT_EQ(copy[2], 3);
    
    free(copy);  /* Libera la memoria */
}
```

4. Prueba: `make test`

**Concepto aprendido:** malloc, free, gestión de memoria dinámica.

---

## Ejercicio 7: Filtrar Array

**Objetivo:** Crear una función que retorne un nuevo array solo con números pares.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int* filter_even(int* arr, int size, int* out_size);
/* Retorna array con solo pares, out_size es el nuevo tamaño */
```

2. Implementa en `src/math_utils.c`:
```c
int* filter_even(int* arr, int size, int* out_size) {
    /* Contar cuántos pares hay */
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) count++;
    }
    
    /* Crear array con esos elementos */
    int* result = (int*)malloc(count * sizeof(int));
    if (result == NULL) {
        *out_size = 0;
        return NULL;
    }
    
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            result[idx++] = arr[i];
        }
    }
    
    *out_size = count;
    return result;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_filter_even(void) {
    printf("Running: test_filter_even\n");
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size;
    int* evens = filter_even(arr, 6, &size);
    
    ASSERT_EQ(size, 3);  /* 2, 4, 6 */
    ASSERT_EQ(evens[0], 2);
    ASSERT_EQ(evens[1], 4);
    ASSERT_EQ(evens[2], 6);
    
    free(evens);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Parámetros por referencia, filtrado dinámico.

---

## Ejercicio 8: Búsqueda Binaria

**Objetivo:** Implementar búsqueda binaria en un array ordenado.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int binary_search(int* arr, int size, int target);
/* Retorna índice si encuentra, -1 si no */
```

2. Implementa en `src/math_utils.c`:
```c
int binary_search(int* arr, int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_binary_search(void) {
    printf("Running: test_binary_search\n");
    int arr[] = {1, 3, 5, 7, 9, 11};
    
    ASSERT_EQ(binary_search(arr, 6, 7), 3);
    ASSERT_EQ(binary_search(arr, 6, 1), 0);
    ASSERT_EQ(binary_search(arr, 6, 11), 5);
    ASSERT_EQ(binary_search(arr, 6, 4), -1);  /* No existe */
}
```

4. Prueba: `make test`

**Concepto aprendido:** Algoritmos eficientes, O(log n).

---

## Ejercicio 9: Bubble Sort

**Objetivo:** Implementar ordenamiento por burbuja.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
void bubble_sort(int* arr, int size);  /* Ordena arr in-place */
```

2. Implementa en `src/math_utils.c`:
```c
void bubble_sort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_bubble_sort(void) {
    printf("Running: test_bubble_sort\n");
    int arr[] = {5, 2, 8, 1, 9};
    bubble_sort(arr, 5);
    
    ASSERT_EQ(arr[0], 1);
    ASSERT_EQ(arr[1], 2);
    ASSERT_EQ(arr[4], 9);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Algoritmos de ordenamiento, O(n²).

---

## Ejercicio 10: Estadísticas de Array

**Objetivo:** Crear una struct que contenga estadísticas (promedio, mínimo, máximo).

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
typedef struct {
    double average;
    int minimum;
    int maximum;
} ArrayStats;

ArrayStats calculate_stats(int* arr, int size);
```

2. Implementa en `src/math_utils.c`:
```c
ArrayStats calculate_stats(int* arr, int size) {
    ArrayStats stats;
    int sum = 0;
    
    stats.minimum = arr[0];
    stats.maximum = arr[0];
    
    for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (arr[i] < stats.minimum) stats.minimum = arr[i];
        if (arr[i] > stats.maximum) stats.maximum = arr[i];
    }
    
    stats.average = (double)sum / size;
    return stats;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_calculate_stats(void) {
    printf("Running: test_calculate_stats\n");
    int arr[] = {1, 2, 3, 4, 5};
    ArrayStats stats = calculate_stats(arr, 5);
    
    ASSERT_EQ((int)stats.average, 3);  /* promedio = 3 */
    ASSERT_EQ(stats.minimum, 1);
    ASSERT_EQ(stats.maximum, 5);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Structs complejos, retorno de múltiples valores.

---

## Cómo Completar

```bash
# Compilar
make clean && make

# Ejecutar tests
make test

# Commit
git add -A
git commit -m "Complete intermediate exercises"
```

---

## Próximo Paso

Cuando termines, avanza a **EXERCISES_ADVANCED.md** 🚀

