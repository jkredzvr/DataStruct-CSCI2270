#ifndef __graph_hpp_INCLUDED__
#define __graph_hpp_INCLUDED__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <stdlib.h>

enum Criteria { Skills, Interests, Rank, Department };

struct Trait{
  Criteria _Criteria;
  std::string Classification;
  std::string SkillName;
  int SkillWeight;

  void printDetails();
  //Struct constructor
  Trait(Criteria initCriteria, std::string initClassification, std::string initSkillName, int initSkillWeight):
    _Criteria(initCriteria), Classification(initClassification), SkillName(initSkillName), SkillWeight(initSkillWeight) {}
};


struct ConnectedPerson;

class Person {
  public:
    int WeightValue;

    int criteria1Weight;
    int criteria2Weight;

    std::string Name;
    std::vector<Trait> Department;
    std::vector<Trait> Rank;
    std::vector<Trait> Skills;
    std::vector<Trait> Interests;
    std::vector<ConnectedPerson> Connections;
    int DetermineWeight(std::string criteria);
    int DetermineWeight(std::string criteria, Person PersonB);
    bool DetermineConnection(std::string criteria, Person PersonB);
    Person(){};
    Person(std::string name, std::vector<Trait> department, std::vector<Trait> rank, std::vector<Trait> skills, std::vector<Trait> interests):
    Name(name), Department(department), Rank(rank), Skills(skills), Interests(interests) {}

};

struct ConnectedPerson {
  Person *person;
  int weight;
  ConnectedPerson(Person *_person, int _weight ): person(_person), weight(_weight) {}
};

struct TraitNode{
    Trait *trait;
    TraitNode *next;

    //struct constructor (default and parametrized)
    TraitNode(Trait *trait, TraitNode *initNext=nullptr):
      trait(trait), next(initNext){}
};

class TraitLinkedList{
  private:
    int numTraits;

  public:
    TraitNode *head;
    int getNumOfTraits(TraitNode *traitNode, int accumulator);
    Trait* getTraitAtIndex(TraitNode *traitNode, int atIndex, int currentIndex);
    void addTraitNode(Trait *trait, TraitNode *traitNode);
    TraitLinkedList(): numTraits(0), head(nullptr) {};
};

class Graph{

  private:
    std::vector <Person> People;


  public:
    TraitLinkedList SkillsTraitList;
    TraitLinkedList InterestsTraitList;
    TraitLinkedList RankTraitList;
    TraitLinkedList DepartmentTraitList;

    void insertPerson(std::string personName);
    void insertConnection(Person PersonA, Person PersonB, int weight);

    std::string name;
    void Init(char* traitfilename, char* personfilename);
    void GenerateTraitLinkedLists(char* traitfilename);
    void GeneratePeople(char* personfilename);
    Person GeneratePerson(std::string name);

    void GenerateGraph(std::string connectionCriteria, std::string weightCriteria);
    Criteria ConnectionCriteria;
    Criteria WeightCriteria;
    //trait hashTraitTable[];

    Graph(){};
};


#endif
