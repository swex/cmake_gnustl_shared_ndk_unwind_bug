# cmake_gnustl_shared_ndk_unwind_bug
#bug example
#howto build:
```bash
export NDK_PATH="your NDK path"
rm -Rf build && mkdir build &&cd build && cmake ../  -DANDROID_TOOLCHAIN=gcc -DBUILD_SHARED_LIBS=ON  -DCMAKE_TOOLCHAIN_FILE=$NDK_PATH/build/cmake/android.toolchain.cmake -DCMAKE_BUILD_TYPE=Debug  -DANDROID_ABI=$ARCH -DANDROID_PLATFORM=android-16 -DANDROID_STL=gnustl_shared -DANDROID_CPP_FEATURES="rtti exceptions" -DCMAKE_SYSTEM_VERSION=27 && make VERBOSE=1 && cd ..
#after build check readelf output
$NDK_PATH/toolchains/arm-linux-androideabi-4.9/prebuilt/linux-x86_64/arm-linux-androideabi/bin/readelf -sW build/lib1/*.so |grep -i UND|grep -i unw
```
I'm facing:

```
    32: 00000000     0 FUNC    GLOBAL DEFAULT  UND __aeabi_unwind_cpp_pr0
    47: 00000000     0 FUNC    GLOBAL DEFAULT  UND __aeabi_unwind_cpp_pr1
    65: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_Resume
    83: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_Complete
    84: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_DeleteException
   115: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetDataRelBase
   116: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetTextRelBase
   117: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetRegionStart
   118: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_VRS_Set
   119: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetLanguageSpecificData
   120: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_VRS_Get
   121: 00000000     0 FUNC    GLOBAL DEFAULT  UND __gnu_unwind_frame
   128: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_RaiseException
   129: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_Resume_or_Rethrow
   570: 00000000     0 FUNC    GLOBAL DEFAULT  UND __aeabi_unwind_cpp_pr0
   585: 00000000     0 FUNC    GLOBAL DEFAULT  UND __aeabi_unwind_cpp_pr1
   603: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_Resume
   621: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_Complete
   622: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_DeleteException
   653: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetDataRelBase
   654: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetTextRelBase
   655: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetRegionStart
   656: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_VRS_Set
   657: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_GetLanguageSpecificData
   658: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_VRS_Get
   659: 00000000     0 FUNC    GLOBAL DEFAULT  UND __gnu_unwind_frame
   666: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_RaiseException
   667: 00000000     0 FUNC    GLOBAL DEFAULT  UND _Unwind_Resume_or_Rethrow
```
