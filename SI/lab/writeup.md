# AG

## Ejecucion

`./nreinas 8 100 1000 ROUL ONEP FLIP 0.85 0.025`

## 1. Analiss

De 41 hasta 70 reinas la probabilidad de mutación de 0.05 a 0.0.25 anterior es
demasiado para asegurar una solución. Entonces en este nuevo estudio se añaden
columnas de 0.01375 y 0.0125, en las que aparecen mas soluciones a lo largo do todo
la dimensión de N de reinas.

Elegimos 0.01375 de Pm para N reinas de 41 a 67, y 0.0125 de 68 a 70, porque
así se evitan las instancias donde el algoritmo genético no llega a una solución
satisfactoria. 


## 2. Manual de Asignación

 - Parametro 1: \<N de reinas\>
 - Parametro 2: 100
 - Parametro 3: 10000
 - Parametro 4: TOUR
 - Parametro 5: ONEP
 - Parametro 6: FLIP
 - Parametro 7: 0.85
 - Parametro 8: para N reinas
   - menor que 8: 0.05 <br>
   - de 9 a 60: 0.0125 <br>
   - 61: 0.01375 <br>
   - de 62 a 70: 0.0125 <br>


## 3. Anaslsis del comportamiento global del SI basado en AG con respecto 4 criterios

### Completitud

Si se sigue el manual de asignación correctamente, si, es completo

### Optimalidad

El problema no es de optimización, mientras que haya 0 jaques, dos soluciones son igualmente optimas

### Complejidad en tiempo y


| N reinas | tiempo (s) |
|----------|------------|
| 7        | 0m0.029s |
| 8        | 0m0.018s |
| 23       | 0m0.171s |
| 28       | 0m3.058s |
| 40       | 0m5.631s |
| 41       | 0m3.852s |
| 61       | 0m13.347s |
| 68       | 0m9.291s |
| 72       | 0m28.189s |
| 73       | 0m36.349s |

### Complejidad en memoria

Fijo, ya que el tamaño de la población es siempre 100

