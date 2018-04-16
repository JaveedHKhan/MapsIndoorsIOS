//
//  POIData.h
//  MIAIOS
//
//  Created by Daniel Nielsen on 02/09/15.
//  Copyright (c) 2015-2018 MapsPeople A/S. All rights reserved.
//

#import <MapsIndoors/MapsIndoors.h>

@interface POIData : MPLocationsProvider<MPLocationsProviderDelegate>

@property (readonly) MPLocationQuery* locationQuery;
@property (readonly) MPLocation* latestLocation;

@end
