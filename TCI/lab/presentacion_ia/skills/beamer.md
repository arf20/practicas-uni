---
name: beamer
description: "Crear, compilar y verificar presentaciones Beamer en LaTeX."
---

# Skill: presentaciones Beamer

## Cuándo usarla

- El usuario pide una presentación, diapositivas o un deck en LaTeX/Beamer.
- Hay que convertir un informe, una investigación o un guion en una presentación técnica breve.
- El deck necesita diagramas TikZ (flujos, pilas de protocolos, secuencias) o tablas comparativas.

## Regla general

Un deck breve: **9–12 diapositivas**, una idea por diapositiva y viñetas de una o dos líneas. Escribir el texto en el idioma del usuario y mantener los términos técnicos en inglés.

## Procedimiento

### 1. Inspeccionar el entorno

```bash
kpsewhich beamer.cls beamerthememetropolis.sty tikz.sty booktabs.sty
fc-list | grep -i "Fira Sans"
```

### 2. Elegir el motor

- Metropolis se ve como está diseñado con **Fira Sans**; en ese caso usar `lualatex` o `xelatex`.
- Si Fira no está instalado, compilar con **`pdflatex`**: Metropolis no carga `fontspec` y usa la fuente sans por defecto. El aviso «You need to compile with XeLaTeX or LuaLaTeX to use the Fira fonts» es inofensivo.
- No insistir con LuaLaTeX sin Fira: puede fallar al cargar `lmsans10-regular` como OpenType.

### 3. Esqueleto

```latex
\documentclass[aspectratio=169,10pt]{beamer}

\usetheme[progressbar=frametitle,numbering=fraction]{metropolis}
\usepackage[spanish]{babel}
\usepackage{booktabs}
\usepackage{tikz}
\usetikzlibrary{positioning,arrows.meta,calc}

\definecolor{btblue}{HTML}{0082FC}
\definecolor{btdark}{HTML}{102A43}
\definecolor{btlight}{HTML}{E8F3FF}
\definecolor{btorange}{HTML}{E8752B}

\setbeamercolor{progress bar}{fg=btblue}
\setbeamercolor{alerted text}{fg=btorange}
\setbeamercolor{block title}{bg=btblue!12,fg=btdark}
\setbeamercolor{block body}{bg=btlight}
\setbeamertemplate{frame footer}{\tiny TCI · WPAN}
```

### 4. Mapear el contenido a diapositivas

Portada → contexto → una diapositiva por sección del documento → implementación/método → resumen → referencias. Reflejar los nombres de las secciones en los títulos para que el deck se pueda seguir junto al documento.

No usar `\section{}` salvo que se quieran páginas de sección: Metropolis inserta diapositivas extra.

### 5. Diagramas en TikZ

Prefijar **todos** los estilos propios. Nombres genéricos como `dev`, `step` o `layer` colisionan con claves de PGF y rompen la compilación.

```latex
\tikzset{
  btdev/.style={draw=btblue!70, fill=btlight, rounded corners=3pt,
                minimum width=3.4cm, minimum height=1.4cm,
                align=center, font=\small},
  btstep/.style={draw=btblue!65, fill=btlight, rounded corners=3pt,
                 text width=2.6cm, minimum height=1.25cm,
                 align=center, font=\scriptsize},
  btlayer/.style={draw=btblue!55, fill=btlight, rounded corners=2pt,
                  minimum height=0.55cm, align=center, font=\scriptsize},
  btflow/.style={-{Latex[length=2mm]}, thick, btblue!80}
}
```

Pila de protocolos reutilizable:

