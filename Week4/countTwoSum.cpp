/*
The goal of this problem is to implement a variant of the 2-SUM algorithm covered in this week's lectures.

The file contains 1 million integers, both positive and negative (there might be some repetitions!).This is your array of integers, with the
i th row of the file specifying the i thentry of the array.

Your task is to compute the number of target values t in the interval [-10000,10000] (inclusive) such that there are distinct numbers
x,y in the input file that satisfy x+y=t.

*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <fstream>


std::vector<long long> readFile(){
    std::vector<long long> s;
    std::ifstream file("/Users/berkeyavas/Desktop/code/GraphSearch-ShortestPath-DataStructures/Week4/algo1-programming_prob-2sum.txt");
    long long num;
    std::string line;
    while(getline(file, line, '\n')){
        num = std::stoll(line);
        s.push_back(num);
    }
    return s;
}


int count2Sum(std::vector<long long> s, int targetInterval){
	std::unordered_set<long long> se;
	std::vector<long long>::iterator front = s.begin();
	std::vector<long long>::iterator back = s.end() - 1;
	//std::cout << (*front) << " " << (*back);
	while(front != back){
		if((*front) + (*back) < -targetInterval)
			front++;

		else if((*front) + (*back) > targetInterval)
			back--;

		else
		{
			for(;;){
				se.insert((*front) + (*back));
				front++;
				if((*front) + (*back) > targetInterval)
					break;
			}
		}
	}
	return se.size();
}

int main(int argc, char const *argv[])
{
	// READ INTEGER STREAM FROM FILE AND PUT IN VECTOR
	// SORT VECTOR
	// PUT 2 ITERATOR, ONE FOR BEGINNING OF THE ARRAY(begin), OTHER ONE FOR END OF ARRAY(end)
	// WHILE NOT begin iter equals to end iter
	// IF begin+end < -10000 advance begin iter
	// ELSE IF begin+end > 10000 lower end iter
	// ELSE ITER UNTIL BEGIN+END>10000: ADD begin+end in hash table and advance begin iter
	// return hash table size
    auto s = readFile();
    std::sort(s.begin(), s.end());
    std::cout << count2Sum(s, 10000);
    return 0;
}
