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
raíz del repositorio. Este workflow usa `peaceiris/actions-gh-pages`, una acción
estable y bien mantenida que evita dependencias con versiones deprecadas.

```yaml
name: Publish Doxygen Docs

on:
  push:
    branches:
      - master

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

      - name: Deploy to GitHub Pages
        uses: peaceiris/actions-gh-pages@v3
        with:
          github_token: ${{ secrets.GITHUB_TOKEN }}
          publish_dir: ./docs/html
```

Explicación rápida de las secciones importantes:

- `on: push` en rama `master`: dispara el workflow en cada push.
- `actions/checkout`: obtiene el código fuente.
- Instalación de `doxygen` y `graphviz`: necesario para generar los HTML.
- `make docs`: ejecuta el `Makefile` target que genera `docs/html`.
- `peaceiris/actions-gh-pages@v3`: acción estable que publica el contenido en GitHub Pages automáticamente (usando el token GITHUB_TOKEN proporcionado por Actions). Publica en la rama `gh-pages` que GitHub Pages detecta y sirve.

**Nota sobre versiones y deprecaciones**

- GitHub y las acciones oficiales pueden deprecar versiones antiguas
  (por ejemplo `actions/upload-artifact@v3`). La versión anterior del workflow
  usaba `actions/upload-pages-artifact@v2` y `actions/deploy-pages@v2`, que a su vez
  dependían de `upload-artifact@v3` deprecado, causando fallos automáticos.
  
- **Solución implementada**: este workflow usa `peaceiris/actions-gh-pages@v3`,
  una acción de terceros bien mantenida que no tiene esa dependencia y es más
  estable para publicar en GitHub Pages. Publica en la rama `gh-pages` que GitHub
  Pages detecta automáticamente.

- Si tienes problemas de deprecación futura, verifica el changelog de GitHub Actions
  y actualiza las referencias a las versiones recomendadas, o migra a alternativas
  como `peaceiris/actions-gh-pages`.


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
