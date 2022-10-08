# Créer un executable à partir de fichiers sources
add_executable(testUnivers testUnivers.cxx)


#linking test to its library
target_link_libraries(testUnivers Particules)
