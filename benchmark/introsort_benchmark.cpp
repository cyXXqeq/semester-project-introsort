#include <fstream>      // ifstream
#include <iostream>     // cout
#include <string>       // string, stoi
#include <string_view>  // string_view
#include <chrono>       // high_resolution_clock, duration_cast, nanoseconds
#include <sstream>      // stringstream

// подключаем вашу структуру данных
#include "introsort.hpp"

#include "vector"
#include "sorting_strategy.hpp"  // SortingStrategy

using namespace std;
using namespace itis;

// абсолютный путь до набора данных и папки проекта
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};
const auto path = string(kDatasetPath);

void base_sort_bench(itis::SortingStrategy& sortingStrategy, const string& filepath, int file_length) {
  vector<int> array = {};
  ifstream fin(filepath);
  int value;
  // заполнение буфера
  for (int i = 0; i < file_length; i++) {
    fin >> value;
    array.push_back(value);
  }
  const auto time_point_before = chrono::steady_clock::now();
  sortingStrategy.Sort(array);
  const auto time_point_after = chrono::steady_clock::now();
  const auto time_diff = time_point_after - time_point_before;
  const auto time_elapsed_ns = chrono::duration_cast<chrono::nanoseconds>(time_diff).count();
  cout << time_elapsed_ns << '\n';
  fin.close();
}

void base_sort_fixed_size_bench(itis::SortingStrategy& sortingStrategy, int data_size, const string& data_type) {
  const string data_folder = path + "/" + data_type;
  string data_path;
  string filename = "/" + to_string(data_size) + ".csv";
  for (int num = 1; num <= 5; num++) {
    data_path = data_folder + "/0" + to_string(num) + filename;
    base_sort_bench(sortingStrategy, data_path, data_size);
  }
}

void base_sort_full_bench(itis::SortingStrategy& sortingStrategy, const string& data_type) {
  const string data_folder = path + "/" + data_type;
  string data_path;
  int fifth = 2;
  for (int data_size = 100; data_size <= 1000000; data_size *= fifth) {
    fifth = fifth == 2 ? 5 : 2;
    cout << "--" + to_string(data_size) + "--" << endl;
    string filename = "/" + to_string(data_size) + ".csv";
    for (int num = 1; num <= 5; num++) {
      data_path = data_folder + "/0" + to_string(num) + filename;
      base_sort_bench(sortingStrategy, data_path, data_size);
    }
  }
}

int main() {
  IntroSort introSort;
  cout << "----Good data----" << endl;
  base_sort_fixed_size_bench(introSort,5000, "good");
  cout << "----Bad data----" << endl;
  base_sort_full_bench(introSort,"bad");
  return 0;
}