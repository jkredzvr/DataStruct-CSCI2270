#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include "Graph.hpp"
using namespace std;

vector<string> criterias;

void NetworkMap(Graph graph){
  bool match = false;
  string chosenCriteria;
  string connectionCriteria;
  string weightCriteria;

  while(!match){
    cout << "Enter criteria for determining connecting/pairing people" << endl;
    cout << "Department, Rank, Interests, Skills \n"  << endl;

    cin >> chosenCriteria;

    for (int i=0; i< criterias.size(); i++ ){
      if( 0 == strcmp( (chosenCriteria).c_str() , (criterias[i]).c_str()))
        match=true;
    }
    if(!match)
      cout << "Enter one of the criteria options above.\n" << endl;
  }
  connectionCriteria = chosenCriteria;
   cout<< "\nYou have chosen: " << connectionCriteria << endl << endl;


  match = false;

  while(!match){
    cout << "Enter criteria for determining the weights of paired people" << endl;
    cout << "Department, Rank, Interests, Skills \n" << endl;

    cin >> chosenCriteria;


    for (int i=0; i< criterias.size(); i++ ){
      if( 0 == strcmp( (chosenCriteria).c_str() , (criterias[i]).c_str()))
        match=true;
    }
    if(!match)
      cout << "Enter one of the criteria options above.\n" << endl;
  }
  weightCriteria= chosenCriteria;
  cout<< "\nYou have chosen: " << weightCriteria << endl << endl;

  graph.GenerateGraph(connectionCriteria,weightCriteria);
}

int main(int argc, char *argv[]){
  //1st arguement is filename
  char* traitfilename = argv[1];
  char* personfilename = argv[2];

  criterias = vector<string>();
  criterias.push_back("Department");
  criterias.push_back("Rank");
  criterias.push_back("Interests");
  criterias.push_back("Skills");


  if (traitfilename != "")
  	cout << "TraitfileName: " <<  traitfilename << endl;
  else{
    cout << "require trait file " << endl;
    return 0;
  }

  if (personfilename != "")
  	cout << "PersonfileName: " <<  personfilename << endl;
  else{
    cout << "require person file " << endl;
    return 0;
  }

  Graph newGraph = Graph();


  newGraph.Init(traitfilename, personfilename);

  /*
  for(int i=0 ; i < numTraits ; i++ ){
    Trait *selectedTrait = newGraph.SkillsTraitList.getTraitAtIndex(newGraph.SkillsTraitList.head, i, 0);
    if(selectedTrait == nullptr){
      cout << "didnt find trait at index: " <<  i << endl;
    }
    else{

      cout << "Selected trait: " << selectedTrait->_Criteria << selectedTrait->Classification << selectedTrait->SkillName << selectedTrait->SkillWeight << endl;
    }
  }


  for(int i=0 ; i < numTraits1 ; i++ ){
    Trait *selectedTrait = newGraph.DepartmentTraitList.getTraitAtIndex(newGraph.DepartmentTraitList.head, i, 0);
    if(selectedTrait == nullptr){
      cout << "didnt find trait at index: " <<  i << endl;
    }
    else{

      cout << "Selected trait: " << selectedTrait->_Criteria << selectedTrait->Classification << selectedTrait->SkillName << selectedTrait->SkillWeight << endl;
    }
  }

  for(int i=0 ; i < numTraits2 ; i++ ){
    Trait *selectedTrait = newGraph.RankTraitList.getTraitAtIndex(newGraph.RankTraitList.head, i, 0);
    if(selectedTrait == nullptr){
      cout << "didnt find trait at index: " <<  i << endl;
    }
    else{

      cout << "Selected trait: " << selectedTrait->_Criteria << selectedTrait->Classification << selectedTrait->SkillName << selectedTrait->SkillWeight << endl;
    }
  }

  for(int i=0 ; i < numTraits4 ; i++ ){
    Trait *selectedTrait = newGraph.InterestsTraitList.getTraitAtIndex(newGraph.InterestsTraitList.head, i, 0);
    if(selectedTrait == nullptr){
      cout << "didnt find trait at index: " <<  i << endl;
    }
    else{

      cout << "Selected trait: " << selectedTrait->_Criteria << selectedTrait->Classification << selectedTrait->SkillName << selectedTrait->SkillWeight << endl;
    }
  }

 */

  bool exitProgram = false;

  while(!exitProgram){
    cout << "======Main Menu======" << endl;
    cout << "1. Generate Network Map" << endl;
    cout << "2. Quit \n " << endl;
    cout << "Enter the number to execute the command. \n" << endl;

    int menuChoice;

    cin >> menuChoice;

    //switch statement ...
    switch(menuChoice) {
        case 1 : {
          NetworkMap(newGraph);
          break;
        }
        case 2: {
          exitProgram = true;
          break;
       }
    }
  }

  return 0;
}
