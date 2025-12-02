# Proyectos de C - Construcción Real

Estos son proyectos inspirados en cursos de MIT, Harvard y otros institutos de excelencia. Son desafiantes, educativos y te preparan para problemas reales.

---

## 🔰 NIVEL PRINCIPIANTE

### Proyecto 1: Calculadora Interactiva

**Objetivo:** Crear una calculadora de línea de comandos que realice operaciones matemáticas.

**Características:**
- Menú interactivo
- Operaciones: suma, resta, multiplicación, división, potencia, raíz cuadrada
- Historial de operaciones (últimas 10)
- Validación de entrada

**Estructura sugerida:**
```
src/
  calculator.c       # Lógica principal
  operations.c       # Funciones de cálculo

include/
  calculator.h
  operations.h

tests/
  test_calculator.c
```

**Requisitos:**
1. Función `double add(double a, double b)`
2. Función `double calculate(char op, double a, double b)`
3. Array para historial: `history[10]`
4. Función `void display_menu()`
5. Función `void add_to_history(double result)`

**Salida esperada:**
```
=== Calculadora Interactiva ===
1. Suma
2. Resta
3. Multiplicación
4. División
5. Potencia
6. Ver historial
7. Salir

Selecciona operación: 1
Primer número: 5
Segundo número: 3
Resultado: 8.000000
```

**Conceptos aprendidos:**
- Entrada/salida interactiva
- Funciones modulares
- Arrays
- Validación de entrada
- Menús

**Tiempo estimado:** 2-3 horas

**Extensiones (opcional):**
- Guardar historial en archivo
- Operaciones con múltiples números
- Modo científico (seno, coseno, logaritmo)

---

### Proyecto 2: Gestor de Contactos

**Objetivo:** Crear una aplicación para guardar y consultar contactos.

**Características:**
- Agregar contactos (nombre, teléfono, email)
- Buscar por nombre
- Listar todos los contactos
- Eliminar contacto
- Guardar/cargar desde archivo

**Estructura sugerida:**
```
src/
  contacts.c         # Lógica de contactos
  file_handler.c     # Manejo de archivos

include/
  contacts.h
  file_handler.h

tests/
  test_contacts.c

data/
  contacts.txt       # Archivo de datos
```

**Estructura de datos:**
```c
typedef struct {
    char name[50];
    char phone[15];
    char email[50];
} Contact;
```

**Funciones requeridas:**
1. `Contact* load_contacts(const char* filename, int* count)`
2. `void add_contact(Contact* contacts, int* count, Contact new_contact)`
3. `Contact* search_contact(Contact* contacts, int count, const char* name)`
4. `void delete_contact(Contact* contacts, int* count, const char* name)`
5. `void save_contacts(Contact* contacts, int count, const char* filename)`

**Salida esperada:**
```
=== Gestor de Contactos ===
1. Agregar contacto
2. Buscar contacto
3. Listar todos
4. Eliminar contacto
5. Salir

Opción: 1
Nombre: Juan
Teléfono: 555-1234
Email: juan@example.com
✓ Contacto agregado
```

**Conceptos aprendidos:**
- Structs complejos
- Arreglos de structs
- I/O de archivos
- Búsqueda y filtrado
- Manipulación de strings

**Tiempo estimado:** 3-4 horas

---

### Proyecto 3: Editor de Texto Minimalista

**Objetivo:** Crear un editor de texto simple con búsqueda y reemplazo.

**Características:**
- Cargar archivo de texto
- Mostrar líneas numeradas
- Búsqueda de palabra
- Contar palabras, líneas, caracteres
- Reemplazar palabra
- Guardar cambios

**Estructura sugerida:**
```
src/
  editor.c           # Lógica principal
  text_utils.c       # Utilidades de texto

include/
  editor.h
  text_utils.h

tests/
  test_editor.c
```

