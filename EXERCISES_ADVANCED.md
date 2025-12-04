# Ejercicios de C - Nivel Avanzado

Estos ejercicios cubren conceptos avanzados: recursión, listas enlazadas, manejo de archivos, y optimización.

---

## Ejercicio 1: Recursión - Factorial

**Objetivo:** Implementar factorial usando recursión.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
long factorial(int n);  /* Calcula n! de forma recursiva */
```

2. Implementa en `src/math_utils.c`:
```c
long factorial(int n) {
    if (n < 0) return -1;  /* Error */
    if (n == 0 || n == 1) return 1;
    return n * factorial(n - 1);
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_factorial(void) {
    printf("Running: test_factorial\n");
    ASSERT_EQ(factorial(0), 1);
    ASSERT_EQ(factorial(1), 1);
    ASSERT_EQ(factorial(5), 120);
    ASSERT_EQ(factorial(10), 3628800);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Recursión, base case, casos especiales.

---

## Ejercicio 2: Recursión - Fibonacci

**Objetivo:** Implementar Fibonacci (versión simple y optimizada).

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
long fibonacci(int n);  /* Calcula el n-ésimo número de Fibonacci */
```

2. Implementa en `src/math_utils.c`:
```c
long fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_fibonacci(void) {
    printf("Running: test_fibonacci\n");
    ASSERT_EQ(fibonacci(0), 0);
    ASSERT_EQ(fibonacci(1), 1);
    ASSERT_EQ(fibonacci(6), 8);
    ASSERT_EQ(fibonacci(10), 55);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Recursión, eficiencia O(2^n) vs O(n).

**Optimización (bonus):**
```c
long fibonacci_optimized(int n, long* memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    
    memo[n] = fibonacci_optimized(n - 1, memo) + 
              fibonacci_optimized(n - 2, memo);
    return memo[n];
}
```

---

## Ejercicio 3: Nodo de Lista Enlazada

**Objetivo:** Crear una lista enlazada simple con inserción y búsqueda.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* create_node(int value);
Node* insert_node(Node* head, int value);
Node* search_node(Node* head, int value);
void print_list(Node* head);
void free_list(Node* head);
```

2. Implementa en `src/math_utils.c`:
```c
Node* create_node(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return NULL;
    node->value = value;
    node->next = NULL;
    return node;
}

Node* insert_node(Node* head, int value) {
    Node* new_node = create_node(value);
    if (new_node == NULL) return head;
    
    if (head == NULL) return new_node;
    
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

Node* search_node(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->value == value) return current;
        current = current->next;
    }
    return NULL;
}

void print_list(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_linked_list(void) {
    printf("Running: test_linked_list\n");
    
    Node* head = NULL;
    head = insert_node(head, 10);
    head = insert_node(head, 20);
    head = insert_node(head, 30);
    
    ASSERT_TRUE(search_node(head, 20) != NULL);
    ASSERT_TRUE(search_node(head, 40) == NULL);
    
    print_list(head);
    free_list(head);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Estructuras recursivas, gestión de memoria.

---

## Ejercicio 4: Pila (Stack)

**Objetivo:** Implementar una pila con operaciones push, pop, peek.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
typedef struct {
    int* items;
    int top;
    int capacity;
} Stack;

Stack* create_stack(int capacity);
void push(Stack* stack, int value);
int pop(Stack* stack);
int peek(Stack* stack);
int is_empty(Stack* stack);
void free_stack(Stack* stack);
```

2. Implementa en `src/math_utils.c`:
```c
Stack* create_stack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->items = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

void push(Stack* stack, int value) {
    if (stack->top < stack->capacity - 1) {
        stack->items[++stack->top] = value;
    }
}

int pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    }
    return -1;
}

int peek(Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top];
    }
    return -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

void free_stack(Stack* stack) {
    free(stack->items);
    free(stack);
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_stack(void) {
    printf("Running: test_stack\n");
    Stack* stack = create_stack(10);
    
    push(stack, 5);
    push(stack, 10);
    push(stack, 15);
    
    ASSERT_EQ(peek(stack), 15);
    ASSERT_EQ(pop(stack), 15);
    ASSERT_EQ(pop(stack), 10);
    ASSERT_FALSE(is_empty(stack));
    
    free_stack(stack);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Estructuras de datos, LIFO.

---

## Ejercicio 5: Cola (Queue)

**Objetivo:** Implementar una cola con operaciones enqueue, dequeue.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
typedef struct {
    int* items;
    int front;
    int rear;
    int capacity;
} Queue;

Queue* create_queue(int capacity);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int is_queue_empty(Queue* q);
void free_queue(Queue* q);
```

2. Implementa en `src/math_utils.c`:
```c
Queue* create_queue(int capacity) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->items = (int*)malloc(capacity * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear < q->capacity - 1) {
        q->items[++q->rear] = value;
    }
}

int dequeue(Queue* q) {
    if (q->front <= q->rear) {
        return q->items[q->front++];
    }
    return -1;
}

int is_queue_empty(Queue* q) {
    return q->front > q->rear ? 1 : 0;
}

void free_queue(Queue* q) {
    free(q->items);
    free(q);
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_queue(void) {
    printf("Running: test_queue\n");
    Queue* q = create_queue(10);
    
    enqueue(q, 5);
    enqueue(q, 10);
    enqueue(q, 15);
    
    ASSERT_EQ(dequeue(q), 5);   /* FIFO */
    ASSERT_EQ(dequeue(q), 10);
    ASSERT_FALSE(is_queue_empty(q));
    
    free_queue(q);
}
```

4. Prueba: `make test`

**Concepto aprendido:** FIFO, estructuras de datos lineales.

---

## Ejercicio 6: Árbol Binario Simple

**Objetivo:** Crear un árbol binario con inserción y recorrido.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* create_tree_node(int value);
TreeNode* insert_tree(TreeNode* root, int value);
void inorder_traversal(TreeNode* root);
void free_tree(TreeNode* root);
```

2. Implementa en `src/math_utils.c`:
```c
TreeNode* create_tree_node(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeNode* insert_tree(TreeNode* root, int value) {
    if (root == NULL) {
        return create_tree_node(value);
    }
    
    if (value < root->value) {
        root->left = insert_tree(root->left, value);
    } else {
        root->right = insert_tree(root->right, value);
    }
    
    return root;
}

void inorder_traversal(TreeNode* root) {
    if (root == NULL) return;
    
    inorder_traversal(root->left);
    printf("%d ", root->value);
    inorder_traversal(root->right);
}

void free_tree(TreeNode* root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_binary_tree(void) {
    printf("Running: test_binary_tree\n");
    TreeNode* root = NULL;
    
    root = insert_tree(root, 50);
    root = insert_tree(root, 30);
    root = insert_tree(root, 70);
    root = insert_tree(root, 20);
    root = insert_tree(root, 40);
    
    printf("Inorder: ");
    inorder_traversal(root);
    printf("\n");
    
    free_tree(root);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Árboles, BST, recorrido en profundidad.

---

## Ejercicio 7: Quicksort Recursivo

**Objetivo:** Implementar quicksort, un algoritmo eficiente O(n log n).

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
void quicksort(int* arr, int low, int high);
```

2. Implementa en `src/math_utils.c`:
```c
static int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_quicksort(void) {
    printf("Running: test_quicksort\n");
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    quicksort(arr, 0, 6);
    
    ASSERT_EQ(arr[0], 11);
    ASSERT_EQ(arr[6], 90);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Divide and conquer, O(n log n).

---

## Ejercicio 8: Manejo de Archivos

**Objetivo:** Escribir números a un archivo y leerlos.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int write_array_to_file(int* arr, int size, const char* filename);
int read_array_from_file(int** arr, int* size, const char* filename);
```

2. Implementa en `src/math_utils.c`:
```c
#include <stdio.h>

int write_array_to_file(int* arr, int size, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) return -1;
    
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d\n", arr[i]);
    }
    
    fclose(file);
    return 0;
}

int read_array_from_file(int** arr, int* size, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) return -1;
    
    fscanf(file, "%d", size);
    *arr = (int*)malloc(*size * sizeof(int));
    
    for (int i = 0; i < *size; i++) {
        fscanf(file, "%d", &(*arr)[i]);
    }
    
    fclose(file);
    return 0;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_file_io(void) {
    printf("Running: test_file_io\n");
    int original[] = {1, 2, 3, 4, 5};
    
    write_array_to_file(original, 5, "/tmp/test_array.txt");
    
    int* loaded = NULL;
    int loaded_size = 0;
    read_array_from_file(&loaded, &loaded_size, "/tmp/test_array.txt");
    
    ASSERT_EQ(loaded_size, 5);
    ASSERT_EQ(loaded[0], 1);
    
    free(loaded);
}
```

4. Prueba: `make test`

**Concepto aprendido:** I/O de archivos, FILE*, fopen, fprintf.

---

## Ejercicio 9: Búsqueda en Profundidad (DFS)

**Objetivo:** Implementar DFS en un grafo representado como matriz de adyacencia.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
void dfs(int* adj[], int visited[], int node, int n);
```

2. Implementa en `src/math_utils.c`:
```c
void dfs(int* adj[], int visited[], int node, int n) {
    visited[node] = 1;
    printf("%d ", node);
    
    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(adj, visited, i, n);
        }
    }
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_dfs(void) {
    printf("Running: test_dfs\n");
    int n = 4;
    
    /* Crear matriz de adyacencia */
    int** adj = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }
    
    /* Aristas */
    adj[0][1] = 1; adj[1][0] = 1;
    adj[0][2] = 1; adj[2][0] = 1;
    adj[1][3] = 1; adj[3][1] = 1;
    
    int visited[4] = {0};
    printf("DFS: ");
    dfs(adj, visited, 0, n);
    printf("\n");
    
    for (int i = 0; i < n; i++) free(adj[i]);
    free(adj);
}
```

4. Prueba: `make test`

**Concepto aprendido:** Grafos, DFS, matriz de adyacencia.

---

## Ejercicio 10: Problema N-Reinas (Backtracking)

**Objetivo:** Resolver el problema de las N-Reinas usando backtracking.

**Tareas:**
1. Agrega en `include/math_utils.h`:
```c
int solve_n_queens(int n);  /* Retorna número de soluciones */
```

2. Implementa en `src/math_utils.c`:
```c
static int is_safe(int* board, int n, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            abs(board[i] - col) == abs(i - row)) {
            return 0;
        }
    }
    return 1;
}

