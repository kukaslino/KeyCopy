#include <unity.h>
#include <unity_config.h>

#ifdef UNIT_TEST
#include <iostream> // Para simular entradas e saídas no ambiente nativo
#include <string>
#else
#include <Arduino.h>
#endif

void setUp() {
    // Inicialização antes de cada teste (opcional)
}

void tearDown() {
    // Limpeza após cada teste (opcional)
}

void test_blink() {
    TEST_ASSERT_EQUAL(1, 1);
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_blink);
    UNITY_END();
}

void loop() {}
