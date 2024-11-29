#ifndef LOGIC_H
#define LOGIC_H

#include <Arduino.h>

String encrypt(String data, String key);

void Iniciate_SD_test();
String read_SD_test(int fileNumber);

#endif
