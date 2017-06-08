#ifndef DISJOINTSETS_H
#define DISJOINTSETS_H


class DisjointSets
{
    public:
        DisjointSets(int n);
        virtual ~DisjointSets();
        int find(int u);
        void merge(int x, int y);
    private:
        int *parent, *rnk;
        int n;
};

#endif // DISJOINTSETS_H
