# C/C++ Development Stack — Herramientas, librerías y extensiones profesionales

Fecha: 2025-12-04

Esta guía presenta un stack **completo y profesional** para desarrollo en C/C++,
incluyendo compiladores, herramientas de build, testing, análisis estático,
documentación, debugging y extensiones de VS Code.

## Índice

1. [Stack recomendado](#stack-recomendado)
2. [Compiladores y toolchains](#compiladores-y-toolchains)
3. [Build systems](#build-systems)
4. [Testing frameworks](#testing-frameworks)
5. [Librerías estándar y externas](#librerías-estándar-y-externas)
6. [Herramientas de análisis y debugging](#herramientas-de-análisis-y-debugging)
7. [Documentación](#documentación)
8. [Extensiones de VS Code](#extensiones-de-vs-code)
9. [Formateo y linting](#formateo-y-linting)
10. [CI/CD](#cicd)
11. [Stack minimalista vs profesional](#stack-minimalista-vs-profesional)

## Stack recomendado

**Stack minimalista (para empezar):**
```
Compilador: gcc o clang
Build: Makefile
Testing: assert() o CUnit básico
Documentación: Doxygen + Markdown
Análisis: clangd
Formateo: clang-format
CI/CD: GitHub Actions
```

**Stack profesional (empresarial):**
```
Compiladores: gcc, clang (múltiples versiones)
Build: CMake (+ Ninja para velocidad)
Testing: Catch2 o GoogleTest
Documentación: Doxygen + Sphinx
Análisis: clangd + AddressSanitizer + Valgrind
Formateo: clang-format + cpplint
Profiling: perf, gperftools
CI/CD: GitHub Actions + Codecov
Packaging: CPack, conan
```

## Compiladores y toolchains

### GCC (GNU Compiler Collection)

**Qué es:** Compilador estándar en Linux/Unix.

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt install build-essential gcc g++ gdb

# macOS (Homebrew)
brew install gcc

# Windows (MinGW)
# Descarga desde: http://www.mingw.org/
```

**Uso básico:**
```bash
gcc -Wall -Wextra -O2 -g -o programa archivo.c
```

**Flags útiles:**
- `-Wall -Wextra` — activa warnings importantes.
- `-O0` / `-O2` / `-O3` — niveles de optimización.
- `-g` — incluye símbolos de debug.
- `-fanalyzer` — análisis estático integrado (gcc 10+).
- `-fsanitize=address` — detecta memory leaks.

**Documentación:** [gcc.gnu.org](https://gcc.gnu.org/)

### Clang (LLVM)

**Qué es:** Compilador moderno, más fast feedback y análisis.

**Instalación:**
```bash
# Ubuntu/Debian
sudo apt install clang llvm

# macOS
brew install llvm

# Windows
# Descarga: https://releases.llvm.org/download.html
```

**Uso:**
```bash
clang -Wall -Wextra -O2 -g -o programa archivo.c
```

**Ventajas:** Mensajes de error más claros, mejor para análisis.

**Documentación:** [clang.llvm.org](https://clang.llvm.org/)

### Comparación

| Feature | GCC | Clang |
|---------|-----|-------|
| Velocidad de compilación | Media | Rápida |
| Mensajes de error | Básicos | Muy claros |
| Optimización | Excelente | Excelente |
| Integración IDE | Media | Excelente (clangd) |
| Community | Grande | Grande |

**Recomendación:** Usa ambos — compila con ambos para detectar problemas.

## Build systems

### Makefile (minimalista)

**Uso:** Automatizar compilación, testing, documentación.

**Ejemplo:**
```makefile
CC = gcc
CFLAGS = -Wall -Wextra -O2 -Iinclude -g
SRCDIR = src
BINDIR = build

$(BINDIR)/programa: $(SRCDIR)/main.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: build run test clean docs
build: $(BINDIR)/programa
run: build
	$(BINDIR)/programa
test: build
	$(BINDIR)/programa --test
docs:
	doxygen Doxyfile
clean:
	rm -rf $(BINDIR)
```

**Ventajas:** Simple, portable, ampliamente soportado.
**Desventajas:** No es portable a Windows sin msys/cygwin.

### CMake (profesional)

**Qué es:** Generador de build systems multiplataforma.

**Instalación:**
```bash
sudo apt install cmake
```

**Ejemplo `CMakeLists.txt`:**
```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

add_executable(programa src/main.c src/utils.c)
target_include_directories(programa PRIVATE include)

enable_testing()
add_test(NAME test COMMAND programa --test)
```

**Uso:**
```bash
mkdir build && cd build
cmake ..
make
```

**Ventajas:** Multiplataforma, auto-detección, muy flexible.
**Desventajas:** Curva de aprendizaje más pronunciada.

**Documentación:** [cmake.org](https://cmake.org/)

### Comparación

| Feature | Makefile | CMake |
|---------|----------|-------|
| Aprendizaje | Rápido | Medio |
| Multiplataforma | No (sí con MinGW) | Sí |
| Complejidad | Simple | Media-Alta |
| Ecosistema | Estándar | Profesional |

**Recomendación:** Comienza con Makefile, migra a CMake en proyectos complejos.

## Testing frameworks

### Assert (integrado)

**Uso:**
```c
#include <assert.h>

assert(resultado == esperado);
```

**Ventajas:** Integrado, sin dependencias.
**Desventajas:** Termina ejecución, poco flexible.

### CUnit

**Instalación:**
```bash
sudo apt install libcunit1-dev
```

**Ejemplo:**
```c
#include <CUnit/CUnit.h>

void test_suma() {
    CU_ASSERT_EQUAL(suma(2, 3), 5);
}

int main() {
    CU_initialize_registry();
    CU_add_test(suite, "test_suma", test_suma);
    CU_basic_run_tests();
    CU_cleanup_registry();
}
```

**Documentación:** [cunit.sourceforge.net](http://cunit.sourceforge.net/)

### Catch2 (C++)

**Instalación:**
```bash
sudo apt install catch2-dev  # o descargar header-only
```

**Ejemplo:**
```cpp
#include <catch2/catch.hpp>

TEST_CASE("Suma", "[math]") {
    REQUIRE(suma(2, 3) == 5);
    REQUIRE(suma(0, 0) == 0);
}
```

**Ventajas:** Sintaxis moderna, muy flexible, multiplataforma.

### GoogleTest (C++ o C con wrapper)

**Instalación:**
```bash
sudo apt install libgtest-dev
```

**Uso:** Similar a Catch2, muy usado en empresas.

**Documentación:** [google.github.io/googletest](https://google.github.io/googletest/)

## Librerías estándar y externas

### Librerías estándar de C

| Librería | Uso |
|----------|-----|
| `<stdio.h>` | I/O (printf, scanf, file operations) |
| `<stdlib.h>` | Utilidades (malloc, free, exit) |
| `<string.h>` | Strings (strlen, strcpy, strcmp) |
| `<math.h>` | Matemáticas (sin, cos, sqrt) |
| `<time.h>` | Tiempo y fecha |
| `<ctype.h>` | Clasificación de caracteres |
| `<assert.h>` | Aserciones |
| `<errno.h>` | Manejo de errores |
| `<limits.h>` | Límites de tipos |

### Librerías C++ estándar (STL)

| Librería | Contenedor/Utilidad |
|----------|-------------------|
| `<vector>` | Array dinámico |
| `<map>` / `<unordered_map>` | Diccionarios |
| `<set>` / `<unordered_set>` | Conjuntos |
| `<queue>` | Colas |
| `<stack>` | Pilas |
| `<algorithm>` | Algoritmos (sort, find, etc.) |
| `<memory>` | Smart pointers (unique_ptr, shared_ptr) |
| `<string>` | Strings (más safe que char*) |
| `<iostream>` | I/O streams |

### Librerías externas populares

| Librería | Uso | Instalación |
|----------|-----|-------------|
| **OpenSSL** | Criptografía, SSL/TLS | `libssl-dev` |
| **libcurl** | HTTP/HTTPS | `libcurl4-openssl-dev` |
| **zlib** | Compresión | `zlib1g-dev` |
| **libjson-c** | Parsing JSON | `libjson-c-dev` |
| **sqlite3** | Base de datos embebida | `libsqlite3-dev` |
| **pthread** | Threading | `libpthread` (integrado) |
| **boost** | Utilidades C++ avanzadas | `libboost-all-dev` |
| **SDL2** | Gráficos / Games | `libsdl2-dev` |

**Instalación múltiple (Ubuntu):**
```bash
sudo apt install libssl-dev libcurl4-openssl-dev zlib1g-dev libjson-c-dev libsqlite3-dev
```

## Herramientas de análisis y debugging

### GDB (GNU Debugger)

**Instalación:**
```bash
sudo apt install gdb
```

**Comandos básicos:**
```bash
gdb ./programa
(gdb) run                  # ejecuta el programa
(gdb) break main           # breakpoint
(gdb) next                 # siguiente línea
(gdb) step                 # entra en función
(gdb) print variable       # inspecciona variable
(gdb) backtrace            # stack trace
(gdb) quit                 # sale
```

**Compilación con símbolos:**
```bash
gcc -g -o programa archivo.c  # -g para debug
```

**Documentación:** [gnu.org/software/gdb](https://www.gnu.org/software/gdb/)

### Valgrind (Memory debugging)

**Instalación:**
```bash
sudo apt install valgrind
```

**Uso:**
```bash
valgrind --leak-check=full ./programa
```

**Detecta:** Memory leaks, buffer overflows, accesos inválidos.

### AddressSanitizer (Compilador integrado)

**Compilación:**
```bash
gcc -fsanitize=address -g -o programa archivo.c
./programa
```

**Detecta:** Memory leaks, buffer overflows, use-after-free, etc.

**Ventaja:** Más rápido que Valgrind, integrado en compilador.

### Clangd (Análisis estático en IDE)

**Instalación:**
```bash
sudo apt install clangd-12
```

**Integración en VS Code:**
- Extensión: "clangd" (LLVM-vs-code-extensions.vscode-clangd)
- Proporciona: hover info, diagnostics en tiempo real, autocompletado.

## Documentación

### Doxygen

**Instalación:**
```bash
sudo apt install doxygen graphviz
```

**Uso:**
```bash
doxygen -g Doxyfile       # genera config
doxygen Doxyfile          # genera docs
```

**Comentarios Doxygen:**
```c
/**
 * @brief Suma dos números.
 * @param a Primer número.
 * @param b Segundo número.
 * @return La suma de a y b.
 */
int suma(int a, int b) {
    return a + b;
}
```

**Documentación:** [doxygen.nl](https://www.doxygen.nl/)

### Sphinx (Documentación avanzada)

**Instalación:**
```bash
pip install sphinx sphinx-rtd-theme
```

**Uso:** Para documentación técnica completa (tutoriales, guías, APIs).

**Documentación:** [sphinx-doc.org](https://www.sphinx-doc.org/)

## Extensiones de VS Code

**Recomendadas:**

1. **C/C++ (Microsoft)**
   - ID: `ms-vscode.cpptools`
   - IntelliSense, debugging, browsing.

2. **clangd**
   - ID: `llvm-vs-code-extensions.vscode-clangd`
   - Análisis estático superior a IntelliSense.

3. **Makefile Tools**
   - ID: `ms-vscode.makefile-tools`
   - Soporte para Makefile.

4. **CMake Tools**
   - ID: `ms-vscode.cmake-tools`
   - Soporte para CMake.

5. **Clang-Format**
   - ID: `xaver.clang-format`
   - Formateo automático.

6. **Doxygen Documentation Generator**
   - ID: `cschlosser.doxdocgen`
   - Genera plantillas de comentarios.

7. **GitLens**
   - ID: `eamodio.gitlens`
   - Historial y anotaciones Git.

8. **Better Comments**
   - ID: `aaron-bond.better-comments`
   - Colores en comentarios.

**Instalación:**
```bash
code --install-extension ms-vscode.cpptools
code --install-extension llvm-vs-code-extensions.vscode-clangd
code --install-extension ms-vscode.makefile-tools
# etc.
```

## Formateo y linting

### clang-format

**Instalación:**
```bash
sudo apt install clang-format
```

**Configuración (`.clang-format`):**
```yaml
BasedOnStyle: LLVM
IndentWidth: 4
ColumnLimit: 80
```

**Uso:**
```bash
clang-format -i archivo.c  # formatea en-place
```

### cpplint

**Instalación:**
```bash
pip install cpplint
```

**Uso:**
```bash
cpplint archivo.c
```

### flawfinder (seguridad)

**Instalación:**
```bash
sudo apt install flawfinder
```

**Uso:**
```bash
flawfinder archivo.c
```

## CI/CD

### GitHub Actions workflow

**Ejemplo `.github/workflows/build.yml`:**
```yaml
name: Build and Test

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3
      - name: Install dependencies
        run: |
          sudo apt update
          sudo apt install -y gcc g++ make clang-format valgrind
      - name: Build
        run: make build
      - name: Format check
        run: clang-format -n src/*.c include/*.h
      - name: Test
        run: make test
      - name: Docs
        run: make docs
```

## Stack minimalista vs profesional

### Minimalista (para empezar)

```
Compilador: gcc
Build: Makefile
Testing: assert()
IDE: VS Code + C/C++ extension
Documentación: Doxygen
Análisis: clangd
Versionado: Git + GitHub
```

**Instalación total (Ubuntu):**
```bash
sudo apt install build-essential gcc g++ gdb clang clang-format doxygen graphviz
code --install-extension ms-vscode.cpptools
code --install-extension llvm-vs-code-extensions.vscode-clangd
```

### Profesional (empresarial)

```
Compiladores: gcc, clang (múltiples versiones)
Build: CMake + Ninja
Testing: Catch2 + GoogleTest
IDE: VS Code con full toolchain
Documentación: Doxygen + Sphinx
Análisis: clangd + AddressSanitizer + Valgrind
Linters: clang-format + flawfinder + cpplint
Profiling: perf, gperftools
CI/CD: GitHub Actions + Codecov
Packaging: CPack, conan
Versionado: Git con GitFlow
```

**Instalación total (Ubuntu):**
```bash
sudo apt install build-essential gcc g++ gdb clang cmake ninja-build \
  libcatch2-dev libgtest-dev doxygen graphviz valgrind clang-format \
  clang-tools python3-dev libboost-all-dev sqlite3 libsqlite3-dev
pip install cpplint flawfinder sphinx sphinx-rtd-theme conan
```

## Siguientes pasos

1. **Comienza con minimalista:** gcc, Makefile, assert(), VS Code.
2. **Experimenta** con cada herramienta en proyectos pequeños.
3. **Migra a profesional** cuando manejes proyectos más complejos.
4. **Especialízate** en las que más uses (CMake, Valgrind, etc.).
5. **Lee documentación oficial** de cada herramienta.

## Recursos útiles

- **C Standard Library:** [cppreference.com/w/c](https://en.cppreference.com/w/c)
- **C++ Standard Library:** [cppreference.com/w/cpp](https://en.cppreference.com/w/cpp)
- **Compiler Explorer:** [godbolt.org](https://godbolt.org/) — visualiza assembly.
- **Open Source Projects:** Linux kernel, Git, SQLite, Redis.

