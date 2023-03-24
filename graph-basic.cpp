// graph implementation
#include<iostream>
#include<vector>
#include <queue>
using namespace std;

typedef pair<int, int> ii;
typedef vector <int> vi;
typedef vector <vi> vvi;

void dfs(vvi adjlist, bool visited[], int source)
{
	if(visited[source])
		return;
	visited[source]=true;
	cout<<"\nAt "<<source<<"th node ";  //or any process
	for(int i=0;i<adjlist[source].size();)
	{
		dfs(adjlist,visited,adjlist[source][i]);
		i++;
	}
}

 void bfs(vvi adjlist, int source)
 {
 	queue <int> q;
 	int n=adjlist.size();
 	bool visited[n];
 	for (int i = 0; i < n; i++)
 		visited[i]=false;
 	int dist[n] = {0};  //in case you need it

 	visited[source] = true;
 	dist[source] = 0;
 	q.push(source);
 	while(!q.empty())
 	{
 		int s= q.front();
 		q.pop();
 		cout<<"\nAt node "<<s;  //or any process
 		for(auto u : adjlist[s])
 		{
 			if(visited[u])
 				continue;
 			visited[u]=true;
 			dist[u]=dist[s]+1;
 			q.push(u);
 		}
 	}
 }

 void findcycle(vvi adjlist, bool visited[], int source,int prev)    //works only for digraphs
{
	if(visited[source] && prev!=source)
	{	
		cout<<"\nCycle found! at node "<<source;
		return;
	}
	visited[source] = true;
	cout<<"\nAt node "<<source;
	for(int i=0;i<adjlist[source].size();i++)
		findcycle(adjlist,visited,adjlist[source][i],source);
}

int mat[100][100];
void list_to_mat(vvi adjlist)
{
	int n=adjlist.size();
	//int mat[n][n]={0};
	for(int i=0;i<100;i++)
	{
		for(int j=0;j<100;j++)
			mat[i][j]=-1;
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{	
			mat[i][adjlist[i][j]]=1;  //or weight in place if 1
			if(mat[i][j]==-1)
				mat[i][j]=0;
		}
	}
}

void print_graphmatrix(int mat[][100], int size)
{
	for(int i=0;i<size;)
	{	
		cout<<endl;
		for(int j=0;j<size;j++)
		{
			if(mat[i][j]==-1)
			{
				i++;
				j=0;
				break;
			}
			cout<<mat[i][j]<<"  ";
		}
		if(mat[i][0]==-1)
		{	cout<<endl; break;}
	}
}



int main()
{
	cout<<"Enter the number of nodes: ";  //edges, it was earlier
	int n;
	cin>>n;
	vector <vi> adjlist;
	for(int i=0;i<n;i++)
	{
		vi adj;
		cout<<"\nEnter the degree of "<<i<<"th node: ";
		int ne;
		cin>>ne;
		int t;
		cout<<"Enter the adjacent nodes: ";
		for(int j=0;j<ne;j++)
		{
			cin>>t;
			adj.push_back(t);
		}
		adjlist.push_back(adj);
	}

	bool visited[n];
	for(int i=0;i<n;i++)
		visited[i]=false;
	//dfs(adjlist,visited,0);
	//bfs(adjlist,0);
	list_to_mat(adjlist);  //resulted matrix is stored in mat
	print_graphmatrix(mat,100);
	return 0;
}
