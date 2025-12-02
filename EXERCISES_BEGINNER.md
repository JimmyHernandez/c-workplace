# Ejercicios de C - Nivel Principiante

Estos ejercicios te ayudarán a aprender los conceptos básicos de C. Completa cada uno y pruébalo con `make test`.

---

## Ejercicio 1: Función de Suma Simple

**Objetivo:** Crear una función que sume dos números.

**Tarea:**
1. Abre `include/math_utils.h`
2. Verifica que existe `int math_add(int a, int b);`
3. Abre `src/math_utils.c` y verifica la implementación
4. En `tests/test_main.c`, agrega un test:
```c
void test_sum_simple(void) {
    printf("Running: test_sum_simple\n");
    ASSERT_EQ(math_add(2, 3), 5);
    ASSERT_EQ(math_add(0, 0), 0);
    ASSERT_EQ(math_add(-5, 5), 0);
}
```
5. Llama `test_sum_simple()` en `main()`
6. Ejecuta: `make test`

**Concepto aprendido:** Funciones simples, parámetros, return.

---

## Ejercicio 2: Función de Resta

**Objetivo:** Crear una función que reste dos números.

**Tarea:**
1. Abre `include/math_utils.h`
2. Verifica que existe `int math_subtract(int a, int b);`
3. Abre `src/math_utils.c` y verifica la implementación
4. En `tests/test_main.c`, agrega un test:
```c
void test_subtract(void) {
    printf("Running: test_subtract\n");
    ASSERT_EQ(math_subtract(10, 3), 7);
    ASSERT_EQ(math_subtract(5, 5), 0);
    ASSERT_EQ(math_subtract(0, 5), -5);
}
```
5. Llama `test_subtract()` en `main()`
6. Ejecuta: `make test`

**Concepto aprendido:** Lógica negativa, números negativos.

---

## Ejercicio 3: Función de Multiplicación

**Objetivo:** Crear una función que multiplique dos números.

**Tarea:**
1. Abre `include/math_utils.h`
2. Verifica que existe `int math_multiply(int a, int b);`
3. Abre `src/math_utils.c` y verifica la implementación
4. En `tests/test_main.c`, agrega un test:
```c
void test_multiply(void) {
    printf("Running: test_multiply\n");
    ASSERT_EQ(math_multiply(4, 5), 20);
    ASSERT_EQ(math_multiply(0, 100), 0);
    ASSERT_EQ(math_multiply(-3, 4), -12);
}
```
5. Llama `test_multiply()` en `main()`
6. Ejecuta: `make test`

**Concepto aprendido:** Multiplicación, casos especiales (cero, negativos).

---

## Ejercicio 4: Función que Cuenta Dígitos

**Objetivo:** Crear una función que cuente cuántos dígitos tiene un número.

**Tareas:**
1. Agrega la declaración en `include/math_utils.h`:
```c
int count_digits(int num);  /* Retorna cuántos dígitos tiene num */
```

2. Implementa en `src/math_utils.c`:
```c
int count_digits(int num) {
    if (num == 0) return 1;
    int count = 0;
    if (num < 0) num = -num;  /* Ignora el signo */
    while (num > 0) {
        count++;
        num /= 10;
    }
    return count;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_count_digits(void) {
    printf("Running: test_count_digits\n");
    ASSERT_EQ(count_digits(0), 1);
    ASSERT_EQ(count_digits(5), 1);
    ASSERT_EQ(count_digits(42), 2);
    ASSERT_EQ(count_digits(1000), 4);
    ASSERT_EQ(count_digits(-123), 3);
}
```

4. Actualiza `Makefile` si es necesario
5. Ejecuta: `make test`

**Concepto aprendido:** Bucles (while), condicionales, división entera.

---

## Ejercicio 5: Función que Calcula el Absoluto

