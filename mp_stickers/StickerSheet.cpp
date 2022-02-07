#include "StickerSheet.h"
#include <vector>
#include <iostream>
using namespace std;

    StickerSheet::StickerSheet(const Image &picture,unsigned max){
        base_image= new Image(picture);             //new   
        amount_stickers=max;
        cout<<"h"<<endl;
    }
    StickerSheet::StickerSheet(const StickerSheet &other){
        base_image = new Image(*other.base_image);
        amount_stickers=other.amount_stickers;
        for(unsigned i=0;i<other.stickers.size();i++){
            Image *temp= new Image( *(other.stickers[i]));      //new 
            stickers.push_back(temp);
            coordinates.push_back(other.coordinates[i]);
        }
        cout<<"e"<<endl;
    }

    const StickerSheet & StickerSheet::operator= (const StickerSheet &other){
        if(&other!=this ){
            for(int i=0;i<(int)stickers.size();i++){
            delete stickers[i]; //new 
        }
            delete base_image;      //new 
            base_image = new Image(*other.base_image);
            amount_stickers=other.amount_stickers;
            for(unsigned i=0;i<other.stickers.size();i++){
                Image *temp= new Image( *(other.stickers[i]));      //new 
                stickers.push_back(temp);
                coordinates.push_back(other.coordinates[i]);
            }
        }
        cout<<"e"<<endl;
        return *this;
    }
    // void StickerSheet::_copy(StickerSheet const &other){
    //     // delete[] imageData_;

    // // Copy `other` to self
    //     for(unsigned i=0;i<other.stickers.size();i++){
    //         Image *temp= new Image( *(other.stickers[i]));      //new 
    //         stickers.push_back(temp);
    //         coordinates.push_back(other.coordinates[i]);
    //     }
    // }
    StickerSheet::~StickerSheet(){
        for(int i=0;i<(int)stickers.size();i++){
            delete stickers[i]; //new 
        }
        delete base_image;      //new 
    }
    void StickerSheet::changeMaxStickers(unsigned max){
        amount_stickers= max;
        while(max<=stickers.size()-1){
            cout<<"here"<<endl;
            delete stickers.at(stickers.size()-1);    //new 
            // stickers.pop_back();
            cout<<"here"<<endl;
            stickers.erase(stickers.end()-1);

        }
        cout<<"l"<<endl;
    }
    int StickerSheet::addSticker(Image &sticker, unsigned x, unsigned y ){
        for(unsigned i=0; i<stickers.size();i++){
            if(stickers[i]==nullptr){
                stickers[i]=new Image(sticker); //new 
                coordinates[i]=make_pair(x,y);
                return i;
            }
        }
        if(amount_stickers==stickers.size())return -1;
        stickers.push_back(new Image(sticker)); // new 
        coordinates.push_back(make_pair(x,y));
        cout<<"o"<<endl;
        return stickers.size()-1;
    }
    bool StickerSheet::translate(unsigned index, unsigned x, unsigned y){
        if(index>coordinates.size()-1 || index<0) return false;
        coordinates[index]=make_pair(x,y);
        cout<<"w"<<endl;
        return true;
    }
    void StickerSheet::removeSticker(unsigned index){
        Image *temp=stickers[index];
        stickers[index]=nullptr;
        cout<<"r"<<endl;
        // delete temp;
    }
    Image * StickerSheet::getSticker(unsigned index){
        cout<<"l"<<endl;
        if(index>=stickers.size() || index<0)return NULL;
        return stickers[index];
    }
    Image StickerSheet::render() const{
        Image final=*base_image;
        for(unsigned i =0; i<stickers.size();i++){
            if(stickers[i]==nullptr) continue;
            for(unsigned x=0; x<stickers[i]->width();x++){
                for(unsigned y=0; y<stickers[i]->height();y++){
                    if(coordinates[i].first+stickers[i]->width()>final.width()) {
                        final.resize(coordinates[i].first+stickers[i]->width(),final.height());
                    }
                    if(stickers[i]->height()+coordinates[i].second>final.height()){
                        final.resize(final.width(),stickers[i]->height()+coordinates[i].second);
                    }
                    
                    HSLAPixel & finalPixel= final.getPixel(x+coordinates[i].first,y+coordinates[i].second);
                    if(stickers[i]->getPixel(x,y).a==0)continue;
                    finalPixel=stickers[i]->getPixel(x,y);
                }
            }
        }
        cout<<"d"<<endl;
        return final;
    }