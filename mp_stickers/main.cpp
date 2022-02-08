#include "Image.h"
#include "StickerSheet.h"

int main() {
  
  //
  // Reminder:
  //   Before exiting main, save your creation to disk as myImage.png
  Image base;     
  base.readFromFile("spiderman-cool.png");
  Image toby,portal,holland;
  toby.readFromFile("toby_crying.png");
  portal.readFromFile("spiderman-portal.png");
  holland.readFromFile("spiderman-holland.png");


  StickerSheet sheet(base, 5);
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

  sheet.addSticker(portal, 40, 200);
  sheet.addSticker(holland, 60, 200);
  sheet.addSticker(toby, 20, 400);
  // sheet.changeMaxStickers(1);
  Image out = sheet.render();
  out.writeToFile("myImage.png");

  return 0;
}
