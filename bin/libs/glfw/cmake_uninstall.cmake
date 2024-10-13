
if (NOT EXISTS "C:/Users/elipe/OneDrive/Desktop/Project/bin/libs/glfw/install_manifest.txt")
    message(FATAL_ERROR "Cannot find install manifest: \"C:/Users/elipe/OneDrive/Desktop/Project/bin/libs/glfw/install_manifest.txt\"")
endif()

file(READ "C:/Users/elipe/OneDrive/Desktop/Project/bin/libs/glfw/install_manifest.txt" files)
string(REGEX REPLACE "\n" ";" files "${files}")

foreach (file ${files})
  message(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    exec_program("C:/Users/elipe/Downloads/cmake-3.29.0-rc4-windows-x86_64/cmake-3.29.0-rc4-windows-x86_64/bin/cmake.exe" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif()
  elseif (IS_SYMLINK "$ENV{DESTDIR}${file}")
    EXEC_PROGRAM("C:/Users/elipe/Downloads/cmake-3.29.0-rc4-windows-x86_64/cmake-3.29.0-rc4-windows-x86_64/bin/cmake.exe" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
                 OUTPUT_VARIABLE rm_out
                 RETURN_VALUE rm_retval)
    if (NOT "${rm_retval}" STREQUAL 0)
      message(FATAL_ERROR "Problem when removing symlink \"$ENV{DESTDIR}${file}\"")
    endif()
  else()
    message(STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif()
endforeach()
