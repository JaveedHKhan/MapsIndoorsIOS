//
//  DemosUITests.swift
//  DemosUITests
//
//  Created by Michael Bech Hansen on 05/04/2018.
//  Copyright © 2018 MapsPeople A/S. All rights reserved.
//

import XCTest

class DemosUITests: XCTestCase {
    
    var peakMemUsage = 0.0
    var accumulatedMem = 0.0
    let avgMemLimit = 260.0
    let memLimit = 370.0
    var numberOfMemSamples = 0.0

    override func setUp() {
        super.setUp()
        
        continueAfterFailure = false
        XCUIApplication().launch()
    }
    
    fileprivate func assertMemoryUsageTimespan(_ app: XCUIApplication) {
        assertMemoryUsage(app)
        _ = app.wait(for: .notRunning, timeout: 0.5)
        assertMemoryUsage(app)
        _ = app.wait(for: .notRunning, timeout: 0.5)
    }
    
    fileprivate func assertMemoryUsage(_ app: XCUIApplication) {
        numberOfMemSamples += 1.0
        let memoryLabel = app.staticTexts["MemoryFootprint"]
        XCTAssert(memoryLabel.exists)
        let memoryAsDouble = (memoryLabel.label as NSString).doubleValue
        accumulatedMem += memoryAsDouble
        peakMemUsage = max(peakMemUsage, memoryAsDouble)
        
        XCTAssert(accumulatedMem / numberOfMemSamples < avgMemLimit, "Average memory consumption exceeded limit of \(avgMemLimit)mb")
        XCTAssert(peakMemUsage < memLimit, "Peak memory consumption exceeded limit of \(memLimit)mb")
    }
    
    func testDemoSamples() {
        
        
        let app = XCUIApplication()

// Why doesn't this produce trustworthy numbers?
//        let metric = XCTMemoryMetric.init(application: app)
//        let options = XCTMeasureOptions.init()
//        options.iterationCount = 1
//
//        measure(metrics: [metric], options: options) {
        
            let tablesQuery = app.tables
            
            tablesQuery.staticTexts["Show Location Demo"].tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Location Details Demo"]/*[[".cells.staticTexts[\" Location Details Demo\"]",".staticTexts[\" Location Details Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Show Multiple Locations Demo"]/*[[".cells.staticTexts[\" Show Multiple Locations Demo\"]",".staticTexts[\" Show Multiple Locations Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Show Route Demo"]/*[[".cells.staticTexts[\" Show Route Demo\"]",".staticTexts[\" Show Route Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            tablesQuery.staticTexts["Show leg 0, all steps"].tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Show Venue Demo"]/*[[".cells.staticTexts[\" Show Venue Demo\"]",".staticTexts[\" Show Venue Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Show Building Demo"]/*[[".cells.staticTexts[\" Show Building Demo\"]",".staticTexts[\" Show Building Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Show Floor Demo"]/*[[".cells.staticTexts[\" Show Floor Demo\"]",".staticTexts[\" Show Floor Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Change Display Setting Demo"]/*[[".cells.staticTexts[\" Change Display Setting Demo\"]",".staticTexts[\" Change Display Setting Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery.staticTexts["Custom Floor Selector Demo"].tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars["Stigsborgvej - Floor 0"].buttons["Floor"].tap()
            assertMemoryUsageTimespan(app)
            app.alerts["Select Floor"].buttons["Floor 1 "].tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            app.tables/*@START_MENU_TOKEN@*/.staticTexts["Show My Location Demo"]/*[[".cells.staticTexts[\" Show My Location Demo\"]",".staticTexts[\" Show My Location Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Search Map Demo"]/*[[".cells.staticTexts[\" Search Map Demo\"]",".staticTexts[\" Search Map Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            assertMemoryUsageTimespan(app)
            app.buttons["Search"].tap()
            assertMemoryUsageTimespan(app)
            app.searchFields.firstMatch.tap()
            assertMemoryUsageTimespan(app)
            app.searchFields.firstMatch.typeText("park")
            assertMemoryUsageTimespan(app)
            tablesQuery.cells.element(boundBy: 0).tap()
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            
            tablesQuery/*@START_MENU_TOKEN@*/.staticTexts["Multiple Datasets Demo"]/*[[".cells.staticTexts[\" Multiple Datasets Demo\"]",".staticTexts[\" Multiple Datasets Demo\"]"],[[[-1,1],[-1,0]]],[0]]@END_MENU_TOKEN@*/.tap()
            app.navigationBars.buttons["Datasets"].tap()
            app.alerts.buttons["Aalborg City"].tap()
            XCTAssertTrue(app.buttons["Aalborg City"].waitForExistence(timeout: 30))
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons["Datasets"].tap()
            app.alerts.buttons["Stigsborgvej"].tap()
            XCTAssertTrue(app.buttons["Stigsborgvej"].waitForExistence(timeout: 10))
            assertMemoryUsageTimespan(app)
            app.navigationBars.buttons.firstMatch.tap()
            assertMemoryUsageTimespan(app)

//        }

        print("\(#function): Average memory usage:  \(accumulatedMem/numberOfMemSamples)")
        print("\(#function): Peak memory usage:     \(peakMemUsage)")
        
    }
}
