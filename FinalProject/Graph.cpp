#include "Graph.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;


// Splits string by delim into vector of indivisual words
vector<string> split(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
};


/* Graph methods*/
void Graph::Init(char* traitfilename, char* personfilename){

  //Generate Trait Linked lists
  GenerateTraitLinkedLists(traitfilename);

  //Generate People
  GeneratePeople(personfilename);


  for (int i=0; i < People.size() ; i++){
    cout << People[i].Name << endl;
    for(int j=0; j < People[i].Department.size() ; j++){
        People[i].Department[j].printDetails();
    }

    for(int j=0; j < People[i].Rank.size() ; j++){
        People[i].Rank[j].printDetails();
    }
    for(int j=0; j < People[i].Interests.size() ; j++){
        People[i].Interests[j].printDetails();
    }
    for(int j=0; j < People[i].Skills.size() ; j++){
        People[i].Skills[j].printDetails();
    }
  }
}


/* Trait Methods */

//Tail Recurive Linked List methods
int TraitLinkedList::getNumOfTraits(TraitNode *traitNode, int accumulator){
  if(traitNode == nullptr){
    return accumulator;
  }
  else{
    getNumOfTraits(traitNode->next, (accumulator + 1) );
  }
};

void Trait::printDetails(){
  cout << "Criteria: " << _Criteria << ", Classification: " << Classification <<  ", SkillName: " << SkillName <<  ", SkillWeight: " << SkillWeight << endl;
}

Trait* TraitLinkedList::getTraitAtIndex(TraitNode *traitNode, int atIndex, int currentIndex){
  if(traitNode == nullptr){
    return nullptr;
  }
  else{
    if(atIndex == currentIndex) {
	     return traitNode->trait;
    }
    else{
	     getTraitAtIndex(traitNode->next, atIndex, currentIndex+1);
    }
  }
};

void TraitLinkedList::addTraitNode(Trait *trait, TraitNode *traitNode){
  if(head == nullptr){
    TraitNode *newTraitNode = new TraitNode(trait, nullptr);
    head = newTraitNode;
    return;
  }
  if(traitNode->next == nullptr){
    TraitNode *newTraitNode = new TraitNode(trait, nullptr);
    traitNode-> next = newTraitNode;
    return;
  }
  else{
    addTraitNode(trait, traitNode->next);
  }
};


//Creates TraitLinked list from raw trait file
void Graph::GenerateTraitLinkedLists(char* traitfilename){
  //Initiallize empty LinkedLists
  SkillsTraitList = TraitLinkedList();
  InterestsTraitList = TraitLinkedList();
  RankTraitList = TraitLinkedList();
  DepartmentTraitList = TraitLinkedList();

  //read trait file
  ifstream myfile;
  myfile.open(traitfilename);

  //parsed new line
  string line;

  if( myfile.is_open() ){
    string classification;
    string skillName;
    int skillWeight;
    Criteria traitCriteria;

    //read each new line and create a Trait
    while(getline(myfile, line)){

      cout<< line << endl;
      //Parse each line delimited by ,
      vector <string> fields = split( line, ',' );
      classification = fields[1];
      if(fields[2] == ""){
         skillName = "NULL";
      }
      else{
         skillName = fields[2];
      }
      skillWeight = stoi( fields[3] );

      switch (stoi(fields[0])) {
        case 1: {
          traitCriteria = Skills;
          Trait *newTrait = new Trait(traitCriteria, classification, skillName, skillWeight);
	        SkillsTraitList.addTraitNode(newTrait, SkillsTraitList.head);
	        break;
	      }
        case 2: {
          traitCriteria = Interests;
          Trait *newTrait = new Trait(traitCriteria, classification, skillName, skillWeight);
          InterestsTraitList.addTraitNode(newTrait, InterestsTraitList.head);
          break;
	      }
        case 3: {
          traitCriteria = Rank;
          Trait *newTrait = new Trait(traitCriteria, classification, skillName, skillWeight);
          RankTraitList.addTraitNode(newTrait, RankTraitList.head);
          break;
	        }
        case 4: {
          traitCriteria = Department;
          Trait *newTrait = new Trait(traitCriteria, classification, skillName, skillWeight);
          DepartmentTraitList.addTraitNode(newTrait, DepartmentTraitList.head);
          break;
	       }
      }
    }
  }
  else {
    cout << "Could not open file\n";
  }
}

