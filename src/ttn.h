#include <hal/hal.h>
#include <SPI.h>
#include <vector>
#include <Preferences.h>
#include "configuration.h"
#include "credentials.h"

// -----------------------------------------------------------------------------
// Globals
// -----------------------------------------------------------------------------

// LMIC GPIO configuration
// const lmic_pinmap lmic_pins;

// Message counter, stored in RTC memory, survives deep sleep.
extern RTC_DATA_ATTR uint32_t count;

#ifdef USE_ABP
    // These callbacks are only used in over-the-air activation, so they are
    // left empty here (we cannot leave them out completely unless
    // DISABLE_JOIN is set in config.h, otherwise the linker will complain).
    extern void os_getArtEui (u1_t* buf);
    extern void os_getDevEui (u1_t* buf);
    extern void os_getDevKey (u1_t* buf);
#endif

#ifdef USE_OTAA
    extern void os_getArtEui (u1_t* buf);
    extern void os_getDevEui (u1_t* buf);
    extern void os_getDevKey (u1_t* buf);
#endif

// extern std::vector<void(*)(uint8_t message);

// -----------------------------------------------------------------------------
// Private methods
// -----------------------------------------------------------------------------

// void _ttn_callback(uint8_t message);

// void forceTxSingleChannelDr();

// DevEUI generator using devices's MAC address - from https://github.com/cyberman54/ESP32-Paxcounter/blob/master/src/lorawan.cpp
// void gen_lora_deveui(uint8_t *pdeveui);

// void printHex2(unsigned v);

// LMIC library will call this method when an event is fired
// void onEvent(ev_t event);

// -----------------------------------------------------------------------------
// Public methods
// -----------------------------------------------------------------------------

void ttn_register(void (*callback)(uint8_t message));

size_t ttn_response_len();

void ttn_response(uint8_t * buffer, size_t len);

// If the value for LORA packet counts is unknown, restore from flash
void initCount();

bool ttn_setup();

void ttn_join();

void ttn_sf(unsigned char sf);

void ttn_adr(bool enabled);

uint32_t ttn_get_count();

void ttn_set_cnt();

/// Blow away our prefs (i.e. to rejoin from scratch)
void ttn_erase_prefs();

void ttn_send(uint8_t * data, uint8_t data_size, uint8_t port, bool confirmed);

void ttnLoop();
