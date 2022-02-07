#include "Image.h"
#include "cs225/PNG.h"
#include <iostream>
#include "stickerSheet.h"
using namespace cs225;
int main() {
  Image alma;     alma.readFromFile("tests/alma.png");
  Image i;        i.readFromFile("tests/i.png");


  StickerSheet sheet(alma, 5);
  // sheet.addSticker(i, 800, 200);
  // sheet.addSticker(i, 50, 500);

  // sheet.changeMaxStickers(7);
  // sheet.removeSticker(1);
  // sheet.changeMaxStickers(4);
  // sheet.removeSticker(0);
  // sheet.addSticker(i, 20, 500);
  // sheet.changeMaxStickers(1);
  // sheet.removeSticker(0);
  // sheet.changeMaxStickers(2);
  // sheet.addSticker(i, 800, 200);
  // sheet.addSticker(i, 20, 500);

  sheet.addSticker(i, 20, 200);
  sheet.addSticker(i, 40, 200);
  sheet.addSticker(i, 60, 200);
  sheet.changeMaxStickers(1);


  // REQUIRE( sheet.render() == expected );





  // Image alma; alma.readFromFile("tests/alma.png");
  // Image i;    i.readFromFile("tests/i.png");

  // StickerSheet sheet(alma, 5);
  // sheet.addSticker(i, 20, 200);
  Image out = sheet.render();
  out.writeToFile("shubh.png");

  // Image expected;
  // expected.readFromFile("tests/expected.png");
  // Image alma;

  // std::cout << "Using Image::lighten to create `lighten.png`..." << std::endl;
  // alma.readFromFile("alma.png");

  // alma.lighten(0.2);
  // alma.writeToFile("lighten.png");

  // std::cout << "Using Image::saturate to create `saturate.png`..." << std::endl;
  // alma.readFromFile("alma.png");
  // alma.saturate(0.2);
  // alma.writeToFile("saturate.png");

  // std::cout << "Using Image::scale to create `scale.png`..." << std::endl;
  // alma.readFromFile("alma.png");
  // alma.scale(2);
  // alma.writeToFile("scale2x.png");

  return 0;
}
