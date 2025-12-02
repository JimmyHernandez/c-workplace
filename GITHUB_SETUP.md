# 📤 Guía: Subir a GitHub

Tu proyecto está listo para subirse a GitHub. Sigue estos pasos:

---

## Paso 1: Crear Repositorio en GitHub

1. Ve a https://github.com/new
2. Inicia sesión con tu cuenta (o crea una si no tienes)
3. Completa el formulario:
   - **Repository name:** `c-workspace` (o el nombre que prefieras)
   - **Description:** `C learning workspace with test framework, exercises and projects`
   - **Public** o **Private** (elige según prefieras)
   - **NO marques** "Initialize this repository with:" (ya tienes commits locales)
4. Haz clic en "Create repository"

---

## Paso 2: Conectar Repositorio Local a GitHub

Después de crear el repo en GitHub, verás instrucciones. Ejecuta en WSL:

```bash
wsl
cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace

# Agregar el repositorio remoto (reemplaza USUARIO por tu usuario de GitHub)
git remote add origin https://github.com/USUARIO/c-workspace.git

# Cambiar rama principal a 'main' (GitHub usa 'main' por defecto)
git branch -M main

# Subir commits
git push -u origin main
```

**Ejemplo completo:**
```bash
git remote add origin https://github.com/jimoem24/c-workspace.git
git branch -M main
git push -u origin main
```

---

## Paso 3: Verificar que se Subió

Después de ejecutar los comandos anteriores:
- Ve a tu repositorio en GitHub: `https://github.com/USUARIO/c-workspace`
- Deberías ver todos tus archivos (src/, tests/, include/, WORKLOG.md, PROJECTS.md, etc.)

---

## Paso 4: Futuros Commits

Después del primer push, los próximos commits son más simples:

```bash
# Hacer cambios en tu código
git add -A
git commit -m "Add new feature"

# Subir
git push
```

---

## Comando Rápido (Copiar y Pegar)

Si quieres hacerlo todo de una vez, desde WSL:

```bash
wsl
cd /mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace
git remote add origin https://github.com/USUARIO/c-workspace.git
git branch -M main
git push -u origin main
```

**Reemplaza `USUARIO` con tu nombre de usuario de GitHub.**

---

## Alternativa: Token de Acceso (si falla con HTTPS)

Si te pide contraseña y no funciona:

1. Ve a GitHub: Settings → Developer settings → Personal access tokens
2. Crea un nuevo token con permisos `repo`
3. Copia el token
4. En WSL, cuando te pida contraseña, pega el token

O usa SSH (más seguro):

```bash
# Generar clave SSH (si no tienes)
ssh-keygen -t rsa -b 4096 -C "tu_email@example.com"

# Agregar a ssh-agent
eval "$(ssh-agent -s)"
ssh-add ~/.ssh/id_rsa

# Copiar clave pública
cat ~/.ssh/id_rsa.pub

# Ir a GitHub: Settings → SSH and GPG keys → New SSH key
# Pegar la clave pública

# Usar SSH en lugar de HTTPS
git remote remove origin
git remote add origin git@github.com:USUARIO/c-workspace.git
git push -u origin main
```

---

## Verificar Configuración de Git

Antes de pushear, verifica tu configuración:

```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu_email@example.com"
```

---

## Si Algo Falla

**Error: "fatal: not a git repository"**
- Asegúrate de estar en `/mnt/c/Users/jimmy/OneDrive/Desktop/proyectosRandom/c-workplace`
- Verifica que existe `.git/` con `ls -la`

**Error: "Repository already exists"**
- El remote ya está configurado. Verifica: `git remote -v`
- Si está mal, elimina: `git remote remove origin`

**Error: "Permission denied"**
- Necesitas autenticación (HTTPS token o SSH key)
- Sigue la sección "Token de Acceso" arriba

---

## Estado Actual de tu Proyecto

```
Total de commits: 2
- Initial commit: C workspace scaffold with test harness
- Add test framework, math_utils, exercises and projects documentation

Archivos listos para subir:
- src/main.c, src/math_utils.c
- include/test.h, include/math_utils.h
- tests/test_main.c
- Makefile, .gitignore, README.md
- WORKLOG.md (guía de uso)
- EXERCISES_BEGINNER.md, EXERCISES_INTERMEDIATE.md, EXERCISES_ADVANCED.md
- PROJECTS.md (proyectos reales)
- .vscode/ (configuración VS Code)
- .github/ (scripts de automatización)
```

---

## Próximos Pasos en GitHub

Después de subir:
1. Opcionalmente, habilita GitHub Actions para CI/CD
2. Agrega un `.github/workflows/build.yml` para compilar automáticamente
3. Invita colaboradores si quieres trabajar en equipo
4. Protege la rama `main` con reglas de review

---

**¿Necesitas ayuda con algo específico? Pregunta en los comentarios del README.** 🚀
