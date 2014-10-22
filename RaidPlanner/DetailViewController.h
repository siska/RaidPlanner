//
//  DetailViewController.h
//  RaidPlanner
//
//  Created by S on 10/22/14.
//  Copyright (c) 2014 Ryan Siska. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Adventurer.h" //step 4
#import "Raid.h" //step 5

@interface DetailViewController : UIViewController

@property (strong, nonatomic) Adventurer *adventurer;
@property (weak, nonatomic) IBOutlet UILabel *detailDescriptionLabel;

-(Raid *)createRaid;

@end

