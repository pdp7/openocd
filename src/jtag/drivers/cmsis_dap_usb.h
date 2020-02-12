#include <jtag/interface.h>
#include <libusb.h>
#include <hidapi.h>

struct cmsis_dap {
	struct libusb_context *usb_ctx;
	struct libusb_device_handle *bulk_handle;
	hid_device *hid_handle;
	bool is_hid;
	uint16_t packet_size;
	int packet_count;
	uint8_t *packet_buffer;
	uint8_t caps;
	uint8_t mode;
};

extern struct cmsis_dap *cmsis_dap_handle;
extern const struct command_registration cmsis_dap_command_handlers[];
extern const struct swd_driver cmsis_dap_swd_driver;
extern struct jtag_interface cmsis_dap_interface;

int cmsis_dap_usb_write(struct cmsis_dap *dap, int txlen);
int cmsis_dap_usb_read(struct cmsis_dap *dap);