//Creates people with traits to be entered into People vector from raw people file (file with each person's name)
void Graph::GeneratePeople(char* personfilename){
  //read person file
  ifstream myfile;
  myfile.open(personfilename);

  //parsed new line
  string line;

  if( myfile.is_open() ){
    //read each new line and create a Trait
    while(getline(myfile, line)){

      cout<< line << endl;
      vector <string> fields = split( line, ',' );
      //Parse each line delimited by ,
      string name = fields[0];
      insertPerson(name);
    }
  }
  else {
    cout << "Could not open file\n";
  }
}

//Method to create a person instance with randomized Traits and add to People vector
void Graph::insertPerson( string personName ) {
  bool found = false;
  for (int i = 0 ; i < People.size(); i++ ) {
    if(People[i].Name == personName){
      found = true;
      cout << "person already in list" << endl;
      break;
    }
  }
  if(!found){
    Person newPerson = GeneratePerson(personName);
    People.push_back(newPerson);
  }
}

// Generates an instance of Person with randomized traits
Person Graph::GeneratePerson(string name){
  int sizeList;
  int randnum;
  // randomly assign 1 department trait
  vector<Trait> Department = vector<Trait>();
  sizeList = DepartmentTraitList.getNumOfTraits(DepartmentTraitList.head , 0);
  randnum = (rand() % sizeList);
  Trait deptTrait = *DepartmentTraitList.getTraitAtIndex( DepartmentTraitList.head,randnum, 0);
  Department.push_back(deptTrait);


  // randomly assign 1 rank trait
  vector<Trait> Rank = vector<Trait>();
  sizeList = RankTraitList.getNumOfTraits(RankTraitList.head , 0);
  randnum = (rand() % sizeList);
  Trait rankTrait = *RankTraitList.getTraitAtIndex( RankTraitList.head, randnum, 0);
  Rank.push_back(rankTrait);

  //randomly assign 1-4 skill traits
  vector<Trait> Skills = vector<Trait>();
  sizeList = SkillsTraitList.getNumOfTraits(SkillsTraitList.head , 0);
  int randNumSkills = rand() % 4 + 1; //1-3 skills


  for( int i=0 ; i <= randNumSkills ; i++){
    bool duplicate = true;
    Trait *skillTrait = nullptr;
    while (duplicate){
      duplicate = false;
      skillTrait = SkillsTraitList.getTraitAtIndex(  SkillsTraitList.head , rand() % sizeList, 0);

      for(int  i=0 ; i < Skills.size(); i++){
          if( Skills[i].SkillName == skillTrait->SkillName){
            duplicate = true;
          }
      }
    }
    Skills.push_back(*skillTrait);
  }


  //randomly assign 1-4 Interest traits
  vector<Trait> Interests = vector<Trait>();
  sizeList = InterestsTraitList.getNumOfTraits(InterestsTraitList.head, 0);
  randNumSkills = rand() % 4 + 1; //1-3 skills

  for( int i=0 ; i <= randNumSkills ; i++){
    bool duplicate = true;
    Trait *interestTrait = nullptr;
    while (duplicate){
      duplicate = false;
      interestTrait = InterestsTraitList.getTraitAtIndex( InterestsTraitList.head, rand() % sizeList, 0);

      for(int  i=0 ; i < Interests.size(); i++ ){
          if( Interests[i].Classification == interestTrait->Classification){
            duplicate = true;
          }
      }
    }
    Interests.push_back(*interestTrait);
  }

  Person newPerson = Person(name, Department, Rank, Skills, Interests);
  return newPerson;
}

