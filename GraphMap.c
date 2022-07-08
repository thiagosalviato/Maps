#define V 5
#define inf 9999

#include <stdio.h>
#include <locale.h>

int Dijkstra(float fork[V][V], int Vstart, int Vfinal);

int main()
{
    setlocale(LC_ALL, "English");
    
    // Student register: 21174346-5
    float fork[V][V] = {{0, 13.192, 6.596, 0, 0},
                        {0, 0, 0, 6.596, 46.172},
                        {0, 26.384, 0, 0, 19.788},
                        {0, 0, 0, 0, 26.384},
                        {0, 0, 0, 0, 0}};
    int Vstart = 1;
    int Vfinal = 5;
    int return, flag = 1;

    printf("Least cost path:\n");
    Dijkstra(fork, Vstart-1, Vfinal-1);
    
    printf("Other paths:\n");
    do {
        return = Dijkstra(fork, Vstart-1, Vfinal-1);
        
        if(return) {
            flag = 0;
        }
    } while(return);
    if(flag) {
        printf("\nthere are no more routes\n");
    }

    return 0;
}

int Dijkstra(float fork[V][V], int Vstart, int Vfinal)
{
    float cost[V][V], dist[V], pred[V];
    float visit[V], count, minimumdistance, weight = 0;
    int nextvertex, i, j, k, m, cont = 0;

    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            if(fork[i][j] == 0)
                cost[i][j] = inf;
            else
                cost[i][j] = fork[i][j];
    
    for(i = 0; i < V; i++) {
        dist[i] = cost[Vstart][i];
        pred[i] = Vstart;
        visit[i] = 0;
    }
    
    dist[Vstart] = 0;
    visit[Vstart] = 1;
    count = 1;
    
    while(count<V-1) {
        minimumdistance = inf;
        for(i = 0; i < V; i++)
            if(dist[i]<minimumdistance&&!visit[i]) {
                minimumdistance = dist[i];
                nextvertex = i;
            }
        
        visit[nextvertex] = 1;
        
        for(i = 0; i < V; i++)
            if(!visit[i])
                if(minimumdistance+cost[nextvertex][i]<dist[i]) {
                    dist[i] = minimumdistance+cost[nextvertex][i];
                    pred[i] = nextvertex;
                }
        
        count += 1;
    }

    if(Vfinal != Vstart) {
        j = Vfinal;
        
        if(pred[j] == 0) {
            return 0;
        }
        
        printf("\n%d", Vfinal+1);
        
        do {
            k = j;
            j = pred[j];
            printf(" <- %d", j+1);
            weight += fork[j][k];
            if(k == Vfinal || cont > 1) {
                if(k == 0) {
                    fork[j][k] = inf;
                    cont = 0;
                } else {
                    cont = 0;
                    for(m = 0; m < V; m++) {
                        if(fork[m][j] > 0) {
                            cont++;
                        }
                    }
                    if(cont < 2) {
                        fork[j][k] = inf;
                    }
                }
            }
        } while(j != Vstart);
        
        printf("\nweight: %.2f\n\n", weight);
    } else {
        printf("\nError: the source and destination vertices are the same\n\n");
    }
    
    return 1;
}