**Funciones requeridas:**
1. `char** load_file(const char* filename, int* line_count)`
2. `int count_lines(const char* filename)`
3. `int count_words(const char* text)`
4. `char* find_word(char* text, const char* word)`
5. `char* replace_word(char* text, const char* old, const char* new)`

**Salida esperada:**
```
=== Editor de Texto ===
Archivo cargado: document.txt
1: Lorem ipsum dolor sit amet
2: consectetur adipiscing elit
3: sed do eiusmod tempor

Estadísticas:
- Líneas: 3
- Palabras: 15
- Caracteres: 82

Buscar palabra: Lorem
✓ Encontrado en línea 1

Reemplazar 'Lorem' por 'Ipsum'? (s/n): s
✓ Reemplazado
```

**Conceptos aprendidos:**
- Manipulación de strings avanzada
- Lectura/escritura de archivos
- Arrays de strings
- Algoritmos de búsqueda
- Gestión de memoria con strings

**Tiempo estimado:** 3-4 horas

---

## 🎯 NIVEL INTERMEDIO

### Proyecto 4: Sistema de Gestión de Estudiantes

**Objetivo:** Crear un sistema para administrar estudiantes, calificaciones y promedios.

**Características:**
- Registrar estudiantes con matrícula
- Agregar calificaciones por materia
- Calcular promedio general
- Buscar estudiante por ID o nombre
- Generar reporte de desempeño
- Identificar estudiantes en riesgo (promedio < 2.0)

**Estructura sugerida:**
```
src/
  student_system.c
  grade_calculator.c
  file_handler.c

include/
  student_system.h
  grade_calculator.h

tests/
  test_student_system.c

data/
  students.csv
```

**Estructuras de datos:**
```c
typedef struct {
    char name[50];
    int matricula;
    double grades[10];      // Máximo 10 calificaciones
    int grade_count;
} Student;

typedef struct {
    Student* students;
    int count;
} StudentSystem;
```

**Funciones requeridas:**
1. `StudentSystem* create_system()`
2. `void add_student(StudentSystem* sys, Student s)`
3. `void add_grade(StudentSystem* sys, int matricula, double grade)`
4. `double calculate_average(Student* s)`
5. `Student* search_student(StudentSystem* sys, int matricula)`
6. `void print_risk_students(StudentSystem* sys)`
7. `void save_to_csv(StudentSystem* sys, const char* filename)`
8. `void free_system(StudentSystem* sys)`

**Salida esperada:**
```
=== Sistema de Gestión de Estudiantes ===

Estudiante: Juan Pérez (Matrícula: 2023001)
Calificaciones: 3.5, 4.0, 3.8, 4.2
Promedio: 3.88

Estudiantes en riesgo académico:
- María García (Promedio: 1.9)
- Carlos López (Promedio: 1.5)
```

**Conceptos aprendidos:**
- Estructuras anidadas
- Gestión de sistemas
- Cálculos estadísticos
- I/O de archivos CSV
- Búsqueda y filtrado avanzado

**Tiempo estimado:** 5-6 horas

---

### Proyecto 5: Simulador de Banco

**Objetivo:** Crear un sistema bancario con cuentas, transferencias y transacciones.

**Características:**
- Crear cuentas bancarias
- Depositar/retirar dinero
- Transferir entre cuentas
- Consultar saldo
- Historial de transacciones (últimas 50)
- Reporte de movimientos

**Estructura sugerida:**
```
src/
  bank_system.c
  account.c
  transaction.c

include/
  bank_system.h
  account.h
  transaction.h

tests/
  test_bank_system.c
```

**Estructuras de datos:**
```c
typedef struct {
    char date[11];      // YYYY-MM-DD
    char type[20];      // "Depósito", "Retiro", "Transferencia"
    double amount;
    double balance_after;
} Transaction;

typedef struct {
    int account_id;
    char owner[50];
    double balance;
    Transaction transactions[50];
    int transaction_count;
} BankAccount;
```

