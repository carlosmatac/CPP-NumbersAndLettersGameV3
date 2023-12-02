# CPP-NumbersAndLettersGameV3
This other version of the game is built with trees. Each node of the tree represents a letter. 

# Introducción

En esta práctica hemos trabajado con árboles para la implementación del juego de las letras como veníamos haciendo en las prácticas anteriores.
La diferencia con la anterior se puede ver en dos aspectos principales:
- 1) Se ha cambiado el contenedor de diccionario. Antes era un set de string en el que almacenabamos todas las palabras del diccionario. Ahora pasa
a ser un arbol, donde cada nodo contiene una única letra, de forma que se reduce el espacio ocupado por este.
- 2) Se han usado nuevas funciones para mejorar la eficiencia en la resolución con la clase Solver. En concreto getCoincidentWords y getPossibleWords.
Nuestro trabajo ha consistido en completar la clase tree, en concreto los iteradores de preorden, constantes y no constantes, y completar la clase diccionario.
A esta última le faltaba la clase iterador que funciona a partir de iteradores de la clase arbol implementada en la práctica y unas pocas funciones que para
contar los usos y ocurrencias.
Por otro lado también hemos realizado un análisis de la eficiencia de este proyecto resuleto con lo mencionado anteriormente en comparación con la práctica
anterior.

# ANALISIS DE LA EFICIENCIA:

- <b> Análisis de eficiencia en el solver </b>:\n
Para este análisis hemos llevado a cabo la misma ejecución del ejecutable partida letras (mismos argumentos),
con la implementación antigua del solver (practica 5) y la nueva (la práctica actual, 6). En cada ejecución hemos medido
en tiempo cuánto tarda en resolver la partida el solver y estos son los resultados obtenidos:

@image html puntuacion.png
@image html grafico_punt.png
@image html longitud.png
@image html grafico_lon.png

    Podemos comprobar en las gráficas y tablas que el tiempo para resolver el juego con el nuevo método es bastante más rápido que el que
    usábamos en la práctica anterior.
    Este aumento de la eficiencia en la búsqueda de palabras, se debe a que si analizamos el código que entregamos en la práctica anterior,
    la eficiencia de la búsqueda de palabras en el solver, es O(n⁴). Ya que primero obteníamos palabras para el tamaño del vector que contenía
    las letras para jugar y había que ir una por una comprobando si era válida. Con eso ya van dos for anidados más los otros dos que hay que añadir
    de la función auxiliar que comprueba si una palabra se podía formar con las letras dadas, que era un algoritmo que implementamos con un for anidado.
    Como podemos observar, la eficiencia de nuestro programa sería de O(n²) * O(n²). En comparación con la nueva que es capaz de buscar los resultados
    en un multiset con una eficiencia de O(log(n)).
    Ante la complejidad que presentaba el llevar a cabo un análisis de eficiencia con diferentes número de letras, longitud de palabras o tamaño del diccionario,
    hemos optado por hacer una prueba y tomar medidas con los mismos argumentos salvo el modo de juego que sí lo hemos variado.

- <b> Análisis de eficiencia en dictionary: </b>\n
Para este análisis hemos usado la funcinón getOcurrences en el ejecutable de cantidad letras de la práctica 4, en la que el diccionario
se implementa con un set de strings y lo hemos comparado con la implementación del arbol de esta pŕactica. Los resultados son claros.
Podemos observar que usando de contenedor un árbol nos ahorramos almacenar más de la mitad de las letras.\n
243.838 --> letras almacenadas con un árbol\n
674.711 --> letras almacenadas con un set
@image html tabla.png




# Ejecutables

## Partida letras

Dado como argumentos dos archivos, uno con un LetterSet y otro con un Dictionary respectivamente,
u caracter P o L que indica el modo de juego puntuación y longitud respectivamente y un entero que
indica el numero de letras con el que vamos a jugar. El programa muestra por pantalla las mejores
soluciones para esas letras y el diccionario.

> __partida_letras__ \<FicheroLetterSet\>  \<FicheroDictionary\> \<(char)GameMode(P/L)\> \<(int)CantidadLetras\>

@param <FicheroLetterSet> Fichero que contiene las letras con la cantidad de veces con las que se pueden jugar en una partida así
como la puntuación asociada a cada una de ellas
@param <FicheroDictionary> Fichero que contiene todas las palabras con las que se puede jugar
@param <(char)GameMode(P/L)> 'P' si jugamos a puntuación, 'L' si jugamos a palabra más larga (longitud)
@param <(int)CantidadLetras> entero que indica el número de letras que tenemos disponible en una partida, estas
letras son con las que deberemos formas las palabras

## Cantidad letras

El objetivo de este programa es comprobar el correcto funcionamiento de conteo de letras implementado.
Recibirá como argumentos un fichero de diccionario y un fichero de letras,
creará el LettersSet y el Dictionary con la información de dichos ficheros, y para cada letra del
diccionario calculará el número de veces que se usa esa letra y el número de ocurrencias de la letra
en la estructura de diccionario.

> __cantidad_letras__ \<FicheroDictionary\>  \<FicheroLetterSet\>

@param <FicheroDictionary> Fichero que contiene todas las palabras con las que se puede jugar
@param <FicheroLetterSet> Fichero que contiene las letras con la cantidad de veces con las que se pueden jugar en una partida así
como la puntuación asociada a cada una de ellas


## Diccionario

El objetivo de este programa es comprobar el correcto funcionamiento de la clase de iteradores implementado tanto en la clase dictionary
como en la clase del arbol. El funcionamiento de este archivo consiste en:
1- Se carga el contenido del archivo que se pasa como argumento en un diccionario con
   estructura de árbol
2- Se recorre el diccionario creado con un iterador, y se imprimen por pantalla todas sus
   palabras

> __diccionario__ \<FicheroDictionary\>

@param <FicheroDictionary> Fichero que contiene todas las palabras con las que se puede jugar
