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
