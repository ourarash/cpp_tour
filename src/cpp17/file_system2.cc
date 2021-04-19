// filesystem_list_files.cpp
// example for "C++17 In Detail"
// by Bartlomiej Filipek
// 2018/2019

#include <chrono>
#include <filesystem>
#include <iomanip>  // for std::setw
#include <iostream>

namespace fs = std::filesystem;

void DisplayDirectoryTree(const fs::path& pathToScan, int level = 0) {
  for (const auto& entry : fs::directory_iterator(pathToScan)) {
    const auto filenameStr = entry.path().filename().string();
    if (entry.is_directory()) {
      std::cout << std::setw(level * 3) << "" << filenameStr << '\n';
      DisplayDirectoryTree(entry, level + 1);
    } else if (entry.is_regular_file()) {
      std::cout << std::setw(level * 3) << "" << filenameStr << ", size "
                << fs::file_size(entry) << " bytes\n";
    } else
      std::cout << std::setw(level * 3) << ""
                << " [?]" << filenameStr << '\n';
  }
}

int main(int argc, char* argv[]) {
  try {
    const fs::path pathToShow{argc >= 2 ? argv[1] : fs::current_path()};

    std::cout << "listing files in the directory: "
              << fs::absolute(pathToShow).string() << '\n';

    DisplayDirectoryTree(pathToShow);
  } catch (const fs::filesystem_error& err) {
    std::cerr << "filesystem error! " << err.what() << '\n';
    if (!err.path1().empty())
      std::cerr << "path1: " << err.path1().string() << '\n';
    if (!err.path2().empty())
      std::cerr << "path2: " << err.path2().string() << '\n';
  } catch (const std::exception& ex) {
    std::cerr << "general exception: " << ex.what() << '\n';
  }
}