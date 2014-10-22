//
//  MasterViewController.h
//  RaidPlanner
//
//  Created by S on 10/22/14.
//  Copyright (c) 2014 Ryan Siska. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>

@interface MasterViewController : UITableViewController <NSFetchedResultsControllerDelegate>

@property (strong, nonatomic) NSFetchedResultsController *fetchedResultsController;
@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;


@end

/*
step 1 
 - we created using the Master Detail and then went into the cxdatamodeld - we created two new entities of Adventurer and Raid - we then went in and set the attributes for both (name and species for Adventurer and date for Raid) - an important note was that we set the species to receive an integer - want an integer so the user selects from a predetermined set of responses - allowing for a string could lead to the user entering things incorrectly and also makes it more difficult when attempting to update an app
 - on the relationships section as well of xcdatamodeld, we opened the right column,third button and changed the Type to "to many" which basically means one or more - within the Raid - adventurers relationship, we also unchecked the "Optional" property - because there can't be a raid with no adventurers
 - we then created new classes of type NSManagedObject through a new file Core Data - NSManaged one - created a raid and adventurer class with the properties we said they would have - now we can interact with these properties directly rather than having to interact always with an NSManagedObject











*/