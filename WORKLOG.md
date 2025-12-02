# C Workspace Worklog

## Project Summary
A complete C development workspace scaffold built on Windows 11 with WSL (Ubuntu). Includes build system, test framework, modular code structure, and VS Code integration.

---

## Getting Started (Step-by-Step)

### Step 1: Launch WSL
From Windows PowerShell or Command Prompt:
```powershell
wsl
```
You'll see a prompt like `user@machine:/mnt/c/Users/jimmy/...#` indicating you're inside WSL (Ubuntu).

### Step 2: Navigate to Your Project
Inside the WSL terminal:
```bash
cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace
```
Or shorter (if you prefer):
```bash
cd ~/Desktop/proyectosRandom/c-workplace
```

Verify you're in the right folder:
```bash
ls
```
You should see: `Makefile`, `README.md`, `WORKLOG.md`, `src/`, `tests/`, `include/`, `.vscode/`, `.git/`

### Step 3: Check Available Tools
Verify the toolchain is installed:
```bash
gcc --version
make --version
gdb --version
```
All should print version info (gcc 11+, make 4.3+, gdb 15+).

### Step 4: Build the Project
Compile the code:
```bash
make
```
Expected output:
```
mkdir -p build
cc -Wall -Wextra -O2 -Iinclude -g -o build/main src/main.c src/math_utils.c
```
A new `build/` folder is created with `build/main` inside.

### Step 5: Run the Program
Execute the compiled binary:
```bash
make run
```
Expected output:
```
Hello, C workspace!
Quick math demo: 7 + 3 = 10
Quick math demo: 10 * 5 = 50
```

### Step 6: Run Tests
Compile and execute the test suite:
```bash
make test
```
Expected output:
```
=== C Workspace Test Suite ===

Running: test_arithmetic
Running: test_math_utils
Running: test_conditions

=== Test Summary ===
Passed: 11
Failed: 0
Total:  11
RESULT: PASS
```

### Step 7: Clean Build Artifacts (Optional)
Remove compiled binaries to force a fresh build:
```bash
make clean
```
The `build/` folder is deleted. Next `make` will recompile everything.

### Step 8: Use Git (Optional)
Check the current status of your project:
```bash
git status
```
Should show: `On branch master`, `nothing to commit, working tree clean`.

Make a change (e.g., edit `src/main.c`), then:
```bash
git add -A
git commit -m "Your commit message"
```

---

## Using VS Code Remote - WSL (Recommended)

### Setup
1. Open VS Code on Windows.
2. Press `Ctrl+Shift+P` and type `Remote-WSL: Reopen in WSL`.
3. Wait for VS Code to reload; you'll see `WSL: Ubuntu` in the bottom-left corner.
4. Open the workspace folder:
   - `File > Open Folder`
   - Navigate to: `/mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace`
   - Click "Select Folder"
5. When prompted, install recommended extensions (C/C++ tools, clang-format, etc.).

### Build from VS Code
1. Press `Ctrl+Shift+B` (Run Build Task).
2. Select one of:
   - `Make: build` → compiles code
   - `Make: run` → compiles and runs
   - `Make: test` → compiles and runs tests

### Debug from VS Code
1. Open a source file (e.g., `src/main.c`).
2. Click on a line number to set a breakpoint (red dot appears).
3. Press `F5` (Start Debugging).
4. Select a debug configuration:
   - `Debug main (WSL gdb)` → debug the main program
   - `Debug test (WSL gdb)` → debug the test suite
5. The program runs and stops at your breakpoint.
6. Step through code using:
   - `F10` — Step over (next line)
   - `F11` — Step into (enter function)
   - `Shift+F11` — Step out (exit function)
   - `F5` — Continue to next breakpoint
7. View variables and call stack in the left panel.

