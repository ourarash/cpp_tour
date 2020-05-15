#include <map>
#include <memory>
#include <string>

class Image {};
class BitmapImage : public Image {};
class PngImage : public Image {};
class JpgImage : public Image {};

struct IImageFactory {
  virtual std::shared_ptr<Image> Create(std::string_view type) = 0;
};

struct ImageFactory : public IImageFactory {
  virtual std::shared_ptr<Image> Create(std::string_view type) override {
    static std::map<std::string, std::function<std::shared_ptr<Image>()>>
        mapping{{"bmp", []() { return std::make_shared<BitmapImage>(); }},
                {"png", []() { return std::make_shared<PngImage>(); }},
                {"jpg", []() { return std::make_shared<JpgImage>(); }}};
    auto it = mapping.find(type.data());
    if (it != mapping.end()) return it->second();
    return nullptr;
  }
};