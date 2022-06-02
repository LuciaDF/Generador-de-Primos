<br />

# Generador de Primos
 <br />
  <br />
  
## 1.- Objetivo:

 <br />
  <br />
En este proyecto está enfocado en la búsqueda y, finalmente, la acción de generar primos.
 <br />
  <br />
  
## 2.- Algoritmos:
 <br />
 
* Detector de Compuestos
* Miller Rabin
* Random Bits
* RandomGen_Primos

  
<br />
  <br />
  
## Acerca de:

 <br />


### *Detector de Compuestos*:


Para un numero compuesto *n*, *n -1* es primo y se puede escribir de la siguiente manera:

 <br />

<img width="200" alt="" src="https://user-images.githubusercontent.com/62950378/170874057-c5eb4b7c-b0a9-4968-9882-f7f9ab163862.png">

 <br />
 
Esto nos permite utilizarlo para factorizar en el Pequeño Teorema de Fermat (*Test de Primalidad de Fermat*):
 <br />
  <br />
  
<img width="1000" alt="" src="https://user-images.githubusercontent.com/62950378/170874109-621e6d3d-757f-479d-9219-9537a04c1e20.png">
 <br />
 
Si n es primo tendrá que dividir a todos los factores, si al menos divide a uno será pseudoprimo en la base *a*, si no cumple ninguna de estas significa que es compuesto. Con la condición, del Test de Primalidad de Fermat, que 2 < *a* ≤ n-1.


 <br />

###  *Miller Rabin*


Con la ayuda del Detector de Compuestos, el algoritmo Miller Rabin calcula los respectivos *t* y *u* de *n - 1*. Finalmente, determinamos una variable *s* el cual se encargará del grado de confianza, es decir, medir cuan fuerte es un pseudoprimo. Un pseudoprimo fuerte tiene altas probabilidades de ser primo por lo tanto, entre más valor le otorguemos a *s*, más probabilidad tendrá de que sea un pseudoprimo fuerte.
 <br />
 <br />
  <br />
 ###  *Random Bits*

Algoritmo que te permite generar un numero aleatorio de *b* bits. Origina un primo aleatorio el cual, con la ayuda de una "máscara", si su último digito es 1 significa que es impar, si es 0 es par.
 
   <br />
    <br />
     <br />
     
### *RandomGen_Primos*
 
Verifica que un numero de *b* bits sea primo. Con la ayuda de Miller Rabin, si este resulta no ser primo entonces tiene que ir aumentando en 2 unidades hasta ser primo.

 <br />
   <br />
    <br />
   
## 3.- Grado de Confianza:

Acerca del grado de confianza se basó en el punto 4.48 [1] donde se aprecian condiciones con respecto de *pk,t*  el cual es la probabilidad de que n resulta ser compuesto aun puesto a prueba en el algoritmo de Miller-Rabin para un *k* como el número de bits y *t* como el parámetro de seguridad (o, puesto en otras palabras, el grado de confianza). El punto es que por *k* bits se toma un valor *t* definido según las condiciones para tener un óptimo resultado al calcular *pk,t* . La explicación de *pk,t*   se puede ver a fondo en los punto 4.46 y 4.47 [1].

<br />

    OJO: La variable t del punto 2 no es la misma a la del punto 3. 


<br />

En el caso de 16 bits aumentaré más 1 por decisión propia.



<img width="2000" alt="Fact 4.48" src="https://user-images.githubusercontent.com/62950378/171676899-4d552aea-ea2a-463c-a211-d16b64c55361.png">

 <br />
 <br />
 
| Nro bits      | s    |
| ----------- | ---------------- |
| 16 bits     | 2|
|  32 bits      | 3 |
|  64 bits      | 5 |

 <br />
 <br />

## 4.- Pseudocodigo:

 <br />
 
<img width="488" alt="Detector de Compuestos" src="https://user-images.githubusercontent.com/62950378/170874378-9e74d7fa-6d5c-4134-928e-66eac8c8be90.png">

 <br />
 
<img width="587" alt="Miller Rabin" src="https://user-images.githubusercontent.com/62950378/170874429-4fd772b9-d6c6-4331-83d8-a0fe7f83fb0f.png">

 <br />

<img width="635" alt=" Random Bits" src="https://user-images.githubusercontent.com/62950378/170877686-670933e9-4f54-4ebd-a7f8-f2abe2f93c86.png">

 <br />
 
<img width="338" alt="RandomGen_Primos" src="https://user-images.githubusercontent.com/62950378/170877764-39cf408e-1da0-4322-b7b2-3eccec91bf2a.png">
 <br />
 <br />
 
## 5.- Lenguaje de Programación:

 <br />
 

|  Lenguaje de Programación | C++ |
| --------------------------| :---:| 

 <br />
 <br />

 
## 6.- Como instalarlo:

El proyecto está concentrado en el main.cpp el cual se puede descargar o copiar y después añadir a un proyecto ya sea en **Visual Studio** o en **Xcode**.

 <br />
 <br />

 **Descarga:**
 [main.cpp.zip](https://github.com/LuciaDF/Generador-de-Primos/files/8793650/main.cpp.zip)
 <br />
 <br />
## 7.- Instalación Extra:

 <br />

 ### MacOs:
 
Para poder usar  int128_t deberá descargar:

  **1.** package management system **Brew**:

  * Enlace con pasos:


        https://phoenixnap.com/kb/install-homebrew-on-mac

 **2.** Después descargar **Boost** library::

  * Enlace con pasos:

          http://neutrofoton.github.io/blog/2016/03/27/configure-boost-c-plus-plus-on-xcode/

        
 <br />

  ### Windows:

  

  
 <br />
  <br />
  
## 8.- Como usarlo:

Al compilarlo se visualizará un **Menú** el cual al elegir su respectivo número se podrá desplegar el resultado.


```c++

int main(int argc, const char * argv[])
{
    Menu();
}

```

## 8.- Referencias:

[1] A.Menezes, P.van Oorschot y S.Vanstone. (1996). *Chapter 4: Public-Key Parameters. En Handbook of Applied Cryptography(810). CRC Press.*




 <br />
 <br />
  <br />
 <br />
 

______


 <br />
 <br />
  <br />
 <br />
