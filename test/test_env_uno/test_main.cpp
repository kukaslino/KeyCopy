#include <Arduino.h>
#include <unity.h>
#include <unity_config.h>

void setUp() {
    // Inicialização antes de cada teste (opcional)
}

void tearDown() {
    // Limpeza após cada teste (opcional)
}

void test_example_uno() {
    TEST_ASSERT_EQUAL(2, 2);  // Teste básico de exemplo
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_example_uno);
    UNITY_END();
}

void loop() {}
