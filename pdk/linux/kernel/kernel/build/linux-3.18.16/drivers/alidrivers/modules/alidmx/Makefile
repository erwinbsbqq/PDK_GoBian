#
# Makefile for the kernel DVB device drivers.
#

obj-$(CONFIG_DVB_ALI_M36_DMX) += alidmx.o

#alidmx-y := dmx_see_interface.o\
#            dmx_stack_ts_serv.o dmx_stack_ts2pes_serv.o dmx_stack_ts2sec_serv.o \
#			dmx_stack_pcr_serv.o dmx_stack_data_buf.o dmx_linux_interface.o dmx_linux_interface_legacy.o dmx_statistics.o \
#			dmx_stack_pid_filter.o dmx_stack_data_engine.o dmx_hw_interface.o dmx_hw_m37.o

alidmx-y := dmx_data_buf.o \
			dmx_pid_flt.o dmx_data_engine.o dmx_hw_interface.o dmx_hw_from_m37.o dmx_hw_from_user.o dmx_hw_from_see.o\
			dmx_ts_flt.o dmx_sec_flt.o dmx_pes_flt.o dmx_linux_interface.o dmx_see_interface.o dmx_init.o \
			dmx_stream.o dmx_mutex.o dmx_pcr_flt.o dmx_linux_interface_legacy.o dmx_channel_legacy.o \
		    dmx_ts_in_ram_stream.o dmx_instream_ram_legacy.o dmx_dbg.o dmx_subt_if.o



EXTRA_CFLAGS += -I./ -Idrivers/media/dvb/dvb-core/ -Idrivers/media/dvb/frontends/

