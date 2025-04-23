// foo.h
#ifndef FOO_H
#define FOO_H

/**
 * foo: calcula o dia seguinte a uma data válida.
 * Parâmetros de entrada:
 *   month (1..12), day (1..31 conforme mês/ano bissexto), year (1900..2099)
 * Retorno:
 *   "E01": mês fora do intervalo
 *   "E02": dia fora do intervalo ou data inválida
 *   "E03": ano fora do intervalo
 *   "E04": ultrapassou limite máximo de ano ao avançar
 *   buffer estático "DD/MM/YYYY" com data seguinte
 */
char* foo(int month, int day, int year);

#endif // FOO_H