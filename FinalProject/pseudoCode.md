
Interface Trait
  str Classification
  str SkillName
  int SkillWeight


Hashmap 
// Weights between -4 and 4 to classify pairs who are Programmers (positively weighted) , Artistic (negatively weighted), or balanced ( near 0 )
//  Connection criterion will favor/connect pairs of people who are more balanced (weighted near 0)

class Skill : Trait 

| Classification | Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: |
| Programmer  | Java  |       1       |
| Programmer  | Python  |       2       |
| Programmer  | C#  |       3       |
| Programmer  | Unity  |       4       |
| Artist  | Drawing  |       -1       |
| Artist  | Illustrator  |       -2       |
| Artist  |  Photoshop |       -3       |
| Artist  |  Maya |       -4       |


//All weighted to be 0 since weight/connection criterion will be based on # of matched Interests between people

class Interests : Trait 

| Classification | Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: |
| Education  |   |       1       |
| Film  |   |       1       |
| Games  |   |       1       |
| Music  |   |       1       |
| 360 Video  |   |       1       |


//Weighted based on "experience".  Weight/connection criterion be based on sum of skill weight, connecting pairs with total Skill Weight > 4 (favoring teams with more experienced members) or alternatively total weights < 7 (balanced experienced teams) 

class Rank : Trait 

| Classification | Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: |
| Freshman  |   |       1       |
| Sophomore  |   |       2       |
| Junior  |   |       3       |
| Senior  |   |       4       |
| Graduate  |   |       5       |


// Weights between -2 and 2 to classify pairs who are more Programming oriented (positively weighted) , or Artistically Oriented (negatively weighted), or balanced ( near 0 )
//  Connection criterion will favor/connect pairs of people who are more balanced (weighted near 0)

class Department : Trait 

| Classification| Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: |
| CS  |   |       -2       |
| ATLAS  |   |      -1       |
| Arts and Science  |   |       1       |
| Film  |   |       2       |