static int solve_n_queens_helper(int* board, int n, int row) {
    if (row == n) return 1;
    
    int count = 0;
    for (int col = 0; col < n; col++) {
        if (is_safe(board, n, row, col)) {
            board[row] = col;
            count += solve_n_queens_helper(board, n, row + 1);
            board[row] = -1;
        }
    }
    return count;
}

int solve_n_queens(int n) {
    int* board = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) board[i] = -1;
    
    int count = solve_n_queens_helper(board, n, 0);
    free(board);
    return count;
}
```

3. En `tests/test_main.c`, agrega:
```c
void test_n_queens(void) {
    printf("Running: test_n_queens\n");
    ASSERT_EQ(solve_n_queens(4), 2);  /* 4-Reinas tiene 2 soluciones */
    ASSERT_EQ(solve_n_queens(8), 92); /* 8-Reinas tiene 92 soluciones */
}
```

4. Prueba: `make test`

**Concepto aprendido:** Backtracking, optimización, problemas combinatorios.

---

## Cómo Completar

```bash
# Compilar
make clean && make

# Ejecutar tests
make test

# Commit
git add -A
git commit -m "Complete advanced exercises"
```

---

## Próximos Pasos

Felicidades, has completado los ejercicios de C avanzado. Ahora puedes:

1. **Crear un proyecto propio** — Aplica lo aprendido
2. **Contribuir a código abierto** — Busca proyectos C en GitHub
3. **Aprender sistemas operativos** — Entiende cómo funcionan (kernel, threads)
4. **Explorar embebidos** — Arduino, microcontroladores
5. **Especializarte** — Compiladores, bases de datos, renderizado gráfico

