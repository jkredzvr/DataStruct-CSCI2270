Justin Chin Summer 2017 

### Project Objectives 
- Implement algorithms for standard operations on common data structures and discuss the complexity of the operations.  
- Comment on the features of different traversal methods for graphs and other data structures.  
- Formulate and implement solutions to problems using fundamental graph algorithms e.g. depth-first and breadth-first search and a shortest-path algorithm.

Project Requirements
- Contains at least one class.
- Contains at least one graph and one other data structure that we’ve studied this semester.
- Class contain at least 7 public methods.

### Project Summary
The motivation for this project was to create an application that could "match" or pair up students from different colleges and majors based on their interests or knowledge of programming/artistic skill.  In our Virtual Reality/Augmented Reality student club, there are students from different backgrounds, schools, with varying levels of experiences and interests. This application aims to help match students, with varying qualities/traits, based on different matching thresholds. 

Each student or "Person" have properties or "Traits" regarding
Interests [VR, Film, Games, Education]
School [ATLAS, CS, Arts and Science, TAM]
Rank [Freshman, Sophomore, Junior, Senior, Graduate] 
Skills [Photoshop, Unity, Drawing, C# ...]

From the 4 different categories of Traits mentioned above, the application asks which ones you want to match students based two criterias:
1. Connection Criteria "Edge Criterion"
2. Compatibility Criteria "Weight Criterion"

From these network graphs, you could possibly identify/match:
- students with similar skills and similar interests 
- students with balanced/complementary skills/backgrounds (Artistic & Programming focused)
- students with similar interests

Each trait is given a weight to determine whether two people would be a good match as a team for different thresholds.  The following describes the weights for each Trait and thresholds and reasoning for determining a match.

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



Public methods allow for
- Adding a new student
- Seeding the graph network with randomized students
- Removing a student from the graph network
- Selecting the criteria for (Sorting the Groups, Connections, and Compatibility)
- Calculating the network of students based the selected criterion

### How to Run
This program needs:
1) A traits txt file delimited with commas (,)
   Each trait is described below...
   
2) A people txt file with each person's name on a new line.  For the time being the application only uses first names (one word) and there cannot by any duplicate names.



### Dependencies
No Dependencies

### System Requirements
Can be run from Linux terminal calling
./juch6102FinalProj_main traitfilename.txt peoplefilename.txt 

### Open issues/bugs
1.  No duplicate names
2.  Only takes 1 word names at the moment.  
3.  Does not take predefined people with Traits
