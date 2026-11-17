# Worklog del agente

- **Fecha:** 16 de noviembre de 2026
- **Directorio de trabajo:** `/home/arf20/practicas-uni/TCI/ia`
- **Modelo:** `modelo-gordo` (endpoint Custom)
- **Entorno:** Linux, TeX Live con `pdflatex`/`lualatex`, tema Metropolis, TikZ y `booktabs`

---

## Prompt 1

> te he dejado un PDF de material teórico sobre Bluetooth. tu tarea es realizar una investigación sobre el escenario B (realizar una llamada de manos libres, en escenarios.md) siguiendo la estructura de estructura.md, debes recabar información sobre como funcionaría cada parte, y una descripción sobre como sería una posible implementación. has de ser breve.

*Nota: el prompt llegó dos veces. El primer intento no se procesó tras un cambio de modelo; se trabajó sobre el segundo envío.*

**Objetivo:** investigar el escenario B (llamada de manos libres) y redactar un documento breve siguiendo las cinco partes de `estructura.md`, añadiendo una posible implementación.

**Qué se hizo:**

- Se leyeron `escenarios.md` (escenarios A, B y C) y `estructura.md` (Conexión, Capas Bluetooth, Dispositivos, Enlaces, Perfiles).
- Se inspeccionó `Tema 6.pdf`: 33 páginas sobre WPAN, Bluetooth clásico, BLE, RFID y NFC. Se extrajo el texto con `pdftotext -layout`.
- Se complementó la teoría del PDF con la especificación oficial **Hands-Free Profile 1.9** (Bluetooth SIG, 2023), porque las transparencias solo mencionan HFP dentro de la lista de perfiles y no detallan su funcionamiento.
- Se verificó la línea temporal de HFP: **1.5** introduce eSCO, **1.6** añade voz de banda ancha (mSBC, 16 kHz) y **1.9** añade LC3-SWB (32 kHz).

**Resultado:** `investigacion_escenario_B.md` (unos 5,3 KB), con estas secciones:

1. **Conexión:** descubrimiento, SSP, ACL, SDP (UUID `0x111F`), SLC por RFCOMM y apertura del audio al llamar.
2. **Capas Bluetooth:** radio, baseband, LMP, L2CAP, RFCOMM, SDP y HFP; la voz va por SCO/eSCO, no por L2CAP.
3. **Dispositivos:** AG (móvil) y HF (coche/auricular), perfiles comunes y roles maestro/esclavo.
4. **Enlaces:** ACL para control, SCO para CVSD y eSCO para mSBC.
5. **Perfiles:** HFP como principal, HSP de respaldo, SPP como transporte, PBAP/MAP/A2DP opcionales.
6. **Posible implementación:** prototipo HF con ESP32/Bluedroid o AG con BlueZ + oFono, flujo de estados y verificación con `btmon`/Wireshark.

---

## Prompt 2

> ahora, puedes generar una presentación en LaTeX (usando beamer) para presentar toda esta información?

**Objetivo:** convertir la investigación en una presentación Beamer.

**Qué se hizo:**

- Se comprobó el entorno: `beamer.cls`, Metropolis, TikZ y `booktabs` disponibles; Fira Sans **no** instalado.
- Se creó `presentacion_escenario_B.tex` con `aspectratio=169`, tema Metropolis, colores propios y 11 diapositivas:
  1. Portada
  2. El escenario (diagrama AG ↔ HF)
  3. Conexión: establecimiento (flujo de 4 pasos)
  4. Conexión: durante la llamada (diagrama de secuencia)
  5. Capas Bluetooth (pila TikZ)
  6. Dispositivos y roles (dos columnas)
  7. Enlaces (tabla ACL/SCO/eSCO)
  8. Perfiles (imprescindibles/opcionales y versiones)
  9. Posible implementación (ESP32 o BlueZ/oFono + flujo)
  10. Resumen
  11. Referencias

**Incidencias y soluciones:**

- `lualatex` falló al cargar la fuente sans por defecto: `Font \TU/lmss/m/n/10=[lmsans10-regular] ... metric data not found`. Al no estar Fira Sans, Metropolis cae a Latin Modern Sans, que no está disponible como OpenType para LuaTeX. **Solución:** compilar con `pdflatex`; el aviso de Metropolis sobre XeLaTeX/LuaLaTeX es inofensivo.
- Los estilos TikZ `step` y `dev` colisionaron con claves internas de PGF (`/tikz/step requires a value`, `/tikz/dev` desconocido). **Solución:** prefijar todos los estilos: `btstep`, `btdev`, `btlayer`, `btflow`.
- `numbering=fraction` mostraba `2/100` tras la primera compilación. **Solución:** ejecutar `pdflatex` dos veces para que lea el total de diapositivas del `.aux`; queda `2/11`.
- Dos `Overfull \vbox`: la portada (13,8 pt) se corrigió con `\begin{frame}[plain,shrink]`; el diagrama de secuencia (8,6 pt) se corrigió acortando las líneas de vida y la última flecha.
- Se renderizaron las 11 páginas con `pdftoppm` y se revisaron visualmente para detectar desbordamientos, texto cortado y colisiones con el pie.

**Resultado:** `presentacion_escenario_B.pdf`, 11 páginas, 16:9, 151 KB, sin avisos de overfull pendientes. Se eliminaron los auxiliares `.aux`, `.log`, `.nav`, `.out`, `.snm` y `.toc`.

---

## Prompt 3

> muy bien, ahora genera un archivo markdown llamado worklog-agente.md con los prompts de esta sesión y lo que has conseguido hacer de cada uno, y guarda una skill en markdown con lo que has aprendido de beamer en skills/beamer.md

**Objetivo:** documentar la sesión y destilar las lecciones de Beamer en una skill local.

**Qué se hizo:**

- Se creó este `worklog-agente.md` con los tres prompts y el resultado de cada uno.
- Se creó `skills/beamer.md` con el procedimiento, la plantilla mínima, los errores encontrados y una lista de verificación.
- Se comprobó que la skill interna de Hermes `beamer-presentations` ya existe y cubre el mismo flujo; el archivo local es una versión de proyecto, autocontenida y en español.

**Resultado:** `worklog-agente.md` y `skills/beamer.md`.

---

## Artefactos de la sesión

| Archivo | Descripción |
|---|---|
| `investigacion_escenario_B.md` | Investigación del escenario B con las cinco partes de `estructura.md` más implementación. |
| `presentacion_escenario_B.tex` | Fuente Beamer de 11 diapositivas. |
| `presentacion_escenario_B.pdf` | Presentación compilada, 11 páginas en 16:9. |
| `worklog-agente.md` | Este documento. |
| `skills/beamer.md` | Skill local con lo aprendido sobre Beamer. |

## Recompilar la presentación

```bash
cd /home/arf20/practicas-uni/TCI/ia
pdflatex -interaction=nonstopmode -halt-on-error presentacion_escenario_B.tex
pdflatex -interaction=nonstopmode -halt-on-error presentacion_escenario_B.tex
```

## Verificar la presentación

```bash
pdfinfo presentacion_escenario_B.pdf | grep -E "Pages|Page size"
pdftoppm -png -r 100 presentacion_escenario_B.pdf /tmp/slide
```

Revisar las imágenes `/tmp/slide-*.png` antes de entregar.
