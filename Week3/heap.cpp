#include <iostream>
#include <vector>
#include <limits>

class heap
{
	void swim(int idx);
	void sink(int idx);
public:
	heap();
	std::vector<int> h;
	void insert(int i);
	int extractMin();
};


heap::heap(){
	h.push_back(INT_MIN); // arrary must be start at 1
}


void heap::insert(int i){
	h.push_back(i);
	swim(h.size()-1);

}


void heap::swim(int idx){
	// parent -> idx/2
	while(idx != 0 && h[idx/2] > h[idx]){
		int temp = h[idx/2];
		h[idx/2] = h[idx];
		h[idx] = temp;
		idx = idx/2;
	}
}



int heap::extractMin(){

	if (h.size() == 1)
	{
		h.pop_back();
		return h.back();
	}

	if (h.size() <= 0)
	{
		return INT_MIN;
	}

	int min = h[1];
	h[1] = h.back();
	h.pop_back();
	sink(1);
	return min;
}

void heap::sink(int idx){
	int l = 2*idx;
	int r = 2*idx+1;
	int smallest = idx;
	while(idx < h.size()){
		if (l < h.size() && h[l] < h[idx])
		{
			smallest = l;
		}

		if (r < h.size() && h[r] < h[smallest])
		{
			smallest = r;
		}

		if(smallest == idx){
			break;
		}

		int temp = h[idx];
		h[idx] = h[smallest];
		h[smallest] = temp;
		idx = smallest;
		l = idx*2;
		r = idx*2+1;
	}
}


int main(int argc, char const *argv[])
{
	heap h;
	h.insert(3);
	h.insert(5);
	h.insert(1);
	h.insert(-1);
	h.insert(8);
	h.extractMin();
	h.extractMin();
	for (std::vector<int>::iterator i = h.h.begin() + 1; i != h.h.end(); ++i)
	{
		std::cout << *i << " ";
	}
	return 0;
}