**Objetivo:** Crear una función que retorne el valor absoluto de un número.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int absolute(int num);  /* Retorna el valor absoluto */
```

2. Implementa en `src/math_utils.c`:
```c
int absolute(int num) {
    return (num < 0) ? -num : num;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_absolute(void) {
    printf("Running: test_absolute\n");
    ASSERT_EQ(absolute(5), 5);
    ASSERT_EQ(absolute(-5), 5);
    ASSERT_EQ(absolute(0), 0);
    ASSERT_EQ(absolute(-999), 999);
}
```

4. Llama `test_absolute()` en `main()`
5. Ejecuta: `make test`

**Concepto aprendido:** Operador ternario (?:), condicionales.

---

## Ejercicio 6: Función que Comprueba si es Par

**Objetivo:** Crear una función que diga si un número es par o impar.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int is_even(int num);  /* Retorna 1 si es par, 0 si es impar */
```

2. Implementa en `src/math_utils.c`:
```c
int is_even(int num) {
    return (num % 2 == 0) ? 1 : 0;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_is_even(void) {
    printf("Running: test_is_even\n");
    ASSERT_EQ(is_even(2), 1);
    ASSERT_EQ(is_even(3), 0);
    ASSERT_EQ(is_even(0), 1);
    ASSERT_EQ(is_even(-4), 1);
    ASSERT_EQ(is_even(-3), 0);
}
```

4. Llama `test_is_even()` en `main()`
5. Ejecuta: `make test`

**Concepto aprendido:** Operador módulo (%), lógica booleana.

---

## Ejercicio 7: Función que Calcula Potencia

**Objetivo:** Crear una función que eleve un número a una potencia.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int power(int base, int exp);  /* Retorna base^exp */
```

2. Implementa en `src/math_utils.c`:
```c
int power(int base, int exp) {
    if (exp < 0) return 0;  /* No manejamos exponentes negativos */
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_power(void) {
    printf("Running: test_power\n");
    ASSERT_EQ(power(2, 0), 1);
    ASSERT_EQ(power(2, 3), 8);
    ASSERT_EQ(power(5, 2), 25);
    ASSERT_EQ(power(10, 3), 1000);
    ASSERT_EQ(power(0, 5), 0);
}
```

4. Llama `test_power()` en `main()`
5. Ejecuta: `make test`

**Concepto aprendido:** Bucles for, exponentes.

---

## Ejercicio 8: Función que Encuentra el Máximo

**Objetivo:** Crear una función que retorne el número mayor entre dos.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int max(int a, int b);  /* Retorna el mayor de a y b */
```

2. Implementa en `src/math_utils.c`:
```c
int max(int a, int b) {
    return (a > b) ? a : b;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_max(void) {
    printf("Running: test_max\n");
    ASSERT_EQ(max(3, 5), 5);
    ASSERT_EQ(max(10, 2), 10);
    ASSERT_EQ(max(-5, -10), -5);
    ASSERT_EQ(max(0, 0), 0);
}
```

4. Llama `test_max()` en `main()`
5. Ejecuta: `make test`

**Concepto aprendido:** Comparaciones, operador ternario.

---

## Ejercicio 9: Función que Suma Tres Números

**Objetivo:** Crear una función que sume tres números.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int sum_three(int a, int b, int c);
```

2. Implementa en `src/math_utils.c`:
```c
int sum_three(int a, int b, int c) {
    return a + b + c;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_sum_three(void) {
    printf("Running: test_sum_three\n");
    ASSERT_EQ(sum_three(1, 2, 3), 6);
    ASSERT_EQ(sum_three(0, 0, 0), 0);
    ASSERT_EQ(sum_three(-1, 1, 5), 5);
}
```

4. Llama `test_sum_three()` en `main()`
5. Ejecuta: `make test`

**Concepto aprendido:** Funciones con múltiples parámetros.

---

## Ejercicio 10: Función que Invierte un Número

**Objetivo:** Crear una función que invierta los dígitos de un número.

**Ejemplo:** `invert(123)` retorna `321`

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int invert_number(int num);  /* Retorna el número invertido */
```

2. Implementa en `src/math_utils.c`:
```c
int invert_number(int num) {
    int result = 0;
    int original = num;
    if (num < 0) num = -num;  /* Trabaja con positivos */
    
    while (num > 0) {
        result = result * 10 + (num % 10);
        num /= 10;
    }
    
    return (original < 0) ? -result : result;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_invert_number(void) {
    printf("Running: test_invert_number\n");
    ASSERT_EQ(invert_number(123), 321);
    ASSERT_EQ(invert_number(100), 1);
    ASSERT_EQ(invert_number(5), 5);
    ASSERT_EQ(invert_number(-123), -321);
}
```

4. Llama `test_invert_number()` en `main()`
5. Ejecuta: `make test`

**Concepto aprendido:** Manipulación de números, bucles complejos.

---

## Cómo Completar Los Ejercicios

1. **Lee el enunciado** — Entiende qué debes hacer
2. **Escribe el código** — Agrega las funciones y tests
3. **Compila** — Ejecuta `make clean && make`
4. **Prueba** — Ejecuta `make test`
5. **Commit** — Guarda tu progreso: `git add -A && git commit -m "Complete exercise X"`

---

## Comandos Útiles

```bash
# Ver si hay errores de compilación
make clean

# Compilar todo
make

# Ejecutar tests
make test

# Ver el estado de git
git status

# Commit
git add -A
git commit -m "Complete beginner exercises"
```

---

## Próximo Paso

Cuando termines todos estos ejercicios, avanza a **EXERCISES_INTERMEDIATE.md** 🎓

