//
//  DetailViewController.m
//  MapsIndoorsGenericApp
//
//  Created by Daniel Nielsen on 10/08/15.
//  Copyright (c) 2015 MapsPeople A/S. All rights reserved.
//


#import "Global.h"
#import "DetailViewController.h"
#import "TextViewController.h"
@import VCMaterialDesignIcons;
#import "UINavigationController+TransparentNavigationController.h"
#import "DirectionsController.h"
@import AFNetworking;
@import MapsIndoorsSDK;
@import MaterialControls;
#import "UIColor+AppColor.h"
#import "UIButton+AppButton.h"

@interface DetailViewController ()

@end

@implementation DetailViewController {
    NSMutableArray* _fields;
    RoutingData* _routing;
    MPRoute* _route;
    MDButton* _routeBtn;
    MDButton* _showMapBtn;
    NSDictionary* _directionsItem;
}

@synthesize location = _location;

- (void) reload {
    [self viewDidLoad];
    [self viewWillAppear:NO];
}

- (void)awakeFromNib {
    [super awakeFromNib];
    _routing = Global.routingData;
    
    
    //[[NSNotificationCenter defaultCenter] addObserver:_mapControl.loader selector:@selector(startAnimating) name:@"LocationsRequestStarted" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onLocationDetailsReady:) name:@"LocationDetailsReady" object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onRouteResultReady:) name:@"RoutingDataReady" object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(reload) name:@"Reload" object:nil];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.navigationController presentTransparentNavigationBar];
}

- (void) pop: (id)sender {
    [self.navigationController popViewControllerAnimated:YES];
}

- (void)onLocationDetailsReady:(NSNotification*)notification {
    _fields = [NSMutableArray arrayWithCapacity:0];
    
    if (_location != notification.object) {
        self.location = notification.object;
    }
}

- (void)setLocation:(MPLocation *)location {
    _location = location;
    if (_location) {
        if (_location.descr) [_fields addObject:@{@"type": @"description", @"text": _location.descr}];
        
        MPLocation* from = [[MPLocation alloc] initWithPoint:Global.positionProvider.latestPositionResult.geometry andName:kYouAreHere];
        
        [_routing routingFrom: from to: _location by:@"walking" avoid:nil depart:nil arrive:nil];
        
        [self.iconImageView setImageWithURL:[NSURL URLWithString: [Global getIconUrlForType:_location.type]]];
        
        self.titleLabel.text = _location.name;
        //[self.navigationController.navigationBar setBackgroundImage:[UIImage imageNamed:@"lounge"] forBarMetrics:UIBarMetricsDefault];
        
        if (_location.fields) {
            for (NSString* key in _location.fields.keyEnumerator) {
                MPLocationField* field = [_location.fields objectForKey:key];
                if (field.value && field.value.length > 1) {
                    if (!([[key lowercaseString] isEqualToString:@"imageurl"] || [key isEqualToString:@"image"])) {
                        //Not image
                        if ([key isEqualToString:@"openinghours"]) [_fields addObject:@{@"type": key, @"text": field.value, @"icon": [self materialIcon:VCMaterialDesignIconCode.md_time]}];
                        if ([key isEqualToString:@"website"]) [_fields addObject:@{@"type": key, @"text": field.value, @"icon": [self materialIcon:VCMaterialDesignIconCode.md_link]}];
                        if ([key isEqualToString:@"phone"]) [_fields addObject:@{@"type": key, @"text": field.value, @"icon": [self materialIcon:VCMaterialDesignIconCode.md_phone]}];
                        if ([key isEqualToString:@"email"]) [_fields addObject:@{@"type": key, @"text": field.value, @"icon": [self materialIcon:VCMaterialDesignIconCode.md_email]}];
                    } else {
                        //Image
                        [self.headerImageView setImageWithURL:[NSURL URLWithString:field.value]];
                    }
                }
            }
        }
        
        [self.tableView reloadData];
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    
    CAGradientLayer *gradient = [CAGradientLayer layer];
    gradient.frame = CGRectMake(0, 0, 600, 140);
    gradient.colors = [NSArray arrayWithObjects:(id)[[UIColor clearColor] CGColor], (id)[[UIColor colorWithRed:0 green:0 blue:0 alpha:0.6f] CGColor], nil];
    gradient.startPoint = CGPointMake(0, .5f);
    gradient.endPoint = CGPointMake(0, 1.0f);
    [self.headerImageView.layer insertSublayer:gradient atIndex:0];
    
    self.backIconView.image = [self.backIconView.image imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate];
    self.backIconView.tintColor = [UIColor appPrimaryColor];
    [self.backIconView setUserInteractionEnabled:YES];
    self.backIconView.backgroundColor = [UIColor clearColor];
    UITapGestureRecognizer *singleTap =  [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(pop:)];
    [singleTap setNumberOfTapsRequired:1];
    [self.backIconView addGestureRecognizer:singleTap];
    
    [self.tableView setContentInset:UIEdgeInsetsMake(-64,0,0,0)];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    [self.navigationController presentTransparentNavigationBar];
    if (_showMapBtn == nil) {
        _showMapBtn = [UIButton appRectButtonWithTitle:@"Show on map" target:self selector:@selector(showMapController:)];
        [_showMapBtn setTitleColor:[UIColor appSecondaryTextColor] forState:UIControlStateNormal];
        _showMapBtn.backgroundColor = [UIColor appTextAndIconColor];
        
        _routeBtn = [UIButton appRectButtonWithTitle:@"Route" target:self selector:@selector(showDirectionsController:) xOffset:self.tableFooter.frame.size.width-120];
        
        [self.tableFooter addSubview:_showMapBtn];
        [self.tableFooter addSubview:_routeBtn];
        

    }
    
}

- (void) showMapController:(id)sender {
    [[NSNotificationCenter defaultCenter] postNotificationName:@"CloseRouting" object:nil];
    
    [[NSNotificationCenter defaultCenter] postNotificationName:@"LocationDetailsReady" object:_location];
    
    UIBarButtonItem* btn = self.splitViewController.displayModeButtonItem;
    [[UIApplication sharedApplication] sendAction:btn.action
                                               to:btn.target
                                             from:nil
                                         forEvent:nil];
    [self.tableView deselectRowAtIndexPath:self.tableView.indexPathForSelectedRow animated:NO];
}

- (void) showDirectionsController:(id)sender {
    if ([self shouldPerformSegueWithIdentifier:@"DirectionsSegue" sender:self]) {
        [self performSegueWithIdentifier:@"DirectionsSegue" sender:self];
    }
    [self.tableView deselectRowAtIndexPath:self.tableView.indexPathForSelectedRow animated:NO];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    // Return the number of sections.
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    // Return the number of rows in the section.
    return _fields.count;
}

- (UIImage*) materialIcon:(NSString*)iconCode {
    // create icon with Material Design code and font size
    // font size is the basis for icon size
    VCMaterialDesignIcons *icon = [VCMaterialDesignIcons iconWithCode:iconCode fontSize:30.f];
    
    // add attribute to icon
    ;
    [icon addAttribute:NSForegroundColorAttributeName value:[UIColor appPrimaryColor]];
    
    // the icon will be drawn to UIImage in a given size
    return [icon image];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"DetailCell" forIndexPath:indexPath];

    NSDictionary* dict = [_fields objectAtIndex:indexPath.row];
    
    if ([dict objectForKey:@"icon"])
        cell.imageView.image = [dict objectForKey:@"icon"];
    else cell.imageView.image = nil;
    cell.textLabel.text = [dict objectForKey:@"text"];
    cell.textLabel.lineBreakMode = NSLineBreakByTruncatingTail;
    if ([[dict objectForKey:@"type"] isEqualToString:@"website"]) {
        cell.textLabel.numberOfLines = 1;
    } else {
        cell.textLabel.numberOfLines = 3;
    }
    
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    NSDictionary* dict = [_fields objectAtIndex:indexPath.row];
    [[NSNotificationCenter defaultCenter] postNotificationName:@"DetailFieldTapped" object:dict];
}

