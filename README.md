# Wireless Sensor Project

Dieses Projekt dokumentiert die Entwicklung eines drahtlosen Sensorsystems als Schul-/Studienprojekt.  
Es umfasst Hardware-Datenblätter, Konfigurationsdokumente, Arduino/ESP32-Code sowie begleitende Projektunterlagen.

## 📦 Projektinhalt

Das Repository enthält folgende Komponenten:

### 🔧 Hardware-Datenblätter
Im Ordner **/datasheets** befinden sich alle wichtigen Hersteller-Datenblätter:
- ESP32-WROOM-32E / 32UE
- ADS1115 Analog-Digital-Wandler
- TLC271 Operationsverstärker
- Pololu 5V Step-Up Voltage Regulator U1V10F5
- NI-Module 9191 & 9218
- Piezo Film Lab Amplifier
- HC-05 Bluetooth-Modul
- Arduino Nano
- Weitere unterstützende Dokumente

### 💻 Arduino / ESP32 Code
Im Ordner **/code**:
- `Arduino_program_for_Esp32.ino`  
  → Hauptprogramm zur Ansteuerung des drahtlosen Sensorsystems (Auslesen, Senden, Verarbeitung).

### 📚 Projektdokumente
- `Wireless_module.pdf` – Modulbeschreibung  
- `ESP32Configuration.pdf` – Konfigurationseinstellungen für das Board  
- `Stage_Flandez.mp4` – Projektdemonstration / Präsentationsvideo

## ▶️ Ausführen des Codes

### Voraussetzungen
- Arduino IDE (1.8.x oder 2.x)
- ESP32 Board Package  
  → Installierbar über Board Manager  
- Benötigte Bibliotheken (falls im Code verwendet):
  - `Wire.h`
  - ADS1115 Library (z. B. Adafruit ADS1X15)
  - Weitere abhängig vom Projekt

### Schritte
1. Arduino IDE öffnen  
2. Datei `Arduino_program_for_Esp32.ino` laden  
3. Board auswählen: **ESP32 Dev Module**  
4. Port wählen  
5. Sketch hochladen

