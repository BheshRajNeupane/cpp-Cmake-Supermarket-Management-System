add_library(
   functions-exe 
   src/functions-exe/shopping.hpp
   src/functions-exe/menu.cpp
   src/functions-exe/add.cpp
   src/functions-exe/administor.cpp
   src/functions-exe/buyer.cpp
   src/functions-exe/edit.cpp
   src/functions-exe/list.cpp
   src/functions-exe/remove.cpp
   src/functions-exe/recepit.cpp

)

target_include_directories(functions-exe PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
