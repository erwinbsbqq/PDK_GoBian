#ifndef PLATFORM_PLATFORM_H
#define PLATFORM_PLATFORM_H

#include <platform/config.h>
//#include <api/libfs2/types.h>

/* include specific parts */
#ifdef _CVI_

 #include <platform/platform_cvi.h>
 #ifdef CONFIG_STANDARD_ANALOG
  #include <platform/analog.h>
 #endif

#elif defined _WIN32

 #ifdef DIB_KERNEL_MODE

  #include <platform/platform_windows_kernel.h>
  #ifdef CONFIG_STANDARD_ANALOG
   #include <platform/analog_windows_kernel.h>
  #endif

 #else

  #include <platform/platform_windows_user.h>
  #ifdef CONFIG_STANDARD_ANALOG
   #include <platform/analog_windows_user.h>
  #endif

 #endif

#elif defined(__sparc__) || defined(__sparc)

 #include <platform/platform_leon.h>

#elif defined __unix__

 #ifndef __KERNEL__
  #include <platform/platform_linux.h>
 #else
  #include <platform/platform_linux_kernel.h>
 #endif

 #ifdef CONFIG_STANDARD_ANALOG
  #include <platform/analog.h>
 #endif

#endif

/* define a INFO_TEXT in your platform.h and get rid of the strings */
#ifndef INFO_TEXT
#define INFO_TEXT(x) x
#endif


#ifdef __cplusplus
extern "C" {
#endif

/* platform-specific firmware binary requst */
struct firmware {
    UINT8 *buffer;
    UINT32 length;
    void * oct_inst;
};
extern int platform_request_firmware(struct firmware *fw, const char *name);
extern void platform_release_firmware(struct firmware *fw);

#ifdef __cplusplus
}
#endif



#endif
