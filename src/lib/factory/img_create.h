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
    if (type == "bmp")
      return std::make_shared<BitmapImage>();
    else if (type == "png")
      return std::make_shared<PngImage>();
    else if (type == "jpg")
      return std::make_shared<JpgImage>();
    return nullptr;
  }
};