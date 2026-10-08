USE_RASPIKE_ART=1

mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=\
Guitar.o\

APPL_LIBS += -lm

APPL_DIRS += $(mkfile_path)Guitar

INCLUDES += \
	-I$(mkfile_path)Guitar\
