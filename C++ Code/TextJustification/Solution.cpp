/*============================================================================
 * https://leetcode.com/problems/text-justification/description/Given an array of words and a width maxWidth,
 * format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
 * You should pack your words in a greedy approach; that is, pack as many words as you can in each line.
 * Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
 * Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line
 * do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
 * For the last line of text, it should be left justified and no extra space is inserted between words.
*///==========================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
    	int lineCount = 0; //how many lines there are
    	int charCount = 0; //how many characters in a line there are
    	int wordIndex = 0; //cycle through words vector, keep track of words used up to each line

    	bool lastLine = false;

    	maxWidth++; //my code is written such that the maxwidth needs to be one greater than the actual max width

    	line firstLine;
    	firstLine.line = "";
    	line* currentLine = &firstLine;
    	while(wordIndex < (int)words.size() - 1){
			int i = 0; //this will be the offset for words in a new line
    		while(charCount <= maxWidth){
    			string newWord = words[wordIndex+i];
    			if(charCount + (int)newWord.size() <= maxWidth){
    				charCount += newWord.size() + 1; //+1 is for the minimum space that is necessary for each word
    				i++; //increase offset to next word
    				if(i+wordIndex > (int)words.size() -1){
    					lastLine = true;
    					break;
    				}
    			}else{
    				break; //break this while loop so next word is not added
    			}
    		}

    		if(lastLine){ //if this is the last line
    			int k;
    			for(k=0;k<i-1;k++){
    				currentLine -> line += words[wordIndex+k];
    				currentLine -> line += " ";
    			}
    			//add remaining spaces to last line
    			for(;k<maxWidth + 1 - 2*k;k++)
    				currentLine -> line += " ";
    		}else{
				//number of words in this line is i, can calculate how many spaces are needed for justifying
				int spaces, leftoverSpaces;
				if(i != 1){
					spaces = maxWidth - charCount + i - 1; //i-1 represents the spaces that were already accounted for in charCount
					leftoverSpaces = spaces%(i-1); //how many extra spaces are left
					spaces = spaces/(i-1); //min spaces per space between word
				}else{
					spaces = maxWidth - charCount;
					leftoverSpaces = 0;
				}
				//construct string
				for(int k=0;k<i-1;k++){
					currentLine -> line += words[wordIndex+k];

					//distribute spaces
					if(leftoverSpaces > 0){//if there are still extra spaces
						leftoverSpaces--; //place them in this space
						for(int j=0;j<spaces+1;j++)
							currentLine -> line += " ";
					}else{
						for(int j=0;j<spaces;j++) //else give the base number of spaces
							currentLine -> line += " ";
					}
				}
   			}
   			//now add final word with no spaces
   			currentLine -> line += words[wordIndex+i-1];

   			wordIndex+=i; //update wordIndex to new line
   			i = 0; //reset i for next line
   			charCount = 0;
   			currentLine -> nextLine = new line; //create a new line
   			currentLine = currentLine -> nextLine; //move on to nextLine
   			currentLine -> nextLine = nullptr;
   			lineCount++; //keep track of how many lines there are
   		}

    	//construct the return object
    	vector<string> justified = vector<string>();
    	currentLine = &firstLine;
    	for(int i=0;i<lineCount;i++){
    		justified.push_back(currentLine -> line);
    		currentLine = currentLine -> nextLine;
    	}

    	return justified;
    }
    //END fullJustify(vector<string>&, int)

private:
    typedef struct line{
    	string line;
    	struct line* nextLine;
    }line;
};

int main() {
	//string wordsArr[] = {"What","must","be","acknowledgment","shall","be"};
	string wordsArr[] = {"This","is","an","example","of","text", "justification."};


	vector<string> words;
	for(int i=0;i<7;i++){
		words.push_back(wordsArr[i]);
	}

	Solution solution;

	vector<string> justified = solution.fullJustify(words, 16);

	for(int i=0;i<(int)justified.size();i++){
		cout << justified[i] + "\n";
	}
	return 0;
}
