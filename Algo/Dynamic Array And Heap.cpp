#include <malloc.h>
template<class T> struct Heap
{
	T *arr;
	int sz,capacity;
	Heap(){arr= NULL;sz=0;capacity=0;}
	void capCheck()
	{
		if(sz+2>capacity)
		{
			arr=(T*)realloc(arr,(sz+1)*2*sizeof(T));
			capacity=(sz+1)*2;
		}
	}
	void refresh()
	{
		if(capacity >= (sz+1)*2)
		{
			int ncap=sz+1 + ((sz+1)>>1);
			arr=(T*) realloc(arr,ncap*sizeof(T));
			capacity=ncap;
		}
	}
	void clear()
	{
		free(arr);
		arr= NULL;sz=0;capacity=0;
	}
	void heapifyUp()
	{
		int node=sz;
		while( (node>>1) && arr[node]> arr[node>>1] )
		{
			swap(arr[node],arr[node>>1]);
			node>>=1;
		}
	}
	void heapifyDown()
	{
		int node=1;
		while( (node<<1)<=sz )
		{
			int max_i=node;
			if(arr[node<<1] > arr[max_i])max_i=node<<1;
			if((node<<1|1)<=sz && arr[node<<1|1] > arr[max_i])max_i=node<<1|1;
			if(max_i!=node)
			{
				swap(arr[node],arr[max_i]);
				node=max_i;
			}else break;

		}
	}
	void push(T v)
	{
		capCheck();
		arr[++sz]=v;
		heapifyUp();
	}
	void pop()
	{
		///ensure sz > 0
		arr[1]=arr[sz--];
		heapifyDown();
		refresh();
	}
	T front()
	{
		return arr[1];
	}

};
template<class T> struct vector
{
	T *arr;
	int sz,capacity;
	vector(){arr= NULL;sz=0;capacity=0;}
	vector(int n){arr= (T*)malloc(n*sizeof(T));sz=n;capacity=n;}
	void capCheck()
	{
		if(sz+1>capacity)
		{
			arr=(T*)realloc(arr,(sz+1)*2*sizeof(T));
			capacity=(sz+1)*2;
		}
	}
	void refresh()
	{
		if(capacity >= (sz<<1))
		{
			int ncap=sz+(sz>>1);
			arr=(T*) realloc(arr,ncap*sizeof(T));
			capacity=ncap;
		}
	}
	void clear()
	{
		free(arr);
		arr= NULL;sz=0;capacity=0;
	}
	void push_back(T val)
	{
		capCheck();
		arr[sz++]=val;
	}
	void pop_back()
	{
		///ensure sz > 0
		sz--;
		refresh();
	}
	T& operator[](int i){return arr[i];}
};

int main()
{

}