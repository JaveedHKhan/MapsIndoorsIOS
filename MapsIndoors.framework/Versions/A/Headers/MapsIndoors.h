//
//  MapsIndoors.h
//  MapsIndoors
//
//  Created by Daniel Nielsen on 30/08/16.
//  Copyright © 2016 Daniel-Nielsen. All rights reserved.
//


#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

//#import "GoogleMaps/GoogleMaps.h"
//#import "GoogleMaps/GMSAddress.h"
//#import "GoogleMaps/GMSCALayer.h"
//#import "GoogleMaps/GMSCameraPosition.h"
//#import "GoogleMaps/GMSCameraUpdate.h"
//#import "GoogleMaps/GMSCircle.h"
//#import "GoogleMaps/GMSCoordinateBounds+GoogleMaps.h"
//#import "GoogleMaps/GMSDeprecationMacros.h"
//#import "GoogleMaps/GMSGeocoder.h"
//#import "GoogleMaps/GMSGeometryUtils.h"
//#import "GoogleMaps/GMSGroundOverlay.h"
//#import "GoogleMaps/GMSIndoorBuilding.h"
//#import "GoogleMaps/GMSIndoorDisplay.h"
//#import "GoogleMaps/GMSIndoorLevel.h"
//#import "GoogleMaps/GMSMapLayer.h"
//#import "GoogleMaps/GMSMapView+Animation.h"
//#import "GoogleMaps/GMSMapView.h"
//#import "GoogleMaps/GMSMarker.h"
//#import "GoogleMaps/GMSMarkerLayer.h"
//#import "GoogleMaps/GMSMutablePath.h"
//#import "GoogleMaps/GMSOrientation.h"
//#import "GoogleMaps/GMSOverlay.h"
//#import "GoogleMaps/GMSPanorama.h"
//#import "GoogleMaps/GMSPanoramaCamera.h"
//#import "GoogleMaps/GMSPanoramaCameraUpdate.h"
//#import "GoogleMaps/GMSPanoramaLayer.h"
//#import "GoogleMaps/GMSPanoramaLink.h"
//#import "GoogleMaps/GMSPanoramaService.h"
//#import "GoogleMaps/GMSPanoramaView.h"
//#import "GoogleMaps/GMSPath.h"
//#import "GoogleMaps/GMSPolygon.h"
//#import "GoogleMaps/GMSPolyline.h"
//#import "GoogleMaps/GMSProjection.h"
//#import "GoogleMaps/GMSServices.h"
//#import "GoogleMaps/GMSSyncTileLayer.h"
//#import "GoogleMaps/GMSTileLayer.h"
//#import "GoogleMaps/GMSUISettings.h"
//#import "GoogleMaps/GMSURLTileLayer.h"
//#import "GoogleMapsBase/GMSCompatabilityMacros.h"
//#import "GoogleMapsBase/GMSCoordinateBounds.h"
//#import "GoogleMapsBase/GoogleMapsBase.h"
//#import "GoogleMapsCore/GoogleMapsCore.h"


