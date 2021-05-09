#include<bits/stdc++.h>
using namespace std;

// below variables are gloabal variable
char validChar[] = "ACGT";
vector<string> lst;
vector<string> finalLst;
int targetCount = 96;

void generateAll(int len){// generate a specific word with a fix length (len) variable and store it in a vector(lst)
    string str;

    for(int bit = 0; bit < (1 << 12); bit++){ // 2^12 times run it which is 4096
        str = "";
        for(int i = 0; i < len; i++){
            int cur = (bit >> (2 * i)) & 3; // (cur) variable stores the result of right shift operation on (bit) variable which is the position of random charactor in validChar vector
            str += validChar[cur]; // get the character using the (cur) value as the position of the character that you add to (str) from (validChar)
        }
        lst.push_back(str);
    }
}

int difference(const string &a, const string &b){ // calculate positional differences between two string
    int diff = 0;
    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]) diff++;
    }
    return diff;
}

//maintainsConstraint function compare candidate word with validList to see that this candidate word has atleast 3 positional difference
int maintainsConstraint(const vector<string> &validList, const string &candidate){
    for(int i = 0; i < validList.size(); i++){
        if(difference(validList[i], candidate) < 3){ // compare candidate word with validList to see that this candidate word has atleast 3 positional difference
            return 0; // if it has less than 3 positional difference, this returns 0 else return 1
        }
    }
    return 1;
}

int generateValidList(string start){
    vector<string> validList;

    validList.push_back(start);

    int count =1;
    for(int i = 0; (i < lst.size()) && (count <targetCount); i++){ // i should be less than the element in vector(lst) => (i < lst.size()) 
        if(maintainsConstraint(validList, lst[i])){ // maintainsConstraint function must return 0 => less than 3 positional difference or 1=> 3 or more positional difference 
            validList.push_back(lst[i]);
            count++;
        }
    }

    if(validList.size() == targetCount){
        for(int i = 0 ;i < targetCount; i++){
            finalLst.push_back(validList[i]);
         }
    }
    
    return count;
    
}

int main(){
    /* Algorithm Steps:
      Step 1: generateAll(6)
      Step 2: generateValidList(lst[i])
      Step 3: maintainsConstraint(validList, lst[i])
      Step 4: difference(validList[i], candidate) < 3 => 0 or 1
      Step 5: validList.push_back(lst[i])
      Step 6: finalLst.push_back(validList[i]) */
    
    generateAll(6);
    
    //for(int i=0;i< lst.size();i++)
    {
      //  int count = generateValidList(lst[i]); // generateValidList  function =>(goto) maintainsConstraint  function =>(goto) difference function


        int count = generateValidList("AACTCA"); // generateValidList  function =>(goto) maintainsConstraint  function =>(goto) difference function


        if(count == targetCount){ // count must be equal to 96 since targetCount is 96 which is the number of words requested
            for(int j=0 ; j < targetCount ; j++){
                cout << "String " << j+1 << " : " << finalLst[j]<< endl;
            }
            cout << endl; 
//            break;
            
        }
        
    }

    return 0;
}