void Graph::GenerateGraph(string connectionCriteria, string weightCriteria){
  cout<< "Connection Criteria: " << connectionCriteria << ", Weight Criteria: " << weightCriteria << endl;

  //Generate Adjacency/Connections Lists
  Person PersonA;
  Person PersonB;
  for (int i=0; i < People.size() ; i++){
    PersonA = People[i];
    cout << PersonA.Name << endl;

    //clear all previous connections
    PersonA.Connections.clear();

    for(int j=0; j < People.size() ; j++){
      PersonB = People[j];
      if (PersonA.Name == PersonB.Name)
        continue;
      else {
        //Check if person A and B should be connected based on connection Criteria

        if(connectionCriteria != "Interests"){
          PersonA.criteria1Weight =  PersonA.DetermineWeight(connectionCriteria);
          PersonB.criteria1Weight = PersonB.DetermineWeight(connectionCriteria);
        }
        else{
          PersonA.criteria1Weight = PersonA.DetermineWeight(connectionCriteria, PersonB);
        }

        if( PersonA.DetermineConnection(connectionCriteria, PersonB) && connectionCriteria != "Interests"){

          //Calculate weight Criteria's weight
          PersonA.criteria2Weight = PersonA.DetermineWeight(weightCriteria);
          PersonB.criteria2Weight = PersonB.DetermineWeight(weightCriteria);
          cout << PersonA.Name << " is matched with " << PersonB.Name << " with weight of " << PersonA.criteria2Weight << "+" << PersonB.criteria2Weight << endl;
          insertConnection(PersonA, PersonB, (PersonA.criteria2Weight + PersonB.criteria2Weight));
        }
        else if(PersonA.DetermineConnection(connectionCriteria, PersonB) && connectionCriteria == "Interests") {
          PersonA.criteria2Weight = PersonA.DetermineWeight(connectionCriteria, PersonB);
          cout << PersonA.Name << " is matched with " << PersonB.Name << " with weight of " << PersonA.criteria2Weight << endl;
          insertConnection(PersonA, PersonB, PersonA.criteria2Weight);
        }
        else
          continue;
      }
    }
  }
}

//Method to verify personA and personB exists before adding to adjacency/connection vector
void Graph::insertConnection (Person personA, Person personB, int weight ){
  //Check that personA and personB exists in People vector
  for(int i=0 ; i < People.size() ; i++) {
    if(People[i].Name == personA.Name ){
      for(int j=0 ; j < People.size() ; j++){
        if(People[j].Name == personB.Name && i!=j){
          Person *personPtr =  &personB;
          ConnectedPerson connection = ConnectedPerson(personPtr, weight);
          People[i].Connections.push_back(connection);
          return;
        }
      }
    }
  }
}


/* Person class */
int Person::DetermineWeight(string criteria){
  //update person's weight value
  if( criteria == "Department") {
    return Department[0].SkillWeight;
  }
  else if( criteria == "Skills") {
    int totalSkillWeight = 0;
    for(int i =0 ; i < Skills.size() ; i++ ){
      totalSkillWeight += Skills[i].SkillWeight;
    }
    return totalSkillWeight;
  }
  else if( criteria == "Rank") {
    return Rank[0].SkillWeight;
  }
  else{
    cout << "dont recognize this criteria " << criteria << endl;
    return 0;
  }
}

//Method to calculate weights for number of matched interests
int Person::DetermineWeight(string criteria, Person personB){
  int matches=0;
  for (int i=0; i < Interests.size(); i++){
    for (int j=0; j < personB.Interests.size(); j++){
      if (Interests[i].Classification ==  personB.Interests[j].Classification)
        ++matches;
    }
  }
  return matches;
}

bool Person::DetermineConnection(string criteria, Person personB){
  //update person's weight value
  int totalWeight;
  if ( criteria == "Department") {
    totalWeight = (criteria1Weight + personB.criteria1Weight);
    if ( totalWeight  >= -1 && totalWeight <= 1 )
      return true;
    else
      return false;
  }
  else if( criteria == "Skills") {
    totalWeight = criteria1Weight + personB.criteria1Weight;
    if ( totalWeight >= -2 && totalWeight <= 2 )
      return true;
    else
      return false;
  }

  //Balanced team based on matching Upperclassmen and Underclassmen
  else if( criteria == "Rank") {
    totalWeight = criteria1Weight + personB.criteria1Weight;
    if ( totalWeight >= 6 && totalWeight <= 8 )
      return true;
    else
      return false;
  }
  else if( criteria == "Interests") {
    if ( criteria1Weight > 2 )
      return true;
    else
      return false;
  }
  else{
    cout << "dont recognize this criteria " << criteria << endl;
    return false;
  }
}
