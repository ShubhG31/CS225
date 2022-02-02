/**
 * @file StickerSheet.h
 * Contains your declaration of the interface for the StickerSheet class.
 */
#pragma once
#include "Image.h"
#include "cs225/PNG.h"
using namespace cs225;
 class StickerSheet{
   public:
      StickerSheet(const Image &picture,unsigned max);
      StickerSheet(const StickerSheet &other);
      ~StickerSheet();
      const StickerSheet & operator=(const StickerSheet);
      void changeMaxSticker(unsigned max);
      int addSticker(Image &sticker, unsigned x, unsigned y );
 };
