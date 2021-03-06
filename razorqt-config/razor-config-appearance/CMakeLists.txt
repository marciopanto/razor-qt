project(razor-config-appearance)

include_directories (
    ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}
    ${QT_QTCORE_INCLUDE_DIR} ${QT_QTGUI_INCLUDE_DIR}
    ${QT_QTDBUS_INCLUDE_DIR} ${QT_QTXML_INCLUDE_DIR}
    ${CMAKE_SOURCE_DIR}/libraries/
    )

set(H_FILES
    iconthemeinfo.h
   )

set(MOC_FILES
    mainwindow.h
)

set(CPP_FILES
    mainwindow.cpp
    main.cpp
    iconthemeinfo.cpp
   )

set(UI_FILES
    mainwindow.ui
)

set(QRC_FILES

)

set(LIBRARIES
    razorqt
    qtxdg
)


# Translations **********************************
include(RazorTranslate)
razor_translate_to(QM_FILES ${CMAKE_INSTALL_PREFIX}/share/razor/razor-config)
#************************************************

qt4_wrap_cpp(MOC_SOURCES ${MOC_FILES})
qt4_wrap_ui(UI_HEADERS ${UI_FILES})
qt4_add_resources(QRC_SOURCES ${QRC_FILES})


add_executable(${PROJECT_NAME} ${CPP_FILES} ${UI_FILES} ${RESOURCES} ${QRC_SOURCES} ${QM_FILES} ${MOC_SOURCES})
add_dependencies(${PROJECT_NAME} razorqt qtxdg)
target_link_libraries(${PROJECT_NAME}  ${LIBRARIES} ${QT_LIBRARIES})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
install(FILES ${PROJECT_NAME}.desktop DESTINATION ${CMAKE_INSTALL_PREFIX}/share/applications)

razor_config_register(${PROJECT_NAME}.desktop)


