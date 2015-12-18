# include <iostream>
# include <algorithm>

using namespace std;
int MAX = 100000000;

struct AdjListNode{
	int dest;
	int weight;
	struct AdjListNode *next;
};


struct AdjList{
	struct AdjListNode *head;
};

struct Graph{
	int V;
	struct AdjList *array;
};

typedef struct AdjList AdjList;
typedef struct AdjListNode AdjListNode;
typedef struct Graph Graph;


AdjListNode* Create_node(int dest, int weight)
{
	AdjListNode *newnode = (AdjListNode*)malloc(sizeof(AdjListNode));
	newnode->dest = dest;
	newnode->weight = weight;
	newnode->next =NULL;

	return newnode;
}

Graph* create_graph(int V)
{
	cout<<"graph has been added";
	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->V = V;
	graph->array = (AdjList*)malloc(V*sizeof(AdjList));

	for(int i = 0;i<V;i++)
		graph->array[i].head = NULL;
	return graph;
}

void add_edge(Graph *graph, int src, int dest, int weight)
{
	AdjListNode *newnode = Create_node(dest, weight);

	newnode->next = graph->array[src].head;
	graph->array[src].head = newnode;

	newnode = Create_node(src, weight);
	newnode->next = graph->array[dest].head;
	graph->array[dest].head = newnode;
	return ; 
}


struct minHeapNode
{
int v;
int dist;
};

struct minHeap
{
int size;
int capacity;
int *pos;
struct minHeapNode **array;
};

typedef struct minHeapNode minHeapNode;
typedef struct minHeap minHeap;

minHeapNode* create_MinHeapNode(int v, int dist)
{
	minHeapNode *newnode = (minHeapNode *)malloc(sizeof(minHeapNode));
	newnode->v = v;
	newnode->dist = dist;
	return newnode;
}

minHeap* create_minHeap(int capacity)
{
	minHeap *minheap = (minHeap*)malloc(sizeof(minHeap));
	minheap->capacity = capacity;
	minheap->size = 0;
	minheap->array = (minHeapNode**)malloc(capacity*sizeof(minHeapNode*));
	minheap->pos = (int*)malloc(sizeof(int)*capacity);
	for(int i=0;i<capacity;i++)
		minheap->array[i] = NULL;
	return minheap;
}


void swapMinHeapNode(minHeapNode** a, minHeapNode** b)
{
	minHeapNode *temp = *a;
	*a = *b;
	*b = temp;
}

void minHeapify(minHeap *minheap, int idx)
{
	int smallest = idx, left = 2*idx +1, right = 2*idx +2;

	if(left < minheap->size && minheap->array[smallest]->dist > minheap->array[left]->dist)
		smallest = left;

	if(right < minheap->size && minheap->array[smallest]->dist > minheap->array[right]->dist)
		smallest = right;

	if(smallest!=idx)
	{
		//for changing the position of pointer to that vertex, in the position array..
		minHeapNode *smallestNode = minheap->array[smallest];
		minHeapNode *idxNode = minheap->array[idx];

		minheap->pos[smallestNode->v] = idx;
		minheap->pos[idxNode->v] = smallest;

		//ultimately swap the value of two nodes and repeat minheappfiy
		swapMinHeapNode(&minheap->array[idx], &minheap->array[smallest]);
		minHeapify(minheap, smallest);

	}
}

int isEmpty (minHeap *minheap)
{
return minheap->size ==0;
}


minHeapNode* extractMin(minHeap *minheap)
{
	if(isEmpty(minheap))
		return NULL;
	minHeapNode *root = minheap->array[0];
	minHeapNode *last = minheap->array[minheap->size - 1];
	minheap->array[0] = last;

	minheap->pos[root->v] = minheap->size -1;
	minheap->pos[last->v] = 0;
	
	--minheap->size;
	minHeapify(minheap, 0);

	return root;
}



void decreasekey(minHeap *minheap, int v, int dist)
{
	int i = minheap->pos[v];
	minHeapNode *minheapnode = minheap->array[i];

	minheapnode->dist = dist;
	//adjusting the node in the heap so that its new distance is adjusted
	while(i && minheap->array[i]->dist < minheap->array[(i-1)/2]->dist)
	{
		minheap->pos[minheap->array[i]->v] = (i-1)/2;
		minheap->pos[minheap->array[(i-1)/2]->v] = i;

		swapMinHeapNode(&minheap->array[i],&minheap->array[(i-1)/2]);

		i = (i-1)/2;
	}
}


int  isInHeap(minHeap *minheap, int v)
{
	if(minheap->pos[v] < minheap->size)
		return 1;
	return 0;

}

void printArr(int dist[], int n)
{
cout<<"VERTEX    DISTANCE FROM SOURCE\n";

for(int i = 0; i<n; i++)
	cout<<i<<"\t\t"<<dist[i]<<endl;
return ;
}


//dijkstra implementation for the adjacency list
void dijkstra(Graph *graph, int src)
{
	int V = graph->V;
	int dist[V];
	
	//create a minheap storing the edgeset
	minHeap *minheap = create_minHeap(V); 

	for(int i=0;i<V;i++)
	{
		dist[i] = MAX;
		minheap->array[i] = create_MinHeapNode(i , dist[i]);
		minheap->pos[i] = i;
	}

	dist[src] = 0;
	decreasekey(minheap, src, dist[src]);
	minheap->size = V;


	while(!isEmpty(minheap))
	{
		minHeapNode *smallest = extractMin(minheap);
		int u = smallest->v;
		//dist[u] = smallest->dist;
		int base = dist[u];
		AdjListNode *pointer = graph->array[u].head;
		
		while(pointer!=NULL)
		{
			int distance = pointer->weight + base;
			int v = pointer->dest;
			if(isInHeap(minheap,v) && dist[u]!=MAX && dist[v]>distance)
				{
					dist[v] = distance;

					decreasekey(minheap,v,distance);
				}
			pointer = pointer->next;
		}

	}

printArr(dist,V);

}




int main()
{
	int V =9;
	Graph *graph = create_graph(V);
	
	add_edge(graph,0,8,4);
	add_edge(graph,0,7,8);
	add_edge(graph,1,2,8);
	add_edge(graph,1,7,11);
	add_edge(graph,2,3,7);
	add_edge(graph,2,8,2);
	add_edge(graph,2,5,4);
	add_edge(graph,3,4,9);
	add_edge(graph,3,5,14);
	add_edge(graph,4,5,10);
	add_edge(graph,5,6,2);
	add_edge(graph,6,7,1);
	add_edge(graph,6,8,6);
	add_edge(graph,7,8,7);
	cout<<"all the edges have been added\n";

	dijkstra(graph,0);
	
	return 0;
}

































