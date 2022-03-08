/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
#include "kdtree.h"
// #include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */
    LUVAPixel colors;
    map<Point<3>,TileImage*> tileMap; 
    MosaicCanvas *Art= new MosaicCanvas(theSource.getRows(),theSource.getColumns());
    vector<Point<3>> tree;
    for(TileImage & tileExact : theTiles){
        // Point<3> temp=convertToXYZ(tileExact.getAverageColor());
        tree.push_back(convertToXYZ(tileExact.getAverageColor()));
        tileMap.insert({convertToXYZ(tileExact.getAverageColor()),&tileExact});
    }

    // vector<Point<3>> tree;
    KDTree<3> retTree(tree);

    for(int i=0; i<theSource.getRows();i++){
        for(int j=0; j<theSource.getColumns();j++){
            LUVAPixel temp= theSource.getRegionColor(i,j);
            Point<3> NN= retTree.findNearestNeighbor(convertToXYZ(temp));
            Art->setTile(i,j,tileMap[NN]);
        }
    }

    return Art;
}