- (BOOL)shouldPerformSegueWithIdentifier:(NSString *)identifier sender:(id)sender {
    NSDictionary* dict = nil;
    
    if (self.tableView.indexPathForSelectedRow) {
        dict = [_fields objectAtIndex:self.tableView.indexPathForSelectedRow.row];
        
        if ([[dict objectForKey:@"type"] isEqualToString:@"description"] && ![identifier isEqualToString:@"TextSegue"]) {
            [self performSegueWithIdentifier:@"TextSegue" sender:self];
            return NO;
        }
    
        if (![[dict objectForKey:@"type"] isEqualToString:@"directions"]) {
            return NO;
        }
    }
    if ([[UIDevice currentDevice] userInterfaceIdiom] != UIUserInterfaceIdiomPad) {
        [[NSNotificationCenter defaultCenter] postNotificationName:@"ShowHorizontalDirections" object:nil];
        [_routing routingFrom:_routing.origin to:_routing.destination by:@"walking" avoid:nil depart:nil arrive:nil];
        //Hide side menu/master view
        UIBarButtonItem* btn = self.splitViewController.displayModeButtonItem;
        [[UIApplication sharedApplication] sendAction:btn.action
                                                   to:btn.target
                                                 from:nil
                                             forEvent:nil];
        return NO;
    }
    
    return YES;
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"TextSegue"]) {
        NSDictionary* dict = [_fields objectAtIndex:self.tableView.indexPathForSelectedRow.row];
        ((TextViewController*)segue.destinationViewController).text = [dict objectForKey:@"text"];
    }
}

- (void)onRouteResultReady:(NSNotification *)notification {
    _route = notification.object;
    NSMutableArray *mutableArray = [[NSMutableArray alloc] init];
    NSDictionary* directionsItem = @{@"type": @"directions", @"text": [NSString stringWithFormat: @"%d minutes walk", (int)ceil([_route.duration floatValue] / 60.0f)], @"icon": [self materialIcon:VCMaterialDesignIconCode.md_walk]};
    if (_directionsItem == nil) {
        _directionsItem = directionsItem;
        [mutableArray addObject:_directionsItem];
    } else {
        _directionsItem = directionsItem;
    }
    [mutableArray addObjectsFromArray:_fields];
    _fields = mutableArray;
    [self.tableView reloadData];
}


@end