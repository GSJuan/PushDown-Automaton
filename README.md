# PushDown-Automaton
## Autor: Juan García Santos alu0101325583 
### Español:
Simulador de autómata por vaciado de pila

Comando de compilación:
```bash
cmake --build build --config Debug --target all --
```

Comando de ejecución de ejemplo
```bash
./build/PushDown-Automaton -f APv-3.txt -t
```

Nota: Si se quisiera añadir otro fichero de definicion de automata para probar, se debe arrastrar a la carpeta 'test'
Una vez hecho eso, simplemente ejecute el programa dandole el no,bre del archivo como parámetro usando la opción -f
El programa está codificado para que las rutas de los archivos de definición de autómatas esten fijados a ese directorio. Por ello, es necesario que el archivo se encuentre en el directorio y solo pase como argumento el nombre del mismo, no su ruta.

Códigos de error:
  1 - Error en la apertura de archivo de definición de autómata
  2 - Autómata definido incorrectamente

### English:
Empty stack PushDown automaton simulator in C++

Compilation command:
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