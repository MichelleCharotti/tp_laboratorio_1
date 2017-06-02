#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[50];
    int puntaje;
    char linkImagen[50];
    int estado;
    int idPelicula;
}EMovie;


/**\brief Obtiene el primer indice libre del array.
 * \param movie, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param i, recorre la posicion del array.
 * \return El primer indice disponible.
 */
void Estados(EMovie[],int);

/**\brief Obtiene el indice que coincide con el id pasado por parametro.
 * \param movie, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param id, el id a ser buscado en el array.
 * \return Retorna el estado del parametro id.
 */
int buscarID(EMovie[],int,int);

/**
 *  Agrega una pelicula al archivo binario
 *  \param movie la estructura a ser agregada al archivo
 *  \param tam, pasa el tamaño del array.
 *  \return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie[],int);

/** \brief Valida si contienen numeros.
 * \param  validacion, se pasa como parametro para validar.
 * \return Retorna 1 si contiene numeros o 0 si no.
 */
int validacionChar(char[]);

/**
 *  Borra una pelicula del archivo binario
 *  \param movie la estructura a ser eliminada al archivo
 * \param tam, pasa el tamaño del array.
 *  \return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
void borrarPelicula(EMovie[],int);

/** \brief Busca si el dato ingresado existe y lo modifica.
 * \param movie, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \param auxInt, se ingresa dato a modificar.
 * \param respuesta, confirma si se deseas modificar.
 * \return Retorna el estado del dato.
 */
void modificarPelicula(EMovie[],int);

/** \brief Muestra a las peliculas.
 * \param movie, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \return Muestra una lista con los datos.
 */
void listarPelicula(EMovie*,int);

/** \brief Carga el archivo.
 * \param x, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \return Retorna el archivo.
 */
int cargarDesdeArchivo(EMovie*,int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  \param lista la lista de peliculas a ser agregadas en el archivo.
 *  \param nombre el nombre para el archivo.
 */
void generarPagina(EMovie[]);

/** \brief Abre y escribe el archivo.
 * \param x, se pasa como parametro.
 * \param tam, pasa el tamaño del array.
 * \return Retorna el archivo con los datos.
 */
int guardarEnArchivo(EMovie*,int);

#endif // FUNCIONES_H_INCLUDED