```latex
\begin{tikzpicture}
  \node[btlayer, minimum width=4.8cm] (hfp) at (0,0) {HFP (AT)};
  \node[btlayer, minimum width=2.2cm] (sdp) at (-1.25,-0.8) {SDP};
  \node[btlayer, minimum width=2.2cm] (rf) at (1.25,-0.8) {RFCOMM};
  \node[btlayer, minimum width=4.8cm] (l2) at (0,-1.6) {L2CAP};
  \node[btlayer, minimum width=4.8cm] (lm) at (0,-2.4) {Link Manager};
  \node[btlayer, minimum width=4.8cm] (bb) at (0,-3.2) {Baseband};
  \node[btlayer, minimum width=4.8cm] (radio) at (0,-4.0) {Radio};
\end{tikzpicture}
```

Para diagramas de secuencia, usar dos líneas de vida y flechas con `node[above]{...}`; comprobar que la última flecha no queda pegada a las viñetas.

### 6. Compilar dos veces

```bash
pdflatex -interaction=nonstopmode -halt-on-error deck.tex
pdflatex -interaction=nonstopmode -halt-on-error deck.tex
```

La segunda pasada es necesaria con `numbering=fraction`: la primera muestra `n/100` porque aún no ha leído el total del `.aux`.

### 7. Revisar el log

```bash
grep -E "Overfull|Underfull|^!" deck.log
```

- Portada con `Overfull \vbox`: usar `\begin{frame}[plain,shrink]`.
- Diapositiva de contenido con overfull: **no** usar `shrink`; ajustar el diagrama, acortar líneas o reducir texto.
- Escapar `_` dentro de `\texttt{}`: `hfp\_hf`, no `hfp_hf`.

### 8. Verificación visual obligatoria

```bash
pdfinfo deck.pdf | grep -E "Pages|Page size"
pdftoppm -png -r 100 deck.pdf /tmp/slide
```

Cargar cada PNG con `vision_analyze` y comprobar:

- desbordamiento inferior o texto cortado;
- etiquetas TikZ solapadas o fuera de su columna;
- tablas demasiado estrechas o con texto ilegible;
- colisión con el pie de página;
- alineación de la pila o del diagrama.

El log por sí solo no detecta todos los problemas visuales.

### 9. Limpiar

```bash
rm -f deck.aux deck.log deck.nav deck.out deck.snm deck.toc
```

Conservar `.tex` y `.pdf` junto al material fuente.

## Errores vistos y solución

| Síntoma | Causa | Solución |
|---|---|---|
| `Font \TU/lmss/m/n/10=[lmsans10-regular] ... metric data not found` | LuaLaTeX sin Fira; Latin Modern Sans no está como OpenType | Compilar con `pdflatex` o instalar `fira` |
| `/tikz/step requires a value` | `step` es una clave interna de PGF | Renombrar el estilo a `btstep` |
| `I do not know the key '/tikz/dev'` | Estilo `dev` no definido o renombrado a medias | Usar un prefijo único y cambiarlo en todas las apariciones |
| `2/100` en el pie | Primera pasada de `numbering=fraction` | Compilar una segunda vez |
| `Overfull \vbox` en la portada | Título demasiado alto para el frame | `\begin{frame}[plain,shrink]` |
| `Overfull \vbox` en una diapositiva | Diagrama o texto más alto que el área útil | Acortar líneas de vida, reducir viñetas o espaciado |
| `! Missing $ inserted` | `_` sin escapar en `\texttt{}` | `hfp\_hf` |
| Tabla que se sale del ancho | Columnas demasiado anchas | `\scriptsize`, cabeceras cortas y `booktabs` |

## Checklist final

- [ ] 9–12 diapositivas, una idea por diapositiva.
- [ ] Títulos alineados con las secciones del documento fuente.
- [ ] Estilos TikZ con prefijo propio.
- [ ] `pdflatex` ejecutado dos veces.
- [ ] Sin `Overfull \vbox` ni errores en el log.
- [ ] Todas las páginas renderizadas y revisadas visualmente.
- [ ] Pie de página y numeración correctos (`n/N`, no `n/100`).
- [ ] Auxiliares eliminados; `.tex` y `.pdf` conservados.
