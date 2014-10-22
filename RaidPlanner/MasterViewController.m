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
#import "Raid.h" //step 5

@interface MasterViewController () <UITableViewDataSource>

@property NSArray *adventurers; //step 3

@end

@implementation MasterViewController

-(void)viewDidLoad //step 3
{
    [super viewDidLoad];
    [self loadAdventurers]; //step 3
}

-(void)loadAdventurers //step 3
{
    NSFetchRequest *request = [[NSFetchRequest alloc] initWithEntityName:@"Adventurer"];
    request.sortDescriptors = [NSArray arrayWithObject:[NSSortDescriptor sortDescriptorWithKey:@"name" ascending:YES]];
    self.adventurers = [self.managedObjectContext executeFetchRequest:request error:nil];
    [self.tableView reloadData];
}

//step 2 - dragged into storyboard and set event to did end on exit before connecting
- (IBAction)onAddNewAdventurer:(UITextField *)sender
{
    Adventurer *adventurer = [NSEntityDescription insertNewObjectForEntityForName:@"Adventurer" inManagedObjectContext:self.managedObjectContext];

    adventurer.name = sender.text;
    adventurer.species = [NSNumber numberWithInt:arc4random_uniform(4)];

    [self.managedObjectContext save:nil];
    [sender resignFirstResponder];
    [self loadAdventurers]; //step 3
}

//step 4
-(void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    Adventurer *adventurer = [self.adventurers objectAtIndex:self.tableView.indexPathForSelectedRow.row];
    DetailViewController *viewController = segue.destinationViewController;
    viewController.adventurer = adventurer;
}

-(IBAction)unwindFromDetailViewController:(UIStoryboardSegue *)segue //step 4 created - 5 filled out
{
    DetailViewController *viewController = segue.sourceViewController;
    Raid *raid = [viewController createRaid];
    [raid addAdventurersObject:viewController.adventurer];

    [self.managedObjectContext save:nil];
    [self loadAdventurers];
}

#pragma mark - TableView DataSource

//step 3 - numberOfRowsInSection and cellForRow...
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.adventurers.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    Adventurer *adventurer = [self.adventurers objectAtIndex:indexPath.row];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"Cell"];

    cell.textLabel.text = adventurer.name;
    cell.detailTextLabel.text = @(adventurer.raids.count).description; //step 5
    return cell;

}










@end

