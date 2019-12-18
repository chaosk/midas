.DEFAULT_GOAL := build

BUILD_DIR := $(PWD)/.build
SRC_DIR := $(PWD)/src

QMK_IMAGE := qmkfm/qmk_firmware:latest
LOADER_IMAGE := minodisk/teensy_loader:0.0.1

KEYBOARD := ergodox_ez
KEYMAP := chaosk-midas
MICROCONTROLLER := atmega32u4

define QMK_RUN
mkdir -p $(BUILD_DIR) && docker run --rm -it \
	-w /qmk_firmware \
	-v $(SRC_DIR):/qmk_firmware/keyboards/$(KEYBOARD)/keymaps/$(KEYMAP) \
	-v $(BUILD_DIR):/qmk_firmware/.build \
	-e SKIP_GIT=${SKIP_GIT} \
	-e MAKEFLAGS="${MAKEFLAGS}" \
	$(QMK_IMAGE)
endef

define LOADER_RUN
mkdir -p $(BUILD_DIR) && docker run --rm -it \
	--privileged \
	-v /dev/bus/usb:/dev/bus/usb \
	-v $(BUILD_DIR):/qmk/.build \
	$(LOADER_IMAGE)
endef

build:
	$(QMK_RUN) make "$(KEYBOARD):$(KEYMAP)"

clean:
	rm -rf $(BUILD_DIR)

install:
	$(LOADER_RUN) teensy_loader_cli --mcu=$(MICROCONTROLLER) -vw $(KEYBOARD)_$(KEYMAP).hex
