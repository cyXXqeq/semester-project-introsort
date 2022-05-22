#include <fstream>      // ifstream, ofstream
#include <iostream>     // cout
#include <sstream>      // stringstream
#include <string>       // string, getline
#include <string_view>  // string_view
#include <random>       // mt19937_64, random_device
#include <chrono>       // system_clock

using namespace std;

// абсолютный путь до набора данных
static constexpr auto kDatasetPath = string_view{PROJECT_DATASET_DIR};

int main(int argc, char** argv) {

  // Tip 1: можете передать путь до входного/выходного файла в качестве аргумента
  for (int index = 0; index < argc; index++) {
    cout << "Arg: " << argv[index] << '\n';
  }

  const auto path = string(kDatasetPath);  // конвертация string_view в string
  cout << "Dataset path: " << path << endl;


  // Пример: генерация набора данных bad
  for (int papka = 1; papka <= 5; papka++) {
    string string_papka;
    if (papka != 10) {
      string_papka = "0" + to_string(papka);
    } else {
      string_papka = to_string(papka);
    }
    for (int size = 100; size < 1000001; size = size * 10) {
      string string_size = to_string(size);
      auto output_stream =
          ofstream(path + "/" + "bad" + "/" + string_papka + "/" + string_size + ".csv", ios::ios_base::app);

      const auto seed = chrono::system_clock::now().time_since_epoch().count();
      auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
      auto dist = uniform_int_distribution(-100000, 100000);  // равновероятное распределение генерируемых чисел

      if (output_stream) {
        for (int counter = 0; counter < size - 1; counter++) {
          output_stream << dist(engine) << '\n';
        }
        output_stream << dist(engine) << '\n';
      }
    }
    for (int size = 500; size < 5000001; size = size * 10) {
      string string_size = to_string(size);
      auto output_stream =
          ofstream(path + "/" + "bad" + "/" + string_papka + "/" + string_size + ".csv", ios::ios_base::app);

      const auto seed = chrono::system_clock::now().time_since_epoch().count();
      auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
      auto dist = uniform_int_distribution(-100000, 100000);  // равновероятное распределение генерируемых чисел

      if (output_stream) {
        for (int counter = 0; counter < size - 1; counter++) {
          output_stream << dist(engine) << '\n';
        }
        output_stream << dist(engine) << '\n';
      }
    }
  }
  // Пример: генерация набора данных good
  for (int papka = 1; papka <= 5; papka++) {
    string string_papka;
    cout<<1;
    if (papka != 10) {
      string_papka = "0" + to_string(papka);
    } else {
      string_papka = to_string(papka);
    }
    for (int size = 100; size < 1000001; size = size * 10) {
      string string_size = to_string(size);
      auto output_stream =
          ofstream(path + "/" + "good" + "/" + string_papka + "/" + string_size + ".csv", ios::ios_base::app);

      const auto seed = chrono::system_clock::now().time_since_epoch().count();
      auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
      auto dist = uniform_int_distribution(-100000, 100000);  // равновероятное распределение генерируемых чисел
      auto num = dist(engine);

      if (output_stream) {
        for (int counter = num; counter <= num + size - 1; counter++) {
          output_stream << counter << '\n';
        }
      }
      output_stream.close();
    }
    for (int size = 500; size < 500001; size = size * 10) {
      string string_size = to_string(size);
      auto output_stream =
          ofstream(path + "/" + "good" + "/" + string_papka + "/" + string_size + ".csv", ios::ios_base::app);

      const auto seed = chrono::system_clock::now().time_since_epoch().count();
      auto engine = mt19937(seed);  // без seed`а генератор будет выдавать одни и те же значения
      auto dist = uniform_int_distribution(-100000, 100000);  // равновероятное распределение генерируемых чисел
      auto num = dist(engine);

      if (output_stream) {
        for (int counter = num; counter <= num + size - 1; counter++) {
          output_stream << counter << '\n';
        }
      }
      output_stream.close();
    }
  }
  return 0;
}