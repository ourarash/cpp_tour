#include <string>
class BoundingBox {};

struct Image {
  bool IsLoaded();
  void LoadAsync(std::string fileName, BoundingBox& bounds) {
    // Load image on separate thread (without blocking)
  }
  void Draw() {
    // Draws this image at location
  }

 private:
  BoundingBox mBounds;
};

struct ImageProxy {
  void Load(std::string fileName, BoundingBox& bounds) {
    mImage.LoadAsync(fileName, bounds);
  }
  void Draw() {
    if (mImage.IsLoaded()) {
      mImage.Draw();
    } else {
      // Draw blank image with appropriate bounding box
    }
  }

 private:
  Image mImage;
  BoundingBox mBounds;
};
