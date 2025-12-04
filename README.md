# C Workspace (c-workplace)

Simple C project scaffold with build and test targets.

Build and run (using a bash shell with `gcc` installed):

```bash
make        # builds
make run    # runs the program
make test   # builds and runs the test
make clean  # remove build artifacts
```

If `make` is not available, build manually:

```bash
mkdir -p build
gcc -Iinclude -o build/main src/main.c
./build/main
```
## Guías útiles

- **Guía Git CLI**: instrucciones prácticas para trabajar con Git desde la línea de comandos y subir a GitHub — `GIT_CLI_GUIDE.md`.
- **Guía GitHub Actions (Docs)**: cómo generar y publicar la documentación con GitHub Actions (incluye un workflow de ejemplo) — `GITHUB_ACTIONS_GUIDE.md`.
- **Learning Roadmap**: plan de aprendizaje del stack completo en 4 fases con ejercicios progresivos — `LEARNING_ROADMAP.md`.
- **C/C++ Stack Guide**: herramientas, compiladores, librerías, extensiones y frameworks profesionales — `CPP_STACK.md`.

