#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


/**\brief Obtiene el primer indice libre del array.
 * \param persona, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param i, recorre la posicion del array.
 * \return El primer indice disponible.
 */
void  Estados(EPersona[],int);

/** \brief Se ingresan todos los datos a utilizar en el programa.
 * \param persona, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param flag, valida si hay espacio o no.
 * \param flagDig, valida si se ingreso numeros en el nombre.
 * \param cant, cantidad de caracteres que contiene el parametro nombre.
 * \param estados, el estado del dni si ya se ingreso o no.
 * \return Retorna los datos ingresados.
 */
void ingresarDato(EPersona[],int);

/** \brief Busca si el dato ingresado existe y lo borra.
 * \param persona, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param auxDni, se ingresa dato a eliminar.
 * \param respuesta, confirma si se deseas eliminar.
 * \return Retorna el estado del dato.
 */
void borrarUnDato(EPersona[],int);

/** \brief Ordena los datos por nombre y si son iguales por dni.
 * \param persona, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param auxNom, guarda los valores para pasarlo devuelta al dato nombre.
 * \param aux, guarda los valores para pasarlo devuelta a los datos dni, edad y estado.
 * \return Devuelve los valores ordenados.
 */
void ordenPorNombre(EPersona[],int);

/** \brief Tabula un grafico de barras segun los valores de la edad.
 * \param persona, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param contMen, es un contador de edades menores a 18.
 * \param cont, contador de edad entre 19 y 35.
 * \param contMay, contador de edad de mayores de 35.
 * \param dato[], array de los contadores.
 * \param maximo, el mayor valor de los contadores.
 * \return Devuelve grafico.
 */
void graficoEdad(EPersona[],int);

/**\brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param persona, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param dni, el dni a ser buscado en el array.
 * \return Retorna el estado del parametro dni.
 */
int buscarDNI(EPersona[],int,int);


#endif // FUNCIONES_H_INCLUDED
