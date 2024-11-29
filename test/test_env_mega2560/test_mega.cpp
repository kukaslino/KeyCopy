#include <Arduino.h>
#include <unity.h>
#include <SD.h>
#include <logic.h>

void setUp(void) {

}

void tearDown(void) {

}

const int chipSelect = 53;

// Função para normalizar strings
String normalizeString(const String& input) {
    String normalized = input;
    normalized.replace("\r", "");
    normalized.replace("\n", "");
    return normalized;
}

// Testa se a inicialização do SD ocorre com sucesso
void test_initiate_sd() {
    bool initialized = SD.begin(chipSelect);
    TEST_ASSERT_TRUE(initialized);
}

// Testa a leitura de um arquivo existente no cartão SD
void test_read_sd_success() {
    // Remova o arquivo, se existir, para evitar duplicações
    SD.remove("card4.txt");

    // Cria um arquivo de teste no cartão SD
    File testFile = SD.open("card4.txt", FILE_WRITE);
    if (testFile) {
        testFile.print("Conteudo de teste"); // Escreve sem newline
        testFile.close();
    } else {
        TEST_FAIL_MESSAGE("Erro ao criar o arquivo card1.txt");
    }

    // Lê o arquivo usando a função read_SD
    String result = read_SD_test(4);
    TEST_ASSERT_EQUAL_STRING("Conteudo de teste", normalizeString(result).c_str());
}

// Testa a leitura de um arquivo inexistente
void test_read_sd_file_not_found() {
    String result = read_SD_test(99); // Um número de arquivo improvável de existir
    TEST_ASSERT_EQUAL_STRING("", result.c_str());
}

void test_encrypt() {
    String data = "Hello, World!";
    String key = "Xmitt";
    String encryptedData = encrypt(data, key);

    String expectedEncrypted = data;
    for (int i = 0; i < data.length(); i++) {
        expectedEncrypted[i] = data[i] ^ key[i % key.length()];
    }

    TEST_ASSERT_EQUAL_STRING(expectedEncrypted.c_str(), encryptedData.c_str());
}

void test_decrypt() {
    String data = "Hello, World!";
    String key = "Xmitt";
    String encryptedData = encrypt(data, key);
    String decryptedData = encrypt(encryptedData, key);

    TEST_ASSERT_EQUAL_STRING(data.c_str(), decryptedData.c_str());
}

#ifdef ARDUINO

#include <Arduino.h>
void setup() {

    delay(2000);

    UNITY_BEGIN();
    RUN_TEST(test_encrypt);
    RUN_TEST(test_decrypt);
    RUN_TEST(test_initiate_sd);
    RUN_TEST(test_read_sd_success);
    RUN_TEST(test_read_sd_file_not_found);
    UNITY_END();
}

void loop() {

}

#else

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_encrypt);
    RUN_TEST(test_decrypt);
    UNITY_END();
    return 0;
}

#endif
