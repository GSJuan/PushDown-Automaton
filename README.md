# PushDown-Automaton
## Autor: Juan García Santos alu0101325583 
### Español:
Simulador de autómata de pila con finalización por vaciado de pila (APv)

Requisitos: Tener instalado y actualizado cmake y gdb

- Comandos de compilación (ejecutados desde el directorio en el que se encuentra este README):
```bash
cmake -B build
cmake --build build --config Debug --target all --
```

- Comando de ejecución de ejemplo
```bash
./build/PushDown-Automaton -f APv-3.txt -t
```

NOTA: Si se quisiera añadir otro fichero de definicion de automata para probar, se debe arrastrar a la carpeta 'test'.
Una vez hecho eso, simplemente ejecute el programa dandole el nombre del archivo como parámetro usando la opción -f
El programa está codificado para que las rutas de los archivos de definición de autómatas esten fijados a ese directorio. Por ello, es necesario que el archivo se encuentre en el directorio y solo pase como argumento el nombre del mismo, no su ruta.

Códigos de error:
  1 - Error en la apertura de archivo de definición de autómata
  2 - Autómata definido incorrectamente

### English:
Empty stack PushDown automaton simulator in C++

Prequisites: having cmkae and gdb installed and updated

Compilation command (executed inside the directory where this README is located):
```bash
cmake --build build --config Debug --target all --
```

Execution example command:
```bash
./build/PushDown-Automaton -f APv-3.txt -t
```

Note: If you would like to add more example Files, just drag them to the 'test' folder
Once you´ve done that, simply execute the program giving the file name as a parameter.
The program is coded to accept only names of files inside the test folder.

Error codes:
  1 - Error opening automaton definition file
  2 - Automaton not defined correctly 
