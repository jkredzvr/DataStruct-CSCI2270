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

Each student or "Person" have properties or "Traits" regarding:

- Interests [VR, Film, Games, Education]
- School [ATLAS, CS, Arts and Science, TAM]
- Rank [Freshman, Sophomore, Junior, Senior, Graduate] 
- Skills [Photoshop, Unity, Drawing, C# ...]

From the 4 different categories of Traits mentioned above, the application asks which ones you want to match students based two criterias:
1. Connection Criteria "Edge Criterion"
2. Compatibility Criteria "Weight Criterion"

From these network graphs, you could possibly identify/match:
- students with similar skills and similar interests 
- students with balanced/complementary skills/backgrounds (Artistic & Programming focused)
- students with similar interests

Each trait is given a weight to determine whether two people would be a good match as a team for different thresholds.  The following describes the weights for each Trait and thresholds and reasoning for determining a match.


#### Skill Trait 

Weights between -4 and 4 to classify pairs who are Programmers (positively weighted) , Artistic (negatively weighted), or balanced ( near 0 ).  (Positive/Negative values were used to differentiate Programming and Artistically weighted pairs, and not based on my view of Programmers vs Artists) 

Pairs are matched/connect if the sum of their Skill Weights are near 0 ( -2 < sum < 2 )

| Trait Type | Classification | Skill Name | Skill Weight |
| :-------------:| :-------------: | :-------------: | :-------------: |
| Skill | Programmer  | Java  |       1       |
| Skill | Programmer  | Python  |       2       |
| Skill | Programmer  | C#  |       3       |
| Skill | Programmer  | Unity  |       4       |
| Skill | Artist  | Drawing  |       -1       |
| Skill | Artist  | Illustrator  |       -2       |
| Skill | Artist  |  Photoshop |       -3       |
| Skill | Artist  |  Maya |       -4       |


#### Interests Trait 

All interests are weighted to be 1 since pairs will be matched based on # of matched Interests between people.  Threshold for a matched pair is at least 2 same interests.

| Trait Type | Classification | Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: | :-------------: |
| Interests | Education  |   |       1       |
| Interests | Film  |   |       1       |
| Interests | Games  |   |       1       |
| Interests | Music  |   |       1       |
| Interests | 360 Video  |   |       1       |

#### Rank Trait 

Rank represents the current progress in school, with higher weights for upper classmen to represent more "experience". Matched pairs can be determined based on the sum of their weights, with sum  of Skill Weight > 8 (matching teams with more experienced members) or alternatively sum of Skill Weight < 7 (balance of upper and under classmen pairs) 


| Trait Type | Classification | Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: | :-------------: |
| Rank | Freshman  |   |       1       |
| Rank | Sophomore  |   |       2       |
| Rank | Junior  |   |       3       |
| Rank | Senior  |   |       4       |
| Rank | Graduate  |   |       5       |

#### Department Trait 

School department traits are weighted between -2 and 2 to classify pairs who are more Programming oriented (positively weighted) , or Artistically Oriented (negatively weighted), or balanced ( near 0 ).
Pairs are matched/connect if the sum of their Skill Weights are near 0 ( -2 < sum < 2 ) for more balanced teams.

| Trait Type | | Classification| Skill Name | Skill Weight |
| :-------------: | :-------------: | :-------------: | :-------------: |
| Department | CS  |   |       -2       |
| Department | ATLAS  |   |      -1       |
| Department | Arts and Science  |   |       1       |
| Department | Film  |   |       2       |



#### Public methods allow for
- Selection of criterion for weights and connections
- Seeding the graph network with randomized students with traits
- Calculating the network of student's connections and their weight calculations based the 2 selected criterion
- Printing information about the student's trait
- Generating Trait class from a txt file delimited with ,

### How to Run
This program needs:
1) A traits txt file delimited with commas (,)
   Each trait is described below...
   
2) A people txt file with each person's name on a new line.  For the time being the application only uses first names (one word) and there cannot by any duplicate names.

In a linux terminal enter,
./juch6102FinalProj_main traitfilename.txt peoplefilename.txt 
with the juch6102FinalProj_main.o , traitfilename.txt, peoplefilename.txt, in the same directory

### Dependencies
No Dependencies

### System Requirements
Can be run from Linux terminal calling
./juch6102FinalProj_main traitfilename.txt peoplefilename.txt 

### Open issues/bugs
1.  No duplicate names
2.  Only takes 1 word names at the moment.  
3.  Does not take predefined people with Traits