### Terminal in VS Code
Press `` Ctrl+` `` (backtick) to open an integrated terminal.
It automatically opens inside WSL, so you can run `make`, `git`, etc. directly.

---

## Typical Workflow

### Scenario: Add a New Math Function

**1. Add the function declaration to `include/math_utils.h`:**
```c
int math_power(int base, int exponent);  /* Add this line */
```

**2. Implement it in `src/math_utils.c`:**
```c
int math_power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}
```

**3. Test it in `tests/test_main.c`:**
Add a new test function:
```c
void test_power(void) {
    printf("Running: test_power\n");
    ASSERT_EQ(math_power(2, 3), 8);
    ASSERT_EQ(math_power(5, 2), 25);
}
```

Then call it in `main()`:
```c
int main(void) {
    printf("=== C Workspace Test Suite ===\n\n");
    test_arithmetic();
    test_math_utils();
    test_power();  /* Add this */
    test_conditions();
    TEST_SUMMARY();
}
```

**4. Build and test:**
```bash
make clean
make test
```

**5. Commit your changes:**
```bash
git add -A
git commit -m "Add math_power function with tests"
```

---

## Troubleshooting

### "make: command not found"
You're not in WSL. Run `wsl` first to enter WSL.

### "gcc: command not found"
Tools aren't installed in WSL. Run:
```bash
wsl -u root apt update
wsl -u root apt install -y build-essential gdb make
```

### "Clock skew detected" warning
Harmless. Sync Windows time or ignore. Doesn't affect builds.

### Breakpoints not working in debugger
1. Ensure you built with `-g` flag (already in `Makefile`).
2. Rebuild: `make clean && make`
3. Press `F5` again to start debugging.

### "Permission denied" when running `build/main`
Shouldn't happen, but if it does:
```bash
chmod +x build/main
./build/main
```

---

## What Was Built

### 1. Project Structure
```
c-workplace/
├── src/
│   ├── main.c              # Main program (Hello World + math demo)
│   └── math_utils.c        # Reusable math utility functions
├── tests/
│   └── test_main.c         # Test suite using custom harness
├── include/
│   ├── test.h              # Custom test harness (ASSERT macros)
│   └── math_utils.h        # Math utility function declarations
├── build/                  # Generated binaries (auto-created)
├── .vscode/
│   ├── tasks.json          # VS Code build/run/test tasks
│   ├── launch.json         # Debugging configurations (gdb)
│   └── extensions.json     # Recommended extensions
├── .github/
│   └── copilot-instructions.md  # Workspace automation guide
├── .gitignore              # Git exclusion rules
├── Makefile                # Build recipes
└── README.md               # Quick usage guide
```

### 2. Build System (Makefile)
- **Target: `make`** — Compiles `src/main.c` and `src/math_utils.c` → `build/main`
- **Target: `make run`** — Builds and runs the main program
- **Target: `make test`** — Compiles and runs tests
- **Target: `make clean`** — Removes `build/` directory

**Features:**
- Compiler override: `make CC=clang` (defaults to `gcc`)
- Debug symbols included (`-g` flag)
- Warning flags enabled (`-Wall -Wextra`)

### 3. Test Framework (`include/test.h`)
Custom lightweight C test harness with:
- `ASSERT_EQ(actual, expected)` — Equality assertions
- `ASSERT_TRUE(condition)` — Boolean assertions
- `TEST_SUMMARY()` — Prints pass/fail/total counts and returns exit code

**Current tests:**
- `test_arithmetic()` — 3 tests (basic C arithmetic)
- `test_math_utils()` — 5 tests (math_utils functions + edge cases)
- `test_conditions()` — 3 tests (boolean logic)
- **Total: 11 tests passing**

### 4. Reusable Code (`src/math_utils.c` + `include/math_utils.h`)
Functions:
- `int math_add(int a, int b)` — Addition
- `int math_subtract(int a, int b)` — Subtraction
- `int math_multiply(int a, int b)` — Multiplication
- `int math_divide(int a, int b)` — Division (returns 0 on div-by-zero)

Demonstrates modular code: headers in `include/`, implementations in `src/`, tested in `tests/`.

### 5. Git Repository
- Initialized with `.git/` in project root
- `.gitignore` excludes `build/`, object files, editor temp files
- Initial commit: "Initial commit: C workspace scaffold with test harness"
- Ready for branching and remote push

### 6. VS Code Integration

#### Tasks (`Ctrl+Shift+B`)
- `Make: build` → Runs `make`
- `Make: run` → Runs `make run`
- `Make: test` → Runs `make test`

#### Debug Configurations (`F5`)
- `Debug main (WSL gdb)` — Debug main program with gdb
- `Debug test (WSL gdb)` — Debug test suite with gdb
- Both auto-compile before launching via `preLaunchTask`

#### Recommended Extensions
- `ms-vscode.cpptools` — C/C++ language support
- `ms-vscode.cmake-tools` — CMake support (optional future use)
- `xaver.clang-format` — Code formatting

---

## Tools & Environment

### Installed in WSL (Ubuntu)
```bash
build-essential    # gcc, g++, make, binutils
gdb                # GNU Debugger
make               # Build automation
```

### VS Code Extensions (Local + WSL)
- **Remote - WSL** (already installed) — Work directly inside WSL from VS Code

### How to Access & Use

#### Option A: From Windows PowerShell/CMD
Build:
```bash
wsl bash -lc "cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace && make"
```

Run:
```bash
wsl bash -lc "cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace && make run"
```

Test:
```bash
wsl bash -lc "cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace && make test"
```

#### Option B: Open WSL Terminal
1. Launch WSL:
   ```powershell
   wsl
   ```
2. Navigate and build:
   ```bash
   cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace
   make test
   ```

#### Option C: VS Code Remote - WSL (Recommended)
1. Open VS Code
2. `Ctrl+Shift+P` → `Remote-WSL: Reopen in WSL`
3. Open folder: `/mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace`
4. Use:
   - `Ctrl+Shift+B` for build/run/test tasks
   - `F5` to debug
   - Integrated terminal runs natively in WSL

---

## Verification

Last successful build output:
```
=== Main Program ===
Hello, C workspace!
Quick math demo: 7 + 3 = 10
Quick math demo: 10 * 5 = 50

