cmake_minimum_required(VERSION 3.0)

                ##################################################################################DOCTEST
        ################################################################################

        file(READ        ${CMAKE_CURRENT_SOURCE_DIR} / scripts /
             version.txt ver) project(doctest VERSION ${ver})

                option(DOCTEST_WITH_TESTS "Build tests/examples" ON) option(
                        DOCTEST_WITH_MAIN_IN_STATIC_LIB
                        "Build a static lib (cmake target) with a "
                        "main entry point" ON) option(DOCTEST_NO_INSTALL "Skip the "
                                                                         "installation"
                                                                         " proces"
                                                                         "s" OFF)

                        add_library(${PROJECT_NAME} INTERFACE) target_include_directories(
                                ${PROJECT_NAME} INTERFACE $<
                                        BUILD_INTERFACE : ${CMAKE_CURRENT_SOURCE_DIR} / doctest />)

                                ##################################################################################TESTS
        / EXAMPLES /
        HELPERS################################################################################

        if(${DOCTEST_WITH_MAIN_IN_STATIC_LIB}) include(
                scripts / cmake /
                common.cmake) doctest_add_library(${PROJECT_NAME} _with_main STATIC EXCLUDE_FROM_ALL
                                                          doctest /
                                                  parts / doctest_main.cpp) target_link_libraries(${
                PROJECT_NAME} _with_main PUBLIC ${PROJECT_NAME}) endif()

                if(${DOCTEST_WITH_TESTS}) include(scripts / cmake / common.cmake)

                        add_subdirectory(examples / all_features)

                                if(NOT DEFINED ENV{CODE_COVERAGE}) add_subdirectory(
                                        examples /
                                        exe_with_static_libs) add_subdirectory(examples /
                                                                               executable_dll_and_plugin)
                                        add_subdirectory(scripts / playground) endif() endif()

                                                ##################################################################################PACKAGE
        SUPPORT################################################################################

        set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

                set(include_install_dir "include/doctest/") set(config_install_dir
                                                                "lib/cmake/${PROJECT_NAME}")

                        set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake") set(
                                project_config
                                "${"
                                "generated_"
                                "dir}/"
                                "${PROJECT_"
                                "NAME}"
                                "Config."
                                "cmake") set(targets_export_name
                                             "${PROJECT_NAME}Targets") set(namespace "${PROJECT_"
                                                                                     "NAME}::")

                                include(CMakePackageConfigHelpers) write_basic_package_version_file(
                                        "${version_config}" VERSION            ${
                                                PROJECT_VERSION} COMPATIBILITY SameMajorVersion)

                                        configure_file("scripts/cmake/Config.cmake.in"
                                                       "${project_config}" @ONLY)

                                                if(NOT ${DOCTEST_NO_INSTALL}) install(
                                                        TARGETS ${PROJECT_NAME} EXPORT
                                                        "${targets_export_name}" INCLUDES
                                                                DESTINATION
                                                        "${include_install_dir}")

                                                        install(FILES "doctest/"
                                                                      "doctest.h" DESTINATION
                                                                      "${include_install_dir}")

                                                                install(FILES "${project_config}"
                                                                              "${version_"
                                                                              "config"
                                                                              "}" DESTINATION
                                                                              "${config_install_"
                                                                              "dir}")

                                                                        install(EXPORT
                                                                                "${targets_"
                                                                                "export_"
                                                                                "name"
                                                                                "}" NAMESPACE "${"
                                                                                "namespace"
                                                                                "}" DESTINATION
                                                                                "${config_"
                                                                                "install_"
                                                                                "dir}") endif()
