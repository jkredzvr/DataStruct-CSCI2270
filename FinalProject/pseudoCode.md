
Interface Trait
  str Classification
  str SkillName
  int SkillWeight


Hashmap 
// Weights between -4 and 4 to classify pairs who are Programmers (positively weighted) , Artistic (negatively weighted), or balanced ( near 0 )
//  Connection criterion will favor/connect pairs of people who are more balanced (weighted near 0)

class Rank : Trait 

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

| Classification| Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: |
| CS  |   |       -2       |
| ATLAS  |   |      -1       |
| Arts and Science  |   |       1       |
| Film  |   |       2       |

```C
  enum Criterion { Department, Rank, Skills, Interests } 
  
  struct Trait {
    str Classification
    str SkillName
    int SkillWeight
  }
  
  
  
  class NetworkGraph {
    Criterion ConnectionCriteria
    Criterion WeightCriteria
    GenerateGraph()
    Array[Person] GroupMemebers
  }
  
  NetworkGraph::GenerateGraph()
    for each member in GroupMembers
      member.
  
  
  class Person{
    public: 
      DetermineWeight(Criterion)
      DetermineConnection(Person, Criterion)
      str Name
      Trait Rank
      Array[Trait] Skills
      Array[Trait] Interests
      Trait Department
    
    private: 
      int WeightValue
      vector[Person] Connections
      ClearConnections()
      AddConnection()
  }
  
    
  
  
    
    
```


