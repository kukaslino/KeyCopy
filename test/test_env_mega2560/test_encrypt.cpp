#include <Arduino.h>
#include <unity.h>
#include <SD.h>

// Protótipo da função a ser testada
String encrypt(String data, String key);

// Testa a criptografia com dados e chaves diferentes
void test_encrypt_valid_data() {
    String data = "123456";
    String key = "key";
    String expected = String(char(1)) + String(char(53)) + String(char(55)) + 
                      String(char(50)) + String(char(52)) + String(char(56));
    TEST_ASSERT_EQUAL_STRING(expected.c_str(), encrypt(data, key).c_str());
}

void test_encrypt_empty_data() {
    String data = "";
    String key = "key";
    TEST_ASSERT_EQUAL_STRING("", encrypt(data, key).c_str());
}

void test_encrypt_empty_key() {
    String data = "123456";
    String key = "";
    TEST_ASSERT_EQUAL_STRING(data.c_str(), encrypt(data, key).c_str());
}

void setup() {
    UNITY_BEGIN(); // Inicia o Unity
    RUN_TEST(test_encrypt_valid_data);
    RUN_TEST(test_encrypt_empty_data);
    RUN_TEST(test_encrypt_empty_key);
    UNITY_END();   // Finaliza o Unity
}

void loop() {
    // Deixe vazio para testes unitários
}
