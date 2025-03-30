# so_long

Este proyecto es parte del plan de estudios de 42 y consiste en crear un juego 2D usando la biblioteca MiniLibX.

## Descripción

En `so_long`, el jugador debe recolectar todos los coleccionables (representados por la letra 'C') en un mapa y luego llegar a la salida (representada por la letra 'E') para ganar. El jugador se mueve usando las teclas de flecha y el número de movimientos se muestra en la consola.

## Funcionalidades

* **Lectura de mapas:** El programa lee mapas desde archivos de texto.
* **Movimiento del jugador:** El jugador puede moverse hacia arriba, abajo, izquierda y derecha.
* **Colección de objetos:** El jugador puede recoger coleccionables.
* **Salida del juego:** El jugador puede salir del juego una vez que haya recogido todos los coleccionables.
* **Control de errores:** El programa maneja errores en la lectura de mapas y otros errores.
* **Visualización gráfica:** El juego se muestra en una ventana usando MiniLibX.

## Cómo usar

1.  **Clonar el repositorio:**

    ```bash
    git clone git@github.com:pauss12/42_So_long.git so_long
    cd so_long
    ```

2.  **Compilar el programa:**

    ```bash
    make
    ```

3.  **Ejecutar el juego:**

    ```bash
    ./so_long maps/<mapa.ber>
    ```

    Reemplaza `<mapa.ber>` con la ruta del archivo de mapa que deseas jugar.

## Controles

* **Flechas de dirección:** Mover al jugador.
* **ESC:** Salir del juego.

## Formato del mapa

El mapa debe ser un archivo de texto con las siguientes características:

* **Paredes:** Representadas por el carácter '1'.
* **Espacios vacíos:** Representados por el carácter '0'.
* **Jugador:** Representado por el carácter 'P'.
* **Coleccionables:** Representados por el carácter 'C'.
* **Salida:** Representada por el carácter 'E'.
* El mapa debe ser rectangular y estar rodeado de paredes (1).
* Debe haber exactamente un jugador, una salida y al menos un coleccionable.

## Ejemplo de mapa
![alt text](/textures/image.png)

## Errores

El programa maneja los siguientes errores:

* **Mapa inválido:** El mapa no cumple con el formato requerido.
* **Argumentos inválidos:** Se proporciona un número incorrecto de argumentos.
* **Error al leer el mapa:** No se puede leer el archivo del mapa.
* **Mapa no tiene extensión .ber**
* **Error al inicializar MiniLibX:** No se puede inicializar la biblioteca gráfica.
* **Mapa no se puede resolver:** El flood fill no ha podido finalizar
* **Jugador esta rodeado de paredes**
* **Salida rodeada de paredes**
* **Coleccionable rodeado de paredes**
* **No hay o hay mas de una salida**
* **No hay o hay mas de un jugador**
* **No hay coleccionables**


## Créditos

* Este proyecto fue creado por mi (pmendez-) como parte del plan de estudios de 42.
* La biblioteca MiniLibX fue desarrollada por 42.

## Notas adicionales

* Si tienes problemas para compilar o ejecutar el programa, asegúrate de tener MiniLibX instalada correctamente.