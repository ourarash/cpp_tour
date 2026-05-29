// filesystem_path_info.cpp
// example for "C++17 In Detail"
// by Bartlomiej Filipek
// 2018/2019

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main(int argc, char* argv[]) {
  try {
    const fs::path testPath{argc >= 2 ? argv[1] : fs::current_path()};

    std::cout << "path::preferred_separator: ";
    if constexpr (std::is_same_v<fs::path::value_type, wchar_t>)
      std::wcout << "wchar_t: " << fs::path::preferred_separator << L'\n';
    else
      std::cout << fs::path::preferred_separator << '\n';

    std::cout << "exists() = " << fs::exists(testPath) << '\n';

    if (testPath.has_root_name())
      std::cout << "root_name() = " << testPath.root_name() << '\n';
    else
      std::cout << "no root-name\n";

    if (testPath.has_root_directory())
      std::cout << "root directory() = " << testPath.root_directory() << '\n';
    else
      std::cout << "no root-directory\n";

    if (testPath.has_root_path())
      std::cout << "root_path() = " << testPath.root_path() << '\n';
    else
      std::cout << "no root-path\n";

    if (testPath.has_relative_path())
      std::cout << "relative_path() = " << testPath.relative_path() << '\n';
    else
      std::cout << "no relative-path\n";

    if (testPath.has_parent_path())
      std::cout << "parent_path() = " << testPath.parent_path() << '\n';
    else
      std::cout << "no parent-path\n";

    if (testPath.has_filename())
      std::cout << "filename() = " << testPath.filename() << '\n';
    else
      std::cout << "no filename\n";

    if (testPath.has_stem())
      std::cout << "stem() = " << testPath.stem() << '\n';
    else
      std::cout << "no stem\n";

    if (testPath.has_extension())
      std::cout << "extension() = " << testPath.extension() << '\n';
    else
      std::cout << "no extension\n";

    int i = 0;
    for (const auto& part : testPath)
      std::cout << "path part: " << i++ << " = " << part << '\n';

    auto pathAbsolute = fs::absolute(testPath);
    std::cout << "absolute: " << pathAbsolute.string() << '\n';

    pathAbsolute.make_preferred();
    std::cout << "preferred: " << pathAbsolute.string() << '\n';
  } catch (const fs::filesystem_error& err) {
    std::cerr << "filesystem error! " << err.what() << '\n';
    if (!err.path1().empty())
      std::cerr << "path1: " << err.path1().string() << '\n';
    if (!err.path2().empty())
      std::cerr << "path2: " << err.path2().string() << '\n';
  } catch (const std::exception& ex) {
    std::cerr << "general exception: " << ex.what() << '\n';
  } catch (...) {
    std::cerr << "unknown exception!\n";
  }
}