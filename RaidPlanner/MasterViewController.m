//
//  MasterViewController.m
//  RaidPlanner
//
//  Created by S on 10/22/14.
//  Copyright (c) 2014 Ryan Siska. All rights reserved.
//

#import "MasterViewController.h"
#import "DetailViewController.h"
#import "Adventurer.h" //step 2

@interface MasterViewController ()

@end

@implementation MasterViewController

//step 2 - dragged into storyboard and set event to did end on exit before connecting
- (IBAction)onAddNewAdventurer:(UITextField *)sender
{
    Adventurer *adventurer = [NSEntityDescription insertNewObjectForEntityForName:@"Adventurer" inManagedObjectContext:self.managedObjectContext];

    adventurer.name = sender.text;
    adventurer.species = [NSNumber numberWithInt:arc4random_uniform(4)];

    [self.managedObjectContext save:nil];
    [sender resignFirstResponder];
}


@end

