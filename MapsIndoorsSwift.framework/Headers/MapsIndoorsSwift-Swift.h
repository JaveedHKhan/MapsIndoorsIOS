// Generated by Apple Swift version 3.0.2 (swiftlang-800.0.63 clang-800.0.42.1)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if defined(__has_include) && __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if defined(__has_attribute) && __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if defined(__has_attribute) && __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
# if defined(__has_feature) && __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME) SWIFT_ENUM(_type, _name)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if defined(__has_feature) && __has_feature(modules)
@import ObjectiveC;
@import Foundation;
@import Gloss;
@import CoreLocation;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
@class IndoorPoint;
@class Route;

SWIFT_CLASS("_TtC16MapsIndoorsSwift17DirectionsService")
@interface DirectionsService : NSObject
- (nonnull instancetype)initWithMapsIndoorsSolutionId:(NSString * _Nonnull)solutionId googleApiKey:(NSString * _Nonnull)googleApiKey OBJC_DESIGNATED_INITIALIZER;
- (void)routingFrom:(IndoorPoint * _Nonnull)origin to:(IndoorPoint * _Nonnull)destination by:(NSString * _Nonnull)mode avoid:(NSArray<NSString *> * _Nullable)restrictions depart:(NSDate * _Nullable)departureTime arrive:(NSDate * _Nullable)arrivalTime completionHandler:(void (^ _Nonnull)(Route * _Nullable, NSError * _Nullable))handler;
- (void)routingFrom:(IndoorPoint * _Nonnull)from to:(IndoorPoint * _Nonnull)to by:(NSString * _Nonnull)mode completionHandler:(void (^ _Nonnull)(Route * _Nullable, NSError * _Nullable))handler;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift15EncodedPolyline")
@interface EncodedPolyline : NSObject
@property (nonatomic, copy) NSString * _Nonnull points;
- (nullable instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class ZLevelObject;
@class NumberObject;

SWIFT_CLASS("_TtC16MapsIndoorsSwift11IndoorPoint")
@interface IndoorPoint : NSObject
@property (nonatomic) double latitude;
@property (nonatomic) double longitude;
@property (nonatomic) NSInteger floor;
@property (nonatomic, strong) ZLevelObject * _Nonnull zLevel;
@property (nonatomic, strong) NumberObject * _Nonnull lat;
@property (nonatomic, strong) NumberObject * _Nonnull lng;
- (nullable instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithLat:(double)lat lng:(double)lng floor:(NSInteger)floor OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithLat:(double)lat lng:(double)lng;
- (CLLocationCoordinate2D)getCoordinates;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift16MapsIndoorsSwift")
@interface MapsIndoorsSwift : NSObject
/**
  Provides your Solution Id to the MapsIndoors SDK for iOS. This key is generated
  for your solution.
  @return YES if the Solution Id was successfully provided
*/
+ (BOOL)provideSolutionId:(NSString * _Nonnull)solutionId;
/**
  Get Solution Id for the content of MapsIndoors. This key is generated
  for your solution.
*/
+ (NSString * _Nonnull)getSolutionId;
/**
  Sets the language for the content provided by MapsIndoors.
  @param language The language for which the content should be fetched. Uses the two-letter language code ISO 639-1.
*/
+ (void)setLanguage:(NSString * _Nonnull)languageCode;
/**
  Gets the current language for the content provided by MapsIndoors. Uses the two-letter language code ISO 639-1.
*/
+ (NSString * _Nonnull)getLanguage;
/**
  Fetch all neccesary content to be able to run MapsIndoors in offline environments
  @param completionHandler Callback function that fires when content has been fetched or if this process resolves in an error. Note: Does not automatically retry fetch.
*/
+ (void)fetchDataForOfflineUse:(void (^ _Nonnull)(NSError * _Nullable))completionHandler;
/**
  Sets the offline mode for the content provided by MapsIndoors. NB: This forces the implementation to be offline, even if there is no data available offline.
  @param offlineMode The offline mode. Can be true/offline false/offline.
*/
+ (void)setOfflineMode:(BOOL)offlineMode;
/**
  Gets the current offline mode.
*/
+ (BOOL)getOfflineMode;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift12NumberObject")
@interface NumberObject : NSObject
@property (nonatomic) double doubleValue;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class RouteLeg;

SWIFT_PROTOCOL("_TtP16MapsIndoorsSwift13RouteProtocol_")
@protocol RouteProtocol
@property (nonatomic, readonly) double duration;
@property (nonatomic, readonly) double distance;
@property (nonatomic, readonly, copy) NSArray<RouteLeg *> * _Nullable legs;
@end

@class RouteBounds;

SWIFT_CLASS("_TtC16MapsIndoorsSwift5Route")
@interface Route : NSObject <RouteProtocol>
@property (nonatomic, copy) NSString * _Nullable copyrights;
/**
  The route legs: the different route components. Typically a route from 1st floor to 2nd floor will consist of two route legs.
*/
@property (nonatomic, copy) NSArray<RouteLeg *> * _Nullable legs;
@property (nonatomic, copy) NSString * _Nullable overview_polyline;
@property (nonatomic, copy) NSString * _Nullable summary;
@property (nonatomic, copy) NSArray<NSString *> * _Nullable warnings;
@property (nonatomic, strong) RouteBounds * _Nullable bounds;
@property (nonatomic, readonly) double duration;
@property (nonatomic, readonly) double distance;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift11RouteBounds")
@interface RouteBounds : NSObject
@property (nonatomic, strong) IndoorPoint * _Nullable northeast;
@property (nonatomic, strong) IndoorPoint * _Nullable southwest;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class RouteProperty;
@class RouteStep;

/**
  Route leg model. A route model will consist of one ore more route legs. Typically a route from 1st floor to 2nd floor will consist of two route legs. Thus, a route leg defines a continueus route part within the same floor and/or building and/or vehicle.
*/
SWIFT_CLASS("_TtC16MapsIndoorsSwift8RouteLeg")
@interface RouteLeg : NSObject
/**
  <ul>
    <li>
      The routeleg distance
    </li>
  </ul>
*/
@property (nonatomic, strong) RouteProperty * _Nonnull distance;
/**
  The routeleg duration
*/
@property (nonatomic, strong) RouteProperty * _Nonnull duration;
@property (nonatomic, strong) IndoorPoint * _Nullable start_location;
@property (nonatomic, strong) IndoorPoint * _Nullable end_location;
@property (nonatomic, copy) NSString * _Nullable start_address;
@property (nonatomic, copy) NSString * _Nullable end_address;
@property (nonatomic) BOOL isIndoorLeg;
/**
  The array of route actions in this route leg.
*/
@property (nonatomic, copy) NSArray<RouteStep *> * _Nullable steps;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift13RouteProperty")
@interface RouteProperty : NSObject
@property (nonatomic, copy) NSString * _Nullable text;
@property (nonatomic) double value;
- (float)floatValue;
- (nonnull instancetype)init:(double)value OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


@class TransitDetails;

SWIFT_CLASS("_TtC16MapsIndoorsSwift9RouteStep")
@interface RouteStep : NSObject
@property (nonatomic, copy) NSString * _Nullable travel_mode;
@property (nonatomic, strong) IndoorPoint * _Nullable end_location;
@property (nonatomic, strong) IndoorPoint * _Nullable start_location;
@property (nonatomic, strong) RouteProperty * _Nonnull distance;
@property (nonatomic, strong) RouteProperty * _Nonnull duration;
@property (nonatomic, copy) NSString * _Nullable maneuver;
@property (nonatomic, copy) NSArray<IndoorPoint *> * _Nullable geometry;
@property (nonatomic, copy) NSString * _Nullable html_instructions;
@property (nonatomic, copy) NSString * _Nullable highway;
@property (nonatomic, copy) NSString * _Nullable routeContext;
@property (nonatomic, copy) NSArray<RouteStep *> * _Nullable steps;
@property (nonatomic, strong) TransitDetails * _Nullable transit_details;
@property (nonatomic, strong) EncodedPolyline * _Nullable polyline;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift7Routing")
@interface Routing : NSObject
+ (void)setupRouting:(NSString * _Nonnull)solutionId completion:(void (^ _Nonnull)(NSError * _Nullable))completion;
+ (void)getRoute:(NSString * _Nonnull)graphId from:(CLLocationCoordinate2D)from fromFloor:(NSInteger)fromFloor to:(CLLocationCoordinate2D)to toFloor:(NSInteger)toFloor avoid:(NSArray<NSString *> * _Nullable)avoid completion:(void (^ _Nonnull)(Route * _Nullable, NSError * _Nullable))completion;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift13TransitAgency")
@interface TransitAgency : NSObject
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable url;
@property (nonatomic, copy) NSString * _Nullable phone;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class TransitLine;
@class TransitStop;
@class TransitTime;

SWIFT_CLASS("_TtC16MapsIndoorsSwift14TransitDetails")
@interface TransitDetails : NSObject
@property (nonatomic, strong) TransitLine * _Nullable line;
@property (nonatomic, strong) TransitStop * _Nullable arrival_stop;
@property (nonatomic, strong) TransitTime * _Nullable arrival_time;
@property (nonatomic, strong) TransitTime * _Nullable departure_time;
@property (nonatomic, copy) NSString * _Nullable headsign;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

@class TransitVehicle;

SWIFT_CLASS("_TtC16MapsIndoorsSwift11TransitLine")
@interface TransitLine : NSObject
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable short_name;
@property (nonatomic, copy) NSString * _Nullable color;
@property (nonatomic, copy) NSArray<TransitAgency *> * _Nullable agencies;
@property (nonatomic, copy) NSString * _Nullable url;
@property (nonatomic, copy) NSString * _Nullable icon;
@property (nonatomic, copy) NSString * _Nullable text_color;
@property (nonatomic, strong) TransitVehicle * _Nullable vehicle;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift11TransitStop")
@interface TransitStop : NSObject
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, strong) IndoorPoint * _Nullable location;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift11TransitTime")
@interface TransitTime : NSObject
@property (nonatomic, copy) NSString * _Nullable text;
@property (nonatomic, copy) NSString * _Nullable time_zone;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift14TransitVehicle")
@interface TransitVehicle : NSObject
@property (nonatomic, copy) NSString * _Nullable name;
@property (nonatomic, copy) NSString * _Nullable type;
@property (nonatomic, copy) NSString * _Nullable icon;
@property (nonatomic, copy) NSString * _Nullable local_icon;
- (nonnull instancetype)initWithJson:(NSDictionary<NSString *, id> * _Nonnull)json OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end


@interface UIImage (SWIFT_EXTENSION(MapsIndoorsSwift))
@end


SWIFT_CLASS("_TtC16MapsIndoorsSwift12ZLevelObject")
@interface ZLevelObject : NSObject
@property (nonatomic) int intValue;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
@end

#pragma clang diagnostic pop