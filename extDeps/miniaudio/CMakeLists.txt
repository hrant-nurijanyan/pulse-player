add_library(miniaudio STATIC miniaudio_impl.cpp)

target_include_directories(miniaudio PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Platform libraries miniaudio depends on
if(UNIX AND NOT APPLE AND NOT ANDROID)
  target_link_libraries(miniaudio PUBLIC pthread m dl)
elseif(APPLE)
  target_link_libraries(miniaudio PUBLIC
    "-framework CoreAudio"
    "-framework AudioToolbox"
    "-framework CoreFoundation"
  )
elseif(ANDROID)
  target_link_libraries(miniaudio PUBLIC aaudio OpenSLES)
endif()
