# Memorama C++

Juego de memorama en consola desarrollado en C++ para Windows, con categorias tematicas, niveles de dificultad, modo simulacion, mantenimiento de palabras y reporte de partidas.

## Descripcion

El objetivo es encontrar pares de palabras ocultas en un tablero. El jugador selecciona celdas por numero y debe recordar la posicion de cada palabra para completar todos los pares en el menor tiempo posible.

El proyecto incluye:

- Interfaz en consola con pantallas y menu principal.
- Sonidos durante menu, juego, mantenimiento y victoria.
- Categorias de palabras (colores, paises y animales).
- Dificultades de juego (facil, normal y dificil).
- Modo simulacion (la maquina elige categoria y dificultad).
- Registro de datos en archivos de texto y binario.
- Modulo de mantenimiento para agregar, leer y eliminar palabras.

## Menu principal

Opciones disponibles:

- `1.- Jugar`
- `2.- Simulacion`
- `3.- Reporte`
- `4.- Mantenimiento`
- `5.- Salir`

## Mecanica de juego

1. Se solicita alias del jugador.
2. Se escoge categoria: `colores`, `paises` o `animales`.
3. Se escoge dificultad:
   - Facil: `3 pares` (tablero 3x2)
   - Normal: `6 pares` (tablero 4x3)
   - Dificil: `8 pares` (tablero 4x4)
4. Se destapan dos posiciones por turno.
5. Si son iguales, el par queda descubierto; si no, se vuelven a tapar.
6. Al completar todos los pares, se registra el resultado.

## Requisitos

- Windows (usa `windows.h`, `conio.h`, `Beep`, `Sleep`, API de consola)
- Compilador C++ compatible con proyecto tipo Dev-C++ o MinGW
- Archivos de datos en la misma carpeta del ejecutable

## Estructura de archivos

- `Proyecto.cpp`: archivo principal del juego
- `juego.h`: logica de tablero, alias, pares y flujo de partida
- `mantenimiento.h`: alta, baja y lectura de palabras por categoria
- `reportes.h`: escritura y ordenamiento de reportes binarios
- `estetica.h`: utilidades de consola (colores, cursor, margenes, pantallas, audio)
- `ProyectoFinalMemorama.dev`: proyecto de Dev-C++
- `ProyectoFinalMemorama.layout`: layout del proyecto
- `Colores.txt`, `Paises.txt` (y categoria de animales esperada por codigo)
- `DatosJugadores.txt`: historial de tableros/jugadores
- `DatosBinario.dat`: historial binario de partidas
- `Musica/`: archivos `.wav` usados por el juego

## Compilar y ejecutar

### Opcion 1: Dev-C++

1. Abrir `ProyectoFinalMemorama.dev`.
2. Compilar y ejecutar desde el IDE.

### Opcion 2: MinGW (g++)

Compilar desde la carpeta del proyecto:

```bash
g++ Proyecto.cpp -o memorama.exe
memorama.exe
```

## Notas importantes

- Existe un archivo alterno `pantallasss.cpp` con otro `main`; no se recomienda compilarlo junto con `Proyecto.cpp` para evitar conflicto de punto de entrada.
- El codigo espera archivos de categorias para cargar palabras. Si falta alguna categoria, se debe crear su archivo correspondiente.
- Los sonidos `.wav` deben mantenerse disponibles para que el juego reproduzca audio correctamente.

## Equipo

Integrantes observados en el proyecto:

- Alan Gael Gallardo Jimenez
- Carlos Enrique Blanco Ortiz
- (Otros integrantes segun encabezados del proyecto)

## Estado

Proyecto academico funcional en entorno Windows con enfoque en estructuras de datos, manejo de archivos, validacion de entradas y experiencia de usuario en consola.