**Funciones requeridas:**
1. `BankAccount* create_account(int id, const char* owner, double initial_balance)`
2. `int deposit(BankAccount* acc, double amount)`
3. `int withdraw(BankAccount* acc, double amount)`
4. `int transfer(BankAccount* from, BankAccount* to, double amount)`
5. `void print_statement(BankAccount* acc)`
6. `void print_transaction_history(BankAccount* acc, int limit)`

**Salida esperada:**
```
=== Simulador de Banco ===

Cuenta: Juan Pérez (ID: 1001)
Saldo: $5,500.00

Transacciones (últimas 5):
1. 2025-12-02 | Depósito      | +1000.00 | Saldo: 5500.00
2. 2025-12-01 | Retiro        | -500.00  | Saldo: 4500.00
3. 2025-11-30 | Transferencia | -2000.00 | Saldo: 5000.00

Transferencia de Juan a María: $1000.00
✓ Transferencia exitosa
```

**Conceptos aprendidos:**
- Historial de transacciones
- Validación de operaciones
- Manejo de dinero (evitar errores de punto flotante)
- Auditoría y trazabilidad
- Operaciones entre entidades

**Tiempo estimado:** 5-7 horas

---

### Proyecto 6: Analizador de Logs

**Objetivo:** Crear una herramienta para analizar archivos de log de sistemas.

**Características:**
- Leer archivo de log
- Filtrar por tipo de error
- Contar ocurrencias de patrones
- Buscar por rango de tiempo
- Generar reporte de estadísticas
- Identificar patrones sospechosos

**Estructura sugerida:**
```
src/
  log_analyzer.c
  log_parser.c
  statistics.c

include/
  log_analyzer.h

tests/
  test_log_analyzer.c

data/
  system.log
```

**Estructuras de datos:**
```c
typedef struct {
    char timestamp[20];     // YYYY-MM-DD HH:MM:SS
    char level[10];         // ERROR, WARNING, INFO, DEBUG
    char source[50];        // Módulo que generó el log
    char message[256];      // Mensaje del log
} LogEntry;
```

**Funciones requeridas:**
1. `LogEntry* parse_logs(const char* filename, int* count)`
2. `int count_by_level(LogEntry* logs, int count, const char* level)`
3. `LogEntry* filter_by_level(LogEntry* logs, int count, const char* level, int* result_count)`
4. `LogEntry* filter_by_time(LogEntry* logs, int count, const char* start, const char* end, int* result_count)`
5. `void print_statistics(LogEntry* logs, int count)`
6. `void detect_anomalies(LogEntry* logs, int count)`

**Salida esperada:**
```
=== Analizador de Logs ===

Estadísticas:
- Total de entradas: 1245
- Errores: 45 (3.6%)
- Advertencias: 234 (18.8%)
- Info: 966 (77.6%)

Anomalías detectadas:
⚠️ 23 errores en 5 minutos (módulo: database)
⚠️ Patrón repetitivo: "Connection timeout" (89 veces)
```

**Conceptos aprendidos:**
- Parsing de texto
- Expresiones regulares simples
- Análisis estadístico
- Detección de patrones
- Filtrado temporal

**Tiempo estimado:** 5-6 horas

---

## 🚀 NIVEL AVANZADO

### Proyecto 7: Compilador Minimalista

**Objetivo:** Crear un compilador/intérprete para un lenguaje simple.

**Características:**
- Lexer: Tokenizar entrada
- Parser: Construir árbol sintáctico
- Evaluador: Ejecutar instrucciones
- Variables y asignaciones
- Operaciones aritméticas
- Condicionales (if/else)
- Bucles (while)

**Lenguaje soportado:**
```
var x = 10;
var y = 20;
if (x < y) {
    print(x + y);
}
while (x < 15) {
    x = x + 1;
    print(x);
}
```

**Estructura sugerida:**
```
src/
  lexer.c             # Tokenización
  parser.c            # Parsing
  interpreter.c       # Evaluación
  symbol_table.c      # Tabla de símbolos

include/
  lexer.h
  parser.h
  interpreter.h

tests/
  test_interpreter.c
```

