# Collect all .cpp files in the gsl directory
file(GLOB DOJOS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# For each .cpp file, create a separate executable and link Boost libraries
foreach(DOJO ${DOJOS})
    # Get the filename without extension to use as the executable name (prefixed with gsl_)
    get_filename_component(EXE_NAME ${DOJO} NAME_WE)

    add_executable(gsl_${EXE_NAME} ${DOJO})
    
    target_link_libraries(gsl_${EXE_NAME} PRIVATE Boost::iostreams Boost::filesystem gsl gslcblas m)
endforeach()