```C++
  struct Trait{
  enum Criteria;
  string Classification;
  string SkillName;
  int SkillWeight;
}

enum Criteria { Department, Rank, Skills, Interests }

class Graph{
  private:
    vector <Person> People
    vector<Trait> Traits;

  public:
    void insertPerson(string personName)
    void insertConnection(Person PersonA, Person PersonB, weight)

    void Init()
    HashTable GenerateHashTable();
    int hashsum(Criteria , Trait, tableSize);
    Person GeneratePerson(string name);

    void GenerateGraph();
    Criteria ConnectionCriteria;
    Criteria WeightCriteria;
    trait hashTraitTable[];

}

void Graph::Init(){
  //Generate Traits HashMap
  GenerateHashTable();

  //Generate People
  //Read name file
    insertPerson(name);
}


class HashTable	{
 private:
   int tableSize
   hashTable
 public:
   Init()
   insert(value)
   search(value)
   delete(value)
}

void Graph::GenerateHashTable(){
  //create an empty Hashmap for each trait typ
  //read trait file

  // for each trait
    //construct new trait
    // first word  matched to an enum
    // enum Criteria;
    //string Classification;
    //string SkillName;
    //int SkillWeight;

    //determine trait type
    //How/where to add the trait so we can know the size of it and randomly select one...
    int index;
    index = hashsum(trait);
    hashTraitTable[index] =  trait;
}

int Map::hashsum(Trait trait, int tableSize){
  string key;
  sum = 0
  case: Department || Interests || Rank
    key = trait.Classification;
  case: Skills
    key = trait.SkillName;

  for x=0 to key.end
    sum = sum + key[x].ASCII2Int
  return sum;
}



Person Graph::GeneratePerson(string name){
  // randomly assign 1 department trait
  vector<Trait> Department;

  // randomly assign 1 rank trait
  vector<Trait> Rank;

  //randomly assign 2-4 skill traits
  vector<Trait> Skills

  //randomly assign 1-4 Interest traits
  vector<Trait> Interests

  Person newPerson = Person(name, Department, Rank, Skills)
  return newPerson
}

vector<*Trait> Graph::findTrait(string TraitName){
  vector<*Trait> foundTraits;

  vector <int>::iterator i = Traits.begin ();

   while (i != Traits.end ()){
       cout << *i.Classification << endl;
       ++ i;
   }

   i = find (Traits.begin (), Traits.end (), TraitName);

   if (i != v.end ())
   {
       int nPosition = distance (v.begin (), i);
       cout << "Value "<< *i;
       cout << " found in the vector at position: " << nPosition << endl;
   }




}


void Graph::insertPerson( string personName ) {
  bool found = false
  for x = 0 to People.end {
    if(People[x].name == personName){
      found = true;
      break;
    }
  }
  if(!found){
    Person newPerson = GeneratePerson(personName);
    People.push_back(newPerson)
  }
}

void Graph::insertConnection (Person personA, Person personB, int weight ){
  //Check that personA and personB exists and not ==
  for(x=0 ; x < People.size() ; x++) {
    if(People[x].key == personA ){
      for(y=0 ; 7 < People.size() ; y++){
        if(People[y].key == personB && x!=y){
          ConnectedPerson.person = &personB;
          ConnectedPerson.weight = weight;
          People[x].Connections.push_back(ConnectedPerson);
        }
      }
    }
  }
}


void Graph::GenerateGraph(){
  //check that ConnectionCriteria, WeightCriteria, People, Traits are all non zero

  //Generate Adjacency Lists

  for each person in People
    //clear Connections
    PersonA.Connections.clear();
    for each person in People
      if PersonA == personB
        continue
      else if
          PersonA.DetermineWeight(WeightCriteria)
          if(PersonA.DetermineConnection(ConnectionCriteria))
            insertConnection(PersonA, PersonB, PersonA.WeightValue)
          else
            continue;
}



class Person {
  int WeightValue;
  string Name;
  vector<Trait> Department;
  vector<Trait> Rank;
  vector<Trait> Skills
  vector<Trait> Interests
  vector<ConnectedPerson> Connections
  void DetermineWeight(Criteria criteria);
  bool DetermineConnection(Criteria criteria);

  Person(string name, vector<Trait> department, vector<Trait> rank, vector<Trait> skills, vector<Trait> interests);

}

struct ConnectedPerson {
  Person *person;
  int weight;
}


Person::Person(string name, vector<Trait> department, vector<Trait> rank, vector<Trait> skills, vector<Trait> interests){
  Name = name;
  WeightValue = 0;
  Department = department;
  Rank = rank;
  Skills = skills;
  Interests = interests;
}

void Person::DetermineWeight(Criteria criteria){
  switch (criteria){
    case: Department
		  this.WeightValue = this.Department.SkillWeight;
  	case: Skills
  		int totalSkillWeight = 0
  		for each Trait in Skills
  			totalSkillWeight += Trait.SkillWeight
  		this.WeightValue = this.Department.SkillWeight;
  	case: Rank
  		this.WeightValue  = this.Rank.SkillWeight;
  }
}

void Person::DetermineWeight(Criteria criteria, Person personB){
  int matches;
  for this.Interest
    for  personB.interest
      if interest == interest
        matches ++
  this.WeightValue = matches;
}

bool Person::DetermineConnection(Criteria criteria, Person personB){
  switch (criteria){
    case: Skill
  	 	if ( this.weightValue + personB.weightValue >= -2 || <= 2 )
  			//CONNECTED
  			return true;
  		else
  			//Not Connected
        return false;
  	case: Interests
      if ( this.weightValue >= 2 )
        CONNECTED
        return;
      else
        Not Connected
        return;

    case: Rank
      if ( this.weightValue + personB.weightValue >= 5 || <= 10 )
        CONNECTED
        return;
      else
        Not Connected
        return;

  	case: Department
    if ( this.weightValue + personB.weightValue >= -1 || <= 1 )
      CONNECTED
      return;
    else
      Not Connected
      return;
  }
}

  
    
  
  
    
    
```


