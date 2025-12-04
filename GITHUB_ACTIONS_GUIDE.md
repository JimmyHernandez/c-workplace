# GitHub Actions — Publicar documentación Doxygen en GitHub Pages

Fecha: 2025-12-03

Esta guía explica cómo automatizar la generación y publicación de la documentación
HTML generada por Doxygen en GitHub Pages usando GitHub Actions. Incluye un
workflow de ejemplo que ejecuta `make docs` y publica `docs/html` en Pages.

## Resumen del flujo

1. En cada push a la rama `master` (o `main`) se ejecuta el workflow.
2. El runner instala `doxygen` y `graphviz`, ejecuta `make docs` para generar
   la documentación en `docs/html`.
3. El workflow empaqueta `docs/html` y lo despliega a GitHub Pages.

## Requisitos

- Tener `Doxyfile` en la raíz del repo (ya existe en este proyecto).
- Habilitar GitHub Pages en el repositorio (opcional, el workflow puede crear
  la rama `gh-pages` o usar la opción 'Actions' para publicar).

## Workflow de ejemplo

Guarda el siguiente archivo como `.github/workflows/publish-docs.yml` en la
raíz del repositorio. Este workflow usa acciones oficiales para subir el
artefacto y desplegarlo en Pages.

```yaml
name: Publish Doxygen Docs

on:
  push:
    branches:
      - master

permissions:
  contents: read
  pages: write
  id-token: write

jobs:
  build-and-deploy:
    runs-on: ubuntu-latest

    steps:
      - name: Checkout repository
        uses: actions/checkout@v4

      - name: Install dependencies
        run: |
          sudo apt-get update
          sudo apt-get install -y doxygen graphviz

      - name: Build docs
        run: |
          make docs

      - name: Upload Pages artifact
        uses: actions/upload-pages-artifact@v1
        with:
          path: docs/html

  deploy:
    needs: build-and-deploy
    runs-on: ubuntu-latest
    permissions:
      pages: write
      contents: read

    steps:
      - name: Deploy to GitHub Pages
        uses: actions/deploy-pages@v1

```

Explicación rápida de las secciones importantes:

- `permissions`: permite que el token de GitHub Actions despliegue Pages.
- `actions/checkout`: obtiene el código fuente.
- Instalación de `doxygen` y `graphviz`: necesario para generar los HTML.
- `make docs`: ejecuta el `Makefile` target que genera `docs/html`.
- `upload-pages-artifact` y `deploy-pages`: empaquetan y publican el contenido en Pages.

## Qué esperar después del push

- En la pestaña **Actions** del repositorio verás el flujo en ejecución.
- Si todo va bien, GitHub Pages servirá el sitio desde la rama interna que
  Actions crea (o desde `gh-pages`, según configuración). Puedes configurar el
  dominio en la sección Settings → Pages.

## Seguridad y permisos

- El workflow usa `GITHUB_TOKEN` automáticamente disponible en Actions. Asegúrate
  de que la política de tu repositorio permite que Actions publique Pages.
- Para mayor control puedes usar un token personal con permisos específicos,
  pero `GITHUB_TOKEN` suele ser suficiente.

## Opciones y mejoras

- Ejecutar el workflow en `pull_request` para validar la generación de docs en PRs.
- Correr linters o tests antes de generar docs.
- Publicar los artefactos en una rama `gh-pages` usando `peaceiris/actions-gh-pages`.

¿Quieres que añada este workflow al repositorio ahora y haga commit? Puedo
crearlo y commitearlo automáticamente.
