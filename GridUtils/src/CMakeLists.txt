
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(EXE_NAME TestGridUtils)

# 系统第三方库
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 添加自己的子项目
add_subdirectory(3rdParty)

# 定义一个可执行文件（主程序）
add_executable(${EXE_NAME} main.cpp)

target_link_libraries(${EXE_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)


# 链接子项目库到主项目可执行文件
# target_link_libraries(TestGridUtils PRIVATE MyLibrary)
