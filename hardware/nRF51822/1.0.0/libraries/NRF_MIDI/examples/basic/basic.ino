// This is a direct port of mbed library with some minor changes...
// https://developer.mbed.org/users/kshoji/code/BLE_MIDI/file/2b71bfbaa458/

#include <nrf_midi.h>

BLE     ble;

// The default device name is 'MIDI'.
// If the another name is preferred, use this constructor.
// The maximum length of device name is 4 bytes.
// BLEMIDI midi(&device);
BLEMIDI midi(&device, "MYDEV");

// Shows how to use a timer ticker for firing events
Ticker ticker;

//Example onNoteOn Callback
void onNoteOn(uint8_t channel, uint8_t note, uint8_t velocity) {
    // do something with Note On event
}

void send_note_handle(void)
{
    bleMidi.sendNoteOn(0, 63, 127);
}

void setup() {
    // put your setup code here, to run once:
    
    midi.attachNoteOn(onNoteOn);
    
    //Ticker Loops
    ticker1.attach_us(send_note_handle, 100000);
}


void loop() {
    // put your run loop code here
    device.waitForEvent();
}