=== Tests ===
Passed: 11
Failed: 0
Total:  11
RESULT: PASS
```

---

## Next Steps You Can Take

1. **Add more math functions** — Add to `math_utils.h/c`, test in `tests/test_main.c`
2. **Add more test cases** — Expand `tests/test_main.c` with new `ASSERT_*` calls
3. **Create new modules** — Add `src/string_utils.c`, `include/string_utils.h`, etc.
4. **Use version control** — `git status`, `git add`, `git commit`, `git branch`, etc.
5. **Push to GitHub** — Create a repo, `git remote add origin ...`, `git push`
6. **Debug in VS Code** — Set breakpoints, press F5, step through code with gdb

---

## Safety Notes

- **WSL is isolated** — If anything breaks, you can delete and reinstall WSL without affecting Windows.
- **Code is safe on Windows** — All files stored in `c:\Users\jimmy\OneDrive\Desktop\proyectosRandom\c-workplace` (Windows-side), not in WSL.
- **Easy to reset** — Delete WSL: `wsl --unregister Ubuntu` → reinstall: `wsl --install -d Ubuntu`

---

## Files Created/Modified

| File | Purpose |
|------|---------|
| `src/main.c` | Main program demo |
| `src/math_utils.c` | Reusable math functions |
| `tests/test_main.c` | Test suite |
| `include/test.h` | Test harness macros |
| `include/math_utils.h` | Math function declarations |
| `Makefile` | Build recipes |
| `README.md` | Quick usage guide |
| `.vscode/tasks.json` | VS Code build tasks |
| `.vscode/launch.json` | VS Code debug config |
| `.vscode/extensions.json` | Extension recommendations |
| `.github/copilot-instructions.md` | Copilot automation guide |
| `.gitignore` | Git exclusion rules |
| `.git/` | Git repository |

---

## Commands You Have Available

| Task | Command |
|------|---------|
| Build | `make` or `Ctrl+Shift+B` (in VS Code) |
| Run | `make run` or `Ctrl+Shift+B` then select "Make: run" |
| Test | `make test` or `Ctrl+Shift+B` then select "Make: test" |
| Clean | `make clean` |
| Debug | `F5` (in VS Code) |
| Git Status | `git status` |
| Git Commit | `git add -A && git commit -m "message"` |
| Open in WSL | `Ctrl+Shift+P` → "Remote-WSL: Reopen in WSL" |

---

**Your workspace is ready for C development. Happy coding!** 🚀
