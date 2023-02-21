#include <iostream>

enum can_ide {
	/** Standard (11-bit) CAN identifier. */
	CAN_STANDARD_IDENTIFIER,
	/** Extended (29-bit) CAN identifier. */
	CAN_EXTENDED_IDENTIFIER
};

enum can_rtr {
	/** Data frame. */
	CAN_DATAFRAME,
	/** Remote Transmission Request (RTR) frame. */
	CAN_REMOTEREQUEST
};

struct can_frame {
	/** Standard (11-bit) or extended (29-bit) CAN identifier. */
	uint32_t id : 29;
	/** Frame is in the CAN-FD frame format if set to true. */
	uint32_t fd : 1;
	/** Remote Transmission Request (RTR) flag. Use @a can_rtr enum for assignment. */
	uint32_t rtr : 1;
	/** CAN identifier type (standard or extended). Use @a can_ide enum for assignment. */
	uint32_t id_type : 1;
	/** Data Length Code (DLC) indicating data length in bytes. */
	uint8_t dlc;
	/** Baud Rate Switch (BRS). Only valid for CAN-FD. */
	uint8_t brs : 1;
	/** @cond INTERNAL_HIDDEN */
	uint8_t res : 7; /* reserved/padding. */
	/** @endcond */
#if defined(CONFIG_CAN_RX_TIMESTAMP) || defined(__DOXYGEN__)
	/** Captured value of the free-running timer in the CAN controller when
	 * this frame was received. The timer is incremented every bit time and
	 * captured at the start of frame bit (SOF).
	 *
	 * @note @kconfig{CONFIG_CAN_RX_TIMESTAMP} must be selected for this
	 * field to be available.
	 */
	uint16_t timestamp;
#else
	/** @cond INTERNAL_HIDDEN */
	uint8_t res0;  /* reserved/padding. */
	uint8_t res1;  /* reserved/padding. */
	/** @endcond */
#endif
	/** The frame payload data. */
	union {
		uint32_t data_32[2];
		uint8_t data[8];
	};
};

/* CAN frame to be sent */
struct can_frame frame = { 0,							/*id*/
							0,							/*FD*/
							CAN_DATAFRAME,				/*RTR*/
							CAN_EXTENDED_IDENTIFIER,	/*id_type*/
							0,							/*dcl*/
							0,							/*brs*/
							7,							/*res*/
							0,							/*res0*/
							0,							/*res1*/
							{0x1234, 0x1234}
};

/* Constants that aren't configurable in menuconfig */
#define WEB_SERVER "example.com"
#define WEB_PORT "80"
#define WEB_PATH "/"

static const char* REQUEST = "GET " WEB_PATH " HTTP/1.0\r\n" "Host: "WEB_SERVER":"WEB_PORT"\r\n" "User-Agent: esp-idf/1.0 esp32\r\n" "\r\n";

int main() {
	
	std::cout << frame.data_32[0];

}