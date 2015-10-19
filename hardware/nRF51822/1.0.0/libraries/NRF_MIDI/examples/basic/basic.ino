// This is a direct port of mbed library with some minor changes...
// https://developer.mbed.org/users/kshoji/code/BLE_MIDI/file/2b71bfbaa458/

#include <nrf_midi.h>

#define DEBUG 1

BLE     ble;

// The default device name is 'MIDI'.
// If the another name is preferred, use this constructor.
// The maximum length of device name is 4 bytes.
// BLEMIDI midi(&ble);
BLEMIDI midi(&ble, "MYDE");

// Shows how to use a timer ticker for firing events
Ticker ticker;

void onDeviceConnected() {
  digitalWrite(8, HIGH);
}

void onDeviceDisconnected() {
  digitalWrite(8, LOW);
}


//Example onNoteOn Callback
void onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    // do something with Note On event
}

void send_note_handle(void)
{
    midi.sendNoteOn(0, 63, 127);
}

void setup() {
    
    //TODO: Change pin map to real P0_... for pin mode ajustments to work
    pinMode(8, OUTPUT);
    //digitalWrite(8, HIGH);

    //Setup some LED feedback
    midi.attachDeviceConnected(onDeviceConnected);
    midi.attachDeviceDisconnected(onDeviceDisconnected);
  
    // put your setup code here, to run once:
    midi.attachNoteOn(onNoteOn);
    
    //Ticker Loops
    ticker.attach_us(send_note_handle, 100000);
}


void loop() {
    // put your run loop code here
    ble.waitForEvent();
}
