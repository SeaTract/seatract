#/seatract/meta.mk
ROOT_DIR := $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))
GET_SELF_DIR = $(patsubst %/,%,$(dir $(abspath $(lastword $(MAKEFILE_LIST)))))

# Global seatract include path
SEATRACT_INC_DIR := $(ROOT_DIR)/include