**Estructuras de datos:**
```c
typedef enum {
    TOKEN_NUMBER, TOKEN_IDENTIFIER, TOKEN_PLUS, TOKEN_MINUS,
    TOKEN_IF, TOKEN_WHILE, TOKEN_LBRACE, TOKEN_RBRACE, TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[50];
    double value;
} Token;

typedef struct {
    char name[50];
    double value;
} Variable;
```

**Funciones requeridas:**
1. `Token* lexer(const char* input, int* token_count)`
2. `ASTNode* parser(Token* tokens, int count)`
3. `double evaluate(ASTNode* node)`
4. `void execute_program(const char* code)`

**Ejemplo:**
```
Input:
var result = 0;
var i = 1;
while (i <= 5) {
    result = result + i;
    i = i + 1;
}
print(result);

Output: 15
```

**Conceptos aprendidos:**
- Teoría de compiladores
- Tokenización y parsing
- Árboles sintácticos (AST)
- Tablas de símbolos
- Interpretación y evaluación

**Tiempo estimado:** 8-10 horas

---

### Proyecto 8: Base de Datos Simple (B-Tree)

**Objetivo:** Implementar una base de datos simple con índices B-Tree.

**Características:**
- Crear/eliminar registros
- Búsqueda indexada O(log n)
- Rango de consultas
- Persistencia en disco
- Transacciones básicas
- Índices secundarios

**Estructura sugerida:**
```
src/
  btree.c             # Estructura B-Tree
  database.c          # Motor de BD
  persistence.c       # Guardar/cargar

include/
  btree.h
  database.h

tests/
  test_database.c

data/
  database.db
```

**Estructuras de datos:**
```c
typedef struct BTreeNode {
    int* keys;
    struct BTreeNode** children;
    int* records;
    int key_count;
    int is_leaf;
} BTreeNode;

typedef struct {
    int id;
    char name[50];
    int age;
    double salary;
} Employee;
```

**Funciones requeridas:**
1. `BTreeNode* create_btree(int order)`
2. `void insert(BTreeNode* root, int key, int record_id)`
3. `int* search_range(BTreeNode* root, int min, int max, int* count)`
4. `void delete_key(BTreeNode* root, int key)`
5. `void save_database(BTreeNode* root, const char* filename)`
6. `BTreeNode* load_database(const char* filename)`

**Salida esperada:**
```
=== Base de Datos Simple ===

Insertar 100,000 registros...
Índice creado en O(log n)

Buscar empleados con edad entre 25 y 35:
- ID 1001: Juan, 28, $5000
- ID 1005: María, 30, $6000
- ID 1012: Carlos, 32, $5500

Tiempo de búsqueda: 0.002 segundos
```

**Conceptos aprendidos:**
- Estructuras de datos balanceadas
- Complejidad algorítmica
- Persistencia de datos
- Indexación
- Consultas de rango

**Tiempo estimado:** 8-12 horas

---

### Proyecto 9: Máquina Virtual Simple (VM)

**Objetivo:** Crear una máquina virtual que ejecute bytecode.

**Características:**
- Máquina de pila (stack machine)
- Conjunto de instrucciones: PUSH, POP, ADD, SUB, MUL, DIV
- Variables locales y globales
- Funciones y llamadas
- Loops y condicionales
- Garbage collection básico

**Instrucciones soportadas:**
```
PUSH value      ; Empuja valor a la pila
POP             ; Saca valor de la pila
ADD             ; Suma dos valores
SUB             ; Resta
MUL             ; Multiplica
DIV             ; Divide
STORE var       ; Guarda en variable
LOAD var        ; Carga de variable
JMP address     ; Salto incondicional
JIF address     ; Salto si verdadero
CALL func       ; Llamada a función
RET             ; Retorno
HALT            ; Fin del programa
```

**Estructura sugerida:**
```
src/
  vm.c                # Motor de VM
  bytecode.c          # Compilador a bytecode
  stack.c             # Pila virtual

include/
  vm.h

tests/
  test_vm.c
```

