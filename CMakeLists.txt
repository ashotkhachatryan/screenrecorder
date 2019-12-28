if (WINDOWS)
    # Build for Windows
    cmake_minimum_required(VERSION 3.1.0)

    set(CMAKE_SYSTEM_NAME Windows)
    set(CMAKE_C_COMPILER   /usr/bin/x86_64-w64-mingw32-gcc)
    set(CMAKE_CXX_COMPILER /usr/bin/x86_64-w64-mingw32-g++)

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    link_directories(${LIBDIR})
    include_directories(${INCDIR})

    project(screen_recorder)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)

    if(CMAKE_VERSION VERSION_LESS "3.7.0")
        set(CMAKE_INCLUDE_CURRENT_DIR ON)
    endif()

    add_executable(main
        main.cpp
        ScreenRecorder.cpp
    )

    target_link_libraries(main -static-libgcc -static-libstdc++ -lfftools -lavdevice -lpsapi -lole32 -lstrmiids -luuid -loleaut32 -lshlwapi -lgdi32 -lm -lvfw32 -lavformat -lsecur32 -lws2_32 -lavfilter -lavcodec -lswresample -lswscale -lavutil -luser32 -lbcrypt -lpthread)
elseif(LINUX)
    # Build for Linux
    cmake_minimum_required(VERSION 3.1.0)

    set(CMAKE_SYSTEM_NAME Linux)

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    link_directories(${LIBDIR})
    include_directories(${INCDIR})

    project(screen_recorder)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)

    if(CMAKE_VERSION VERSION_LESS "3.7.0")
        set(CMAKE_INCLUDE_CURRENT_DIR ON)
    endif()

    add_executable(main
        main.cpp
        ScreenRecorder.cpp
    )

    target_link_libraries(main -lfftools -lavdevice -lavformat -lm -lbz2 -lz -lavfilter -lavcodec -lx264 -lswresample -lswscale -lavutil -lpostproc -lpthread -lxcb -lxcb-shm -lxcb -lxcb-shape -lxcb -lxcb-xfixes -lxcb-render -lxcb-shape -lxcb -lasound -lSDL2 -lsndio -lXv -lX11 -lXext -llzma)

elseif(MACOS)
    # Build for MacOS
    cmake_minimum_required(VERSION 3.1.0)

    set(CMAKE_SYSTEM_NAME Darwin)

    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)

    link_directories(${LIBDIR})
    include_directories(${INCDIR})

    project(screen_recorder)

    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_AUTOUIC ON)

    if(CMAKE_VERSION VERSION_LESS "3.7.0")
        set(CMAKE_INCLUDE_CURRENT_DIR ON)
    endif()

    add_executable(main
        main.cpp
        ScreenRecorder.cpp
    )

    target_link_libraries(main -lfftools -lavutil -pthread -lm "-framework VideoToolbox" "-framework CoreFoundation" "-framework CoreMedia" "-framework CoreVideo" "-framework CoreServices" -lavcodec -liconv -llzma -lz "-framework AudioToolbox" -lavfilter "-framework OpenGL" "-framework CoreImage" "-framework AppKit" -lavformat -lbz2 -Wl,-framework,Security -lavdevice "-framework Foundation" "-framework AVFoundation" "-framework CoreGraphics" -L/usr/local/lib -lSDL2 -lswresample -lswscale)
elseif(LINUX)

endif()
