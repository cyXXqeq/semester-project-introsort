# Здесь вы можете создавать свои исполняемые файлы (executables)
# исполянемый файл = контрольный тест

# Пример создания контрольного теста (исполняемого файла) под названием demo_benchmark.
# Исходный код предоставлен в файле demo_benchmark.cpp текущей директории.

#add_library(base_sort_benchmark include/base_sort_benchmak.hpp)
#target_sources(base_sort_benchmark PRIVATE include/base_sort_benchmak.hpp)
#target_include_directories(base_sort_benchmark PRIVATE include)


add_executable(introsort_benchmark introsort_benchmark.cpp)
add_executable(quicksort_benchmark quicksort_benchmark.cpp)

# Примечание: Не забываем подключить (прилинковать) библиотеку ${PROJECT_NAME} с реализацией структуры данных.
#target_link_libraries(base_sort_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(introsort_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
target_link_libraries(quicksort_benchmark PRIVATE project_paths project_warnings ${PROJECT_NAME})
