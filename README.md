# BaseGame
Creacion de un juego en c++ con libreria tinyPTC y picoPNG


# Generar Build
Dentro del directorio raiz correr el siguiente comando

```
make
```

Generara una carpeta obj con los archivos compilados

# Correr
Ejecutar el siguiente comando

```
./game
```

En el archivo makefile game es el nombre de nuestra applicacion, cambielo por el nombre que desee.


# Buenas Practicas al programar con C++

Al crear una clase:
    poner el constructor en explicit default para que no pueda ser llamado indirectamente(por inferencia)

Al crear una funcion:
    preguntarse si va a lanzar una excepcion
    preguntarse si puede ejecutarse al momento de compilar(constexpr)
    debe devolver una referencia cons, modificable o ambas
    
