#include "StickerSheet.h"
#include <vector>

    StickerSheet::StickerSheet(const Image &picture,unsigned max){
        base_image= picture;
        amount_stickers=max;
    }
    StickerSheet::StickerSheet(const StickerSheet &other){
        
    }
    const StickerSheet & StickerSheet::operator= (const StickerSheet){
        
    }
    void StickerSheet::changeMaxSticker(unsigned max){
        
    }
    int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y ){

    }
    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){

    }
    void StickerSheet::removeSticker(unsigned index){

    }
    Image * StickerSheet::getSticker(unsigned index){

    }
    Image StickerSheet::render() const{

    }