cmake_minimum_required(VERSION 3.5)

project(Client_1 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Client_1
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        admindialog.h
        admindialog.cpp
        admindialog.ui
        view.h
        view.cpp
        sockethandler.h
        sockethandler.cpp
        control.h
        control.cpp
        client.h
        client.cpp
        createusr.h
        createusr.cpp
        createusr.ui
        accountnumber.h accountnumber.cpp accountnumber.ui
        accountbalance.h accountbalance.cpp accountbalance.ui
        deleteuser.h deleteuser.cpp deleteuser.ui
        transhistory.h transhistory.cpp transhistory.ui
        updateuser.h updateuser.cpp updateuser.ui
        databaseview.h databaseview.cpp databaseview.ui
        userdialog.h userdialog.cpp userdialog.ui
        maketransaction.h maketransaction.cpp maketransaction.ui
        transferamount.h transferamount.cpp transferamount.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Client_1 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(Client_1 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(Client_1
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Client_1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Client_1)
endif()
set_target_properties(Client_1 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS Client_1
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Client_1)
endif()
