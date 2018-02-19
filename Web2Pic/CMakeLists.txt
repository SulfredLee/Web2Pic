# Handle QT libraries
find_package(Qt5 REQUIRED
  Core
  Gui
  WebEngineWidgets
  Widgets)
message(STATUS "BackEnd - QT library status:")
message(STATUS "BackEnd -     version: ${Qt5Widgets_VERSION}")
message(STATUS "BackEnd -     libraries: ${Qt5Widgets_LIBRARIES} ${Qt5WebEngineWidgets_LIBRARIES} ${Qt5Core_LIBRARIES} ${Qt5Core_QTMAIN_LIBRARIES} ${Qt5Gui_LIBRARIES}")
message(STATUS "BackEnd -     include path: ${QT_INCLUDE_DIR}")

file(GLOB Project_src
  "./*.cpp"
  "./*.h")

include_directories(
  .
  ./FrontEnd
  ${QT_INCLUDE_DIR})

add_executable(Web2Pic ${Project_src})
add_dependencies(Web2Pic FrontEnd)

target_link_libraries(Web2Pic
  FrontEnd
  ${Qt5WebEngineWidgets_LIBRARIES}
  ${Qt5Core_LIBRARIES}
  ${Qt5Core_QTMAIN_LIBRARIES}
  ${Qt5Gui_LIBRARIES}
  ${Qt5Widgets_LIBRARIES})

# Creates a folder "executables" and adds target
# project (*.vcproj) under it
set_property(TARGET Web2Pic PROPERTY FOLDER "executables")

# Adds logic to INSTALL.vcproj to copy *.exe to destination directory
install (TARGETS Web2Pic
  RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
  LIBRARY DESTINATION ${PROJECT_BINARY_DIR}/bin
  ARCHIVE DESTINATION ${PROJECT_BINARY_DIR}/bin)
