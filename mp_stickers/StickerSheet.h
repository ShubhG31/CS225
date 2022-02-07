/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"
#include "cs225/PNG.h"
#include <vector>
using namespace std;
using namespace cs225;
 class StickerSheet{
   public:
      vector<Image*> stickers;       // stores the Image pointers for the stickers 
      vector<pair<int,int>> coordinates;  // stores all the coordinates of the stickers 
      Image* base_image;               // is the base image to which the stickers will be applied
      unsigned amount_stickers;       // stores the max number of stickers that can be applied to the base picture
      // void _copy(StickerSheet const &other);

      StickerSheet(const Image &picture,unsigned max);
      StickerSheet(const StickerSheet &other);
      ~StickerSheet();
      const StickerSheet & operator=(const StickerSheet &other);
      void changeMaxStickers(unsigned max);
      int addSticker(Image &sticker, unsigned x, unsigned y );
      bool translate(unsigned index, unsigned x, unsigned y);
      void removeSticker(unsigned index);
      Image * getSticker(unsigned index);
      Image render() const;
 };
