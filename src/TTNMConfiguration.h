#ifdef USE_TTN_MAPPER
#define EV_QUEUED       100
#define EV_PENDING      101
#define EV_ACK          102
#define EV_RESPONSE     103

// #define SEND_INTERVAL           (20 * 1000)     // Sleep for these many millis
// #define MESSAGE_TO_SLEEP_DELAY  5000            // Time after message before going to sleep
// #define LOGO_DELAY              5000            // Time to show logo on first boot

// #define LORAWAN_PORT            10              // Port the messages will be sent to
// #define LORAWAN_CONFIRMED_EVERY 0               // Send confirmed message every these many messages (0 means never)
#define LORAWAN_SF              DR_SF7          // Spreading factor (recommended DR_SF7 for ttn network map purposes, DR_SF10 works for slow moving trackers)
#define LORAWAN_ADR             0               // Enable ADR
// #define REQUIRE_RADIO           true            // If true, we will fail to start if the radio is not found

#endif