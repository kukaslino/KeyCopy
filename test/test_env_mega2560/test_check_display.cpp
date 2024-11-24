#include <Arduino.h>
#include <unity.h>
#include <SD.h>

// Protótipo da função a ser testada
bool CheckAndDisplayFile(int fileNumber);

// Mock para o SD
class MockSD {
public:
    static bool exists(const char *filename) {
        return String(filename) == "card1.txt"; // Simula o arquivo "card1.txt"
    }
};

void test_check_file_exists() {
    TEST_ASSERT_TRUE(CheckAndDisplayFile(1));
}

void test_check_file_not_exists() {
    TEST_ASSERT_FALSE(CheckAndDisplayFile(2));
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_check_file_exists);
    RUN_TEST(test_check_file_not_exists);
    UNITY_END();
}

void loop() {
    // Deixe vazio para testes unitários
}
