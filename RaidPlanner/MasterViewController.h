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

- important note in the .h files we just created - the NSSet, it's like an array but doesn't allow for something to be added twice, to be a duplicate
 
 step 2
 - we went into the storyboard and added a UITextField to the navigation of the MasterVC - we then created an IBAction from that within the MasterVC.m - before we clicked connect, we set the Event to did end on exit
 - imported the Adventurer.h in MasterVC.m so we could interact with the adventurer class and the properties in it that we created during step 1
 - we named the IBAction as onAddNewAdventurer and then added code that, when someone clicks return after clicking on the text field, creates a new adventurer and saves that to Core Data
    - in the first line, we're doing - add later

step 3
didn't have time for notes - adding after based on memory:

 - added the loadAdventurers method to get the Adventurer from Core Data and reload the tableView with the new data - like yesterday we sorted the data and then assigned it back to the nsarray that we created earlier - we also added the tableView datasource methods number... and cellForRow... 
 
 
 step 4 
 - In storyboard for the Detail View Controller, we added a date picker and a button - then within then MasterVC.m, we added a prepareForSegue to send the clicked on adventurer over to the detailVC
 - we also added an unwindFromDetailVC segue (didn't do anyhting with it yet) and in storyboard connected the Attend Raid to the exit button to connect it to the unwind segue
 - within the DetailVC.h, we also imported the Adventurer.h class so that we could creat a property of type Adventurer to receive what was sent in the prepare for segue - in the DetailVC.m then, we deleted all the pre loaded stuff and added a viewDidLoad to set the title of the detail VC to the adventurer's name that was passed over

 step 5
 - this is where we actually set up the relationship between the adventurer and the raids
 - we imported the Raid.h into the MasterVC.m and then set up the unwind segue - most of the work was done within the DetailVC
 - in DetailVC.h, we imported the Raid.h so that we could create a helper method - createRaid - this is what will actually create the raid to be associated with an adventurer (called from the unwind segue)
 - within the DetailVC.m, we imported the CoreData, added an IBOutlet for the datepicker so that we could get the data from it and then implemented the createRaid method which creates a Raid object, sets the raid date to the datePicker date and then returns the date p which is asked for and grabbed during the unwind segue

 - we also updated the storyboard so that the detailedView can show up with the number of raids the adventurer will attend

step 6 
we're making sure that adventurers cant add multiple instances of the same event (raid)

- first we updated the storyboard - clicked on the datePicker and opened the right column - changed the mode to just date and the date to custom - that way it only shows date within the DetailVC and not the time
 - we then updated the createRaid method within the DetailVC.m with the code called out therein - we use the NSFetchRequest object inited with "Raid" from Core Data and updated with the predicate method which sets the date to see if an object for that event (an object with the same date) has already been created - if it's already been created, we just return the first object in the array (which should only contain one event array for that date anyway) to the unwind which calls this method




*/