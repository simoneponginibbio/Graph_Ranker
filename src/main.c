#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define min(x, y) ((x) <= (y) ? (x) : (y))

typedef struct graph
{
    int number;
    int sumPaths;
    struct graph *next;
} Graph;

int getInt()
{
    int num = 0;
    char c = getchar();
    while (c != ' ' && c != '\n' && c != ',' && c != EOF)
    {
        num *= 10;
        num += (c - '0');
        c = getchar();
    }
    return num;
}

int minPaths(int d)
{
    int min, nodes[d], flag[d], matrix[d][d], cost, n = 0, sum = 0, nod = 0;
    for (int i = 0; i < d; ++i)
    {
        nodes[i] = INT_MAX;
        flag[i] = 0;
        for (int j = 0; j < d; ++j)
        {
            cost = getInt();
            matrix[i][j] = cost;
        }
    }
    nodes[0] = 0;
    flag[0] = 1;
    for (int i = 0; i < d - 1; ++i)
    {
        min = INT_MAX;
        for (int j = 1; j < d; ++j)
        {
            if (!flag[j])
            {
                if (matrix[nod][j] != 0 && j != nod)
                {
                    if (nodes[nod] + matrix[nod][j] < nodes[j])
                    {
                        nodes[j] = nodes[nod] + matrix[nod][j];
                    }
                }
                if (nodes[j] < min)
                {
                    min = nodes[j];
                    n = j;
                }
            }
        }
        nod = n;
        if (!flag[nod])
        {
            sum += nodes[nod];
        }
        flag[nod] = 1;
    }
    return sum;
}

Graph addGraph(int i, int d)
{
    Graph graph = {.number = i, .sumPaths = minPaths(d)};
    return graph;
}

void insertInList(Graph **graphs, Graph graph, int k, int index)
{
    if (index == 0)
    {
        Graph *list = malloc(sizeof(Graph));
        list->number = graph.number;
        list->sumPaths = graph.sumPaths;
        list->next = NULL;
        *graphs = list;
    }
    int i = 0;
    Graph *prev = NULL, *curr = *graphs;
    while (curr != NULL && graph.sumPaths >= curr->sumPaths && i < k)
    {
        ++i;
        prev = curr;
        curr = curr->next;
    }
    if (i < k)
    {
        Graph *list = malloc(sizeof(Graph));
        list->number = graph.number;
        list->sumPaths = graph.sumPaths;
        list->next = NULL;
        if (prev != NULL)
        {
            prev->next = list;
            list->next = curr;
        }
        else
        {
            list->next = *graphs;
            *graphs = list;
        }
    }
}

void print(int n)
{
    if (n / 10 != 0)
    {
        print(n / 10);
    }
    putchar((n % 10) + '0');
}

void topK(Graph *graphs, int index)
{
    int i = 1;
    print(graphs->number);
    graphs = graphs->next;
    while (i < index)
    {
        putchar(' ');
        print(graphs->number);
        graphs = graphs->next;
        i++;
    }
}

int main()
{
    int d, k, j, i = 0;
    char input[14], c;
    d = getInt();
    k = getInt();
    Graph *graphs;
    do
    {
        j = 0;
        c = getchar();
        while (c != '\n' && c != EOF)
        {
            input[j] = c;
            ++j;
            c = getchar();
        }
        input[j] = '\0';
        if (strcmp("AggiungiGrafo", input) == 0)
        {
            insertInList(&graphs, addGraph(i, d), k, i);
            ++i;
        }
        if (strcmp("TopK", input) == 0)
        {
            if (i != 0)
            {
                topK(graphs, min(i, k));
            }
            if (!feof(stdin))
            {
                putchar('\n');
            }
        }
    } while (!feof(stdin));
    free(graphs);
    return 0;
}
