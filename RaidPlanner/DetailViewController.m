//
//  DetailViewController.m
//  RaidPlanner
//
//  Created by S on 10/22/14.
//  Copyright (c) 2014 Ryan Siska. All rights reserved.
//

#import "DetailViewController.h"
#import <CoreData/CoreData.h> //step 5

@interface DetailViewController ()
@property (strong, nonatomic) IBOutlet UIDatePicker *datePicker; //step 5

@end

@implementation DetailViewController

-(void)viewDidLoad
{
    self.title = self.adventurer.name;
}

-(Raid *)createRaid
{ //step 6 from here
    NSFetchRequest *request = [[NSFetchRequest alloc] initWithEntityName:@"Raid"];
    request.predicate = [NSPredicate predicateWithFormat:@"date=%@", self.datePicker.date];
    NSArray *results = [self.adventurer.managedObjectContext executeFetchRequest:request error:nil];

    if (results.count > 0) {
        NSLog(@"Raid already exists");
        return results.firstObject;
    } //step 6 down to here

    Raid *raid = [NSEntityDescription insertNewObjectForEntityForName:@"Raid" inManagedObjectContext:self.adventurer.managedObjectContext]; //the self.manager.managedObjectContext was something that Max knew about to get the managedObjectContext - otherwise would likely need to create new property of that type and send it here through prepareForSegue?
    raid.date = self.datePicker.date;
    return raid;
}


@end
