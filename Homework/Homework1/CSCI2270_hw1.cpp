
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

item itemArray[100];
int	fileCounter = 0;
int searchCounter = 0;
int shiftCounter = 0;
int lastFilledIndex = 0;

int main(){
	cout << "Enter file name to be read: ";
	string filename;
	cin >> filename;
	cout << filename <<endl;

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
                //cout << token << endl;
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
            //cout<<newItem.type<<" "<< newItem.state<<" "<< newItem.price<<endl;

            //see if item exists in messageBoardItems...
            SearchForItem(newItem);





		}


        cout<<"file read:"<<fileCounter<<endl;
        cout<<"search array:"<<searchCounter<<endl;
        cout<<"shift array:"<<shiftCounter<<endl;

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

                    cout<<itemArray[searchIndex].type<<" "<<itemArray[searchIndex].price <<" <=" <<newItem.price<<endl;
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
                    cout<<itemArray[searchIndex].type<<" "<<itemArray[searchIndex].price<<endl;

                    cout<<itemArray[searchIndex].type<<" "<<itemArray[searchIndex].price << " >=" <<newItem.price<<endl;
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
        cout<<"added:"<<newItem.type<<" "<< newItem.state<<" "<< newItem.price<<endl;

    }

    cout<<"found: "<< found <<endl;
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

//
//
//
////Code for searching an array
////Return -1 if not found
////if ! -1, then actual index found
//int searchArray(int inputArray[], int searchValue){
//	bool found = false;
//	int index = -1; //flag condition to determine if value found in array
//	int x=0;
//
//	int num_elements = sizeof( inputArray ) / sizeof( inputArray[0] );
//
//	while(!found && x < num_elements-1){
//		if(inputArray[x] == searchValue){
//			found = true;
//			index = x;
//		}
//		else{
//			x++;
//		}
//	}
//	return index;
//}
//
////Bubble Sort
//void bubbleSort(int arr[], int length){
//    for(int i=0; i < length; i++){
//        for(int j=0; j < length - i; j++){
//            if(arr[j] > arr[j+1]){
//                int swapVal = arr[j];
//                arr[j] = arr[j+1];
//                arr[j+1] = swapVal;
//            }
//        }
//    }
//}
//
////InsertionSort
//void insertionSort(int arr[], int length){
//    for( int i=0; i<length; i++){
//        int index = arr[i];
//        int j = i;
//
//        while (j>0 && arr[j-1]>index){
//            arr[j] = arr[j-1];
//            j=j-1;
//        }
//
//        arr[j]=index;
//    }
//}
//
//
//void quickSort(int arr[], int left, int right){
//	int i = left;
//	int j = right;
//	int pivot = arr[(left+right)/2];
//
//	while (i <= j){
//		while(arr[i] < pivot){
//			i++;
//		}
//		while(arr[j] > pivot){
//			j--;
//		}
//
//		if(i<=j){
//			//swap
//			int temp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = temp;
//
//			i++;
//			j--;
//		}
//	}
//	if(left < j){
//		quickSort(arr, left, j);
//
//	}
//	if(i < right){
//		quickSort(arr, i, right);
//	}
//}
