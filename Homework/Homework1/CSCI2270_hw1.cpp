// Justin Chin
// Assignment 1
// Course Instructor: Austin Holler

#include <iostream>
#include <fstream>
#include <typeinfo>
#include <stdlib.h>
using namespace std;

struct item {
	int price;
	string type;
	bool state;
};

item makeItem (string parsedString[]);
string stringParser(string rawString);
void SearchForItem(item newItem);
void removeItemFromIndex(item itemArray[], int removeIndex, int lastIndex);
void SortArray(string sortParameters[]);
bool swapVals(int indexFirst, int indexSecond, string sortParam);

item itemArray[100];
int	fileCounter = 0;
int searchCounter = 0;
int shiftCounter = 0;
int lastFilledIndex = 0;

int main(){
	//cout << "Enter file name to be read: ";
	string filename;
	cin >> filename;
	//cout << filename <<endl;

	string line;

	ifstream myfile;
	myfile.open(filename.c_str());

	if(myfile.is_open()){

        //read each line
		while(getline(myfile,line)){
            fileCounter++;

            string delimiter = ", ";
            int pos = 0;
            int arrayIndex = 0;
            string parsedLine[3];

            string token;
            while ((pos = line.find(delimiter)) != line.npos) {
                token = line.substr(0, pos);

                //read word in line
                parsedLine[arrayIndex] = token;
                arrayIndex++;
                line.erase(0, pos + delimiter.length());
            }
            //last read word in line
            parsedLine[arrayIndex] = line;

            //cout<<parsedLine[0]<<" "<< parsedLine[1]<<" "<<parsedLine[2]<<endl;

            //make new item
            item newItem = makeItem(parsedLine);
            cout<<"item read "<<newItem.type<<" cost "<<newItem.price<<endl;

            if(fileCounter ==1){
                //Fill first index automatically
                lastFilledIndex;
                itemArray[lastFilledIndex]=newItem;
            }
            else{
                //see if item exists in messageBoardItems...
                SearchForItem(newItem);
            }
		}

		//for(int i=0; i<= lastFilledIndex ; i++){
        //    cout << itemArray[i].type << "i:"<< i<< endl;
        //}

		cout<<"#"<<endl;

		//Sort the array
		string sortArrayParameters[5] = { "bike", "chicken", "dresser", "microwave", "truck" };

//       for(int i=0; i<33;i++)
//            cout<<itemArray[i].type<<endl;

        SortArray(sortArrayParameters);
        cout<<"#"<<endl;

        //cout<<"file read:"<<fileCounter<<endl;
        //cout<<"search array:"<<searchCounter<<endl;
        //cout<<"shift array:"<<shiftCounter<<endl;

		myfile.close();
	}
	else{
        cout<<"Couldn't find or open file"<<endl;
	}
	return 0;
}

void SearchForItem(item newItem){
    bool found = false;
    int searchIndex = 0;

    while (!found && searchIndex <= lastFilledIndex){

        //check if match
        if (itemArray[searchIndex].type == newItem.type && itemArray[searchIndex].state != newItem.state){
            if(itemArray[searchIndex].state == false){   // is the newItem a sell item?
                if(itemArray[searchIndex].price <= newItem.price){ //is sell <= buy price
                    found = true;
                    cout<<itemArray[searchIndex].type<<" "<<itemArray[searchIndex].price<<endl;

                    //cout<<itemArray[searchIndex].type<<" "<<itemArray[searchIndex].price <<" <=" <<newItem.price<<endl;
                    removeItemFromIndex(itemArray, searchIndex, lastFilledIndex);
                    shiftCounter++;     //shift array...
                    lastFilledIndex--;	//decrement lastFilled Index
                }
                else{

                }
            }
            else {                             //newItem is buy item
                if(itemArray[searchIndex].price >= newItem.price){//is buy >= sell price
                    found = true;
                    cout<<itemArray[searchIndex].type<<" "<<newItem.price<<endl;

                    //cout<<itemArray[searchIndex].type<<" "<<itemArray[searchIndex].price << " >=" <<newItem.price<<endl;
                    removeItemFromIndex(itemArray, searchIndex, lastFilledIndex);
                    shiftCounter++;    //shift array...
                    lastFilledIndex--; 	//decrement lastFilled Index
                }
                else{

                }

            }
        }
        searchIndex++;
        searchCounter++;

    }
    if (!found){//ie, no matches...
        lastFilledIndex++;
        itemArray[lastFilledIndex]=newItem;
        //cout<<"added:"<<newItem.type<<" "<< newItem.state<<" "<< newItem.price<<endl;

    }

    //cout<<"found: "<< found <<endl;
}


item makeItem (string parsedString[]){
	item newitem;
	newitem.price = atoi(parsedString[2].c_str());
	newitem.type = parsedString[0];
	if(parsedString[1] == "wanted")
		newitem.state = true;
	else
		newitem.state = false;	//selling
	return newitem;
}

void removeItemFromIndex(item itemArray[], int removeIndex, int lastIndex){
    for(int i=removeIndex; i<=lastIndex; i++){
        itemArray[i] = itemArray[i+1];

    }
}


void SortArray(string sortParameters[]){
    int lastIndex=0;
    for(int i=0 ; i<= 4; i++){
        //for each parameter
        string sortParam = sortParameters[i];

        //cout<<lastIndex<<endl;

        int startIndex = lastIndex;
        int startForLoop = lastIndex;
        for(startIndex; startIndex <= lastFilledIndex; startIndex++){
            //cout<< "looking at " << itemArray[startIndex].type << " i:" << startIndex << " vs " << itemArray[startIndex+1].type << " i:" << startIndex+1 <<endl;
            bool isValSwapped = swapVals(startIndex, startIndex+1, sortParam);
            if(isValSwapped){
                lastIndex = startIndex+1;
                int traverseIndex = startIndex;
                for(traverseIndex; traverseIndex > startForLoop ; traverseIndex--){
                    isValSwapped=swapVals(traverseIndex-1, traverseIndex, sortParam);
                    if(isValSwapped)
                        lastIndex = traverseIndex;
                }
            }
        }
    }

    for(int i=0; i<= lastFilledIndex; i++)
        cout<<itemArray[i].type<<endl;
    cout<<lastFilledIndex+1<<endl;

}
bool swapVals(int indexFirst, int indexSecond, string sortParam){
    if(itemArray[indexFirst].type == sortParam && itemArray[indexSecond].type == sortParam)
        //Do nothing iterate to the next for loop
        return false;
    if(itemArray[indexFirst].type == sortParam && itemArray[indexSecond].type != sortParam)
        //Do nothing iterate to the next for loop
        return false;
    if(itemArray[indexFirst].type != sortParam && itemArray[indexSecond].type != sortParam)
        return false;
    if(itemArray[indexFirst].type != sortParam && itemArray[indexSecond].type == sortParam){
        //cout<< "switching "<< itemArray[indexFirst].type << "i: " << indexFirst <<  " for " << itemArray[indexSecond].type << "i: " << indexSecond<<endl;
        item tempItem = itemArray[indexFirst];
        itemArray[indexFirst] = itemArray[indexSecond];
        itemArray[indexSecond] = tempItem;
        return true;
    }

}
