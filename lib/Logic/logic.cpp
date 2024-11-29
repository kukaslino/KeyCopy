#include <Arduino.h>
#include <logic.h>
#include <SD.h>

String encrypt(String data, String key) {
    String encryptedData = data;
    for (int i = 0; i < data.length(); i++) {
        encryptedData[i] = data[i] ^ key[i % key.length()];
    }
    return encryptedData;
}

void Iniciate_SD_test() {
    if (!SD.begin()) {
        Serial.println("Erro ao inicializar o cartão SD");
        while (true); // Fica travado em caso de erro crítico
    }
}

String read_SD_test(int fileNumber) {
    String fileName = "card" + String(fileNumber) + ".txt";
    Iniciate_SD_test();

    File myFile = SD.open(fileName);
    if (myFile) {
        String fileContent = "";
        while (myFile.available()) {
            fileContent += (char)myFile.read();
        }
        myFile.close();
        return fileContent; // Pode ser criptografado ou processado
    } else {
        Serial.println("Erro ao abrir " + fileName);
        return "";
    }
}