**Estructuras de datos:**
```c
typedef enum {
    OP_PUSH, OP_POP, OP_ADD, OP_SUB, OP_MUL, OP_DIV,
    OP_STORE, OP_LOAD, OP_JMP, OP_JIF, OP_HALT
} Opcode;

typedef struct {
    Opcode opcode;
    int operand;
} Instruction;

typedef struct {
    Instruction* instructions;
    int instruction_count;
    double* stack;
    int stack_top;
    double* variables;
    int variable_count;
} VM;
```

**Funciones requeridas:**
1. `VM* create_vm(int stack_size)`
2. `void execute(VM* vm)`
3. `void push(VM* vm, double value)`
4. `double pop(VM* vm)`
5. `Instruction* compile(const char* code, int* count)`

**Ejemplo:**
```
Programa (pseudo-código):
PUSH 10
PUSH 5
ADD
STORE result
PUSH result
PRINT

Output: 15
```

**Conceptos aprendidos:**
- Arquitectura de procesadores
- Máquinas de pila
- Gestión de memoria
- Optimización de bytecode
- Compilación e interpretación

**Tiempo estimado:** 10-15 horas

---

## 📋 Tabla Resumen

| Proyecto | Nivel | Horas | Conceptos Clave |
|----------|-------|-------|-----------------|
| 1. Calculadora | Principiante | 2-3 | I/O, Funciones, Arrays |
| 2. Contactos | Principiante | 3-4 | Structs, Archivos |
| 3. Editor de Texto | Principiante | 3-4 | Strings, Búsqueda |
| 4. Gestión Estudiantes | Intermedio | 5-6 | Sistemas, CSV |
| 5. Banco | Intermedio | 5-7 | Transacciones, Historial |
| 6. Análisis de Logs | Intermedio | 5-6 | Parsing, Estadísticas |
| 7. Compilador | Avanzado | 8-10 | Lexer, Parser, AST |
| 8. Base de Datos | Avanzado | 8-12 | B-Tree, Indexación |
| 9. Máquina Virtual | Avanzado | 10-15 | Bytecode, Stack |

---

## 🎓 Cómo Trabajar con Estos Proyectos

### Para Cada Proyecto:

1. **Crea una rama en git:**
   ```bash
   git checkout -b project/calculator
   ```

2. **Organiza la estructura:**
   ```bash
   mkdir -p src include tests data
   ```

3. **Implementa incrementalmente:**
   - Comienza con la funcionalidad básica
   - Agrega tests conforme avanzas
   - Refactoriza si es necesario

4. **Commit frecuente:**
   ```bash
   git add -A
   git commit -m "Add calculator functionality"
   ```

5. **Prueba exhaustivamente:**
   ```bash
   make clean
   make test
   ```

### Debugging:

```bash
# Compilar con símbolos de depuración
make clean
gcc -g src/*.c tests/test.c -Iinclude -o test

# Ejecutar con gdb
gdb ./test

# Dentro de gdb
(gdb) break main
(gdb) run
(gdb) next / step
(gdb) print variable_name
```

---

## 💡 Recursos Adicionales

- **MIT 6.828** (Operating Systems) — inspiración para máquina virtual
- **Harvard CS50** — construcción de compiladores
- **Crafting Interpreters** — máquinas virtuales y bytecode
- **CLRS** (Introduction to Algorithms) — B-Trees y algoritmos

---

## 🏆 Próximos Pasos Después de Estos Proyectos

1. Contribuir a proyectos C reales (Linux kernel, SQLite, Redis)
2. Aprender sistemas operativos
3. Especializarse en áreas:
   - **Embebidos:** Arduino, Raspberry Pi
   - **Sistemas:** Drivers, kernels
   - **Compiladores:** GCC, LLVM
   - **Bases de datos:** PostgreSQL, SQLite

---

**Elige un proyecto y comienza hoy. La práctica es la mejor forma de aprender C.** 💪

