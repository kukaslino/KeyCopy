#include <SPI.h>
#include <PN532_SPI.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <emulatetag.h>
#include <NdefMessage.h>

// Declarações de funções
void Ler_Cartao();
String ReceberUID();
void Emulate_Card(String uidToEmulate);

// Variáveis globais e objetos
PN532_SPI pn532_spi(SPI, 10);
NfcAdapter nfc = NfcAdapter(pn532_spi);
EmulateTag nfcEmulate(pn532_spi);
String emulatedUID = ""; // Variável para armazenar o UID para emulação

void setup() {
  Serial.begin(9600); // Comunicação serial para receber UID
  nfc.begin();
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    if (command == 'R') { // Comando para ler o cartão
      Ler_Cartao();
    } else if (command == 'E') { // Comando para iniciar a emulação
      emulatedUID = ReceberUID();
      Emulate_Card(emulatedUID);
    }

    delay(5000);
  }
}

// Definições das funções

void Ler_Cartao() {
  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    String uid = tag.getUidString();
    Serial.println(uid);
  }
}

String ReceberUID() {
  String uid = ""; // Limpa o UID anterior

  // Espera o UID via serial
  while (Serial.available() == 0) {
    delay(10); // Pequeno delay para evitar espera ativa
  }

  uid = Serial.readStringUntil('\n'); // Lê o UID como string até o caractere de nova linha
  Serial.print("Emulação recebido: ");
  Serial.println(uid);

  return uid;
}

void Emulate_Card(String uidToEmulate) {
  // Converte o UID de String para uint8_t array
  uint8_t uidBytes[4];
  for (int i = 0; i < 4; i++) {
    String byteString = uidToEmulate.substring(i * 3, i * 3 + 2);
    uidBytes[i] = (uint8_t)strtol(byteString.c_str(), nullptr, 16);
  }

  // Verificação: Imprime o conteúdo de uidBytes para confirmação
  Serial.print("Emulação (Bytes): ");
  for (int i = 0; i < 4; i++) {
    Serial.print("0x");
    if (uidBytes[i] < 0x10) Serial.print("0");
    Serial.print(uidBytes[i], HEX);
    Serial.print(" ");
  }
  Serial.println();

  // Configura o UID para emulação
  nfcEmulate.setUid(uidBytes); // Configura o UID para emulação
  nfcEmulate.init();
  nfcEmulate.emulate();

  if (nfcEmulate.writeOccured()) {
    Serial.println("\nWrite occurred!");
    uint8_t* tag_buf;
    uint16_t length;

    nfcEmulate.getContent(&tag_buf, &length);
    NdefMessage msg = NdefMessage(tag_buf, length);
    msg.print();
  }
}
