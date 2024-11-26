#ifdef UNIT_TEST

#include <unity.h>
#include <unity_config.h>
#include <Arduino.h>

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
    delay(5000);
    UNITY_BEGIN();
    RUN_TEST(test_blink);
    UNITY_END();
}

void loop() {}

#endif