add_executable (eoss-lang "main.cpp" "tokenizer.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET eoss-lang PROPERTY CXX_STANDARD 20)
endif()
