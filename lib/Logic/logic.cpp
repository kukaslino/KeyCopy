#ifdef UNIT_TEST
#include <iostream> // Para simular entradas e saídas no ambiente nativo
#include <string>
#else
#include <Arduino.h>
#endif

String encrypt(String data, String key) {
    String encryptedData = data;
    for (int i = 0; i < data.length(); i++) {
        encryptedData[i] = data[i] ^ key[i % key.length()];
    }
    return encryptedData;
}