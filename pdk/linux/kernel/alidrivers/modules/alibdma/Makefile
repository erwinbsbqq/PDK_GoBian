

obj-$(CONFIG_ALI_BDMA) += alibdma.o

alibdma-y := ali_hwdma.o ali_hwdma_util.o

USING_CMDQ ?= 1
USING_GENTABLE ?= 1

DEFINES += -DHWDMA_CMDQ_MODE=$(USING_CMDQ)
DEFINES += -DHWDMA_GENTABLE=$(USING_GENTABLE)

EXTRA_CFLAGS = $(DEFINES)



