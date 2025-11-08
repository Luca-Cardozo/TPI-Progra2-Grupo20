#pragma once
#include "Fecha.h"
#include "Hora.h"
#include <string>

std::string cargarCadena();
bool fechaDecreciente(Fecha f1, Fecha f2);
bool fechaCreciente(Fecha f1, Fecha f2);
bool fechaHoraCreciente(Fecha f1, Fecha f2, Hora h1, Hora h2);
bool fechaHoraDecreciente(Fecha f1, Fecha f2, Hora h1, Hora h2);
bool intDecreciente(int n1, int n2);
bool intCreciente(int n1, int n2);
int validarPositivo(int num);
void validarCarga(bool resultado);
void validarModificacion(bool resultado);
void validarBaja(bool resultado);
void validarAlta(bool resultado);
int preguntarOrdenCrecienteDecreciente();
std::string pedirCadena(std::string texto = "nombre");
int pedirIdValido(int cantRegistros);
void pedir2FechasValidas(Fecha &f1, Fecha &f2);
void pedir2HorariosValidos(Hora &h1, Hora &h2);
int pedirAnioValido();
int pedirMesValido();
bool confirmarAccion(std::string mensaje);
bool deseaCancelar(std::string mensaje = "Ingrese 0 para cancelar o cualquier numero para continuar: ");
bool pedirIdConCancelacion(std::string mensaje, int &id);
