// #pragma once
#include "cs225/PNG.h"
#include "Image.h"

namespace cs225{
    void Image::lighten(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.l+=0.1;
            }
        }
    }
    void Image::lighten(double amount){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.l+=amount;
            }
        }
    }
    void Image::darken(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.l-=0.1;
            }
        }
    }
    void Image::saturate(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.s+=0.1;
            }
        }
    }
    void Image::saturate(double amount){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.s+=amount;
            }
        }
    }
    void Image::desaturate(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.s-=0.1;
            }
        }
    }
     void Image::desaturate(double amount){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.s-=amount;
            }
        }
    }
    void Image::grayscale(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                pixel.s=0;
            }
        }
    }
    void Image::illinify(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                if(114<=pixel.h && pixel.h<= 293){
                    pixel.h=216;
                }
                else{
                    pixel.h=11;
                }
            }
        }
    }
    void Image::rotateColor(double degrees){
         unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                if(pixel.h+degrees>360){
                    pixel.h=degrees-(360-pixel.h);
                }
                else{
                    pixel.h+=degrees;
                }
            }
        }
    }
    void Image::scale(double factor){
        unsigned height = this->height();
        unsigned width= this->width();
        
        this->resize(factor*width,factor*height);
    }
    void Image::scale(unsigned w, unsigned h){

        this->resize(w,h);

    }
}