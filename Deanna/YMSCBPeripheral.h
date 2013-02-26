//
//  YMSCBPeripheral.h
//  Deanna
//
//  Created by Charles Choi on 12/17/12.
//  Copyright (c) 2012 Yummy Melon Software. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#include "YMSCBUtils.h"
@class YMSCBService;


/**
 YMS CoreBluetooth representation of a peripheral. 
 
 This is effectively a container class which manages an instance of CBPeripheral 
 and its associated delegate callbacks.

 */
@interface YMSCBPeripheral : NSObject <CBPeripheralDelegate>

/// 128 bit address base
@property (nonatomic, assign) yms_u128_t base;

/// Hold (key, value) pairs of (NSString, YMSCBService) instances
@property (nonatomic, strong) NSDictionary *serviceDict;

/// Pointer to CBPeripheral instance of a sensor tag.
@property (nonatomic, strong) CBPeripheral *cbPeriperheral;

/// If ON, enable updates of RSSI.
@property (nonatomic, assign) BOOL shouldPingRSSI;

///**
// Constructor 
// 
// @param peripheral ins
// @return instance of this class
// */
//- (id)initWithPeripheral:(CBPeripheral *)peripheral;
//

/**
 Constructor
 
 @param peripheral pointer to CBPeripheral
 @param hi top 64-bit address value 
 @param lo bottom 64-bit address value
 @param update if YES, update the RSSI.
 @return instance of this class
 */
- (id)initWithPeripheral:(CBPeripheral *)peripheral
                  baseHi:(int64_t)hi
                  baseLo:(int64_t)lo
              updateRSSI:(BOOL)update;



/**
 Generate array of CBUUID for all SensorTag CoreBluetooth services.
 
 The output of this method is to be passed to [CBPeripheral discoverServices:]
 
 @return array of CBUUID services
 */
- (NSArray *)services;

/**
 Find YMSCBService given its corresponding CBService.
 
 @param service this thing
 @return YMSCBService
 */
- (YMSCBService *)findService:(CBService *)service;

/**
 Request RSSI update from CBPeripheral.
 */
- (void)updateRSSI;

@end
