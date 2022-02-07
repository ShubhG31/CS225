// #pragma once
#include "cs225/PNG.h"
#include "Image.h"
using namespace cs225;
    void Image::lighten(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                 if((pixel.l+0.1)>1){
                    pixel.l=1;
                }
                else{
                pixel.l+=0.1;
                }
            }
        }
    }
    void Image::lighten(double amount){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                if((pixel.l+amount)>1){
                    pixel.l=1;
                }
                else{
                pixel.l+=amount;
                }
            }
        }
    }
    void Image::darken(){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                if((pixel.l-0.1)<0){
                    pixel.l=0;
                }
                else{
                pixel.l-=0.1;
                }
            }
        }
    }
    void Image::darken(double amount){
        unsigned height = this->height();
        unsigned width= this->width();
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                if((pixel.l-amount)<0){
                    pixel.l=0;
                }
                else{
                pixel.l-=amount;
                }
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
        while(degrees>360) degrees-=360;
        while(degrees<0)degrees+=360;
        for(unsigned x=0; x<width;x++){
            for(unsigned y=0;y<height;y++){
                HSLAPixel & pixel = this->getPixel(x,y);
                
                // while(degrees>360) degrees-=360;
                // while(degrees<0)degrees+=360;
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
        PNG *oldImage= new PNG(*this);
        // this->resize(factor*width,factor*height);
        // if(factor>1 ){
            this->resize(factor*width,factor*height);
            for(unsigned x=0; x<(factor*width);x++){
                for(unsigned y=0;y<(factor*height);y++){
                    this->getPixel(x,y)=oldImage->getPixel(x/factor,y/factor);
                }
            }
        // }
        // else if(factor<1){
        //     this->resize(factor/width,factor/height);
        //     for(unsigned x=0; x<width;x++){
        //         for(unsigned y=0;y<height;y++){
        //             oldImage->getPixel(x,y)=this->getPixel(factor*x,factor*y);
        //         }
        //     }
        // }   
        delete oldImage;
    }
    void Image::scale(unsigned w, unsigned h){
        // unsigned factor= w/h;
        double height_factor=h/(double) height();
        double width_factor=w/(double)width();
        // height_factor=double(height_factor);
        // width_factor=double(width_factor);
        if(width_factor<height_factor){
            scale(width_factor);
        }
        
        else{
            scale(height_factor);
        }

        // this->resize(w,h);

    }