#import <MapsIndoors/UIColor+HexString.h>
#import <MapsIndoors/MPAppData.h>
#import <MapsIndoors/MPAppMode.h>
#import <MapsIndoors/MPBuilding.h>
#import <MapsIndoors/MPBuildingDataset.h>
#import <MapsIndoors/MPCategoryUIBarButtonItem.h>
#import <MapsIndoors/MPContactModule.h>
#import <MapsIndoors/MPFloor.h>
#import <MapsIndoors/MPFloorButton.h>
#import <MapsIndoors/MPFloorSelectorControl.h>
#import <MapsIndoors/MPFloorTileLayer.h>
#import <MapsIndoors/MPPersistentCacheGMSTileLayer.h>
#import <MapsIndoors/MPGeometry.h>
#import <MapsIndoors/MPInfoSnippetView.h>
#import <MapsIndoors/MPLatLng.h>
#import <MapsIndoors/MPLatLngBounds.h>
#import <MapsIndoors/MPLayerType.h>
#import <MapsIndoors/MPLineGeometry.h>
#import <MapsIndoors/MPLoadIndicator.h>
#import <MapsIndoors/MPLocation.h>
#import <MapsIndoors/MPLocationDataset.h>
#import <MapsIndoors/MPLocationDisplayRule.h>
#import <MapsIndoors/MPLocationDisplayRuleset.h>
#import <MapsIndoors/MPLocationProperty.h>
#import <MapsIndoors/MPLocationPropertyTableCell.h>
#import <MapsIndoors/MPLocationPropertyView.h>
#import <MapsIndoors/MPLocationsProvider.h>
#import <MapsIndoors/MPLocationTableViewController.h>
#import <MapsIndoors/MPLocationView.h>
#import <MapsIndoors/MPMapControl.h>
#import <MapsIndoors/MPMapStyle.h>
#import <MapsIndoors/MPOnlineTileLayer.h>
#import <MapsIndoors/MPOpeningHours.h>
#import <MapsIndoors/MPOpeningHoursModule.h>
#import <MapsIndoors/MPPoint.h>
#import <MapsIndoors/MPSite.h>
#import <MapsIndoors/MPTokenSet.h>
#import <MapsIndoors/MPUIViewController.h>
#import <MapsIndoors/MPURITemplate.h>
#import <MapsIndoors/MPVector.h>
#import <MapsIndoors/MPVenue.h>
#import <MapsIndoors/MPVenueCollection.h>
#import <MapsIndoors/MPVenueProvider.h>
#import <MapsIndoors/NSString+FontAwesome.h>
#import <MapsIndoors/NSURL+QueryParser.h>
#import <MapsIndoors/UIFont+FontAwesome.h>
#import <MapsIndoors/UIFont+RegisterURL.h>
#import <MapsIndoors/MPLocationQuery.h>
#import <MapsIndoors/MPMapExtend.h>
#import <MapsIndoors/MPPositionProvider.h>
#import <MapsIndoors/MPBeaconPositionProvider.h>
#import <MapsIndoors/MPImageRenderer.h>
#import <MapsIndoors/MPMyLocationButton.h>
#import <MapsIndoors/MPBeacon.h>
#import <MapsIndoors/MPDouble.h>
#import <MapsIndoors/PositionCalculator.h>

#import <MapsIndoors/FAImageView.h>
#import <MapsIndoors/MPBeaconCollection.h>
#import <MapsIndoors/MPBuildingCollection.h>
#import <MapsIndoors/MPBuildingReference.h>
#import <MapsIndoors/MPMapButtonControl.h>
#import <MapsIndoors/NSString+CustomFont.h>
#import <MapsIndoors/UIFont+CustomFont.h>
#import <MapsIndoors/MPCategoriesProvider.h>
#import <MapsIndoors/MPCategories.h>
#import <MapsIndoors/MPLocationsCache.h>
#import <MapsIndoors/MPImageProvider.h>
#import <MapsIndoors/MPErrorCodes.h>
#import <MapsIndoors/MPMarkerView.h>
#import <MapsIndoors/NSString+UrlRequest.h>
#import <MapsIndoors/UIImage+MapsIndoorsBundle.h>
#import <MapsIndoors/MPMessage.h>
#import <MapsIndoors/MPMessageDataset.h>
#import <MapsIndoors/MPMessageProvider.h>
#import <MapsIndoors/MPStringCache.h>
#import <MapsIndoors/MPAppDataProvider.h>
#import <MapsIndoors/MPMenuItem.h>
#import <MapsIndoors/MPMIAPI.h>
#import <MapsIndoors/MPVersion.h>
#import <MapsIndoors/MPNotificationsHelper.h>
#import <MapsIndoors/MPMapsIndoors.h>

#import <MapsIndoors/MPDirectionsRenderer.h>
#import <MapsIndoors/MPDirectionsService.h>
#import <MapsIndoors/MPDistanceMatrixElements.h>
#import <MapsIndoors/MPDistanceMatrixProvider.h>
#import <MapsIndoors/MPDistanceMatrixResult.h>
#import <MapsIndoors/MPDistanceMatrixRows.h>
#import <MapsIndoors/MPMapRouteLegButton.h>
#import <MapsIndoors/MPRoute.h>
#import <MapsIndoors/MPRouteBounds.h>
#import <MapsIndoors/MPRouteCoordinate.h>
#import <MapsIndoors/MPRouteInfo.h>
#import <MapsIndoors/MPRouteInstructions.h>
#import <MapsIndoors/MPRouteLeg.h>
#import <MapsIndoors/MPRouteProperty.h>
#import <MapsIndoors/MPRouteResult.h>
#import <MapsIndoors/MPRouteStep.h>
#import <MapsIndoors/MPRoutingControl.h>
#import <MapsIndoors/MPRoutingProvider.h>
#import <MapsIndoors/MPTransitAgency.h>
#import <MapsIndoors/MPTransitDetails.h>
#import <MapsIndoors/MPTransitLine.h>
#import <MapsIndoors/MPTransitStop.h>
#import <MapsIndoors/MPTransitTime.h>
#import <MapsIndoors/MPTransitVehicle.h>
