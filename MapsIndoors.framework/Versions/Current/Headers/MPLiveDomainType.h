//
//  MPLiveDomainType.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 05/08/2020.
//  Copyright © 2020 MapsPeople A/S. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Constant for Occupancy Domain Type
#define kMPLiveDomainTypeOccupancy @"occupancy"
/// Constant for Position Domain Type
#define kMPLiveDomainTypePosition @"position"

NS_ASSUME_NONNULL_BEGIN

/// Convenience class for static Live Domain Types
@interface MPLiveDomainType : NSObject
/// Get the Occupancy Domain Type
@property (class, readonly, nonatomic, strong) NSString* occupancy;
/// Get the Position Domain Type
@property (class, readonly, nonatomic, strong) NSString* position;

@end

NS_ASSUME_NONNULL_END
