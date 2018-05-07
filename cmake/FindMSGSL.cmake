include(FindPackageHandleStandardArgs)

find_path(MSGSL_INCLUDE_DIRS gsl/gsl)

find_package_handle_standard_args(MSGSL
    REQUIRED_VARS MSGSL_INCLUDE_DIRS)

if(TARGET MSGSL::gsl)
    return()
endif()

add_library(MSGSL::gsl INTERFACE IMPORTED)
set_target_properties(MSGSL::gsl PROPERTIES
	INTERFACE_INCLUDE_DIRECTORIES ${MSGSL_INCLUDE_DIRS}
	INTERFACE_COMPILE_FEATURES cxx_std_11)
