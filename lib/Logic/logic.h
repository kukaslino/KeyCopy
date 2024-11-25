#ifndef LOGIC_H
#define LOGIC_H

#ifdef UNIT_TEST
#include <iostream> // Para simular entradas e saídas no ambiente nativo
#include <string>
#else
#include <Arduino.h>
#endif

String encrypt(String data, String key);

#endif
