# Changelog
Changelog for MapsIndoors for iOS. This document structure is based on [Keep a Changelog](http://keepachangelog.com/en/1.0.0/) and the project adheres to [Semantic Versioning](http://semver.org/spec/v2.0.0.html).

<!---
## [Unreleased]
### Added
### Fixed
### Changed
### Removed
-->

## [2.2.1] 2019-08-16

### Fixed
- Fixed some memory related crashes

## [2.2.0] 2019-08-08

### Added
- Map rendering now respects default floor per building configured in the MapsIndoors CMS
- Map rendering can perform clustering of location icons if enabled through the MapsIndoors CMS
- The map can now track user position and render relevant route part if indoor positioning is applicable
- Navigation can now find a nearest Parking lot when requesting directions by car
- Navigation now respects profile settings configured in the MapsIndoors CMS
- Navigation now respects locked doors configured in the MapsIndoors CMS
- Navigation now respects wait times configured in the MapsIndoors CMS
- Optimised directions requests in general
- The app is now WCAG "AA" compliant

### Changed
- Floor Selector now remains hidden until User interacts with Map (applies to Application Start and when selecting Venues) 
- Updated the Clear Map appearance and behaviour to become more intuitive and helpful
- The application now clears memory caches on low-memory warnings
- Implemented data integrity checks in to avoid corrupted data in the application cache

### Fixed
- Fixed a number of memory issues
- Various performance improvements throughout the entire application
- Improved offline search engine to give more meaningful results
- Improved List rendering
- Travel mode restrictions was sometimes not set correctly
- Some display settings performed in the MapsIndoors CMS was not affecting the intended change
- Infowindow popped up every time map was panned around with searchResult of 1 element
- Locations types with Visibility disabled was sometimes still displayed and clickable
- Advanced Icons was sometimes rendered twice upon clicking on a Room with a hidden Icon
- Some instructions in map labels for a requested route was incorrect
- Outlining the building in focus was sometimes inaccurate
- Sometimes the selected location failed to appear momentarily, as well as search results
- After browsing a category, free text search was unintentionally cleared when going back from details view
- Building Highlights/Outlines was difficult to discern even when zooming in
- Return to Venue was displayed when panning/moving away from a selected location
- Disabling Location Service blocked User from using Application
- Title of category was not updated when selecting category through quick access / floating menu
- Tapping on Information Window did not center view based on selected location
- "No Matches for..." warning was unintentionally displayed before populating the list with locations
- Advanced Icon tied to Destination retained on Map upon clearing Route
- Icon was not de-selected when selecting another Floor
- Google Maps logo was covered by my location and MapsPeople logo was misplaced on iPhone XR
- Fixed weird "jump" on the map when selecting route part

## [2.1.0] 2018-09-07

### Fixed
- Fixed issue causing "Clear Map" button not to appear on iOS < 11
- Increased shading behind venue select icon and app info icon
- Improved contrast on "show on map" button
- Fixed cases where distance rounding gave wrong and inconsistent results
- Fixed that category search results where not cleared after deleting letters in the search input field
- Fixed some issues in third party libraries that caused the app to crash under certain circumstances

### Changed
- Disable venueselector button when no venue has been selected
- Relevance-based sorting of POI-lists are now based on distance to user location
### Added
- A lot of accessibility improvements
- Updated MI SDK to 2.1.1

## [2.0.2] 2018-06-23

### Fixed
- Fixed an issue that was causing duplicate segments for some routes between different venues
### Changed
- Updated to latest MapsIndoors SDK
### Removed
- POIData wrapper service for a locations provider

## [2.0.1] 2018-05-25

### Fixed
- Fixed occasional crash caused by rendering some routes
- Fixed that "Clear Map" button does not appear on iOS < 11
- Fixed logic that choosed which building should be in focus
- Fixed that selected location was not cleared after clearing map
- Fixed performance issue: blocking UI thread when adding markers to map.
- Fixed excessive CPU, GPU and battery load
- Fixed poor map startup performance (UI thread blocking) when loading a big map
### Changed
- Animation speed when showing directions is now adapting the the amount of movement and rotation needed for transitioning between steps.
- Better default resolution in map graphics for online use.
- Disallow the map to change floorplan when showing a route (map shows the floor of the shown part of the route)

## [2.0] 2018-04-09
