# SituacionProblema_POAO
Proyecto realizado en la materia de Programación Orientada a Objetos

Este proyecto consta de una base de datos de emprersas PyME's y de trabajadores  de dichas PyME's. Esta base de datos consta de un menú con 5 opciones que se repetirá hasta seleccionar la opción 'Salir':
1) Agregar una PyME
2) Agregar Trabajador
3) Consultar PyME
4) Consultar Trabajador
5) Salir

Al seleccionar la opción 1, se le piden al usuario todos los datos de la PyME, incluyendo su nombre, razón social, dirección, nombre del director, número de trabajadores y cantidad de pesos generados al año. De la misma forma al seleccionar la opción 2, se le pide al usuario el nombre de una PyME y se revisa que esa PyME exista, si es así se solicitan al usuario los datos del trabajador y se guardan automáticamente algunos de los datos de la PyME en la que trabaja. En caso de que la PyME en la que se intenta registrar el trabajor no exista, se muestra un mensaje donde se menciona que la PyME no existe.

Al seleccionar las opciones 3 o 4, se le pide al usuario el nombre de la PyME o trabajador que desea consultar, y se muestran en pantalla todos los datos registrados de esa PyME o trabajador, y en caso de que el usuario introduzca un nombre de PyME o trabajador incorrecto se muestra en pantalla un mensaje de error.

Para la realización de este programa se hizo uso de objetos, se declararon las clases 'PyME' y 'Trabajador'. En ambas clases se declararon sus atributos privados, y las funciones para funciones para asignarle valores a dichos atributos y para consultar esos valores se declararon públicas. Posteriormente en el main se declaró un array de objetos de la clase 'PyME', y otro array de objetos de la clase 'Trabajador' y en estos se almacena la información cada que se agrega una nueva PyME o un nuevo trabajador.
