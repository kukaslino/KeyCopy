#include <unity.h>
#include <logic.h>

void setUp() {

}

void tearDown() {

}

// Teste: Criptografia de dados com chave válida
void test_encrypt_valid_data() {
    String data = "hello";
    String key = "key";
    String expected_encrypted = String(char('h' ^ 'k')) +
                                String(char('e' ^ 'e')) +
                                String(char('l' ^ 'y')) +
                                String(char('l' ^ 'k')) +
                                String(char('o' ^ 'e'));
    String result = encrypt(data, key);
    TEST_ASSERT_EQUAL_STRING(expected_encrypted.c_str(), result.c_str());
}

// Teste: Dados vazios
void test_encrypt_empty_data() {
    String data = "";
    String key = "key";
    String result = encrypt(data, key);
    TEST_ASSERT_EQUAL_STRING("", result.c_str());
}

// Teste: Chave vazia
void test_encrypt_empty_key() {
    String data = "hello";
    String key = "";
    String result = encrypt(data, key);
    TEST_ASSERT_EQUAL_STRING(data.c_str(), result.c_str());
}

// Configuração inicial do Unity
void setup() {
    UNITY_BEGIN();

    RUN_TEST(test_encrypt_valid_data);
    RUN_TEST(test_encrypt_empty_data);
    RUN_TEST(test_encrypt_empty_key);

    UNITY_END();
}

void loop() {
}
