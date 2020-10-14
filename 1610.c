#include <stdio.h>
#include <stdlib.h>

struct Vertex
{
  int value;
  struct Vertex *next;
};

struct Vertex* add(struct Vertex* head, int value) 
{ 
    struct Vertex* nd = (struct Vertex*) malloc(sizeof(struct Vertex)); 
    nd->value  = value; 
    nd->next = head; 
    return nd;
}   

int cor[10005], tempo = 3;

int dfs(int v, struct Vertex** G)
{
  cor[v] = tempo - 2;
  struct Vertex *h = G[v];
  while(h != NULL)
  {
    int u = h->value;
    if(cor[u] < tempo - 2)
    {
      if(dfs(u, G) == 1)
        return 1;
    }
    else if(cor[u] == tempo - 2)
      return 1;
    h = h->next;
  }
  cor[v] = tempo - 1;
  return 0;
}

int main()
{
  int t, i;
  scanf(" %d", &t);
  while(t--)
  {
    struct Vertex* G[10005];
    int n, m;
    scanf(" %d %d", &n, &m);
    for(i = 1; i <= n; i++)
      G[i] = NULL;
    while(m--)
    {
      int u, v;
      scanf(" %d %d", &v, &u);
      G[v] = add(G[v], u);
    }
    int cyc = 0;
    for(i = 1; i <= n && cyc == 0; i++)
      if(cor[i] < tempo && dfs(i, G) == 1)
        cyc = 1;
    puts(cyc ? "SIM" : "NAO");
    tempo += 3;
  }
  
  return 0;
}